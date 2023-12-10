//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define SMB_TARGET   0xD0 // SMB target address of IMU
#define SMB_MTSTA    0xE0 // (MT) start transmitted
#define SMB_MTDB     0xC0 // (MT) data byte transmitted
#define SMB_MRDB     0x80 // (MR) data byte received

#define SMB_STATE_RD1      0x04
#define SMB_STATE_RD_STOP  0x03
#define SMB_STATE_WR2      0x02
#define SMB_STATE_WR1      0x01
#define SMB_STATE_WR_STOP  0x00



//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

volatile U8 smb_data_in;              // Global holder for SMBus data.
volatile U8 smb_data_out [2];         // Global holder for SMBus data.
volatile U8 smb_busy;                 // Software flag to indicate when the
volatile U8 smb_rnw;                   // Software flag to indicate the
volatile U8 smb_ptr;

volatile U8 mpu_state;

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void uartTx(U8 tx);
void setup(void);
U8 smbRead(U8 addr);
void smbWrite(U8 addr, U8 data);

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){          
   U8 i;
   setup();  
   
   smbWrite(0xAA, 0x0);
   
   i = smbRead(0x75);
   
   uartTx('0');
   uartTx('x');
   uartTx((i >> 4) + '0');
   uartTx((i & 0xF) + '0');
   

   for(;;){

   };
}
 
//-----------------------------------------------------------------------------
// Interrupt Vectors
//-----------------------------------------------------------------------------

INTERRUPT (TIMER2_ISR, TIMER2_IRQn){            
 
   // Enable the interrupts
   TMR2CN &= ~TMR2CN_TF2H__SET;
   IE = IE_EA__ENABLED | 
        IE_ET2__ENABLED;  
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
                              case SMB_STATE_RD_STOP:    SMB0CN_STO = 1;   
                                                         break; 
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
      case SMB_MRDB:    smb_data_in = SMB0DAT;           // Store received byte
                        smb_busy = 0;                    // Free SMBus interface
                        SMB0CN_ACK = 0;                  // Send NACK to indicate last byte  of this transfer
                        SMB0CN_STO = 1;                  // Send STOP to terminate transfer
                        break;
      default:          break;
   
   }  
   SMB0CN_SI = 0; //Clear interrupt flag 
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
   SCON0_TI = 0;
   SBUF0 = tx;
   while(!SCON0_TI); 
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
   
   // Setup Timers
   CKCON    = CKCON_T1M__SYSCLK| 
              CKCON_T2ML__EXTERNAL_CLOCK|
              CKCON_T2MH__EXTERNAL_CLOCK;

   TMR2CN   = TMR2CN_T2XCLK__SYSCLK_DIV_12;

   // Timers
   TMOD     = TMOD_T0M__MODE2 |
              TMOD_T1M__MODE2;
	TCON     = TCON_TR0__RUN |
              TCON_TR1__RUN; 
   TH0      = 0x40;           // I2C SCL - 333KHz (above 100KHz max for drivers datasheet)
   TL0      = 0x00;
   TH1      = 0x96;           // Magic values from datasheet for 115200
	TL1      = 0x96; 

   // Timer 2: 
	TMR2CN   = TMR2CN_TR2__RUN; 
   TMR2L    = 0x00;
   TMR2H    = 0x00;
   TMR2RLL  = 0x00;
   TMR2RLH  = 0x00;
  
   // SMBus
   SMB0CF   = SMB0CF_INH__SLAVE_DISABLED|
              SMB0CF_SMBCS__TIMER0|
              SMB0CF_SMBFTE__FREE_TO_ENABLED| 
              SMB0CF_ENSMB__ENABLED; 

   SMB0TC   = SMB0TC_SDD__ADD_8_SYSCLKS;

   // Interrupts
   IE       = IE_EA__ENABLED | 
              IE_ET2__ENABLED;
   EIE1     = EIE1_ESMB0__ENABLED;
}


