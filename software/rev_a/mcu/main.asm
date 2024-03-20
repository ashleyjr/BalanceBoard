;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _smbWrite_PARM_3
	.globl _smbWrite_PARM_2
	.globl _smbRead_PARM_2
	.globl _SMBUS0_ISR
	.globl _TIMER3_ISR
	.globl _TIMER2_ISR
	.globl _UART0_ISR
	.globl _main
	.globl _PWM
	.globl _TMR2CN_TF2H
	.globl _TMR2CN_TF2L
	.globl _TMR2CN_TF2LEN
	.globl _TMR2CN_TF2CEN
	.globl _TMR2CN_T2SPLIT
	.globl _TMR2CN_TR2
	.globl _TMR2CN_T2XCLK
	.globl _TCON_TF1
	.globl _TCON_TR1
	.globl _TCON_TF0
	.globl _TCON_TR0
	.globl _TCON_IE1
	.globl _TCON_IT1
	.globl _TCON_IE0
	.globl _TCON_IT0
	.globl _SPI0CN_SPIF
	.globl _SPI0CN_WCOL
	.globl _SPI0CN_MODF
	.globl _SPI0CN_RXOVRN
	.globl _SPI0CN_NSSMD1
	.globl _SPI0CN_NSSMD0
	.globl _SPI0CN_TXBMT
	.globl _SPI0CN_SPIEN
	.globl _SMB0CN_MASTER
	.globl _SMB0CN_TXMODE
	.globl _SMB0CN_STA
	.globl _SMB0CN_STO
	.globl _SMB0CN_ACKRQ
	.globl _SMB0CN_ARBLOST
	.globl _SMB0CN_ACK
	.globl _SMB0CN_SI
	.globl _SCON0_SMODE
	.globl _SCON0_MCE
	.globl _SCON0_REN
	.globl _SCON0_TB8
	.globl _SCON0_RB8
	.globl _SCON0_TI
	.globl _SCON0_RI
	.globl _PSW_CY
	.globl _PSW_AC
	.globl _PSW_F0
	.globl _PSW_RS1
	.globl _PSW_RS0
	.globl _PSW_OV
	.globl _PSW_F1
	.globl _PSW_PARITY
	.globl _PCA0CN_CF
	.globl _PCA0CN_CR
	.globl _PCA0CN_CCF2
	.globl _PCA0CN_CCF1
	.globl _PCA0CN_CCF0
	.globl _P2_B1
	.globl _P2_B0
	.globl _P1_B7
	.globl _P1_B6
	.globl _P1_B5
	.globl _P1_B4
	.globl _P1_B3
	.globl _P1_B2
	.globl _P1_B1
	.globl _P1_B0
	.globl _P0_B7
	.globl _P0_B6
	.globl _P0_B5
	.globl _P0_B4
	.globl _P0_B3
	.globl _P0_B2
	.globl _P0_B1
	.globl _P0_B0
	.globl _IP_PSPI0
	.globl _IP_PT2
	.globl _IP_PS0
	.globl _IP_PT1
	.globl _IP_PX1
	.globl _IP_PT0
	.globl _IP_PX0
	.globl _IE_EA
	.globl _IE_ESPI0
	.globl _IE_ET2
	.globl _IE_ES0
	.globl _IE_ET1
	.globl _IE_EX1
	.globl _IE_ET0
	.globl _IE_EX0
	.globl _B_B7
	.globl _B_B6
	.globl _B_B5
	.globl _B_B4
	.globl _B_B3
	.globl _B_B2
	.globl _B_B1
	.globl _B_B0
	.globl _ADC0CN0_ADEN
	.globl _ADC0CN0_ADBMEN
	.globl _ADC0CN0_ADINT
	.globl _ADC0CN0_ADBUSY
	.globl _ADC0CN0_ADWINT
	.globl _ADC0CN0_ADCM2
	.globl _ADC0CN0_ADCM1
	.globl _ADC0CN0_ADCM0
	.globl _ACC_ACC7
	.globl _ACC_ACC6
	.globl _ACC_ACC5
	.globl _ACC_ACC4
	.globl _ACC_ACC3
	.globl _ACC_ACC2
	.globl _ACC_ACC1
	.globl _ACC_ACC0
	.globl __XPAGE
	.globl _TMR3RL
	.globl _TMR3
	.globl _TMR2RL
	.globl _TMR2
	.globl _PCA0
	.globl _PCA0CP2
	.globl _PCA0CP1
	.globl _PCA0CP0
	.globl _DP
	.globl _ADC0LT
	.globl _ADC0
	.globl _ADC0GT
	.globl _XBR2
	.globl _XBR1
	.globl _XBR0
	.globl _WDTCN
	.globl _VDM0CN
	.globl _TMR3RLL
	.globl _TMR3RLH
	.globl _TMR3L
	.globl _TMR3H
	.globl _TMR3CN
	.globl _TMR2RLL
	.globl _TMR2RLH
	.globl _TMR2L
	.globl _TMR2H
	.globl _TMR2CN
	.globl _TMOD
	.globl _TL1
	.globl _TL0
	.globl _TH1
	.globl _TH0
	.globl _TCON
	.globl _SPI0DAT
	.globl _SPI0CN
	.globl _SPI0CKR
	.globl _SPI0CFG
	.globl _SP
	.globl _SMB0TC
	.globl _SMB0DAT
	.globl _SMB0CN
	.globl _SMB0CF
	.globl _SMB0ADR
	.globl _SMB0ADM
	.globl _SCON0
	.globl _SBUF0
	.globl _RSTSRC
	.globl _REVID
	.globl _REG0CN
	.globl _REF0CN
	.globl _PSW
	.globl _PSCTL
	.globl _PRTDRV
	.globl _PCON
	.globl _PCA0PWM
	.globl _PCA0POL
	.globl _PCA0MD
	.globl _PCA0L
	.globl _PCA0H
	.globl _PCA0CPM2
	.globl _PCA0CPM1
	.globl _PCA0CPM0
	.globl _PCA0CPL2
	.globl _PCA0CPL1
	.globl _PCA0CPL0
	.globl _PCA0CPH2
	.globl _PCA0CPH1
	.globl _PCA0CPH0
	.globl _PCA0CN
	.globl _PCA0CLR
	.globl _PCA0CENT
	.globl _P2MDOUT
	.globl _P2
	.globl _P1SKIP
	.globl _P1MDOUT
	.globl _P1MDIN
	.globl _P1MAT
	.globl _P1MASK
	.globl _P1
	.globl _P0SKIP
	.globl _P0MDOUT
	.globl _P0MDIN
	.globl _P0MAT
	.globl _P0MASK
	.globl _P0
	.globl _OSCLCN
	.globl _OSCICL
	.globl _IT01CF
	.globl _IP
	.globl _IE
	.globl _FLKEY
	.globl _EIP1
	.globl _EIE1
	.globl _DPL
	.globl _DPH
	.globl _DEVICEID
	.globl _DERIVID
	.globl _CRC0IN
	.globl _CRC0FLIP
	.globl _CRC0DAT
	.globl _CRC0CNT
	.globl _CRC0CN
	.globl _CRC0AUTO
	.globl _CPT1MX
	.globl _CPT1MD
	.globl _CPT1CN
	.globl _CPT0MX
	.globl _CPT0MD
	.globl _CPT0CN
	.globl _CLKSEL
	.globl _CKCON
	.globl _B
	.globl _ADC0TK
	.globl _ADC0PWR
	.globl _ADC0MX
	.globl _ADC0LTL
	.globl _ADC0LTH
	.globl _ADC0L
	.globl _ADC0H
	.globl _ADC0GTL
	.globl _ADC0GTH
	.globl _ADC0CN1
	.globl _ADC0CN0
	.globl _ADC0CF
	.globl _ADC0AC
	.globl _ACC
	.globl _go
	.globl _p
	.globl _gyro_z
	.globl _gyro_y
	.globl _gyro_x
	.globl _accel_z
	.globl _accel_y
	.globl _accel_x
	.globl _sample
	.globl _mpu_state
	.globl _smb_ptr
	.globl _smb_rnw
	.globl _smb_busy
	.globl _smb_data_out
	.globl _smb_data_in
	.globl _smb_target
	.globl _uart_tail
	.globl _uart_head
	.globl _uart_buf
	.globl _sendU16
	.globl _nibble2hex
	.globl _smbReadMpuSensors
	.globl _smbRead
	.globl _smbWrite
	.globl _uartTx
	.globl _uartEmpty
	.globl _setup
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_ACC	=	0x00e0
_ADC0AC	=	0x00b3
_ADC0CF	=	0x00bc
_ADC0CN0	=	0x00e8
_ADC0CN1	=	0x00b2
_ADC0GTH	=	0x00c4
_ADC0GTL	=	0x00c3
_ADC0H	=	0x00be
_ADC0L	=	0x00bd
_ADC0LTH	=	0x00c6
_ADC0LTL	=	0x00c5
_ADC0MX	=	0x00bb
_ADC0PWR	=	0x00df
_ADC0TK	=	0x00b9
_B	=	0x00f0
_CKCON	=	0x008e
_CLKSEL	=	0x00a9
_CPT0CN	=	0x009b
_CPT0MD	=	0x009d
_CPT0MX	=	0x009f
_CPT1CN	=	0x00bf
_CPT1MD	=	0x00ab
_CPT1MX	=	0x00aa
_CRC0AUTO	=	0x00d2
_CRC0CN	=	0x00ce
_CRC0CNT	=	0x00d3
_CRC0DAT	=	0x00de
_CRC0FLIP	=	0x00cf
_CRC0IN	=	0x00dd
_DERIVID	=	0x00ad
_DEVICEID	=	0x00b5
_DPH	=	0x0083
_DPL	=	0x0082
_EIE1	=	0x00e6
_EIP1	=	0x00f3
_FLKEY	=	0x00b7
_IE	=	0x00a8
_IP	=	0x00b8
_IT01CF	=	0x00e4
_OSCICL	=	0x00c7
_OSCLCN	=	0x00b1
_P0	=	0x0080
_P0MASK	=	0x00fe
_P0MAT	=	0x00fd
_P0MDIN	=	0x00f1
_P0MDOUT	=	0x00a4
_P0SKIP	=	0x00d4
_P1	=	0x0090
_P1MASK	=	0x00ee
_P1MAT	=	0x00ed
_P1MDIN	=	0x00f2
_P1MDOUT	=	0x00a5
_P1SKIP	=	0x00d5
_P2	=	0x00a0
_P2MDOUT	=	0x00a6
_PCA0CENT	=	0x009e
_PCA0CLR	=	0x009c
_PCA0CN	=	0x00d8
_PCA0CPH0	=	0x00fc
_PCA0CPH1	=	0x00ea
_PCA0CPH2	=	0x00ec
_PCA0CPL0	=	0x00fb
_PCA0CPL1	=	0x00e9
_PCA0CPL2	=	0x00eb
_PCA0CPM0	=	0x00da
_PCA0CPM1	=	0x00db
_PCA0CPM2	=	0x00dc
_PCA0H	=	0x00fa
_PCA0L	=	0x00f9
_PCA0MD	=	0x00d9
_PCA0POL	=	0x0096
_PCA0PWM	=	0x00f7
_PCON	=	0x0087
_PRTDRV	=	0x00f6
_PSCTL	=	0x008f
_PSW	=	0x00d0
_REF0CN	=	0x00d1
_REG0CN	=	0x00c9
_REVID	=	0x00b6
_RSTSRC	=	0x00ef
_SBUF0	=	0x0099
_SCON0	=	0x0098
_SMB0ADM	=	0x00d6
_SMB0ADR	=	0x00d7
_SMB0CF	=	0x00c1
_SMB0CN	=	0x00c0
_SMB0DAT	=	0x00c2
_SMB0TC	=	0x00ac
_SP	=	0x0081
_SPI0CFG	=	0x00a1
_SPI0CKR	=	0x00a2
_SPI0CN	=	0x00f8
_SPI0DAT	=	0x00a3
_TCON	=	0x0088
_TH0	=	0x008c
_TH1	=	0x008d
_TL0	=	0x008a
_TL1	=	0x008b
_TMOD	=	0x0089
_TMR2CN	=	0x00c8
_TMR2H	=	0x00cd
_TMR2L	=	0x00cc
_TMR2RLH	=	0x00cb
_TMR2RLL	=	0x00ca
_TMR3CN	=	0x0091
_TMR3H	=	0x0095
_TMR3L	=	0x0094
_TMR3RLH	=	0x0093
_TMR3RLL	=	0x0092
_VDM0CN	=	0x00ff
_WDTCN	=	0x0097
_XBR0	=	0x00e1
_XBR1	=	0x00e2
_XBR2	=	0x00e3
_ADC0GT	=	0xc4c3
_ADC0	=	0xbebd
_ADC0LT	=	0xc6c5
_DP	=	0x8382
_PCA0CP0	=	0xfcfb
_PCA0CP1	=	0xeae9
_PCA0CP2	=	0xeceb
_PCA0	=	0xfaf9
_TMR2	=	0xcdcc
_TMR2RL	=	0xcbca
_TMR3	=	0x9594
_TMR3RL	=	0x9392
__XPAGE	=	0x00aa
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_ACC_ACC0	=	0x00e0
_ACC_ACC1	=	0x00e1
_ACC_ACC2	=	0x00e2
_ACC_ACC3	=	0x00e3
_ACC_ACC4	=	0x00e4
_ACC_ACC5	=	0x00e5
_ACC_ACC6	=	0x00e6
_ACC_ACC7	=	0x00e7
_ADC0CN0_ADCM0	=	0x00e8
_ADC0CN0_ADCM1	=	0x00e9
_ADC0CN0_ADCM2	=	0x00ea
_ADC0CN0_ADWINT	=	0x00eb
_ADC0CN0_ADBUSY	=	0x00ec
_ADC0CN0_ADINT	=	0x00ed
_ADC0CN0_ADBMEN	=	0x00ee
_ADC0CN0_ADEN	=	0x00ef
_B_B0	=	0x00f0
_B_B1	=	0x00f1
_B_B2	=	0x00f2
_B_B3	=	0x00f3
_B_B4	=	0x00f4
_B_B5	=	0x00f5
_B_B6	=	0x00f6
_B_B7	=	0x00f7
_IE_EX0	=	0x00a8
_IE_ET0	=	0x00a9
_IE_EX1	=	0x00aa
_IE_ET1	=	0x00ab
_IE_ES0	=	0x00ac
_IE_ET2	=	0x00ad
_IE_ESPI0	=	0x00ae
_IE_EA	=	0x00af
_IP_PX0	=	0x00b8
_IP_PT0	=	0x00b9
_IP_PX1	=	0x00ba
_IP_PT1	=	0x00bb
_IP_PS0	=	0x00bc
_IP_PT2	=	0x00bd
_IP_PSPI0	=	0x00be
_P0_B0	=	0x0080
_P0_B1	=	0x0081
_P0_B2	=	0x0082
_P0_B3	=	0x0083
_P0_B4	=	0x0084
_P0_B5	=	0x0085
_P0_B6	=	0x0086
_P0_B7	=	0x0087
_P1_B0	=	0x0090
_P1_B1	=	0x0091
_P1_B2	=	0x0092
_P1_B3	=	0x0093
_P1_B4	=	0x0094
_P1_B5	=	0x0095
_P1_B6	=	0x0096
_P1_B7	=	0x0097
_P2_B0	=	0x00a0
_P2_B1	=	0x00a1
_PCA0CN_CCF0	=	0x00d8
_PCA0CN_CCF1	=	0x00d9
_PCA0CN_CCF2	=	0x00da
_PCA0CN_CR	=	0x00de
_PCA0CN_CF	=	0x00df
_PSW_PARITY	=	0x00d0
_PSW_F1	=	0x00d1
_PSW_OV	=	0x00d2
_PSW_RS0	=	0x00d3
_PSW_RS1	=	0x00d4
_PSW_F0	=	0x00d5
_PSW_AC	=	0x00d6
_PSW_CY	=	0x00d7
_SCON0_RI	=	0x0098
_SCON0_TI	=	0x0099
_SCON0_RB8	=	0x009a
_SCON0_TB8	=	0x009b
_SCON0_REN	=	0x009c
_SCON0_MCE	=	0x009d
_SCON0_SMODE	=	0x009f
_SMB0CN_SI	=	0x00c0
_SMB0CN_ACK	=	0x00c1
_SMB0CN_ARBLOST	=	0x00c2
_SMB0CN_ACKRQ	=	0x00c3
_SMB0CN_STO	=	0x00c4
_SMB0CN_STA	=	0x00c5
_SMB0CN_TXMODE	=	0x00c6
_SMB0CN_MASTER	=	0x00c7
_SPI0CN_SPIEN	=	0x00f8
_SPI0CN_TXBMT	=	0x00f9
_SPI0CN_NSSMD0	=	0x00fa
_SPI0CN_NSSMD1	=	0x00fb
_SPI0CN_RXOVRN	=	0x00fc
_SPI0CN_MODF	=	0x00fd
_SPI0CN_WCOL	=	0x00fe
_SPI0CN_SPIF	=	0x00ff
_TCON_IT0	=	0x0088
_TCON_IE0	=	0x0089
_TCON_IT1	=	0x008a
_TCON_IE1	=	0x008b
_TCON_TR0	=	0x008c
_TCON_TF0	=	0x008d
_TCON_TR1	=	0x008e
_TCON_TF1	=	0x008f
_TMR2CN_T2XCLK	=	0x00c8
_TMR2CN_TR2	=	0x00ca
_TMR2CN_T2SPLIT	=	0x00cb
_TMR2CN_TF2CEN	=	0x00cc
_TMR2CN_TF2LEN	=	0x00cd
_TMR2CN_TF2L	=	0x00ce
_TMR2CN_TF2H	=	0x00cf
_PWM	=	0x0094
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_uart_buf::
	.ds 50
_uart_head::
	.ds 1
_uart_tail::
	.ds 1
_smb_target::
	.ds 1
_smb_data_in::
	.ds 1
_smb_data_out::
	.ds 2
_smb_busy::
	.ds 1
_smb_rnw::
	.ds 1
_smb_ptr::
	.ds 1
_mpu_state::
	.ds 1
_sample::
	.ds 2
_accel_x::
	.ds 2
_accel_y::
	.ds 2
_accel_z::
	.ds 2
_gyro_x::
	.ds 2
_gyro_y::
	.ds 2
_gyro_z::
	.ds 2
_p::
	.ds 2
_go::
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_smbRead_PARM_2:
	.ds 1
	.area	OSEG    (OVR,DATA)
_smbWrite_PARM_2:
	.ds 1
_smbWrite_PARM_3:
	.ds 1
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_UART0_ISR
	.ds	5
	ljmp	_TIMER2_ISR
	.ds	5
	reti
	.ds	7
	ljmp	_SMBUS0_ISR
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_TIMER3_ISR
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;i                         Allocated to registers r7 
;j                         Allocated to registers r5 r6 
;------------------------------------------------------------
;	src/main.c:88: void main (void){             
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	src/main.c:91: setup();  
	lcall	_setup
;	src/main.c:94: sample = 0;  
	clr	a
	mov	_sample,a
	mov	(_sample + 1),a
;	src/main.c:97: uart_head = 0;
;	1-genFromRTrack replaced	mov	_uart_head,#0x00
	mov	_uart_head,a
;	src/main.c:98: uart_tail = 0;
;	1-genFromRTrack replaced	mov	_uart_tail,#0x00
	mov	_uart_tail,a
;	src/main.c:106: smbWrite(SMB_TARGET_DRV, 0x01, 0x07); // Out of standby and auto cal mode
	mov	_smbWrite_PARM_2,#0x01
	mov	_smbWrite_PARM_3,#0x07
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:107: smbWrite(SMB_TARGET_DRV, 0x1A, 0x38); // ERM Mode, FB_BRAKE_FATOR == 4x, LOOP_GAIN == Medium 
	mov	_smbWrite_PARM_2,#0x1a
	mov	_smbWrite_PARM_3,#0x38
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:108: smbWrite(SMB_TARGET_DRV, 0x16, 0x7F); // RATED_VOLTAGE == 0x7F 
	mov	_smbWrite_PARM_2,#0x16
	mov	_smbWrite_PARM_3,#0x7f
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:109: smbWrite(SMB_TARGET_DRV, 0x17, 0x7F); // OD_CLAMP == 0x7F (signed) 
	mov	_smbWrite_PARM_2,#0x17
	mov	_smbWrite_PARM_3,#0x7f
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:110: smbWrite(SMB_TARGET_DRV, 0x1E, 0x20); // AUTO_CAL_TIME == 500ms to 700ms
	mov	_smbWrite_PARM_2,#0x1e
	mov	_smbWrite_PARM_3,#0x20
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:111: smbWrite(SMB_TARGET_DRV, 0x1B, 0x9F); // DRIVE_TIME == 0x1F
	mov	_smbWrite_PARM_2,#0x1b
	mov	_smbWrite_PARM_3,#0x9f
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:112: smbWrite(SMB_TARGET_DRV, 0x0C, 0x01); // Set GO bit to start auto cal
	mov	_smbWrite_PARM_2,#0x0c
	mov	_smbWrite_PARM_3,#0x01
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:113: for(i=0;i<5;i++){
	mov	r7,#0x00
00109$:
;	src/main.c:114: j = smbRead(SMB_TARGET_DRV, 0x00);
	mov	_smbRead_PARM_2,#0x00
	mov	dpl,#0xb4
	push	ar7
	lcall	_smbRead
	mov	r6,dpl
	pop	ar7
	mov	ar5,r6
	mov	r6,#0x00
;	src/main.c:115: while(0 == uartEmpty());
00101$:
	push	ar7
	push	ar6
	push	ar5
	lcall	_uartEmpty
	mov	a,dpl
	pop	ar5
	pop	ar6
	pop	ar7
	jz	00101$
;	src/main.c:116: sendU16(j);
	mov	dpl,r5
	mov	dph,r6
	push	ar7
	lcall	_sendU16
;	src/main.c:117: uartTx('\n');
	mov	dpl,#0x0a
	lcall	_uartTx
	pop	ar7
;	src/main.c:113: for(i=0;i<5;i++){
	inc	r7
	cjne	r7,#0x05,00161$
00161$:
	jc	00109$
;	src/main.c:119: smbWrite(SMB_TARGET_DRV, 0x01, 0x03);   
	mov	_smbWrite_PARM_2,#0x01
	mov	_smbWrite_PARM_3,#0x03
	mov	dpl,#0xb4
	lcall	_smbWrite
;	src/main.c:123: for(j=0;j<10;j++) PWM = 1; 
00125$:
	mov	r6,#0x00
	mov	r7,#0x00
00111$:
;	assignBit
	setb	_PWM
	inc	r6
	cjne	r6,#0x00,00163$
	inc	r7
00163$:
	clr	c
	mov	a,r6
	subb	a,#0x0a
	mov	a,r7
	subb	a,#0x00
	jc	00111$
;	src/main.c:124: for(j=0;j<10;j++) PWM = 0;
	mov	r6,#0x00
	mov	r7,#0x00
00113$:
;	assignBit
	clr	_PWM
	inc	r6
	cjne	r6,#0x00,00165$
	inc	r7
00165$:
	clr	c
	mov	a,r6
	subb	a,#0x0a
	mov	a,r7
	subb	a,#0x00
	jc	00113$
;	src/main.c:147: }
	sjmp	00125$
;------------------------------------------------------------
;Allocation info for local variables in function 'sendU16'
;------------------------------------------------------------
;s                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	src/main.c:154: void sendU16(U16 s){
;	-----------------------------------------
;	 function sendU16
;	-----------------------------------------
_sendU16:
	mov	r6,dpl
;	src/main.c:155: uartTx(nibble2hex(s >> 12));
	mov	a,dph
	mov	r7,a
	swap	a
	anl	a,#0x0f
	mov	dpl,a
	push	ar7
	push	ar6
	lcall	_nibble2hex
	lcall	_uartTx
	pop	ar6
	pop	ar7
;	src/main.c:156: uartTx(nibble2hex(s >> 8));
	mov	dpl,r7
	push	ar7
	push	ar6
	lcall	_nibble2hex
	lcall	_uartTx
	pop	ar6
	pop	ar7
;	src/main.c:157: uartTx(nibble2hex(s >> 4));
	mov	ar4,r6
	mov	a,r7
	swap	a
	xch	a,r4
	swap	a
	anl	a,#0x0f
	xrl	a,r4
	xch	a,r4
	anl	a,#0x0f
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	mov	dpl,r4
	push	ar7
	push	ar6
	lcall	_nibble2hex
	lcall	_uartTx
	pop	ar6
	pop	ar7
;	src/main.c:158: uartTx(nibble2hex(s));
	mov	dpl,r6
	lcall	_nibble2hex
	lcall	_uartTx
;	src/main.c:159: uartTx(',');
	mov	dpl,#0x2c
;	src/main.c:160: }
	ljmp	_uartTx
;------------------------------------------------------------
;Allocation info for local variables in function 'nibble2hex'
;------------------------------------------------------------
;n                         Allocated to registers r7 
;i                         Allocated to registers r6 
;------------------------------------------------------------
;	src/main.c:162: U8 nibble2hex(U8 n){
;	-----------------------------------------
;	 function nibble2hex
;	-----------------------------------------
_nibble2hex:
;	src/main.c:164: i = n & 0xF;
;	src/main.c:165: if(i > 0x9){
	mov	a,dpl
	anl	a,#0x0f
	mov	r7,a
	add	a,#0xff - 0x09
	jnc	00102$
;	src/main.c:166: i += ('A' - 0xA);
	mov	ar6,r7
	mov	a,#0x37
	add	a,r6
	mov	r6,a
	sjmp	00103$
00102$:
;	src/main.c:168: i += '0';
	mov	a,#0x30
	add	a,r7
	mov	r6,a
00103$:
;	src/main.c:170: return i;
	mov	dpl,r6
;	src/main.c:171: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART0_ISR'
;------------------------------------------------------------
;	src/main.c:177: INTERRUPT (UART0_ISR, UART0_IRQn){     // Service both Rx & Tx flags 
;	-----------------------------------------
;	 function UART0_ISR
;	-----------------------------------------
_UART0_ISR:
	push	ar7
	push	ar6
	push	psw
	mov	psw,#0x00
;	src/main.c:178: if(SCON0_RI){
	jnb	_SCON0_RI,00102$
;	src/main.c:179: p = SBUF0;   
	mov	_p,_SBUF0
	mov	(_p + 1),#0x00
00102$:
;	src/main.c:181: SCON0_RI = 0;
;	assignBit
	clr	_SCON0_RI
;	src/main.c:182: SCON0_TI = 0;
;	assignBit
	clr	_SCON0_TI
;	src/main.c:183: IE |= IE_ES0__ENABLED; 
	mov	r6,_IE
	orl	ar6,#0x10
	mov	_IE,r6
;	src/main.c:184: } 
	pop	psw
	pop	ar6
	pop	ar7
	reti
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;	eliminated unneeded push/pop acc
;------------------------------------------------------------
;Allocation info for local variables in function 'TIMER2_ISR'
;------------------------------------------------------------
;	src/main.c:186: INTERRUPT (TIMER2_ISR, TIMER2_IRQn){            
;	-----------------------------------------
;	 function TIMER2_ISR
;	-----------------------------------------
_TIMER2_ISR:
	push	acc
	push	ar7
	push	ar6
	push	psw
	mov	psw,#0x00
;	src/main.c:187: go = 1;
;	src/main.c:188: sample++;   
	mov	a,#0x01
	mov	_go,a
	add	a,_sample
	mov	_sample,a
	clr	a
	addc	a,(_sample + 1)
	mov	(_sample + 1),a
;	src/main.c:190: TMR2CN &= ~TMR2CN_TF2H__SET;
	anl	_TMR2CN,#0x7f
;	src/main.c:191: IE |= IE_ET2__ENABLED; 
	mov	r6,_IE
	orl	ar6,#0x20
	mov	_IE,r6
;	src/main.c:193: } 
	pop	psw
	pop	ar6
	pop	ar7
	pop	acc
	reti
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function 'TIMER3_ISR'
;------------------------------------------------------------
;	src/main.c:195: INTERRUPT (TIMER3_ISR, TIMER3_IRQn){            
;	-----------------------------------------
;	 function TIMER3_ISR
;	-----------------------------------------
_TIMER3_ISR:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x00
;	src/main.c:197: if(uart_head != uart_tail){ 
	mov	a,_uart_tail
	cjne	a,_uart_head,00109$
	sjmp	00102$
00109$:
;	src/main.c:198: SBUF0 = uart_buf[uart_tail];
	mov	a,_uart_tail
	add	a,#_uart_buf
	mov	r1,a
	mov	_SBUF0,@r1
;	src/main.c:199: uart_tail++;
	inc	_uart_tail
;	src/main.c:200: uart_tail %= UART_BUF_SIZE;
	mov	r6,_uart_tail
	mov	r7,#0x00
	mov	__modsint_PARM_2,#0x32
;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
	mov	(__modsint_PARM_2 + 1),r7
	mov	dpl,r6
	mov	dph,r7
	lcall	__modsint
	mov	r6,dpl
	mov	r7,dph
	mov	_uart_tail,r6
00102$:
;	src/main.c:204: TMR3CN &= ~TMR3CN_TF3H__SET;
	anl	_TMR3CN,#0x7f
;	src/main.c:205: EIE1 |= EIE1_ET3__ENABLED;
	mov	r6,_EIE1
	orl	ar6,#0x80
	mov	_EIE1,r6
;	src/main.c:206: } 
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'SMBUS0_ISR'
;------------------------------------------------------------
;	src/main.c:212: INTERRUPT(SMBUS0_ISR, SMBUS0_IRQn){ 
;	-----------------------------------------
;	 function SMBUS0_ISR
;	-----------------------------------------
_SMBUS0_ISR:
	push	acc
	push	b
	push	dpl
	push	dph
	push	ar7
	push	ar6
	push	psw
	mov	psw,#0x00
;	src/main.c:213: switch (SMB0CN & 0xF0) {
	mov	r6,_SMB0CN
	anl	ar6,#0xf0
	mov	r7,#0x00
	cjne	r6,#0x80,00170$
	cjne	r7,#0x00,00170$
	sjmp	00112$
00170$:
	cjne	r6,#0xc0,00171$
	cjne	r7,#0x00,00171$
	sjmp	00102$
00171$:
	cjne	r6,#0xe0,00172$
	cjne	r7,#0x00,00172$
	sjmp	00173$
00172$:
	ljmp	00131$
00173$:
;	src/main.c:215: case SMB_MTSTA:   SMB0DAT = smb_target;               // Load address of the target slave (only one)
	mov	_SMB0DAT,_smb_target
;	src/main.c:216: SMB0DAT &= 0xFE;                    // Clear the LSB of the address for the 
	anl	_SMB0DAT,#0xfe
;	src/main.c:217: SMB0DAT |= smb_rnw;                 // Load R/W bit
	mov	a,_smb_rnw
	orl	_SMB0DAT,a
;	src/main.c:218: SMB0CN_STA = 0;                     // Manually clear START bit 
;	assignBit
	clr	_SMB0CN_STA
;	src/main.c:219: break;
	ljmp	00131$
;	src/main.c:221: case SMB_MTDB:    if(SMB0CN_ACK) {
00102$:
	jnb	_SMB0CN_ACK,00110$
;	src/main.c:222: switch(mpu_state){ 
	mov	r7,_mpu_state
	cjne	r7,#0x00,00175$
	sjmp	00106$
00175$:
	cjne	r7,#0x01,00176$
	sjmp	00105$
00176$:
	cjne	r7,#0x02,00177$
	sjmp	00104$
00177$:
	cjne	r7,#0x04,00178$
	sjmp	00179$
00178$:
	ljmp	00131$
00179$:
;	src/main.c:223: case SMB_STATE_RD1:        mpu_state = SMB_STATE_RD_STOP;
	mov	_mpu_state,#0x03
;	src/main.c:224: break;
	ljmp	00131$
;	src/main.c:225: case SMB_STATE_WR2:        SMB0DAT = smb_data_out[1]; 
00104$:
	mov	_SMB0DAT,(_smb_data_out + 0x0001)
;	src/main.c:226: mpu_state = SMB_STATE_WR1;
	mov	_mpu_state,#0x01
;	src/main.c:227: break;
	ljmp	00131$
;	src/main.c:228: case SMB_STATE_WR1:        SMB0DAT = smb_data_out[0]; 
00105$:
	mov	_SMB0DAT,_smb_data_out
;	src/main.c:229: mpu_state = SMB_STATE_WR_STOP;
	mov	_mpu_state,#0x00
;	src/main.c:230: break;
	ljmp	00131$
;	src/main.c:231: case SMB_STATE_WR_STOP:    SMB0CN_STO = 1;   
00106$:
;	assignBit
	setb	_SMB0CN_STO
;	src/main.c:232: smb_busy = 0;     
	mov	_smb_busy,#0x00
;	src/main.c:234: }
	ljmp	00131$
00110$:
;	src/main.c:238: SMB0CN_STO = 1;               // Send STOP condition,followed
;	assignBit
	setb	_SMB0CN_STO
;	src/main.c:239: SMB0CN_STA = 1;               // By a START 
;	assignBit
	setb	_SMB0CN_STA
;	src/main.c:241: break;
	ljmp	00131$
;	src/main.c:243: case SMB_MRDB:    switch(mpu_state){
00112$:
	mov	a,_mpu_state
	mov	r7,a
	add	a,#0xff - 0x1d
	jnc	00180$
	ljmp	00131$
00180$:
	mov	a,r7
	mov	b,a
	add	a,#(00181$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,b
	add	a,#(00182$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00181$:
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00127$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00131$
	.db	00126$
	.db	00125$
	.db	00124$
	.db	00123$
	.db	00122$
	.db	00121$
	.db	00120$
	.db	00119$
	.db	00118$
	.db	00117$
	.db	00116$
	.db	00115$
	.db	00114$
	.db	00113$
00182$:
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00127$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00131$>>8
	.db	00126$>>8
	.db	00125$>>8
	.db	00124$>>8
	.db	00123$>>8
	.db	00122$>>8
	.db	00121$>>8
	.db	00120$>>8
	.db	00119$>>8
	.db	00118$>>8
	.db	00117$>>8
	.db	00116$>>8
	.db	00115$>>8
	.db	00114$>>8
	.db	00113$>>8
;	src/main.c:244: case SMB_STATE_MPU13:   accel_x = SMB0DAT;
00113$:
	mov	_accel_x,_SMB0DAT
	mov	(_accel_x + 1),#0x00
;	src/main.c:245: mpu_state = SMB_STATE_MPU12;
	mov	_mpu_state,#0x1c
;	src/main.c:246: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:247: break;
	ljmp	00131$
;	src/main.c:248: case SMB_STATE_MPU12:   accel_x <<= 8;
00114$:
	mov	(_accel_x + 1),_accel_x
	mov	_accel_x,#0x00
;	src/main.c:249: accel_x |= SMB0DAT;
	mov	r6,_SMB0DAT
	mov	r7,#0x00
	mov	a,r6
	orl	_accel_x,a
	mov	a,r7
	orl	(_accel_x + 1),a
;	src/main.c:250: mpu_state = SMB_STATE_MPU11;
	mov	_mpu_state,#0x1b
;	src/main.c:251: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:252: break;
	ljmp	00131$
;	src/main.c:253: case SMB_STATE_MPU11:   accel_y = SMB0DAT;
00115$:
	mov	_accel_y,_SMB0DAT
	mov	(_accel_y + 1),#0x00
;	src/main.c:254: mpu_state = SMB_STATE_MPU10;
	mov	_mpu_state,#0x1a
;	src/main.c:255: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:256: break;
	ljmp	00131$
;	src/main.c:257: case SMB_STATE_MPU10:   accel_y <<= 8;
00116$:
	mov	(_accel_y + 1),_accel_y
	mov	_accel_y,#0x00
;	src/main.c:258: accel_y |= SMB0DAT;
	mov	r6,_SMB0DAT
	mov	r7,#0x00
	mov	a,r6
	orl	_accel_y,a
	mov	a,r7
	orl	(_accel_y + 1),a
;	src/main.c:259: mpu_state = SMB_STATE_MPU09;
	mov	_mpu_state,#0x19
;	src/main.c:260: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:261: break;
	ljmp	00131$
;	src/main.c:262: case SMB_STATE_MPU09:   accel_z = SMB0DAT;
00117$:
	mov	_accel_z,_SMB0DAT
	mov	(_accel_z + 1),#0x00
;	src/main.c:263: mpu_state = SMB_STATE_MPU08;
	mov	_mpu_state,#0x18
;	src/main.c:264: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:265: break;
	ljmp	00131$
;	src/main.c:266: case SMB_STATE_MPU08:   accel_z <<= 8;
00118$:
	mov	(_accel_z + 1),_accel_z
	mov	_accel_z,#0x00
;	src/main.c:267: accel_z |= SMB0DAT;
	mov	r6,_SMB0DAT
	mov	r7,#0x00
	mov	a,r6
	orl	_accel_z,a
	mov	a,r7
	orl	(_accel_z + 1),a
;	src/main.c:268: mpu_state = SMB_STATE_MPU07;
	mov	_mpu_state,#0x17
;	src/main.c:269: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:270: break;
	ljmp	00131$
;	src/main.c:271: case SMB_STATE_MPU07:   mpu_state = SMB_STATE_MPU06;  // Throw away temp lower data
00119$:
	mov	_mpu_state,#0x16
;	src/main.c:272: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:273: break;
	ljmp	00131$
;	src/main.c:274: case SMB_STATE_MPU06:   mpu_state = SMB_STATE_MPU05;  // Throw awat temp higher data
00120$:
	mov	_mpu_state,#0x15
;	src/main.c:275: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:276: break;
	ljmp	00131$
;	src/main.c:277: case SMB_STATE_MPU05:   gyro_x = SMB0DAT;
00121$:
	mov	_gyro_x,_SMB0DAT
	mov	(_gyro_x + 1),#0x00
;	src/main.c:278: mpu_state = SMB_STATE_MPU04;
	mov	_mpu_state,#0x14
;	src/main.c:279: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:280: break;
;	src/main.c:281: case SMB_STATE_MPU04:   gyro_x <<= 8;
	sjmp	00131$
00122$:
	mov	(_gyro_x + 1),_gyro_x
	mov	_gyro_x,#0x00
;	src/main.c:282: gyro_x |= SMB0DAT;
	mov	r6,_SMB0DAT
	mov	r7,#0x00
	mov	a,r6
	orl	_gyro_x,a
	mov	a,r7
	orl	(_gyro_x + 1),a
;	src/main.c:283: mpu_state = SMB_STATE_MPU03;
	mov	_mpu_state,#0x13
;	src/main.c:284: SMB0CN_ACK = 1;         
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:285: break;
;	src/main.c:286: case SMB_STATE_MPU03:   gyro_y = SMB0DAT;
	sjmp	00131$
00123$:
	mov	_gyro_y,_SMB0DAT
	mov	(_gyro_y + 1),#0x00
;	src/main.c:287: mpu_state = SMB_STATE_MPU02;
	mov	_mpu_state,#0x12
;	src/main.c:288: SMB0CN_ACK = 1;               
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:289: break;
;	src/main.c:290: case SMB_STATE_MPU02:   gyro_y <<= 8;
	sjmp	00131$
00124$:
	mov	(_gyro_y + 1),_gyro_y
	mov	_gyro_y,#0x00
;	src/main.c:291: gyro_y |= SMB0DAT;
	mov	r6,_SMB0DAT
	mov	r7,#0x00
	mov	a,r6
	orl	_gyro_y,a
	mov	a,r7
	orl	(_gyro_y + 1),a
;	src/main.c:292: mpu_state = SMB_STATE_MPU01;
	mov	_mpu_state,#0x11
;	src/main.c:293: SMB0CN_ACK = 1;               
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:294: break;
;	src/main.c:295: case SMB_STATE_MPU01:   gyro_z = SMB0DAT;
	sjmp	00131$
00125$:
	mov	_gyro_z,_SMB0DAT
	mov	(_gyro_z + 1),#0x00
;	src/main.c:296: mpu_state = SMB_STATE_MPU00;
	mov	_mpu_state,#0x10
;	src/main.c:297: SMB0CN_ACK = 1;                 
;	assignBit
	setb	_SMB0CN_ACK
;	src/main.c:298: break;
;	src/main.c:299: case SMB_STATE_MPU00:   gyro_z <<= 8;
	sjmp	00131$
00126$:
	mov	(_gyro_z + 1),_gyro_z
	mov	_gyro_z,#0x00
;	src/main.c:300: gyro_z |= SMB0DAT;
	mov	r6,_SMB0DAT
	mov	r7,#0x00
	mov	a,r6
	orl	_gyro_z,a
	mov	a,r7
	orl	(_gyro_z + 1),a
;	src/main.c:301: smb_busy = 0;                    
	mov	_smb_busy,#0x00
;	src/main.c:302: SMB0CN_ACK = 0;                  
;	assignBit
	clr	_SMB0CN_ACK
;	src/main.c:303: SMB0CN_STO = 1;                  
;	assignBit
	setb	_SMB0CN_STO
;	src/main.c:304: break;
;	src/main.c:305: case SMB_STATE_RD_STOP: smb_data_in = SMB0DAT;
	sjmp	00131$
00127$:
	mov	_smb_data_in,_SMB0DAT
;	src/main.c:306: SMB0CN_ACK = 0;                  
;	assignBit
	clr	_SMB0CN_ACK
;	src/main.c:307: SMB0CN_STO = 1;                  
;	assignBit
	setb	_SMB0CN_STO
;	src/main.c:308: smb_busy = 0;
	mov	_smb_busy,#0x00
;	src/main.c:315: }  
00131$:
;	src/main.c:316: SMB0CN_SI = 0; //Clear interrupt flag 
;	assignBit
	clr	_SMB0CN_SI
;	src/main.c:317: }
	pop	psw
	pop	ar6
	pop	ar7
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	reti
;	eliminated unneeded push/pop ar1
;	eliminated unneeded push/pop ar0
;------------------------------------------------------------
;Allocation info for local variables in function 'smbReadMpuSensors'
;------------------------------------------------------------
;	src/main.c:319: void smbReadMpuSensors (void) {
;	-----------------------------------------
;	 function smbReadMpuSensors
;	-----------------------------------------
_smbReadMpuSensors:
;	src/main.c:320: while (smb_busy);             // Wait for bus to be free.
00101$:
	mov	a,_smb_busy
	jnz	00101$
;	src/main.c:321: smb_target = SMB_TARGET_IMU;
	mov	_smb_target,#0xd0
;	src/main.c:322: mpu_state = SMB_STATE_WR1;
	mov	_mpu_state,#0x01
;	src/main.c:323: smb_data_out[0] = 0x3B;
	mov	_smb_data_out,#0x3b
;	src/main.c:324: smb_busy = 1;                 // Claim SMBus (set to busy)  
	mov	_smb_busy,#0x01
;	src/main.c:325: smb_rnw = 0;                  // Mark this transfer as a WRITE
	mov	_smb_rnw,#0x00
;	src/main.c:326: SMB0CN_STA = 1;               // Start transfer 
;	assignBit
	setb	_SMB0CN_STA
;	src/main.c:327: while (smb_busy);             // Wait for bus to be free.
00104$:
	mov	a,_smb_busy
	jnz	00104$
;	src/main.c:328: mpu_state = SMB_STATE_MPU13; 
	mov	_mpu_state,#0x1d
;	src/main.c:329: smb_busy = 1;                 // Claim SMBus (set to busy)  
	mov	_smb_busy,#0x01
;	src/main.c:330: smb_rnw = 1;                  // Mark this transfer as a WRITE
	mov	_smb_rnw,#0x01
;	src/main.c:331: SMB0CN_STA = 1;               // Start transfer  
;	assignBit
	setb	_SMB0CN_STA
;	src/main.c:332: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'smbRead'
;------------------------------------------------------------
;addr                      Allocated with name '_smbRead_PARM_2'
;target                    Allocated to registers r7 
;------------------------------------------------------------
;	src/main.c:334: U8 smbRead (U8 target, U8 addr){
;	-----------------------------------------
;	 function smbRead
;	-----------------------------------------
_smbRead:
	mov	r7,dpl
;	src/main.c:335: while (smb_busy);          // Wait for bus to be free.
00101$:
	mov	a,_smb_busy
	jnz	00101$
;	src/main.c:336: smb_target = target;
	mov	_smb_target,r7
;	src/main.c:337: mpu_state = SMB_STATE_WR1;
	mov	_mpu_state,#0x01
;	src/main.c:338: smb_data_out[0] = addr;
	mov	_smb_data_out,_smbRead_PARM_2
;	src/main.c:339: smb_busy = 1;              // Claim SMBus (set to busy)  
	mov	_smb_busy,#0x01
;	src/main.c:340: smb_rnw = 0;               // Mark this transfer as a WRITE
	mov	_smb_rnw,#0x00
;	src/main.c:341: SMB0CN_STA = 1;            // Start transfer 
;	assignBit
	setb	_SMB0CN_STA
;	src/main.c:342: while (smb_busy);          // Wait for bus to be free.
00104$:
	mov	a,_smb_busy
	jnz	00104$
;	src/main.c:343: mpu_state = SMB_STATE_RD1; 
	mov	_mpu_state,#0x04
;	src/main.c:344: smb_busy = 1;              // Claim SMBus (set to busy)  
	mov	_smb_busy,#0x01
;	src/main.c:345: smb_rnw = 1;               // Mark this transfer as a WRITE
	mov	_smb_rnw,#0x01
;	src/main.c:346: SMB0CN_STA = 1;            // Start transfer 
;	assignBit
	setb	_SMB0CN_STA
;	src/main.c:347: while (smb_busy);
00107$:
	mov	a,_smb_busy
	jnz	00107$
;	src/main.c:348: return smb_data_in;
	mov	dpl,_smb_data_in
;	src/main.c:349: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'smbWrite'
;------------------------------------------------------------
;addr                      Allocated with name '_smbWrite_PARM_2'
;data                      Allocated with name '_smbWrite_PARM_3'
;target                    Allocated to registers r7 
;------------------------------------------------------------
;	src/main.c:351: void smbWrite (U8 target, U8 addr, U8 data){
;	-----------------------------------------
;	 function smbWrite
;	-----------------------------------------
_smbWrite:
	mov	r7,dpl
;	src/main.c:352: while(smb_busy);
00101$:
	mov	a,_smb_busy
	jnz	00101$
;	src/main.c:353: smb_target = target;
	mov	_smb_target,r7
;	src/main.c:354: mpu_state = SMB_STATE_WR2;
	mov	_mpu_state,#0x02
;	src/main.c:355: smb_data_out[1] = addr;
	mov	(_smb_data_out + 0x0001),_smbWrite_PARM_2
;	src/main.c:356: smb_data_out[0] = data;
	mov	_smb_data_out,_smbWrite_PARM_3
;	src/main.c:357: smb_busy = 1;              // Claim SMBus (set to busy)  
	mov	_smb_busy,#0x01
;	src/main.c:358: smb_rnw = 0;               // Mark this transfer as a WRITE
	mov	_smb_rnw,#0x00
;	src/main.c:359: SMB0CN_STA = 1;            // Start transfer 
;	assignBit
	setb	_SMB0CN_STA
;	src/main.c:360: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartTx'
;------------------------------------------------------------
;tx                        Allocated to registers r7 
;------------------------------------------------------------
;	src/main.c:366: void uartTx(U8 tx){ 
;	-----------------------------------------
;	 function uartTx
;	-----------------------------------------
_uartTx:
	mov	r7,dpl
;	src/main.c:367: uart_buf[uart_head] = tx;
	mov	a,_uart_head
	add	a,#_uart_buf
	mov	r0,a
	mov	@r0,ar7
;	src/main.c:368: uart_head++;
	inc	_uart_head
;	src/main.c:369: uart_head %= UART_BUF_SIZE;
	mov	r6,_uart_head
	mov	r7,#0x00
	mov	__modsint_PARM_2,#0x32
;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
	mov	(__modsint_PARM_2 + 1),r7
	mov	dpl,r6
	mov	dph,r7
	lcall	__modsint
	mov	r6,dpl
	mov	_uart_head,r6
;	src/main.c:370: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartEmpty'
;------------------------------------------------------------
;	src/main.c:372: U8 uartEmpty(void){ 
;	-----------------------------------------
;	 function uartEmpty
;	-----------------------------------------
_uartEmpty:
;	src/main.c:373: if(uart_head == uart_tail){
	mov	a,_uart_tail
	cjne	a,_uart_head,00102$
;	src/main.c:374: return 1;
	mov	dpl,#0x01
	ret
00102$:
;	src/main.c:376: return 0;
	mov	dpl,#0x00
;	src/main.c:378: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'setup'
;------------------------------------------------------------
;	src/main.c:384: void setup(void){
;	-----------------------------------------
;	 function setup
;	-----------------------------------------
_setup:
;	src/main.c:387: WDTCN    = 0xDE;
	mov	_WDTCN,#0xde
;	src/main.c:388: WDTCN    = 0xAD;
	mov	_WDTCN,#0xad
;	src/main.c:391: CLKSEL_CLKDIV__SYSCLK_DIV_1; 
	mov	_CLKSEL,#0x00
;	src/main.c:399: P0SKIP_B7__SKIPPED;
	mov	_P0SKIP,#0xcf
;	src/main.c:408: P1MDOUT_B7__OPEN_DRAIN;
	mov	_P1MDOUT,#0x10
;	src/main.c:415: P1SKIP_B5__SKIPPED;
	mov	_P1SKIP,#0x3f
;	src/main.c:418: XBR0_URT0E__ENABLED; 
	mov	_XBR0,#0x05
;	src/main.c:420: XBR2_XBARE__ENABLED;
	mov	_XBR2,#0xc0
;	src/main.c:423: SCON0    = SCON0_REN__RECEIVE_ENABLED;
	mov	_SCON0,#0x10
;	src/main.c:428: CKCON_T2MH__EXTERNAL_CLOCK;
	mov	_CKCON,#0x08
;	src/main.c:430: TMR2CN   = TMR2CN_T2XCLK__SYSCLK_DIV_12;
	mov	_TMR2CN,#0x00
;	src/main.c:435: TMOD_T1M__MODE2;
	mov	_TMOD,#0x22
;	src/main.c:437: TCON_TR1__RUN; 
	mov	_TCON,#0x50
;	src/main.c:438: TH0      = 0xF5;  // 60KHz 
	mov	_TH0,#0xf5
;	src/main.c:439: TL0      = 0x80;
	mov	_TL0,#0x80
;	src/main.c:440: TH1      = 0x96;  // Magic values from datasheet for 115200
	mov	_TH1,#0x96
;	src/main.c:441: TL1      = 0x96; 
	mov	_TL1,#0x96
;	src/main.c:444: TMR2CN   = TMR2CN_TR2__RUN; 
	mov	_TMR2CN,#0x04
;	src/main.c:445: TMR2L    = 0x00;
	mov	_TMR2L,#0x00
;	src/main.c:446: TMR2H    = 0xD8;
	mov	_TMR2H,#0xd8
;	src/main.c:447: TMR2RLL  = 0x00;
	mov	_TMR2RLL,#0x00
;	src/main.c:448: TMR2RLH  = 0xD8;  // 200Hz/5ms 
	mov	_TMR2RLH,#0xd8
;	src/main.c:451: TMR3CN   = TMR3CN_TR3__RUN; 
	mov	_TMR3CN,#0x04
;	src/main.c:452: TMR3L    = 0x00;
	mov	_TMR3L,#0x00
;	src/main.c:453: TMR3H    = 0xFC;
	mov	_TMR3H,#0xfc
;	src/main.c:454: TMR3RLL  = 0x00;
	mov	_TMR3RLL,#0x00
;	src/main.c:455: TMR3RLH  = 0xFC;  // 2KHz/0.5ms       
	mov	_TMR3RLH,#0xfc
;	src/main.c:461: SMB0CF_ENSMB__ENABLED; 
	mov	_SMB0CF,#0xc4
;	src/main.c:463: SMB0TC   = SMB0TC_SDD__ADD_8_SYSCLKS;
	mov	_SMB0TC,#0x03
;	src/main.c:468: IE_ET2__ENABLED;
	mov	_IE,#0xb0
;	src/main.c:470: EIE1_ET3__ENABLED;
	mov	_EIE1,#0x81
;	src/main.c:471: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
