//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define UART_BUF_SIZE      50

#define SMB_TARGET         0xD0 // SMB target address of IMU
#define SMB_MTSTA          0xE0 // (MT) start transmitted
#define SMB_MTDB           0xC0 // (MT) data byte transmitted
#define SMB_MRDB           0x80 // (MR) data byte received

#define SMB_STATE_MPU14    0x1E
#define SMB_STATE_MPU13    0x1D
#define SMB_STATE_MPU12    0x1C
#define SMB_STATE_MPU11    0x1B
#define SMB_STATE_MPU10    0x1A
#define SMB_STATE_MPU09    0x19
#define SMB_STATE_MPU08    0x18
#define SMB_STATE_MPU07    0x17
#define SMB_STATE_MPU06    0x16
#define SMB_STATE_MPU05    0x15
#define SMB_STATE_MPU04    0x14
#define SMB_STATE_MPU03    0x13
#define SMB_STATE_MPU02    0x12
#define SMB_STATE_MPU01    0x11
#define SMB_STATE_MPU00    0x10
#define SMB_STATE_RD1      0x04
#define SMB_STATE_RD_STOP  0x03
#define SMB_STATE_WR2      0x02
#define SMB_STATE_WR1      0x01
#define SMB_STATE_WR_STOP  0x00

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

volatile U8 uart_buf[UART_BUF_SIZE];
volatile U8 uart_head;
volatile U8 uart_tail;

volatile U8 smb_data_in;              // Global holder for SMBus data.
volatile U8 smb_data_out [2];         // Global holder for SMBus data.
volatile U8 smb_busy;                 // Software flag to indicate when the
volatile U8 smb_rnw;                   // Software flag to indicate the
volatile U8 smb_ptr;

volatile U8 mpu_state;

volatile U16 sample;
volatile U16 accel_x;
volatile U16 accel_y;
volatile U16 accel_z;
volatile U16 gyro_x;
volatile U16 gyro_y;
volatile U16 gyro_z;
volatile U16 p;

volatile U8 go;

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void uartTx(U8 tx);
U8 uartEmpty(void);
void setup(void);
U8 nibble2hex(U8);
void smbReadMpuSensors (void);
U8 smbRead(U8 addr);
void smbWrite(U8 addr, U8 data);
void sendU16(U16 s);

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){            
   setup();  
   
   // Sample counter to 0
   sample = 0;  

   p = 0;

   // Setup UART buffer
   uart_head = 0;
   uart_tail = 0;

   // MPU out of sleep
   smbWrite(0x6B, 0x00);  

   for(;;){
      smbReadMpuSensors();      
      if(uartEmpty()){
         while(smb_busy);
         sendU16(sample); 
         sendU16(accel_x); 
         sendU16(accel_y);
         sendU16(accel_z); 
         sendU16(gyro_x);
         sendU16(gyro_y);
         sendU16(gyro_z);
         sendU16(p);
         uartTx('\n');
      }
      go = 0;
      while(!go);
   }
}

//-----------------------------------------------------------------------------
// UART Helpers
//-----------------------------------------------------------------------------


void sendU16(U16 s){
   uartTx(nibble2hex(s >> 12));
   uartTx(nibble2hex(s >> 8));
   uartTx(nibble2hex(s >> 4));
   uartTx(nibble2hex(s));
   uartTx(',');
}

U8 nibble2hex(U8 n){
   U8 i;
   i = n & 0xF;
   if(i > 0x9){
      i += ('A' - 0xA);
   }else{
      i += '0';
   }
   return i;
}

//-----------------------------------------------------------------------------
// Interrupt Vectors
//-----------------------------------------------------------------------------

INTERRUPT (UART0_ISR, UART0_IRQn){     // Service both Rx & Tx flags 
   if(SCON0_RI){
      p = SBUF0;   
   }
   SCON0_RI = 0;
   SCON0_TI = 0;
   IE |= IE_ES0__ENABLED; 
} 

INTERRUPT (TIMER2_ISR, TIMER2_IRQn){            
   go = 1;
   sample++;   
   // Enable the interrupts
   TMR2CN &= ~TMR2CN_TF2H__SET;
   IE |= IE_ET2__ENABLED; 

} 

INTERRUPT (TIMER3_ISR, TIMER3_IRQn){            

   if(uart_head != uart_tail){ 
      SBUF0 = uart_buf[uart_tail];
      uart_tail++;
      uart_tail %= UART_BUF_SIZE;
   }

   // Enable the interrupts
   TMR3CN &= ~TMR3CN_TF3H__SET;
   EIE1 |= EIE1_ET3__ENABLED;
} 

//-----------------------------------------------------------------------------
// SMB
//-----------------------------------------------------------------------------

INTERRUPT(SMBUS0_ISR, SMBUS0_IRQn){ 
   switch (SMB0CN & 0xF0) {
      // Master Transmitter/Receiver: START condition transmitted.
      case SMB_MTSTA:   SMB0DAT = SMB_TARGET;            // Load address of the target slave (only one)
                        SMB0DAT &= 0xFE;                 // Clear the LSB of the address for the 
                        SMB0DAT |= smb_rnw;               // Load R/W bit
                        SMB0CN_STA = 0;                  // Manually clear START bit 
                        break;
      // Master Transmitter: Data byte transmitted only writes
      case SMB_MTDB:    if(SMB0CN_ACK) {
                           switch(mpu_state){ 
                              case SMB_STATE_RD1:        mpu_state = SMB_STATE_RD_STOP;
                                                         break;
                              case SMB_STATE_RD_STOP:    break; 
                              case SMB_STATE_WR2:        SMB0DAT = smb_data_out[1]; 
                                                         mpu_state = SMB_STATE_WR1;
                                                         break;
                              case SMB_STATE_WR1:        SMB0DAT = smb_data_out[0]; 
                                                         mpu_state = SMB_STATE_WR_STOP;
                                                         break;
                              case SMB_STATE_WR_STOP:    SMB0CN_STO = 1;   
                                                         smb_busy = 0;     
                              default:                   break;
                           }

                        } else {
                           // Transmission failed
                           SMB0CN_STO = 1;               // Send STOP condition,followed
                           SMB0CN_STA = 1;               // By a START 
                        }
                        break;
      // Master Receiver: byte received
      case SMB_MRDB:    switch(mpu_state){
                           case SMB_STATE_MPU13:   accel_x = SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU12;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU12:   accel_x <<= 8;
                                                   accel_x |= SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU11;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU11:   accel_y = SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU10;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU10:   accel_y <<= 8;
                                                   accel_y |= SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU09;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU09:   accel_z = SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU08;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU08:   accel_z <<= 8;
                                                   accel_z |= SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU07;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU07:   mpu_state = SMB_STATE_MPU06;  // Throw away temp lower data
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU06:   mpu_state = SMB_STATE_MPU05;  // Throw awat temp higher data
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU05:   gyro_x = SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU04;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU04:   gyro_x <<= 8;
                                                   gyro_x |= SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU03;
                                                   SMB0CN_ACK = 1;         
                                                   break;
                           case SMB_STATE_MPU03:   gyro_y = SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU02;
                                                   SMB0CN_ACK = 1;               
                                                   break;
                           case SMB_STATE_MPU02:   gyro_y <<= 8;
                                                   gyro_y |= SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU01;
                                                   SMB0CN_ACK = 1;               
                                                   break;
                           case SMB_STATE_MPU01:   gyro_z = SMB0DAT;
                                                   mpu_state = SMB_STATE_MPU00;
                                                   SMB0CN_ACK = 1;                 
                                                   break;
                           case SMB_STATE_MPU00:   gyro_z <<= 8;
                                                   gyro_z |= SMB0DAT;
                                                   smb_busy = 0;                    
                                                   SMB0CN_ACK = 0;                  
                                                   SMB0CN_STO = 1;                  
                                                   break;
                           default:                smb_data_in = SMB0DAT; 
                                                   smb_busy = 0;                    // Free SMBus interface
                                                   SMB0CN_ACK = 0;                  // Send NACK to indicate last byte  of this transfer
                                                   SMB0CN_STO = 1;                  // Send STOP to terminate transfer
                                                   break;
                        }
                        break;
      default:          break;
   
   }  
   SMB0CN_SI = 0; //Clear interrupt flag 
}

void smbReadMpuSensors (void) {
   while (smb_busy);             // Wait for bus to be free.
   mpu_state = SMB_STATE_WR1;
   smb_data_out[0] = 0x3B;
   smb_busy = 1;                 // Claim SMBus (set to busy)  
   smb_rnw = 0;                  // Mark this transfer as a WRITE
   SMB0CN_STA = 1;               // Start transfer 
   while (smb_busy);             // Wait for bus to be free.
   mpu_state = SMB_STATE_MPU13; 
   smb_busy = 1;                 // Claim SMBus (set to busy)  
   smb_rnw = 1;                  // Mark this transfer as a WRITE
   SMB0CN_STA = 1;               // Start transfer  
}

U8 smbRead (U8 addr){
   while (smb_busy);          // Wait for bus to be free.
   mpu_state = SMB_STATE_WR1;
   smb_data_out[0] = addr;
   smb_busy = 1;              // Claim SMBus (set to busy)  
   smb_rnw = 0;               // Mark this transfer as a WRITE
   SMB0CN_STA = 1;            // Start transfer 
   while (smb_busy);          // Wait for bus to be free.
   mpu_state = SMB_STATE_RD1; 
   smb_busy = 1;              // Claim SMBus (set to busy)  
   smb_rnw = 1;               // Mark this transfer as a WRITE
   SMB0CN_STA = 1;            // Start transfer 
   while (smb_busy);
   return smb_data_in;
}

void smbWrite (U8 addr, U8 data){
   while(smb_busy);
   mpu_state = SMB_STATE_WR2;
   smb_data_out[1] = addr;
   smb_data_out[0] = data;
   smb_busy = 1;              // Claim SMBus (set to busy)  
   smb_rnw = 0;               // Mark this transfer as a WRITE
   SMB0CN_STA = 1;            // Start transfer 
}

//-----------------------------------------------------------------------------
// UART
//-----------------------------------------------------------------------------

void uartTx(U8 tx){ 
   uart_buf[uart_head] = tx;
   uart_head++;
   uart_head %= UART_BUF_SIZE;
}

U8 uartEmpty(void){ 
   if(uart_head == uart_tail){
      return 1;
   } else {
      return 0;
   }
}
//-----------------------------------------------------------------------------
// Setup
//-----------------------------------------------------------------------------

void setup(void){

   // Disabled watchdog
   WDTCN    = 0xDE;
   WDTCN    = 0xAD;

	CLKSEL   = CLKSEL_CLKSL__HFOSC |			     
              CLKSEL_CLKDIV__SYSCLK_DIV_1; 
   
   // Enable IOs 
   P0SKIP   = P0SKIP_B0__SKIPPED|
              P0SKIP_B1__SKIPPED|
              P0SKIP_B2__SKIPPED|
              P0SKIP_B3__SKIPPED|
              P0SKIP_B6__SKIPPED|
              P0SKIP_B7__SKIPPED;

   P1MDOUT  = 0x00;
   P1SKIP   = P1SKIP_B0__SKIPPED|
              P1SKIP_B1__SKIPPED|
              P1SKIP_B2__SKIPPED|
              P1SKIP_B3__SKIPPED|
              P1SKIP_B4__SKIPPED|
              P1SKIP_B5__SKIPPED;

   XBR0     = XBR0_SMB0E__ENABLED|
              XBR0_URT0E__ENABLED; 
   XBR2     = XBR2_WEAKPUD__PULL_UPS_DISABLED | 
              XBR2_XBARE__ENABLED;
   
   // UART
   SCON0    = SCON0_REN__RECEIVE_ENABLED;

   // Setup Clocks
   CKCON    = CKCON_T1M__SYSCLK| 
              CKCON_T2ML__EXTERNAL_CLOCK|
              CKCON_T2MH__EXTERNAL_CLOCK;

   TMR2CN   = TMR2CN_T2XCLK__SYSCLK_DIV_12;

   // Timer 0: I2C SCL
   // Timer 1: UART clock
   TMOD     = TMOD_T0M__MODE2 |
              TMOD_T1M__MODE2;
	TCON     = TCON_TR0__RUN |
              TCON_TR1__RUN; 
   TH0      = 0xF5;  // 60KHz 
   TL0      = 0x80;
   TH1      = 0x96;  // Magic values from datasheet for 115200
	TL1      = 0x96; 

   // Timer 2: MPU Sample timer
	TMR2CN   = TMR2CN_TR2__RUN; 
   TMR2L    = 0x00;
   TMR2H    = 0xD8;
   TMR2RLL  = 0x00;
   TMR2RLH  = 0xD8;  // 200Hz/5ms 
    
   // Timer 3: UART Transmit timer
	TMR3CN   = TMR3CN_TR3__RUN; 
   TMR3L    = 0x00;
   TMR3H    = 0xFC;
   TMR3RLL  = 0x00;
   TMR3RLH  = 0xFC;  // 2KHz/0.5ms       
  
   // SMBus
   SMB0CF   = SMB0CF_INH__SLAVE_DISABLED|
              SMB0CF_SMBCS__TIMER0|
              SMB0CF_SMBFTE__FREE_TO_ENABLED| 
              SMB0CF_ENSMB__ENABLED; 

   SMB0TC   = SMB0TC_SDD__ADD_8_SYSCLKS;

   // Interrupts
   IE       = IE_EA__ENABLED | 
              IE_ES0__ENABLED | 
              IE_ET2__ENABLED;
   EIE1     = EIE1_ESMB0__ENABLED |
              EIE1_ET3__ENABLED;
}


