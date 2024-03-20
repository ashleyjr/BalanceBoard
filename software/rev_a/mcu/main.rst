                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _smbWrite_PARM_3
                                     12 	.globl _smbWrite_PARM_2
                                     13 	.globl _smbRead_PARM_2
                                     14 	.globl _SMBUS0_ISR
                                     15 	.globl _TIMER3_ISR
                                     16 	.globl _TIMER2_ISR
                                     17 	.globl _UART0_ISR
                                     18 	.globl _main
                                     19 	.globl _PWM
                                     20 	.globl _TMR2CN_TF2H
                                     21 	.globl _TMR2CN_TF2L
                                     22 	.globl _TMR2CN_TF2LEN
                                     23 	.globl _TMR2CN_TF2CEN
                                     24 	.globl _TMR2CN_T2SPLIT
                                     25 	.globl _TMR2CN_TR2
                                     26 	.globl _TMR2CN_T2XCLK
                                     27 	.globl _TCON_TF1
                                     28 	.globl _TCON_TR1
                                     29 	.globl _TCON_TF0
                                     30 	.globl _TCON_TR0
                                     31 	.globl _TCON_IE1
                                     32 	.globl _TCON_IT1
                                     33 	.globl _TCON_IE0
                                     34 	.globl _TCON_IT0
                                     35 	.globl _SPI0CN_SPIF
                                     36 	.globl _SPI0CN_WCOL
                                     37 	.globl _SPI0CN_MODF
                                     38 	.globl _SPI0CN_RXOVRN
                                     39 	.globl _SPI0CN_NSSMD1
                                     40 	.globl _SPI0CN_NSSMD0
                                     41 	.globl _SPI0CN_TXBMT
                                     42 	.globl _SPI0CN_SPIEN
                                     43 	.globl _SMB0CN_MASTER
                                     44 	.globl _SMB0CN_TXMODE
                                     45 	.globl _SMB0CN_STA
                                     46 	.globl _SMB0CN_STO
                                     47 	.globl _SMB0CN_ACKRQ
                                     48 	.globl _SMB0CN_ARBLOST
                                     49 	.globl _SMB0CN_ACK
                                     50 	.globl _SMB0CN_SI
                                     51 	.globl _SCON0_SMODE
                                     52 	.globl _SCON0_MCE
                                     53 	.globl _SCON0_REN
                                     54 	.globl _SCON0_TB8
                                     55 	.globl _SCON0_RB8
                                     56 	.globl _SCON0_TI
                                     57 	.globl _SCON0_RI
                                     58 	.globl _PSW_CY
                                     59 	.globl _PSW_AC
                                     60 	.globl _PSW_F0
                                     61 	.globl _PSW_RS1
                                     62 	.globl _PSW_RS0
                                     63 	.globl _PSW_OV
                                     64 	.globl _PSW_F1
                                     65 	.globl _PSW_PARITY
                                     66 	.globl _PCA0CN_CF
                                     67 	.globl _PCA0CN_CR
                                     68 	.globl _PCA0CN_CCF2
                                     69 	.globl _PCA0CN_CCF1
                                     70 	.globl _PCA0CN_CCF0
                                     71 	.globl _P2_B1
                                     72 	.globl _P2_B0
                                     73 	.globl _P1_B7
                                     74 	.globl _P1_B6
                                     75 	.globl _P1_B5
                                     76 	.globl _P1_B4
                                     77 	.globl _P1_B3
                                     78 	.globl _P1_B2
                                     79 	.globl _P1_B1
                                     80 	.globl _P1_B0
                                     81 	.globl _P0_B7
                                     82 	.globl _P0_B6
                                     83 	.globl _P0_B5
                                     84 	.globl _P0_B4
                                     85 	.globl _P0_B3
                                     86 	.globl _P0_B2
                                     87 	.globl _P0_B1
                                     88 	.globl _P0_B0
                                     89 	.globl _IP_PSPI0
                                     90 	.globl _IP_PT2
                                     91 	.globl _IP_PS0
                                     92 	.globl _IP_PT1
                                     93 	.globl _IP_PX1
                                     94 	.globl _IP_PT0
                                     95 	.globl _IP_PX0
                                     96 	.globl _IE_EA
                                     97 	.globl _IE_ESPI0
                                     98 	.globl _IE_ET2
                                     99 	.globl _IE_ES0
                                    100 	.globl _IE_ET1
                                    101 	.globl _IE_EX1
                                    102 	.globl _IE_ET0
                                    103 	.globl _IE_EX0
                                    104 	.globl _B_B7
                                    105 	.globl _B_B6
                                    106 	.globl _B_B5
                                    107 	.globl _B_B4
                                    108 	.globl _B_B3
                                    109 	.globl _B_B2
                                    110 	.globl _B_B1
                                    111 	.globl _B_B0
                                    112 	.globl _ADC0CN0_ADEN
                                    113 	.globl _ADC0CN0_ADBMEN
                                    114 	.globl _ADC0CN0_ADINT
                                    115 	.globl _ADC0CN0_ADBUSY
                                    116 	.globl _ADC0CN0_ADWINT
                                    117 	.globl _ADC0CN0_ADCM2
                                    118 	.globl _ADC0CN0_ADCM1
                                    119 	.globl _ADC0CN0_ADCM0
                                    120 	.globl _ACC_ACC7
                                    121 	.globl _ACC_ACC6
                                    122 	.globl _ACC_ACC5
                                    123 	.globl _ACC_ACC4
                                    124 	.globl _ACC_ACC3
                                    125 	.globl _ACC_ACC2
                                    126 	.globl _ACC_ACC1
                                    127 	.globl _ACC_ACC0
                                    128 	.globl __XPAGE
                                    129 	.globl _TMR3RL
                                    130 	.globl _TMR3
                                    131 	.globl _TMR2RL
                                    132 	.globl _TMR2
                                    133 	.globl _PCA0
                                    134 	.globl _PCA0CP2
                                    135 	.globl _PCA0CP1
                                    136 	.globl _PCA0CP0
                                    137 	.globl _DP
                                    138 	.globl _ADC0LT
                                    139 	.globl _ADC0
                                    140 	.globl _ADC0GT
                                    141 	.globl _XBR2
                                    142 	.globl _XBR1
                                    143 	.globl _XBR0
                                    144 	.globl _WDTCN
                                    145 	.globl _VDM0CN
                                    146 	.globl _TMR3RLL
                                    147 	.globl _TMR3RLH
                                    148 	.globl _TMR3L
                                    149 	.globl _TMR3H
                                    150 	.globl _TMR3CN
                                    151 	.globl _TMR2RLL
                                    152 	.globl _TMR2RLH
                                    153 	.globl _TMR2L
                                    154 	.globl _TMR2H
                                    155 	.globl _TMR2CN
                                    156 	.globl _TMOD
                                    157 	.globl _TL1
                                    158 	.globl _TL0
                                    159 	.globl _TH1
                                    160 	.globl _TH0
                                    161 	.globl _TCON
                                    162 	.globl _SPI0DAT
                                    163 	.globl _SPI0CN
                                    164 	.globl _SPI0CKR
                                    165 	.globl _SPI0CFG
                                    166 	.globl _SP
                                    167 	.globl _SMB0TC
                                    168 	.globl _SMB0DAT
                                    169 	.globl _SMB0CN
                                    170 	.globl _SMB0CF
                                    171 	.globl _SMB0ADR
                                    172 	.globl _SMB0ADM
                                    173 	.globl _SCON0
                                    174 	.globl _SBUF0
                                    175 	.globl _RSTSRC
                                    176 	.globl _REVID
                                    177 	.globl _REG0CN
                                    178 	.globl _REF0CN
                                    179 	.globl _PSW
                                    180 	.globl _PSCTL
                                    181 	.globl _PRTDRV
                                    182 	.globl _PCON
                                    183 	.globl _PCA0PWM
                                    184 	.globl _PCA0POL
                                    185 	.globl _PCA0MD
                                    186 	.globl _PCA0L
                                    187 	.globl _PCA0H
                                    188 	.globl _PCA0CPM2
                                    189 	.globl _PCA0CPM1
                                    190 	.globl _PCA0CPM0
                                    191 	.globl _PCA0CPL2
                                    192 	.globl _PCA0CPL1
                                    193 	.globl _PCA0CPL0
                                    194 	.globl _PCA0CPH2
                                    195 	.globl _PCA0CPH1
                                    196 	.globl _PCA0CPH0
                                    197 	.globl _PCA0CN
                                    198 	.globl _PCA0CLR
                                    199 	.globl _PCA0CENT
                                    200 	.globl _P2MDOUT
                                    201 	.globl _P2
                                    202 	.globl _P1SKIP
                                    203 	.globl _P1MDOUT
                                    204 	.globl _P1MDIN
                                    205 	.globl _P1MAT
                                    206 	.globl _P1MASK
                                    207 	.globl _P1
                                    208 	.globl _P0SKIP
                                    209 	.globl _P0MDOUT
                                    210 	.globl _P0MDIN
                                    211 	.globl _P0MAT
                                    212 	.globl _P0MASK
                                    213 	.globl _P0
                                    214 	.globl _OSCLCN
                                    215 	.globl _OSCICL
                                    216 	.globl _IT01CF
                                    217 	.globl _IP
                                    218 	.globl _IE
                                    219 	.globl _FLKEY
                                    220 	.globl _EIP1
                                    221 	.globl _EIE1
                                    222 	.globl _DPL
                                    223 	.globl _DPH
                                    224 	.globl _DEVICEID
                                    225 	.globl _DERIVID
                                    226 	.globl _CRC0IN
                                    227 	.globl _CRC0FLIP
                                    228 	.globl _CRC0DAT
                                    229 	.globl _CRC0CNT
                                    230 	.globl _CRC0CN
                                    231 	.globl _CRC0AUTO
                                    232 	.globl _CPT1MX
                                    233 	.globl _CPT1MD
                                    234 	.globl _CPT1CN
                                    235 	.globl _CPT0MX
                                    236 	.globl _CPT0MD
                                    237 	.globl _CPT0CN
                                    238 	.globl _CLKSEL
                                    239 	.globl _CKCON
                                    240 	.globl _B
                                    241 	.globl _ADC0TK
                                    242 	.globl _ADC0PWR
                                    243 	.globl _ADC0MX
                                    244 	.globl _ADC0LTL
                                    245 	.globl _ADC0LTH
                                    246 	.globl _ADC0L
                                    247 	.globl _ADC0H
                                    248 	.globl _ADC0GTL
                                    249 	.globl _ADC0GTH
                                    250 	.globl _ADC0CN1
                                    251 	.globl _ADC0CN0
                                    252 	.globl _ADC0CF
                                    253 	.globl _ADC0AC
                                    254 	.globl _ACC
                                    255 	.globl _go
                                    256 	.globl _p
                                    257 	.globl _gyro_z
                                    258 	.globl _gyro_y
                                    259 	.globl _gyro_x
                                    260 	.globl _accel_z
                                    261 	.globl _accel_y
                                    262 	.globl _accel_x
                                    263 	.globl _sample
                                    264 	.globl _mpu_state
                                    265 	.globl _smb_ptr
                                    266 	.globl _smb_rnw
                                    267 	.globl _smb_busy
                                    268 	.globl _smb_data_out
                                    269 	.globl _smb_data_in
                                    270 	.globl _smb_target
                                    271 	.globl _uart_tail
                                    272 	.globl _uart_head
                                    273 	.globl _uart_buf
                                    274 	.globl _sendU16
                                    275 	.globl _nibble2hex
                                    276 	.globl _smbReadMpuSensors
                                    277 	.globl _smbRead
                                    278 	.globl _smbWrite
                                    279 	.globl _uartTx
                                    280 	.globl _uartEmpty
                                    281 	.globl _setup
                                    282 ;--------------------------------------------------------
                                    283 ; special function registers
                                    284 ;--------------------------------------------------------
                                    285 	.area RSEG    (ABS,DATA)
      000000                        286 	.org 0x0000
                           0000E0   287 _ACC	=	0x00e0
                           0000B3   288 _ADC0AC	=	0x00b3
                           0000BC   289 _ADC0CF	=	0x00bc
                           0000E8   290 _ADC0CN0	=	0x00e8
                           0000B2   291 _ADC0CN1	=	0x00b2
                           0000C4   292 _ADC0GTH	=	0x00c4
                           0000C3   293 _ADC0GTL	=	0x00c3
                           0000BE   294 _ADC0H	=	0x00be
                           0000BD   295 _ADC0L	=	0x00bd
                           0000C6   296 _ADC0LTH	=	0x00c6
                           0000C5   297 _ADC0LTL	=	0x00c5
                           0000BB   298 _ADC0MX	=	0x00bb
                           0000DF   299 _ADC0PWR	=	0x00df
                           0000B9   300 _ADC0TK	=	0x00b9
                           0000F0   301 _B	=	0x00f0
                           00008E   302 _CKCON	=	0x008e
                           0000A9   303 _CLKSEL	=	0x00a9
                           00009B   304 _CPT0CN	=	0x009b
                           00009D   305 _CPT0MD	=	0x009d
                           00009F   306 _CPT0MX	=	0x009f
                           0000BF   307 _CPT1CN	=	0x00bf
                           0000AB   308 _CPT1MD	=	0x00ab
                           0000AA   309 _CPT1MX	=	0x00aa
                           0000D2   310 _CRC0AUTO	=	0x00d2
                           0000CE   311 _CRC0CN	=	0x00ce
                           0000D3   312 _CRC0CNT	=	0x00d3
                           0000DE   313 _CRC0DAT	=	0x00de
                           0000CF   314 _CRC0FLIP	=	0x00cf
                           0000DD   315 _CRC0IN	=	0x00dd
                           0000AD   316 _DERIVID	=	0x00ad
                           0000B5   317 _DEVICEID	=	0x00b5
                           000083   318 _DPH	=	0x0083
                           000082   319 _DPL	=	0x0082
                           0000E6   320 _EIE1	=	0x00e6
                           0000F3   321 _EIP1	=	0x00f3
                           0000B7   322 _FLKEY	=	0x00b7
                           0000A8   323 _IE	=	0x00a8
                           0000B8   324 _IP	=	0x00b8
                           0000E4   325 _IT01CF	=	0x00e4
                           0000C7   326 _OSCICL	=	0x00c7
                           0000B1   327 _OSCLCN	=	0x00b1
                           000080   328 _P0	=	0x0080
                           0000FE   329 _P0MASK	=	0x00fe
                           0000FD   330 _P0MAT	=	0x00fd
                           0000F1   331 _P0MDIN	=	0x00f1
                           0000A4   332 _P0MDOUT	=	0x00a4
                           0000D4   333 _P0SKIP	=	0x00d4
                           000090   334 _P1	=	0x0090
                           0000EE   335 _P1MASK	=	0x00ee
                           0000ED   336 _P1MAT	=	0x00ed
                           0000F2   337 _P1MDIN	=	0x00f2
                           0000A5   338 _P1MDOUT	=	0x00a5
                           0000D5   339 _P1SKIP	=	0x00d5
                           0000A0   340 _P2	=	0x00a0
                           0000A6   341 _P2MDOUT	=	0x00a6
                           00009E   342 _PCA0CENT	=	0x009e
                           00009C   343 _PCA0CLR	=	0x009c
                           0000D8   344 _PCA0CN	=	0x00d8
                           0000FC   345 _PCA0CPH0	=	0x00fc
                           0000EA   346 _PCA0CPH1	=	0x00ea
                           0000EC   347 _PCA0CPH2	=	0x00ec
                           0000FB   348 _PCA0CPL0	=	0x00fb
                           0000E9   349 _PCA0CPL1	=	0x00e9
                           0000EB   350 _PCA0CPL2	=	0x00eb
                           0000DA   351 _PCA0CPM0	=	0x00da
                           0000DB   352 _PCA0CPM1	=	0x00db
                           0000DC   353 _PCA0CPM2	=	0x00dc
                           0000FA   354 _PCA0H	=	0x00fa
                           0000F9   355 _PCA0L	=	0x00f9
                           0000D9   356 _PCA0MD	=	0x00d9
                           000096   357 _PCA0POL	=	0x0096
                           0000F7   358 _PCA0PWM	=	0x00f7
                           000087   359 _PCON	=	0x0087
                           0000F6   360 _PRTDRV	=	0x00f6
                           00008F   361 _PSCTL	=	0x008f
                           0000D0   362 _PSW	=	0x00d0
                           0000D1   363 _REF0CN	=	0x00d1
                           0000C9   364 _REG0CN	=	0x00c9
                           0000B6   365 _REVID	=	0x00b6
                           0000EF   366 _RSTSRC	=	0x00ef
                           000099   367 _SBUF0	=	0x0099
                           000098   368 _SCON0	=	0x0098
                           0000D6   369 _SMB0ADM	=	0x00d6
                           0000D7   370 _SMB0ADR	=	0x00d7
                           0000C1   371 _SMB0CF	=	0x00c1
                           0000C0   372 _SMB0CN	=	0x00c0
                           0000C2   373 _SMB0DAT	=	0x00c2
                           0000AC   374 _SMB0TC	=	0x00ac
                           000081   375 _SP	=	0x0081
                           0000A1   376 _SPI0CFG	=	0x00a1
                           0000A2   377 _SPI0CKR	=	0x00a2
                           0000F8   378 _SPI0CN	=	0x00f8
                           0000A3   379 _SPI0DAT	=	0x00a3
                           000088   380 _TCON	=	0x0088
                           00008C   381 _TH0	=	0x008c
                           00008D   382 _TH1	=	0x008d
                           00008A   383 _TL0	=	0x008a
                           00008B   384 _TL1	=	0x008b
                           000089   385 _TMOD	=	0x0089
                           0000C8   386 _TMR2CN	=	0x00c8
                           0000CD   387 _TMR2H	=	0x00cd
                           0000CC   388 _TMR2L	=	0x00cc
                           0000CB   389 _TMR2RLH	=	0x00cb
                           0000CA   390 _TMR2RLL	=	0x00ca
                           000091   391 _TMR3CN	=	0x0091
                           000095   392 _TMR3H	=	0x0095
                           000094   393 _TMR3L	=	0x0094
                           000093   394 _TMR3RLH	=	0x0093
                           000092   395 _TMR3RLL	=	0x0092
                           0000FF   396 _VDM0CN	=	0x00ff
                           000097   397 _WDTCN	=	0x0097
                           0000E1   398 _XBR0	=	0x00e1
                           0000E2   399 _XBR1	=	0x00e2
                           0000E3   400 _XBR2	=	0x00e3
                           00C4C3   401 _ADC0GT	=	0xc4c3
                           00BEBD   402 _ADC0	=	0xbebd
                           00C6C5   403 _ADC0LT	=	0xc6c5
                           008382   404 _DP	=	0x8382
                           00FCFB   405 _PCA0CP0	=	0xfcfb
                           00EAE9   406 _PCA0CP1	=	0xeae9
                           00ECEB   407 _PCA0CP2	=	0xeceb
                           00FAF9   408 _PCA0	=	0xfaf9
                           00CDCC   409 _TMR2	=	0xcdcc
                           00CBCA   410 _TMR2RL	=	0xcbca
                           009594   411 _TMR3	=	0x9594
                           009392   412 _TMR3RL	=	0x9392
                           0000AA   413 __XPAGE	=	0x00aa
                                    414 ;--------------------------------------------------------
                                    415 ; special function bits
                                    416 ;--------------------------------------------------------
                                    417 	.area RSEG    (ABS,DATA)
      000000                        418 	.org 0x0000
                           0000E0   419 _ACC_ACC0	=	0x00e0
                           0000E1   420 _ACC_ACC1	=	0x00e1
                           0000E2   421 _ACC_ACC2	=	0x00e2
                           0000E3   422 _ACC_ACC3	=	0x00e3
                           0000E4   423 _ACC_ACC4	=	0x00e4
                           0000E5   424 _ACC_ACC5	=	0x00e5
                           0000E6   425 _ACC_ACC6	=	0x00e6
                           0000E7   426 _ACC_ACC7	=	0x00e7
                           0000E8   427 _ADC0CN0_ADCM0	=	0x00e8
                           0000E9   428 _ADC0CN0_ADCM1	=	0x00e9
                           0000EA   429 _ADC0CN0_ADCM2	=	0x00ea
                           0000EB   430 _ADC0CN0_ADWINT	=	0x00eb
                           0000EC   431 _ADC0CN0_ADBUSY	=	0x00ec
                           0000ED   432 _ADC0CN0_ADINT	=	0x00ed
                           0000EE   433 _ADC0CN0_ADBMEN	=	0x00ee
                           0000EF   434 _ADC0CN0_ADEN	=	0x00ef
                           0000F0   435 _B_B0	=	0x00f0
                           0000F1   436 _B_B1	=	0x00f1
                           0000F2   437 _B_B2	=	0x00f2
                           0000F3   438 _B_B3	=	0x00f3
                           0000F4   439 _B_B4	=	0x00f4
                           0000F5   440 _B_B5	=	0x00f5
                           0000F6   441 _B_B6	=	0x00f6
                           0000F7   442 _B_B7	=	0x00f7
                           0000A8   443 _IE_EX0	=	0x00a8
                           0000A9   444 _IE_ET0	=	0x00a9
                           0000AA   445 _IE_EX1	=	0x00aa
                           0000AB   446 _IE_ET1	=	0x00ab
                           0000AC   447 _IE_ES0	=	0x00ac
                           0000AD   448 _IE_ET2	=	0x00ad
                           0000AE   449 _IE_ESPI0	=	0x00ae
                           0000AF   450 _IE_EA	=	0x00af
                           0000B8   451 _IP_PX0	=	0x00b8
                           0000B9   452 _IP_PT0	=	0x00b9
                           0000BA   453 _IP_PX1	=	0x00ba
                           0000BB   454 _IP_PT1	=	0x00bb
                           0000BC   455 _IP_PS0	=	0x00bc
                           0000BD   456 _IP_PT2	=	0x00bd
                           0000BE   457 _IP_PSPI0	=	0x00be
                           000080   458 _P0_B0	=	0x0080
                           000081   459 _P0_B1	=	0x0081
                           000082   460 _P0_B2	=	0x0082
                           000083   461 _P0_B3	=	0x0083
                           000084   462 _P0_B4	=	0x0084
                           000085   463 _P0_B5	=	0x0085
                           000086   464 _P0_B6	=	0x0086
                           000087   465 _P0_B7	=	0x0087
                           000090   466 _P1_B0	=	0x0090
                           000091   467 _P1_B1	=	0x0091
                           000092   468 _P1_B2	=	0x0092
                           000093   469 _P1_B3	=	0x0093
                           000094   470 _P1_B4	=	0x0094
                           000095   471 _P1_B5	=	0x0095
                           000096   472 _P1_B6	=	0x0096
                           000097   473 _P1_B7	=	0x0097
                           0000A0   474 _P2_B0	=	0x00a0
                           0000A1   475 _P2_B1	=	0x00a1
                           0000D8   476 _PCA0CN_CCF0	=	0x00d8
                           0000D9   477 _PCA0CN_CCF1	=	0x00d9
                           0000DA   478 _PCA0CN_CCF2	=	0x00da
                           0000DE   479 _PCA0CN_CR	=	0x00de
                           0000DF   480 _PCA0CN_CF	=	0x00df
                           0000D0   481 _PSW_PARITY	=	0x00d0
                           0000D1   482 _PSW_F1	=	0x00d1
                           0000D2   483 _PSW_OV	=	0x00d2
                           0000D3   484 _PSW_RS0	=	0x00d3
                           0000D4   485 _PSW_RS1	=	0x00d4
                           0000D5   486 _PSW_F0	=	0x00d5
                           0000D6   487 _PSW_AC	=	0x00d6
                           0000D7   488 _PSW_CY	=	0x00d7
                           000098   489 _SCON0_RI	=	0x0098
                           000099   490 _SCON0_TI	=	0x0099
                           00009A   491 _SCON0_RB8	=	0x009a
                           00009B   492 _SCON0_TB8	=	0x009b
                           00009C   493 _SCON0_REN	=	0x009c
                           00009D   494 _SCON0_MCE	=	0x009d
                           00009F   495 _SCON0_SMODE	=	0x009f
                           0000C0   496 _SMB0CN_SI	=	0x00c0
                           0000C1   497 _SMB0CN_ACK	=	0x00c1
                           0000C2   498 _SMB0CN_ARBLOST	=	0x00c2
                           0000C3   499 _SMB0CN_ACKRQ	=	0x00c3
                           0000C4   500 _SMB0CN_STO	=	0x00c4
                           0000C5   501 _SMB0CN_STA	=	0x00c5
                           0000C6   502 _SMB0CN_TXMODE	=	0x00c6
                           0000C7   503 _SMB0CN_MASTER	=	0x00c7
                           0000F8   504 _SPI0CN_SPIEN	=	0x00f8
                           0000F9   505 _SPI0CN_TXBMT	=	0x00f9
                           0000FA   506 _SPI0CN_NSSMD0	=	0x00fa
                           0000FB   507 _SPI0CN_NSSMD1	=	0x00fb
                           0000FC   508 _SPI0CN_RXOVRN	=	0x00fc
                           0000FD   509 _SPI0CN_MODF	=	0x00fd
                           0000FE   510 _SPI0CN_WCOL	=	0x00fe
                           0000FF   511 _SPI0CN_SPIF	=	0x00ff
                           000088   512 _TCON_IT0	=	0x0088
                           000089   513 _TCON_IE0	=	0x0089
                           00008A   514 _TCON_IT1	=	0x008a
                           00008B   515 _TCON_IE1	=	0x008b
                           00008C   516 _TCON_TR0	=	0x008c
                           00008D   517 _TCON_TF0	=	0x008d
                           00008E   518 _TCON_TR1	=	0x008e
                           00008F   519 _TCON_TF1	=	0x008f
                           0000C8   520 _TMR2CN_T2XCLK	=	0x00c8
                           0000CA   521 _TMR2CN_TR2	=	0x00ca
                           0000CB   522 _TMR2CN_T2SPLIT	=	0x00cb
                           0000CC   523 _TMR2CN_TF2CEN	=	0x00cc
                           0000CD   524 _TMR2CN_TF2LEN	=	0x00cd
                           0000CE   525 _TMR2CN_TF2L	=	0x00ce
                           0000CF   526 _TMR2CN_TF2H	=	0x00cf
                           000094   527 _PWM	=	0x0094
                                    528 ;--------------------------------------------------------
                                    529 ; overlayable register banks
                                    530 ;--------------------------------------------------------
                                    531 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        532 	.ds 8
                                    533 ;--------------------------------------------------------
                                    534 ; overlayable bit register bank
                                    535 ;--------------------------------------------------------
                                    536 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        537 bits:
      000020                        538 	.ds 1
                           008000   539 	b0 = bits[0]
                           008100   540 	b1 = bits[1]
                           008200   541 	b2 = bits[2]
                           008300   542 	b3 = bits[3]
                           008400   543 	b4 = bits[4]
                           008500   544 	b5 = bits[5]
                           008600   545 	b6 = bits[6]
                           008700   546 	b7 = bits[7]
                                    547 ;--------------------------------------------------------
                                    548 ; internal ram data
                                    549 ;--------------------------------------------------------
                                    550 	.area DSEG    (DATA)
      000021                        551 _uart_buf::
      000021                        552 	.ds 50
      000053                        553 _uart_head::
      000053                        554 	.ds 1
      000054                        555 _uart_tail::
      000054                        556 	.ds 1
      000055                        557 _smb_target::
      000055                        558 	.ds 1
      000056                        559 _smb_data_in::
      000056                        560 	.ds 1
      000057                        561 _smb_data_out::
      000057                        562 	.ds 2
      000059                        563 _smb_busy::
      000059                        564 	.ds 1
      00005A                        565 _smb_rnw::
      00005A                        566 	.ds 1
      00005B                        567 _smb_ptr::
      00005B                        568 	.ds 1
      00005C                        569 _mpu_state::
      00005C                        570 	.ds 1
      00005D                        571 _sample::
      00005D                        572 	.ds 2
      00005F                        573 _accel_x::
      00005F                        574 	.ds 2
      000061                        575 _accel_y::
      000061                        576 	.ds 2
      000063                        577 _accel_z::
      000063                        578 	.ds 2
      000065                        579 _gyro_x::
      000065                        580 	.ds 2
      000067                        581 _gyro_y::
      000067                        582 	.ds 2
      000069                        583 _gyro_z::
      000069                        584 	.ds 2
      00006B                        585 _p::
      00006B                        586 	.ds 2
      00006D                        587 _go::
      00006D                        588 	.ds 1
                                    589 ;--------------------------------------------------------
                                    590 ; overlayable items in internal ram 
                                    591 ;--------------------------------------------------------
                                    592 	.area	OSEG    (OVR,DATA)
                                    593 	.area	OSEG    (OVR,DATA)
      000008                        594 _smbRead_PARM_2:
      000008                        595 	.ds 1
                                    596 	.area	OSEG    (OVR,DATA)
      000008                        597 _smbWrite_PARM_2:
      000008                        598 	.ds 1
      000009                        599 _smbWrite_PARM_3:
      000009                        600 	.ds 1
                                    601 ;--------------------------------------------------------
                                    602 ; Stack segment in internal ram 
                                    603 ;--------------------------------------------------------
                                    604 	.area	SSEG
      00006E                        605 __start__stack:
      00006E                        606 	.ds	1
                                    607 
                                    608 ;--------------------------------------------------------
                                    609 ; indirectly addressable internal ram data
                                    610 ;--------------------------------------------------------
                                    611 	.area ISEG    (DATA)
                                    612 ;--------------------------------------------------------
                                    613 ; absolute internal ram data
                                    614 ;--------------------------------------------------------
                                    615 	.area IABS    (ABS,DATA)
                                    616 	.area IABS    (ABS,DATA)
                                    617 ;--------------------------------------------------------
                                    618 ; bit data
                                    619 ;--------------------------------------------------------
                                    620 	.area BSEG    (BIT)
                                    621 ;--------------------------------------------------------
                                    622 ; paged external ram data
                                    623 ;--------------------------------------------------------
                                    624 	.area PSEG    (PAG,XDATA)
                                    625 ;--------------------------------------------------------
                                    626 ; external ram data
                                    627 ;--------------------------------------------------------
                                    628 	.area XSEG    (XDATA)
                                    629 ;--------------------------------------------------------
                                    630 ; absolute external ram data
                                    631 ;--------------------------------------------------------
                                    632 	.area XABS    (ABS,XDATA)
                                    633 ;--------------------------------------------------------
                                    634 ; external initialized ram data
                                    635 ;--------------------------------------------------------
                                    636 	.area XISEG   (XDATA)
                                    637 	.area HOME    (CODE)
                                    638 	.area GSINIT0 (CODE)
                                    639 	.area GSINIT1 (CODE)
                                    640 	.area GSINIT2 (CODE)
                                    641 	.area GSINIT3 (CODE)
                                    642 	.area GSINIT4 (CODE)
                                    643 	.area GSINIT5 (CODE)
                                    644 	.area GSINIT  (CODE)
                                    645 	.area GSFINAL (CODE)
                                    646 	.area CSEG    (CODE)
                                    647 ;--------------------------------------------------------
                                    648 ; interrupt vector 
                                    649 ;--------------------------------------------------------
                                    650 	.area HOME    (CODE)
      000000                        651 __interrupt_vect:
      000000 02 00 79         [24]  652 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  653 	reti
      000004                        654 	.ds	7
      00000B 32               [24]  655 	reti
      00000C                        656 	.ds	7
      000013 32               [24]  657 	reti
      000014                        658 	.ds	7
      00001B 32               [24]  659 	reti
      00001C                        660 	.ds	7
      000023 02 02 17         [24]  661 	ljmp	_UART0_ISR
      000026                        662 	.ds	5
      00002B 02 02 3B         [24]  663 	ljmp	_TIMER2_ISR
      00002E                        664 	.ds	5
      000033 32               [24]  665 	reti
      000034                        666 	.ds	7
      00003B 02 02 D2         [24]  667 	ljmp	_SMBUS0_ISR
      00003E                        668 	.ds	5
      000043 32               [24]  669 	reti
      000044                        670 	.ds	7
      00004B 32               [24]  671 	reti
      00004C                        672 	.ds	7
      000053 32               [24]  673 	reti
      000054                        674 	.ds	7
      00005B 32               [24]  675 	reti
      00005C                        676 	.ds	7
      000063 32               [24]  677 	reti
      000064                        678 	.ds	7
      00006B 32               [24]  679 	reti
      00006C                        680 	.ds	7
      000073 02 02 66         [24]  681 	ljmp	_TIMER3_ISR
                                    682 ;--------------------------------------------------------
                                    683 ; global & static initialisations
                                    684 ;--------------------------------------------------------
                                    685 	.area HOME    (CODE)
                                    686 	.area GSINIT  (CODE)
                                    687 	.area GSFINAL (CODE)
                                    688 	.area GSINIT  (CODE)
                                    689 	.globl __sdcc_gsinit_startup
                                    690 	.globl __sdcc_program_startup
                                    691 	.globl __start__stack
                                    692 	.globl __mcs51_genXINIT
                                    693 	.globl __mcs51_genXRAMCLEAR
                                    694 	.globl __mcs51_genRAMCLEAR
                                    695 	.area GSFINAL (CODE)
      0000D2 02 00 76         [24]  696 	ljmp	__sdcc_program_startup
                                    697 ;--------------------------------------------------------
                                    698 ; Home
                                    699 ;--------------------------------------------------------
                                    700 	.area HOME    (CODE)
                                    701 	.area HOME    (CODE)
      000076                        702 __sdcc_program_startup:
      000076 02 00 D5         [24]  703 	ljmp	_main
                                    704 ;	return from main will return to caller
                                    705 ;--------------------------------------------------------
                                    706 ; code
                                    707 ;--------------------------------------------------------
                                    708 	.area CSEG    (CODE)
                                    709 ;------------------------------------------------------------
                                    710 ;Allocation info for local variables in function 'main'
                                    711 ;------------------------------------------------------------
                                    712 ;i                         Allocated to registers r7 
                                    713 ;j                         Allocated to registers r5 r6 
                                    714 ;------------------------------------------------------------
                                    715 ;	src/main.c:88: void main (void){             
                                    716 ;	-----------------------------------------
                                    717 ;	 function main
                                    718 ;	-----------------------------------------
      0000D5                        719 _main:
                           000007   720 	ar7 = 0x07
                           000006   721 	ar6 = 0x06
                           000005   722 	ar5 = 0x05
                           000004   723 	ar4 = 0x04
                           000003   724 	ar3 = 0x03
                           000002   725 	ar2 = 0x02
                           000001   726 	ar1 = 0x01
                           000000   727 	ar0 = 0x00
                                    728 ;	src/main.c:91: setup();  
      0000D5 12 05 52         [24]  729 	lcall	_setup
                                    730 ;	src/main.c:94: sample = 0;  
      0000D8 E4               [12]  731 	clr	a
      0000D9 F5 5D            [12]  732 	mov	_sample,a
      0000DB F5 5E            [12]  733 	mov	(_sample + 1),a
                                    734 ;	src/main.c:97: uart_head = 0;
                                    735 ;	1-genFromRTrack replaced	mov	_uart_head,#0x00
      0000DD F5 53            [12]  736 	mov	_uart_head,a
                                    737 ;	src/main.c:98: uart_tail = 0;
                                    738 ;	1-genFromRTrack replaced	mov	_uart_tail,#0x00
      0000DF F5 54            [12]  739 	mov	_uart_tail,a
                                    740 ;	src/main.c:106: smbWrite(SMB_TARGET_DRV, 0x01, 0x07); // Out of standby and auto cal mode
      0000E1 75 08 01         [24]  741 	mov	_smbWrite_PARM_2,#0x01
      0000E4 75 09 07         [24]  742 	mov	_smbWrite_PARM_3,#0x07
      0000E7 75 82 B4         [24]  743 	mov	dpl,#0xb4
      0000EA 12 05 0B         [24]  744 	lcall	_smbWrite
                                    745 ;	src/main.c:107: smbWrite(SMB_TARGET_DRV, 0x1A, 0x38); // ERM Mode, FB_BRAKE_FATOR == 4x, LOOP_GAIN == Medium 
      0000ED 75 08 1A         [24]  746 	mov	_smbWrite_PARM_2,#0x1a
      0000F0 75 09 38         [24]  747 	mov	_smbWrite_PARM_3,#0x38
      0000F3 75 82 B4         [24]  748 	mov	dpl,#0xb4
      0000F6 12 05 0B         [24]  749 	lcall	_smbWrite
                                    750 ;	src/main.c:108: smbWrite(SMB_TARGET_DRV, 0x16, 0x7F); // RATED_VOLTAGE == 0x7F 
      0000F9 75 08 16         [24]  751 	mov	_smbWrite_PARM_2,#0x16
      0000FC 75 09 7F         [24]  752 	mov	_smbWrite_PARM_3,#0x7f
      0000FF 75 82 B4         [24]  753 	mov	dpl,#0xb4
      000102 12 05 0B         [24]  754 	lcall	_smbWrite
                                    755 ;	src/main.c:109: smbWrite(SMB_TARGET_DRV, 0x17, 0x7F); // OD_CLAMP == 0x7F (signed) 
      000105 75 08 17         [24]  756 	mov	_smbWrite_PARM_2,#0x17
      000108 75 09 7F         [24]  757 	mov	_smbWrite_PARM_3,#0x7f
      00010B 75 82 B4         [24]  758 	mov	dpl,#0xb4
      00010E 12 05 0B         [24]  759 	lcall	_smbWrite
                                    760 ;	src/main.c:110: smbWrite(SMB_TARGET_DRV, 0x1E, 0x20); // AUTO_CAL_TIME == 500ms to 700ms
      000111 75 08 1E         [24]  761 	mov	_smbWrite_PARM_2,#0x1e
      000114 75 09 20         [24]  762 	mov	_smbWrite_PARM_3,#0x20
      000117 75 82 B4         [24]  763 	mov	dpl,#0xb4
      00011A 12 05 0B         [24]  764 	lcall	_smbWrite
                                    765 ;	src/main.c:111: smbWrite(SMB_TARGET_DRV, 0x1B, 0x9F); // DRIVE_TIME == 0x1F
      00011D 75 08 1B         [24]  766 	mov	_smbWrite_PARM_2,#0x1b
      000120 75 09 9F         [24]  767 	mov	_smbWrite_PARM_3,#0x9f
      000123 75 82 B4         [24]  768 	mov	dpl,#0xb4
      000126 12 05 0B         [24]  769 	lcall	_smbWrite
                                    770 ;	src/main.c:112: smbWrite(SMB_TARGET_DRV, 0x0C, 0x01); // Set GO bit to start auto cal
      000129 75 08 0C         [24]  771 	mov	_smbWrite_PARM_2,#0x0c
      00012C 75 09 01         [24]  772 	mov	_smbWrite_PARM_3,#0x01
      00012F 75 82 B4         [24]  773 	mov	dpl,#0xb4
      000132 12 05 0B         [24]  774 	lcall	_smbWrite
                                    775 ;	src/main.c:113: for(i=0;i<5;i++){
      000135 7F 00            [12]  776 	mov	r7,#0x00
      000137                        777 00109$:
                                    778 ;	src/main.c:114: j = smbRead(SMB_TARGET_DRV, 0x00);
      000137 75 08 00         [24]  779 	mov	_smbRead_PARM_2,#0x00
      00013A 75 82 B4         [24]  780 	mov	dpl,#0xb4
      00013D C0 07            [24]  781 	push	ar7
      00013F 12 04 DE         [24]  782 	lcall	_smbRead
      000142 AE 82            [24]  783 	mov	r6,dpl
      000144 D0 07            [24]  784 	pop	ar7
      000146 8E 05            [24]  785 	mov	ar5,r6
      000148 7E 00            [12]  786 	mov	r6,#0x00
                                    787 ;	src/main.c:115: while(0 == uartEmpty());
      00014A                        788 00101$:
      00014A C0 07            [24]  789 	push	ar7
      00014C C0 06            [24]  790 	push	ar6
      00014E C0 05            [24]  791 	push	ar5
      000150 12 05 45         [24]  792 	lcall	_uartEmpty
      000153 E5 82            [12]  793 	mov	a,dpl
      000155 D0 05            [24]  794 	pop	ar5
      000157 D0 06            [24]  795 	pop	ar6
      000159 D0 07            [24]  796 	pop	ar7
      00015B 60 ED            [24]  797 	jz	00101$
                                    798 ;	src/main.c:116: sendU16(j);
      00015D 8D 82            [24]  799 	mov	dpl,r5
      00015F 8E 83            [24]  800 	mov	dph,r6
      000161 C0 07            [24]  801 	push	ar7
      000163 12 01 AA         [24]  802 	lcall	_sendU16
                                    803 ;	src/main.c:117: uartTx('\n');
      000166 75 82 0A         [24]  804 	mov	dpl,#0x0a
      000169 12 05 25         [24]  805 	lcall	_uartTx
      00016C D0 07            [24]  806 	pop	ar7
                                    807 ;	src/main.c:113: for(i=0;i<5;i++){
      00016E 0F               [12]  808 	inc	r7
      00016F BF 05 00         [24]  809 	cjne	r7,#0x05,00161$
      000172                        810 00161$:
      000172 40 C3            [24]  811 	jc	00109$
                                    812 ;	src/main.c:119: smbWrite(SMB_TARGET_DRV, 0x01, 0x03);   
      000174 75 08 01         [24]  813 	mov	_smbWrite_PARM_2,#0x01
      000177 75 09 03         [24]  814 	mov	_smbWrite_PARM_3,#0x03
      00017A 75 82 B4         [24]  815 	mov	dpl,#0xb4
      00017D 12 05 0B         [24]  816 	lcall	_smbWrite
                                    817 ;	src/main.c:123: for(j=0;j<10;j++) PWM = 1; 
      000180                        818 00125$:
      000180 7E 00            [12]  819 	mov	r6,#0x00
      000182 7F 00            [12]  820 	mov	r7,#0x00
      000184                        821 00111$:
                                    822 ;	assignBit
      000184 D2 94            [12]  823 	setb	_PWM
      000186 0E               [12]  824 	inc	r6
      000187 BE 00 01         [24]  825 	cjne	r6,#0x00,00163$
      00018A 0F               [12]  826 	inc	r7
      00018B                        827 00163$:
      00018B C3               [12]  828 	clr	c
      00018C EE               [12]  829 	mov	a,r6
      00018D 94 0A            [12]  830 	subb	a,#0x0a
      00018F EF               [12]  831 	mov	a,r7
      000190 94 00            [12]  832 	subb	a,#0x00
      000192 40 F0            [24]  833 	jc	00111$
                                    834 ;	src/main.c:124: for(j=0;j<10;j++) PWM = 0;
      000194 7E 00            [12]  835 	mov	r6,#0x00
      000196 7F 00            [12]  836 	mov	r7,#0x00
      000198                        837 00113$:
                                    838 ;	assignBit
      000198 C2 94            [12]  839 	clr	_PWM
      00019A 0E               [12]  840 	inc	r6
      00019B BE 00 01         [24]  841 	cjne	r6,#0x00,00165$
      00019E 0F               [12]  842 	inc	r7
      00019F                        843 00165$:
      00019F C3               [12]  844 	clr	c
      0001A0 EE               [12]  845 	mov	a,r6
      0001A1 94 0A            [12]  846 	subb	a,#0x0a
      0001A3 EF               [12]  847 	mov	a,r7
      0001A4 94 00            [12]  848 	subb	a,#0x00
      0001A6 40 F0            [24]  849 	jc	00113$
                                    850 ;	src/main.c:147: }
      0001A8 80 D6            [24]  851 	sjmp	00125$
                                    852 ;------------------------------------------------------------
                                    853 ;Allocation info for local variables in function 'sendU16'
                                    854 ;------------------------------------------------------------
                                    855 ;s                         Allocated to registers r6 r7 
                                    856 ;------------------------------------------------------------
                                    857 ;	src/main.c:154: void sendU16(U16 s){
                                    858 ;	-----------------------------------------
                                    859 ;	 function sendU16
                                    860 ;	-----------------------------------------
      0001AA                        861 _sendU16:
      0001AA AE 82            [24]  862 	mov	r6,dpl
                                    863 ;	src/main.c:155: uartTx(nibble2hex(s >> 12));
      0001AC E5 83            [12]  864 	mov	a,dph
      0001AE FF               [12]  865 	mov	r7,a
      0001AF C4               [12]  866 	swap	a
      0001B0 54 0F            [12]  867 	anl	a,#0x0f
      0001B2 F5 82            [12]  868 	mov	dpl,a
      0001B4 C0 07            [24]  869 	push	ar7
      0001B6 C0 06            [24]  870 	push	ar6
      0001B8 12 01 FF         [24]  871 	lcall	_nibble2hex
      0001BB 12 05 25         [24]  872 	lcall	_uartTx
      0001BE D0 06            [24]  873 	pop	ar6
      0001C0 D0 07            [24]  874 	pop	ar7
                                    875 ;	src/main.c:156: uartTx(nibble2hex(s >> 8));
      0001C2 8F 82            [24]  876 	mov	dpl,r7
      0001C4 C0 07            [24]  877 	push	ar7
      0001C6 C0 06            [24]  878 	push	ar6
      0001C8 12 01 FF         [24]  879 	lcall	_nibble2hex
      0001CB 12 05 25         [24]  880 	lcall	_uartTx
      0001CE D0 06            [24]  881 	pop	ar6
      0001D0 D0 07            [24]  882 	pop	ar7
                                    883 ;	src/main.c:157: uartTx(nibble2hex(s >> 4));
      0001D2 8E 04            [24]  884 	mov	ar4,r6
      0001D4 EF               [12]  885 	mov	a,r7
      0001D5 C4               [12]  886 	swap	a
      0001D6 CC               [12]  887 	xch	a,r4
      0001D7 C4               [12]  888 	swap	a
      0001D8 54 0F            [12]  889 	anl	a,#0x0f
      0001DA 6C               [12]  890 	xrl	a,r4
      0001DB CC               [12]  891 	xch	a,r4
      0001DC 54 0F            [12]  892 	anl	a,#0x0f
      0001DE CC               [12]  893 	xch	a,r4
      0001DF 6C               [12]  894 	xrl	a,r4
      0001E0 CC               [12]  895 	xch	a,r4
      0001E1 8C 82            [24]  896 	mov	dpl,r4
      0001E3 C0 07            [24]  897 	push	ar7
      0001E5 C0 06            [24]  898 	push	ar6
      0001E7 12 01 FF         [24]  899 	lcall	_nibble2hex
      0001EA 12 05 25         [24]  900 	lcall	_uartTx
      0001ED D0 06            [24]  901 	pop	ar6
      0001EF D0 07            [24]  902 	pop	ar7
                                    903 ;	src/main.c:158: uartTx(nibble2hex(s));
      0001F1 8E 82            [24]  904 	mov	dpl,r6
      0001F3 12 01 FF         [24]  905 	lcall	_nibble2hex
      0001F6 12 05 25         [24]  906 	lcall	_uartTx
                                    907 ;	src/main.c:159: uartTx(',');
      0001F9 75 82 2C         [24]  908 	mov	dpl,#0x2c
                                    909 ;	src/main.c:160: }
      0001FC 02 05 25         [24]  910 	ljmp	_uartTx
                                    911 ;------------------------------------------------------------
                                    912 ;Allocation info for local variables in function 'nibble2hex'
                                    913 ;------------------------------------------------------------
                                    914 ;n                         Allocated to registers r7 
                                    915 ;i                         Allocated to registers r6 
                                    916 ;------------------------------------------------------------
                                    917 ;	src/main.c:162: U8 nibble2hex(U8 n){
                                    918 ;	-----------------------------------------
                                    919 ;	 function nibble2hex
                                    920 ;	-----------------------------------------
      0001FF                        921 _nibble2hex:
                                    922 ;	src/main.c:164: i = n & 0xF;
                                    923 ;	src/main.c:165: if(i > 0x9){
      0001FF E5 82            [12]  924 	mov	a,dpl
      000201 54 0F            [12]  925 	anl	a,#0x0f
      000203 FF               [12]  926 	mov	r7,a
      000204 24 F6            [12]  927 	add	a,#0xff - 0x09
      000206 50 08            [24]  928 	jnc	00102$
                                    929 ;	src/main.c:166: i += ('A' - 0xA);
      000208 8F 06            [24]  930 	mov	ar6,r7
      00020A 74 37            [12]  931 	mov	a,#0x37
      00020C 2E               [12]  932 	add	a,r6
      00020D FE               [12]  933 	mov	r6,a
      00020E 80 04            [24]  934 	sjmp	00103$
      000210                        935 00102$:
                                    936 ;	src/main.c:168: i += '0';
      000210 74 30            [12]  937 	mov	a,#0x30
      000212 2F               [12]  938 	add	a,r7
      000213 FE               [12]  939 	mov	r6,a
      000214                        940 00103$:
                                    941 ;	src/main.c:170: return i;
      000214 8E 82            [24]  942 	mov	dpl,r6
                                    943 ;	src/main.c:171: }
      000216 22               [24]  944 	ret
                                    945 ;------------------------------------------------------------
                                    946 ;Allocation info for local variables in function 'UART0_ISR'
                                    947 ;------------------------------------------------------------
                                    948 ;	src/main.c:177: INTERRUPT (UART0_ISR, UART0_IRQn){     // Service both Rx & Tx flags 
                                    949 ;	-----------------------------------------
                                    950 ;	 function UART0_ISR
                                    951 ;	-----------------------------------------
      000217                        952 _UART0_ISR:
      000217 C0 07            [24]  953 	push	ar7
      000219 C0 06            [24]  954 	push	ar6
      00021B C0 D0            [24]  955 	push	psw
      00021D 75 D0 00         [24]  956 	mov	psw,#0x00
                                    957 ;	src/main.c:178: if(SCON0_RI){
      000220 30 98 06         [24]  958 	jnb	_SCON0_RI,00102$
                                    959 ;	src/main.c:179: p = SBUF0;   
      000223 85 99 6B         [24]  960 	mov	_p,_SBUF0
      000226 75 6C 00         [24]  961 	mov	(_p + 1),#0x00
      000229                        962 00102$:
                                    963 ;	src/main.c:181: SCON0_RI = 0;
                                    964 ;	assignBit
      000229 C2 98            [12]  965 	clr	_SCON0_RI
                                    966 ;	src/main.c:182: SCON0_TI = 0;
                                    967 ;	assignBit
      00022B C2 99            [12]  968 	clr	_SCON0_TI
                                    969 ;	src/main.c:183: IE |= IE_ES0__ENABLED; 
      00022D AE A8            [24]  970 	mov	r6,_IE
      00022F 43 06 10         [24]  971 	orl	ar6,#0x10
      000232 8E A8            [24]  972 	mov	_IE,r6
                                    973 ;	src/main.c:184: } 
      000234 D0 D0            [24]  974 	pop	psw
      000236 D0 06            [24]  975 	pop	ar6
      000238 D0 07            [24]  976 	pop	ar7
      00023A 32               [24]  977 	reti
                                    978 ;	eliminated unneeded push/pop dpl
                                    979 ;	eliminated unneeded push/pop dph
                                    980 ;	eliminated unneeded push/pop b
                                    981 ;	eliminated unneeded push/pop acc
                                    982 ;------------------------------------------------------------
                                    983 ;Allocation info for local variables in function 'TIMER2_ISR'
                                    984 ;------------------------------------------------------------
                                    985 ;	src/main.c:186: INTERRUPT (TIMER2_ISR, TIMER2_IRQn){            
                                    986 ;	-----------------------------------------
                                    987 ;	 function TIMER2_ISR
                                    988 ;	-----------------------------------------
      00023B                        989 _TIMER2_ISR:
      00023B C0 E0            [24]  990 	push	acc
      00023D C0 07            [24]  991 	push	ar7
      00023F C0 06            [24]  992 	push	ar6
      000241 C0 D0            [24]  993 	push	psw
      000243 75 D0 00         [24]  994 	mov	psw,#0x00
                                    995 ;	src/main.c:187: go = 1;
                                    996 ;	src/main.c:188: sample++;   
      000246 74 01            [12]  997 	mov	a,#0x01
      000248 F5 6D            [12]  998 	mov	_go,a
      00024A 25 5D            [12]  999 	add	a,_sample
      00024C F5 5D            [12] 1000 	mov	_sample,a
      00024E E4               [12] 1001 	clr	a
      00024F 35 5E            [12] 1002 	addc	a,(_sample + 1)
      000251 F5 5E            [12] 1003 	mov	(_sample + 1),a
                                   1004 ;	src/main.c:190: TMR2CN &= ~TMR2CN_TF2H__SET;
      000253 53 C8 7F         [24] 1005 	anl	_TMR2CN,#0x7f
                                   1006 ;	src/main.c:191: IE |= IE_ET2__ENABLED; 
      000256 AE A8            [24] 1007 	mov	r6,_IE
      000258 43 06 20         [24] 1008 	orl	ar6,#0x20
      00025B 8E A8            [24] 1009 	mov	_IE,r6
                                   1010 ;	src/main.c:193: } 
      00025D D0 D0            [24] 1011 	pop	psw
      00025F D0 06            [24] 1012 	pop	ar6
      000261 D0 07            [24] 1013 	pop	ar7
      000263 D0 E0            [24] 1014 	pop	acc
      000265 32               [24] 1015 	reti
                                   1016 ;	eliminated unneeded push/pop dpl
                                   1017 ;	eliminated unneeded push/pop dph
                                   1018 ;	eliminated unneeded push/pop b
                                   1019 ;------------------------------------------------------------
                                   1020 ;Allocation info for local variables in function 'TIMER3_ISR'
                                   1021 ;------------------------------------------------------------
                                   1022 ;	src/main.c:195: INTERRUPT (TIMER3_ISR, TIMER3_IRQn){            
                                   1023 ;	-----------------------------------------
                                   1024 ;	 function TIMER3_ISR
                                   1025 ;	-----------------------------------------
      000266                       1026 _TIMER3_ISR:
      000266 C0 20            [24] 1027 	push	bits
      000268 C0 E0            [24] 1028 	push	acc
      00026A C0 F0            [24] 1029 	push	b
      00026C C0 82            [24] 1030 	push	dpl
      00026E C0 83            [24] 1031 	push	dph
      000270 C0 07            [24] 1032 	push	(0+7)
      000272 C0 06            [24] 1033 	push	(0+6)
      000274 C0 05            [24] 1034 	push	(0+5)
      000276 C0 04            [24] 1035 	push	(0+4)
      000278 C0 03            [24] 1036 	push	(0+3)
      00027A C0 02            [24] 1037 	push	(0+2)
      00027C C0 01            [24] 1038 	push	(0+1)
      00027E C0 00            [24] 1039 	push	(0+0)
      000280 C0 D0            [24] 1040 	push	psw
      000282 75 D0 00         [24] 1041 	mov	psw,#0x00
                                   1042 ;	src/main.c:197: if(uart_head != uart_tail){ 
      000285 E5 54            [12] 1043 	mov	a,_uart_tail
      000287 B5 53 02         [24] 1044 	cjne	a,_uart_head,00109$
      00028A 80 1F            [24] 1045 	sjmp	00102$
      00028C                       1046 00109$:
                                   1047 ;	src/main.c:198: SBUF0 = uart_buf[uart_tail];
      00028C E5 54            [12] 1048 	mov	a,_uart_tail
      00028E 24 21            [12] 1049 	add	a,#_uart_buf
      000290 F9               [12] 1050 	mov	r1,a
      000291 87 99            [24] 1051 	mov	_SBUF0,@r1
                                   1052 ;	src/main.c:199: uart_tail++;
      000293 05 54            [12] 1053 	inc	_uart_tail
                                   1054 ;	src/main.c:200: uart_tail %= UART_BUF_SIZE;
      000295 AE 54            [24] 1055 	mov	r6,_uart_tail
      000297 7F 00            [12] 1056 	mov	r7,#0x00
      000299 75 08 32         [24] 1057 	mov	__modsint_PARM_2,#0x32
                                   1058 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      00029C 8F 09            [24] 1059 	mov	(__modsint_PARM_2 + 1),r7
      00029E 8E 82            [24] 1060 	mov	dpl,r6
      0002A0 8F 83            [24] 1061 	mov	dph,r7
      0002A2 12 05 FD         [24] 1062 	lcall	__modsint
      0002A5 AE 82            [24] 1063 	mov	r6,dpl
      0002A7 AF 83            [24] 1064 	mov	r7,dph
      0002A9 8E 54            [24] 1065 	mov	_uart_tail,r6
      0002AB                       1066 00102$:
                                   1067 ;	src/main.c:204: TMR3CN &= ~TMR3CN_TF3H__SET;
      0002AB 53 91 7F         [24] 1068 	anl	_TMR3CN,#0x7f
                                   1069 ;	src/main.c:205: EIE1 |= EIE1_ET3__ENABLED;
      0002AE AE E6            [24] 1070 	mov	r6,_EIE1
      0002B0 43 06 80         [24] 1071 	orl	ar6,#0x80
      0002B3 8E E6            [24] 1072 	mov	_EIE1,r6
                                   1073 ;	src/main.c:206: } 
      0002B5 D0 D0            [24] 1074 	pop	psw
      0002B7 D0 00            [24] 1075 	pop	(0+0)
      0002B9 D0 01            [24] 1076 	pop	(0+1)
      0002BB D0 02            [24] 1077 	pop	(0+2)
      0002BD D0 03            [24] 1078 	pop	(0+3)
      0002BF D0 04            [24] 1079 	pop	(0+4)
      0002C1 D0 05            [24] 1080 	pop	(0+5)
      0002C3 D0 06            [24] 1081 	pop	(0+6)
      0002C5 D0 07            [24] 1082 	pop	(0+7)
      0002C7 D0 83            [24] 1083 	pop	dph
      0002C9 D0 82            [24] 1084 	pop	dpl
      0002CB D0 F0            [24] 1085 	pop	b
      0002CD D0 E0            [24] 1086 	pop	acc
      0002CF D0 20            [24] 1087 	pop	bits
      0002D1 32               [24] 1088 	reti
                                   1089 ;------------------------------------------------------------
                                   1090 ;Allocation info for local variables in function 'SMBUS0_ISR'
                                   1091 ;------------------------------------------------------------
                                   1092 ;	src/main.c:212: INTERRUPT(SMBUS0_ISR, SMBUS0_IRQn){ 
                                   1093 ;	-----------------------------------------
                                   1094 ;	 function SMBUS0_ISR
                                   1095 ;	-----------------------------------------
      0002D2                       1096 _SMBUS0_ISR:
      0002D2 C0 E0            [24] 1097 	push	acc
      0002D4 C0 F0            [24] 1098 	push	b
      0002D6 C0 82            [24] 1099 	push	dpl
      0002D8 C0 83            [24] 1100 	push	dph
      0002DA C0 07            [24] 1101 	push	ar7
      0002DC C0 06            [24] 1102 	push	ar6
      0002DE C0 D0            [24] 1103 	push	psw
      0002E0 75 D0 00         [24] 1104 	mov	psw,#0x00
                                   1105 ;	src/main.c:213: switch (SMB0CN & 0xF0) {
      0002E3 AE C0            [24] 1106 	mov	r6,_SMB0CN
      0002E5 53 06 F0         [24] 1107 	anl	ar6,#0xf0
      0002E8 7F 00            [12] 1108 	mov	r7,#0x00
      0002EA BE 80 05         [24] 1109 	cjne	r6,#0x80,00170$
      0002ED BF 00 02         [24] 1110 	cjne	r7,#0x00,00170$
      0002F0 80 65            [24] 1111 	sjmp	00112$
      0002F2                       1112 00170$:
      0002F2 BE C0 05         [24] 1113 	cjne	r6,#0xc0,00171$
      0002F5 BF 00 02         [24] 1114 	cjne	r7,#0x00,00171$
      0002F8 80 1A            [24] 1115 	sjmp	00102$
      0002FA                       1116 00171$:
      0002FA BE E0 05         [24] 1117 	cjne	r6,#0xe0,00172$
      0002FD BF 00 02         [24] 1118 	cjne	r7,#0x00,00172$
      000300 80 03            [24] 1119 	sjmp	00173$
      000302                       1120 00172$:
      000302 02 04 A8         [24] 1121 	ljmp	00131$
      000305                       1122 00173$:
                                   1123 ;	src/main.c:215: case SMB_MTSTA:   SMB0DAT = smb_target;               // Load address of the target slave (only one)
      000305 85 55 C2         [24] 1124 	mov	_SMB0DAT,_smb_target
                                   1125 ;	src/main.c:216: SMB0DAT &= 0xFE;                    // Clear the LSB of the address for the 
      000308 53 C2 FE         [24] 1126 	anl	_SMB0DAT,#0xfe
                                   1127 ;	src/main.c:217: SMB0DAT |= smb_rnw;                 // Load R/W bit
      00030B E5 5A            [12] 1128 	mov	a,_smb_rnw
      00030D 42 C2            [12] 1129 	orl	_SMB0DAT,a
                                   1130 ;	src/main.c:218: SMB0CN_STA = 0;                     // Manually clear START bit 
                                   1131 ;	assignBit
      00030F C2 C5            [12] 1132 	clr	_SMB0CN_STA
                                   1133 ;	src/main.c:219: break;
      000311 02 04 A8         [24] 1134 	ljmp	00131$
                                   1135 ;	src/main.c:221: case SMB_MTDB:    if(SMB0CN_ACK) {
      000314                       1136 00102$:
      000314 30 C1 39         [24] 1137 	jnb	_SMB0CN_ACK,00110$
                                   1138 ;	src/main.c:222: switch(mpu_state){ 
      000317 AF 5C            [24] 1139 	mov	r7,_mpu_state
      000319 BF 00 02         [24] 1140 	cjne	r7,#0x00,00175$
      00031C 80 2A            [24] 1141 	sjmp	00106$
      00031E                       1142 00175$:
      00031E BF 01 02         [24] 1143 	cjne	r7,#0x01,00176$
      000321 80 1C            [24] 1144 	sjmp	00105$
      000323                       1145 00176$:
      000323 BF 02 02         [24] 1146 	cjne	r7,#0x02,00177$
      000326 80 0E            [24] 1147 	sjmp	00104$
      000328                       1148 00177$:
      000328 BF 04 02         [24] 1149 	cjne	r7,#0x04,00178$
      00032B 80 03            [24] 1150 	sjmp	00179$
      00032D                       1151 00178$:
      00032D 02 04 A8         [24] 1152 	ljmp	00131$
      000330                       1153 00179$:
                                   1154 ;	src/main.c:223: case SMB_STATE_RD1:        mpu_state = SMB_STATE_RD_STOP;
      000330 75 5C 03         [24] 1155 	mov	_mpu_state,#0x03
                                   1156 ;	src/main.c:224: break;
      000333 02 04 A8         [24] 1157 	ljmp	00131$
                                   1158 ;	src/main.c:225: case SMB_STATE_WR2:        SMB0DAT = smb_data_out[1]; 
      000336                       1159 00104$:
      000336 85 58 C2         [24] 1160 	mov	_SMB0DAT,(_smb_data_out + 0x0001)
                                   1161 ;	src/main.c:226: mpu_state = SMB_STATE_WR1;
      000339 75 5C 01         [24] 1162 	mov	_mpu_state,#0x01
                                   1163 ;	src/main.c:227: break;
      00033C 02 04 A8         [24] 1164 	ljmp	00131$
                                   1165 ;	src/main.c:228: case SMB_STATE_WR1:        SMB0DAT = smb_data_out[0]; 
      00033F                       1166 00105$:
      00033F 85 57 C2         [24] 1167 	mov	_SMB0DAT,_smb_data_out
                                   1168 ;	src/main.c:229: mpu_state = SMB_STATE_WR_STOP;
      000342 75 5C 00         [24] 1169 	mov	_mpu_state,#0x00
                                   1170 ;	src/main.c:230: break;
      000345 02 04 A8         [24] 1171 	ljmp	00131$
                                   1172 ;	src/main.c:231: case SMB_STATE_WR_STOP:    SMB0CN_STO = 1;   
      000348                       1173 00106$:
                                   1174 ;	assignBit
      000348 D2 C4            [12] 1175 	setb	_SMB0CN_STO
                                   1176 ;	src/main.c:232: smb_busy = 0;     
      00034A 75 59 00         [24] 1177 	mov	_smb_busy,#0x00
                                   1178 ;	src/main.c:234: }
      00034D 02 04 A8         [24] 1179 	ljmp	00131$
      000350                       1180 00110$:
                                   1181 ;	src/main.c:238: SMB0CN_STO = 1;               // Send STOP condition,followed
                                   1182 ;	assignBit
      000350 D2 C4            [12] 1183 	setb	_SMB0CN_STO
                                   1184 ;	src/main.c:239: SMB0CN_STA = 1;               // By a START 
                                   1185 ;	assignBit
      000352 D2 C5            [12] 1186 	setb	_SMB0CN_STA
                                   1187 ;	src/main.c:241: break;
      000354 02 04 A8         [24] 1188 	ljmp	00131$
                                   1189 ;	src/main.c:243: case SMB_MRDB:    switch(mpu_state){
      000357                       1190 00112$:
      000357 E5 5C            [12] 1191 	mov	a,_mpu_state
      000359 FF               [12] 1192 	mov	r7,a
      00035A 24 E2            [12] 1193 	add	a,#0xff - 0x1d
      00035C 50 03            [24] 1194 	jnc	00180$
      00035E 02 04 A8         [24] 1195 	ljmp	00131$
      000361                       1196 00180$:
      000361 EF               [12] 1197 	mov	a,r7
      000362 F5 F0            [12] 1198 	mov	b,a
      000364 24 0B            [12] 1199 	add	a,#(00181$-3-.)
      000366 83               [24] 1200 	movc	a,@a+pc
      000367 F5 82            [12] 1201 	mov	dpl,a
      000369 E5 F0            [12] 1202 	mov	a,b
      00036B 24 22            [12] 1203 	add	a,#(00182$-3-.)
      00036D 83               [24] 1204 	movc	a,@a+pc
      00036E F5 83            [12] 1205 	mov	dph,a
      000370 E4               [12] 1206 	clr	a
      000371 73               [24] 1207 	jmp	@a+dptr
      000372                       1208 00181$:
      000372 A8                    1209 	.db	00131$
      000373 A8                    1210 	.db	00131$
      000374 A8                    1211 	.db	00131$
      000375 9E                    1212 	.db	00127$
      000376 A8                    1213 	.db	00131$
      000377 A8                    1214 	.db	00131$
      000378 A8                    1215 	.db	00131$
      000379 A8                    1216 	.db	00131$
      00037A A8                    1217 	.db	00131$
      00037B A8                    1218 	.db	00131$
      00037C A8                    1219 	.db	00131$
      00037D A8                    1220 	.db	00131$
      00037E A8                    1221 	.db	00131$
      00037F A8                    1222 	.db	00131$
      000380 A8                    1223 	.db	00131$
      000381 A8                    1224 	.db	00131$
      000382 85                    1225 	.db	00126$
      000383 78                    1226 	.db	00125$
      000384 61                    1227 	.db	00124$
      000385 54                    1228 	.db	00123$
      000386 3D                    1229 	.db	00122$
      000387 30                    1230 	.db	00121$
      000388 28                    1231 	.db	00120$
      000389 20                    1232 	.db	00119$
      00038A 08                    1233 	.db	00118$
      00038B FA                    1234 	.db	00117$
      00038C E2                    1235 	.db	00116$
      00038D D4                    1236 	.db	00115$
      00038E BC                    1237 	.db	00114$
      00038F AE                    1238 	.db	00113$
      000390                       1239 00182$:
      000390 04                    1240 	.db	00131$>>8
      000391 04                    1241 	.db	00131$>>8
      000392 04                    1242 	.db	00131$>>8
      000393 04                    1243 	.db	00127$>>8
      000394 04                    1244 	.db	00131$>>8
      000395 04                    1245 	.db	00131$>>8
      000396 04                    1246 	.db	00131$>>8
      000397 04                    1247 	.db	00131$>>8
      000398 04                    1248 	.db	00131$>>8
      000399 04                    1249 	.db	00131$>>8
      00039A 04                    1250 	.db	00131$>>8
      00039B 04                    1251 	.db	00131$>>8
      00039C 04                    1252 	.db	00131$>>8
      00039D 04                    1253 	.db	00131$>>8
      00039E 04                    1254 	.db	00131$>>8
      00039F 04                    1255 	.db	00131$>>8
      0003A0 04                    1256 	.db	00126$>>8
      0003A1 04                    1257 	.db	00125$>>8
      0003A2 04                    1258 	.db	00124$>>8
      0003A3 04                    1259 	.db	00123$>>8
      0003A4 04                    1260 	.db	00122$>>8
      0003A5 04                    1261 	.db	00121$>>8
      0003A6 04                    1262 	.db	00120$>>8
      0003A7 04                    1263 	.db	00119$>>8
      0003A8 04                    1264 	.db	00118$>>8
      0003A9 03                    1265 	.db	00117$>>8
      0003AA 03                    1266 	.db	00116$>>8
      0003AB 03                    1267 	.db	00115$>>8
      0003AC 03                    1268 	.db	00114$>>8
      0003AD 03                    1269 	.db	00113$>>8
                                   1270 ;	src/main.c:244: case SMB_STATE_MPU13:   accel_x = SMB0DAT;
      0003AE                       1271 00113$:
      0003AE 85 C2 5F         [24] 1272 	mov	_accel_x,_SMB0DAT
      0003B1 75 60 00         [24] 1273 	mov	(_accel_x + 1),#0x00
                                   1274 ;	src/main.c:245: mpu_state = SMB_STATE_MPU12;
      0003B4 75 5C 1C         [24] 1275 	mov	_mpu_state,#0x1c
                                   1276 ;	src/main.c:246: SMB0CN_ACK = 1;         
                                   1277 ;	assignBit
      0003B7 D2 C1            [12] 1278 	setb	_SMB0CN_ACK
                                   1279 ;	src/main.c:247: break;
      0003B9 02 04 A8         [24] 1280 	ljmp	00131$
                                   1281 ;	src/main.c:248: case SMB_STATE_MPU12:   accel_x <<= 8;
      0003BC                       1282 00114$:
      0003BC 85 5F 60         [24] 1283 	mov	(_accel_x + 1),_accel_x
      0003BF 75 5F 00         [24] 1284 	mov	_accel_x,#0x00
                                   1285 ;	src/main.c:249: accel_x |= SMB0DAT;
      0003C2 AE C2            [24] 1286 	mov	r6,_SMB0DAT
      0003C4 7F 00            [12] 1287 	mov	r7,#0x00
      0003C6 EE               [12] 1288 	mov	a,r6
      0003C7 42 5F            [12] 1289 	orl	_accel_x,a
      0003C9 EF               [12] 1290 	mov	a,r7
      0003CA 42 60            [12] 1291 	orl	(_accel_x + 1),a
                                   1292 ;	src/main.c:250: mpu_state = SMB_STATE_MPU11;
      0003CC 75 5C 1B         [24] 1293 	mov	_mpu_state,#0x1b
                                   1294 ;	src/main.c:251: SMB0CN_ACK = 1;         
                                   1295 ;	assignBit
      0003CF D2 C1            [12] 1296 	setb	_SMB0CN_ACK
                                   1297 ;	src/main.c:252: break;
      0003D1 02 04 A8         [24] 1298 	ljmp	00131$
                                   1299 ;	src/main.c:253: case SMB_STATE_MPU11:   accel_y = SMB0DAT;
      0003D4                       1300 00115$:
      0003D4 85 C2 61         [24] 1301 	mov	_accel_y,_SMB0DAT
      0003D7 75 62 00         [24] 1302 	mov	(_accel_y + 1),#0x00
                                   1303 ;	src/main.c:254: mpu_state = SMB_STATE_MPU10;
      0003DA 75 5C 1A         [24] 1304 	mov	_mpu_state,#0x1a
                                   1305 ;	src/main.c:255: SMB0CN_ACK = 1;         
                                   1306 ;	assignBit
      0003DD D2 C1            [12] 1307 	setb	_SMB0CN_ACK
                                   1308 ;	src/main.c:256: break;
      0003DF 02 04 A8         [24] 1309 	ljmp	00131$
                                   1310 ;	src/main.c:257: case SMB_STATE_MPU10:   accel_y <<= 8;
      0003E2                       1311 00116$:
      0003E2 85 61 62         [24] 1312 	mov	(_accel_y + 1),_accel_y
      0003E5 75 61 00         [24] 1313 	mov	_accel_y,#0x00
                                   1314 ;	src/main.c:258: accel_y |= SMB0DAT;
      0003E8 AE C2            [24] 1315 	mov	r6,_SMB0DAT
      0003EA 7F 00            [12] 1316 	mov	r7,#0x00
      0003EC EE               [12] 1317 	mov	a,r6
      0003ED 42 61            [12] 1318 	orl	_accel_y,a
      0003EF EF               [12] 1319 	mov	a,r7
      0003F0 42 62            [12] 1320 	orl	(_accel_y + 1),a
                                   1321 ;	src/main.c:259: mpu_state = SMB_STATE_MPU09;
      0003F2 75 5C 19         [24] 1322 	mov	_mpu_state,#0x19
                                   1323 ;	src/main.c:260: SMB0CN_ACK = 1;         
                                   1324 ;	assignBit
      0003F5 D2 C1            [12] 1325 	setb	_SMB0CN_ACK
                                   1326 ;	src/main.c:261: break;
      0003F7 02 04 A8         [24] 1327 	ljmp	00131$
                                   1328 ;	src/main.c:262: case SMB_STATE_MPU09:   accel_z = SMB0DAT;
      0003FA                       1329 00117$:
      0003FA 85 C2 63         [24] 1330 	mov	_accel_z,_SMB0DAT
      0003FD 75 64 00         [24] 1331 	mov	(_accel_z + 1),#0x00
                                   1332 ;	src/main.c:263: mpu_state = SMB_STATE_MPU08;
      000400 75 5C 18         [24] 1333 	mov	_mpu_state,#0x18
                                   1334 ;	src/main.c:264: SMB0CN_ACK = 1;         
                                   1335 ;	assignBit
      000403 D2 C1            [12] 1336 	setb	_SMB0CN_ACK
                                   1337 ;	src/main.c:265: break;
      000405 02 04 A8         [24] 1338 	ljmp	00131$
                                   1339 ;	src/main.c:266: case SMB_STATE_MPU08:   accel_z <<= 8;
      000408                       1340 00118$:
      000408 85 63 64         [24] 1341 	mov	(_accel_z + 1),_accel_z
      00040B 75 63 00         [24] 1342 	mov	_accel_z,#0x00
                                   1343 ;	src/main.c:267: accel_z |= SMB0DAT;
      00040E AE C2            [24] 1344 	mov	r6,_SMB0DAT
      000410 7F 00            [12] 1345 	mov	r7,#0x00
      000412 EE               [12] 1346 	mov	a,r6
      000413 42 63            [12] 1347 	orl	_accel_z,a
      000415 EF               [12] 1348 	mov	a,r7
      000416 42 64            [12] 1349 	orl	(_accel_z + 1),a
                                   1350 ;	src/main.c:268: mpu_state = SMB_STATE_MPU07;
      000418 75 5C 17         [24] 1351 	mov	_mpu_state,#0x17
                                   1352 ;	src/main.c:269: SMB0CN_ACK = 1;         
                                   1353 ;	assignBit
      00041B D2 C1            [12] 1354 	setb	_SMB0CN_ACK
                                   1355 ;	src/main.c:270: break;
      00041D 02 04 A8         [24] 1356 	ljmp	00131$
                                   1357 ;	src/main.c:271: case SMB_STATE_MPU07:   mpu_state = SMB_STATE_MPU06;  // Throw away temp lower data
      000420                       1358 00119$:
      000420 75 5C 16         [24] 1359 	mov	_mpu_state,#0x16
                                   1360 ;	src/main.c:272: SMB0CN_ACK = 1;         
                                   1361 ;	assignBit
      000423 D2 C1            [12] 1362 	setb	_SMB0CN_ACK
                                   1363 ;	src/main.c:273: break;
      000425 02 04 A8         [24] 1364 	ljmp	00131$
                                   1365 ;	src/main.c:274: case SMB_STATE_MPU06:   mpu_state = SMB_STATE_MPU05;  // Throw awat temp higher data
      000428                       1366 00120$:
      000428 75 5C 15         [24] 1367 	mov	_mpu_state,#0x15
                                   1368 ;	src/main.c:275: SMB0CN_ACK = 1;         
                                   1369 ;	assignBit
      00042B D2 C1            [12] 1370 	setb	_SMB0CN_ACK
                                   1371 ;	src/main.c:276: break;
      00042D 02 04 A8         [24] 1372 	ljmp	00131$
                                   1373 ;	src/main.c:277: case SMB_STATE_MPU05:   gyro_x = SMB0DAT;
      000430                       1374 00121$:
      000430 85 C2 65         [24] 1375 	mov	_gyro_x,_SMB0DAT
      000433 75 66 00         [24] 1376 	mov	(_gyro_x + 1),#0x00
                                   1377 ;	src/main.c:278: mpu_state = SMB_STATE_MPU04;
      000436 75 5C 14         [24] 1378 	mov	_mpu_state,#0x14
                                   1379 ;	src/main.c:279: SMB0CN_ACK = 1;         
                                   1380 ;	assignBit
      000439 D2 C1            [12] 1381 	setb	_SMB0CN_ACK
                                   1382 ;	src/main.c:280: break;
                                   1383 ;	src/main.c:281: case SMB_STATE_MPU04:   gyro_x <<= 8;
      00043B 80 6B            [24] 1384 	sjmp	00131$
      00043D                       1385 00122$:
      00043D 85 65 66         [24] 1386 	mov	(_gyro_x + 1),_gyro_x
      000440 75 65 00         [24] 1387 	mov	_gyro_x,#0x00
                                   1388 ;	src/main.c:282: gyro_x |= SMB0DAT;
      000443 AE C2            [24] 1389 	mov	r6,_SMB0DAT
      000445 7F 00            [12] 1390 	mov	r7,#0x00
      000447 EE               [12] 1391 	mov	a,r6
      000448 42 65            [12] 1392 	orl	_gyro_x,a
      00044A EF               [12] 1393 	mov	a,r7
      00044B 42 66            [12] 1394 	orl	(_gyro_x + 1),a
                                   1395 ;	src/main.c:283: mpu_state = SMB_STATE_MPU03;
      00044D 75 5C 13         [24] 1396 	mov	_mpu_state,#0x13
                                   1397 ;	src/main.c:284: SMB0CN_ACK = 1;         
                                   1398 ;	assignBit
      000450 D2 C1            [12] 1399 	setb	_SMB0CN_ACK
                                   1400 ;	src/main.c:285: break;
                                   1401 ;	src/main.c:286: case SMB_STATE_MPU03:   gyro_y = SMB0DAT;
      000452 80 54            [24] 1402 	sjmp	00131$
      000454                       1403 00123$:
      000454 85 C2 67         [24] 1404 	mov	_gyro_y,_SMB0DAT
      000457 75 68 00         [24] 1405 	mov	(_gyro_y + 1),#0x00
                                   1406 ;	src/main.c:287: mpu_state = SMB_STATE_MPU02;
      00045A 75 5C 12         [24] 1407 	mov	_mpu_state,#0x12
                                   1408 ;	src/main.c:288: SMB0CN_ACK = 1;               
                                   1409 ;	assignBit
      00045D D2 C1            [12] 1410 	setb	_SMB0CN_ACK
                                   1411 ;	src/main.c:289: break;
                                   1412 ;	src/main.c:290: case SMB_STATE_MPU02:   gyro_y <<= 8;
      00045F 80 47            [24] 1413 	sjmp	00131$
      000461                       1414 00124$:
      000461 85 67 68         [24] 1415 	mov	(_gyro_y + 1),_gyro_y
      000464 75 67 00         [24] 1416 	mov	_gyro_y,#0x00
                                   1417 ;	src/main.c:291: gyro_y |= SMB0DAT;
      000467 AE C2            [24] 1418 	mov	r6,_SMB0DAT
      000469 7F 00            [12] 1419 	mov	r7,#0x00
      00046B EE               [12] 1420 	mov	a,r6
      00046C 42 67            [12] 1421 	orl	_gyro_y,a
      00046E EF               [12] 1422 	mov	a,r7
      00046F 42 68            [12] 1423 	orl	(_gyro_y + 1),a
                                   1424 ;	src/main.c:292: mpu_state = SMB_STATE_MPU01;
      000471 75 5C 11         [24] 1425 	mov	_mpu_state,#0x11
                                   1426 ;	src/main.c:293: SMB0CN_ACK = 1;               
                                   1427 ;	assignBit
      000474 D2 C1            [12] 1428 	setb	_SMB0CN_ACK
                                   1429 ;	src/main.c:294: break;
                                   1430 ;	src/main.c:295: case SMB_STATE_MPU01:   gyro_z = SMB0DAT;
      000476 80 30            [24] 1431 	sjmp	00131$
      000478                       1432 00125$:
      000478 85 C2 69         [24] 1433 	mov	_gyro_z,_SMB0DAT
      00047B 75 6A 00         [24] 1434 	mov	(_gyro_z + 1),#0x00
                                   1435 ;	src/main.c:296: mpu_state = SMB_STATE_MPU00;
      00047E 75 5C 10         [24] 1436 	mov	_mpu_state,#0x10
                                   1437 ;	src/main.c:297: SMB0CN_ACK = 1;                 
                                   1438 ;	assignBit
      000481 D2 C1            [12] 1439 	setb	_SMB0CN_ACK
                                   1440 ;	src/main.c:298: break;
                                   1441 ;	src/main.c:299: case SMB_STATE_MPU00:   gyro_z <<= 8;
      000483 80 23            [24] 1442 	sjmp	00131$
      000485                       1443 00126$:
      000485 85 69 6A         [24] 1444 	mov	(_gyro_z + 1),_gyro_z
      000488 75 69 00         [24] 1445 	mov	_gyro_z,#0x00
                                   1446 ;	src/main.c:300: gyro_z |= SMB0DAT;
      00048B AE C2            [24] 1447 	mov	r6,_SMB0DAT
      00048D 7F 00            [12] 1448 	mov	r7,#0x00
      00048F EE               [12] 1449 	mov	a,r6
      000490 42 69            [12] 1450 	orl	_gyro_z,a
      000492 EF               [12] 1451 	mov	a,r7
      000493 42 6A            [12] 1452 	orl	(_gyro_z + 1),a
                                   1453 ;	src/main.c:301: smb_busy = 0;                    
      000495 75 59 00         [24] 1454 	mov	_smb_busy,#0x00
                                   1455 ;	src/main.c:302: SMB0CN_ACK = 0;                  
                                   1456 ;	assignBit
      000498 C2 C1            [12] 1457 	clr	_SMB0CN_ACK
                                   1458 ;	src/main.c:303: SMB0CN_STO = 1;                  
                                   1459 ;	assignBit
      00049A D2 C4            [12] 1460 	setb	_SMB0CN_STO
                                   1461 ;	src/main.c:304: break;
                                   1462 ;	src/main.c:305: case SMB_STATE_RD_STOP: smb_data_in = SMB0DAT;
      00049C 80 0A            [24] 1463 	sjmp	00131$
      00049E                       1464 00127$:
      00049E 85 C2 56         [24] 1465 	mov	_smb_data_in,_SMB0DAT
                                   1466 ;	src/main.c:306: SMB0CN_ACK = 0;                  
                                   1467 ;	assignBit
      0004A1 C2 C1            [12] 1468 	clr	_SMB0CN_ACK
                                   1469 ;	src/main.c:307: SMB0CN_STO = 1;                  
                                   1470 ;	assignBit
      0004A3 D2 C4            [12] 1471 	setb	_SMB0CN_STO
                                   1472 ;	src/main.c:308: smb_busy = 0;
      0004A5 75 59 00         [24] 1473 	mov	_smb_busy,#0x00
                                   1474 ;	src/main.c:315: }  
      0004A8                       1475 00131$:
                                   1476 ;	src/main.c:316: SMB0CN_SI = 0; //Clear interrupt flag 
                                   1477 ;	assignBit
      0004A8 C2 C0            [12] 1478 	clr	_SMB0CN_SI
                                   1479 ;	src/main.c:317: }
      0004AA D0 D0            [24] 1480 	pop	psw
      0004AC D0 06            [24] 1481 	pop	ar6
      0004AE D0 07            [24] 1482 	pop	ar7
      0004B0 D0 83            [24] 1483 	pop	dph
      0004B2 D0 82            [24] 1484 	pop	dpl
      0004B4 D0 F0            [24] 1485 	pop	b
      0004B6 D0 E0            [24] 1486 	pop	acc
      0004B8 32               [24] 1487 	reti
                                   1488 ;	eliminated unneeded push/pop ar1
                                   1489 ;	eliminated unneeded push/pop ar0
                                   1490 ;------------------------------------------------------------
                                   1491 ;Allocation info for local variables in function 'smbReadMpuSensors'
                                   1492 ;------------------------------------------------------------
                                   1493 ;	src/main.c:319: void smbReadMpuSensors (void) {
                                   1494 ;	-----------------------------------------
                                   1495 ;	 function smbReadMpuSensors
                                   1496 ;	-----------------------------------------
      0004B9                       1497 _smbReadMpuSensors:
                                   1498 ;	src/main.c:320: while (smb_busy);             // Wait for bus to be free.
      0004B9                       1499 00101$:
      0004B9 E5 59            [12] 1500 	mov	a,_smb_busy
      0004BB 70 FC            [24] 1501 	jnz	00101$
                                   1502 ;	src/main.c:321: smb_target = SMB_TARGET_IMU;
      0004BD 75 55 D0         [24] 1503 	mov	_smb_target,#0xd0
                                   1504 ;	src/main.c:322: mpu_state = SMB_STATE_WR1;
      0004C0 75 5C 01         [24] 1505 	mov	_mpu_state,#0x01
                                   1506 ;	src/main.c:323: smb_data_out[0] = 0x3B;
      0004C3 75 57 3B         [24] 1507 	mov	_smb_data_out,#0x3b
                                   1508 ;	src/main.c:324: smb_busy = 1;                 // Claim SMBus (set to busy)  
      0004C6 75 59 01         [24] 1509 	mov	_smb_busy,#0x01
                                   1510 ;	src/main.c:325: smb_rnw = 0;                  // Mark this transfer as a WRITE
      0004C9 75 5A 00         [24] 1511 	mov	_smb_rnw,#0x00
                                   1512 ;	src/main.c:326: SMB0CN_STA = 1;               // Start transfer 
                                   1513 ;	assignBit
      0004CC D2 C5            [12] 1514 	setb	_SMB0CN_STA
                                   1515 ;	src/main.c:327: while (smb_busy);             // Wait for bus to be free.
      0004CE                       1516 00104$:
      0004CE E5 59            [12] 1517 	mov	a,_smb_busy
      0004D0 70 FC            [24] 1518 	jnz	00104$
                                   1519 ;	src/main.c:328: mpu_state = SMB_STATE_MPU13; 
      0004D2 75 5C 1D         [24] 1520 	mov	_mpu_state,#0x1d
                                   1521 ;	src/main.c:329: smb_busy = 1;                 // Claim SMBus (set to busy)  
      0004D5 75 59 01         [24] 1522 	mov	_smb_busy,#0x01
                                   1523 ;	src/main.c:330: smb_rnw = 1;                  // Mark this transfer as a WRITE
      0004D8 75 5A 01         [24] 1524 	mov	_smb_rnw,#0x01
                                   1525 ;	src/main.c:331: SMB0CN_STA = 1;               // Start transfer  
                                   1526 ;	assignBit
      0004DB D2 C5            [12] 1527 	setb	_SMB0CN_STA
                                   1528 ;	src/main.c:332: }
      0004DD 22               [24] 1529 	ret
                                   1530 ;------------------------------------------------------------
                                   1531 ;Allocation info for local variables in function 'smbRead'
                                   1532 ;------------------------------------------------------------
                                   1533 ;addr                      Allocated with name '_smbRead_PARM_2'
                                   1534 ;target                    Allocated to registers r7 
                                   1535 ;------------------------------------------------------------
                                   1536 ;	src/main.c:334: U8 smbRead (U8 target, U8 addr){
                                   1537 ;	-----------------------------------------
                                   1538 ;	 function smbRead
                                   1539 ;	-----------------------------------------
      0004DE                       1540 _smbRead:
      0004DE AF 82            [24] 1541 	mov	r7,dpl
                                   1542 ;	src/main.c:335: while (smb_busy);          // Wait for bus to be free.
      0004E0                       1543 00101$:
      0004E0 E5 59            [12] 1544 	mov	a,_smb_busy
      0004E2 70 FC            [24] 1545 	jnz	00101$
                                   1546 ;	src/main.c:336: smb_target = target;
      0004E4 8F 55            [24] 1547 	mov	_smb_target,r7
                                   1548 ;	src/main.c:337: mpu_state = SMB_STATE_WR1;
      0004E6 75 5C 01         [24] 1549 	mov	_mpu_state,#0x01
                                   1550 ;	src/main.c:338: smb_data_out[0] = addr;
      0004E9 85 08 57         [24] 1551 	mov	_smb_data_out,_smbRead_PARM_2
                                   1552 ;	src/main.c:339: smb_busy = 1;              // Claim SMBus (set to busy)  
      0004EC 75 59 01         [24] 1553 	mov	_smb_busy,#0x01
                                   1554 ;	src/main.c:340: smb_rnw = 0;               // Mark this transfer as a WRITE
      0004EF 75 5A 00         [24] 1555 	mov	_smb_rnw,#0x00
                                   1556 ;	src/main.c:341: SMB0CN_STA = 1;            // Start transfer 
                                   1557 ;	assignBit
      0004F2 D2 C5            [12] 1558 	setb	_SMB0CN_STA
                                   1559 ;	src/main.c:342: while (smb_busy);          // Wait for bus to be free.
      0004F4                       1560 00104$:
      0004F4 E5 59            [12] 1561 	mov	a,_smb_busy
      0004F6 70 FC            [24] 1562 	jnz	00104$
                                   1563 ;	src/main.c:343: mpu_state = SMB_STATE_RD1; 
      0004F8 75 5C 04         [24] 1564 	mov	_mpu_state,#0x04
                                   1565 ;	src/main.c:344: smb_busy = 1;              // Claim SMBus (set to busy)  
      0004FB 75 59 01         [24] 1566 	mov	_smb_busy,#0x01
                                   1567 ;	src/main.c:345: smb_rnw = 1;               // Mark this transfer as a WRITE
      0004FE 75 5A 01         [24] 1568 	mov	_smb_rnw,#0x01
                                   1569 ;	src/main.c:346: SMB0CN_STA = 1;            // Start transfer 
                                   1570 ;	assignBit
      000501 D2 C5            [12] 1571 	setb	_SMB0CN_STA
                                   1572 ;	src/main.c:347: while (smb_busy);
      000503                       1573 00107$:
      000503 E5 59            [12] 1574 	mov	a,_smb_busy
      000505 70 FC            [24] 1575 	jnz	00107$
                                   1576 ;	src/main.c:348: return smb_data_in;
      000507 85 56 82         [24] 1577 	mov	dpl,_smb_data_in
                                   1578 ;	src/main.c:349: }
      00050A 22               [24] 1579 	ret
                                   1580 ;------------------------------------------------------------
                                   1581 ;Allocation info for local variables in function 'smbWrite'
                                   1582 ;------------------------------------------------------------
                                   1583 ;addr                      Allocated with name '_smbWrite_PARM_2'
                                   1584 ;data                      Allocated with name '_smbWrite_PARM_3'
                                   1585 ;target                    Allocated to registers r7 
                                   1586 ;------------------------------------------------------------
                                   1587 ;	src/main.c:351: void smbWrite (U8 target, U8 addr, U8 data){
                                   1588 ;	-----------------------------------------
                                   1589 ;	 function smbWrite
                                   1590 ;	-----------------------------------------
      00050B                       1591 _smbWrite:
      00050B AF 82            [24] 1592 	mov	r7,dpl
                                   1593 ;	src/main.c:352: while(smb_busy);
      00050D                       1594 00101$:
      00050D E5 59            [12] 1595 	mov	a,_smb_busy
      00050F 70 FC            [24] 1596 	jnz	00101$
                                   1597 ;	src/main.c:353: smb_target = target;
      000511 8F 55            [24] 1598 	mov	_smb_target,r7
                                   1599 ;	src/main.c:354: mpu_state = SMB_STATE_WR2;
      000513 75 5C 02         [24] 1600 	mov	_mpu_state,#0x02
                                   1601 ;	src/main.c:355: smb_data_out[1] = addr;
      000516 85 08 58         [24] 1602 	mov	(_smb_data_out + 0x0001),_smbWrite_PARM_2
                                   1603 ;	src/main.c:356: smb_data_out[0] = data;
      000519 85 09 57         [24] 1604 	mov	_smb_data_out,_smbWrite_PARM_3
                                   1605 ;	src/main.c:357: smb_busy = 1;              // Claim SMBus (set to busy)  
      00051C 75 59 01         [24] 1606 	mov	_smb_busy,#0x01
                                   1607 ;	src/main.c:358: smb_rnw = 0;               // Mark this transfer as a WRITE
      00051F 75 5A 00         [24] 1608 	mov	_smb_rnw,#0x00
                                   1609 ;	src/main.c:359: SMB0CN_STA = 1;            // Start transfer 
                                   1610 ;	assignBit
      000522 D2 C5            [12] 1611 	setb	_SMB0CN_STA
                                   1612 ;	src/main.c:360: }
      000524 22               [24] 1613 	ret
                                   1614 ;------------------------------------------------------------
                                   1615 ;Allocation info for local variables in function 'uartTx'
                                   1616 ;------------------------------------------------------------
                                   1617 ;tx                        Allocated to registers r7 
                                   1618 ;------------------------------------------------------------
                                   1619 ;	src/main.c:366: void uartTx(U8 tx){ 
                                   1620 ;	-----------------------------------------
                                   1621 ;	 function uartTx
                                   1622 ;	-----------------------------------------
      000525                       1623 _uartTx:
      000525 AF 82            [24] 1624 	mov	r7,dpl
                                   1625 ;	src/main.c:367: uart_buf[uart_head] = tx;
      000527 E5 53            [12] 1626 	mov	a,_uart_head
      000529 24 21            [12] 1627 	add	a,#_uart_buf
      00052B F8               [12] 1628 	mov	r0,a
      00052C A6 07            [24] 1629 	mov	@r0,ar7
                                   1630 ;	src/main.c:368: uart_head++;
      00052E 05 53            [12] 1631 	inc	_uart_head
                                   1632 ;	src/main.c:369: uart_head %= UART_BUF_SIZE;
      000530 AE 53            [24] 1633 	mov	r6,_uart_head
      000532 7F 00            [12] 1634 	mov	r7,#0x00
      000534 75 08 32         [24] 1635 	mov	__modsint_PARM_2,#0x32
                                   1636 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      000537 8F 09            [24] 1637 	mov	(__modsint_PARM_2 + 1),r7
      000539 8E 82            [24] 1638 	mov	dpl,r6
      00053B 8F 83            [24] 1639 	mov	dph,r7
      00053D 12 05 FD         [24] 1640 	lcall	__modsint
      000540 AE 82            [24] 1641 	mov	r6,dpl
      000542 8E 53            [24] 1642 	mov	_uart_head,r6
                                   1643 ;	src/main.c:370: }
      000544 22               [24] 1644 	ret
                                   1645 ;------------------------------------------------------------
                                   1646 ;Allocation info for local variables in function 'uartEmpty'
                                   1647 ;------------------------------------------------------------
                                   1648 ;	src/main.c:372: U8 uartEmpty(void){ 
                                   1649 ;	-----------------------------------------
                                   1650 ;	 function uartEmpty
                                   1651 ;	-----------------------------------------
      000545                       1652 _uartEmpty:
                                   1653 ;	src/main.c:373: if(uart_head == uart_tail){
      000545 E5 54            [12] 1654 	mov	a,_uart_tail
      000547 B5 53 04         [24] 1655 	cjne	a,_uart_head,00102$
                                   1656 ;	src/main.c:374: return 1;
      00054A 75 82 01         [24] 1657 	mov	dpl,#0x01
      00054D 22               [24] 1658 	ret
      00054E                       1659 00102$:
                                   1660 ;	src/main.c:376: return 0;
      00054E 75 82 00         [24] 1661 	mov	dpl,#0x00
                                   1662 ;	src/main.c:378: }
      000551 22               [24] 1663 	ret
                                   1664 ;------------------------------------------------------------
                                   1665 ;Allocation info for local variables in function 'setup'
                                   1666 ;------------------------------------------------------------
                                   1667 ;	src/main.c:384: void setup(void){
                                   1668 ;	-----------------------------------------
                                   1669 ;	 function setup
                                   1670 ;	-----------------------------------------
      000552                       1671 _setup:
                                   1672 ;	src/main.c:387: WDTCN    = 0xDE;
      000552 75 97 DE         [24] 1673 	mov	_WDTCN,#0xde
                                   1674 ;	src/main.c:388: WDTCN    = 0xAD;
      000555 75 97 AD         [24] 1675 	mov	_WDTCN,#0xad
                                   1676 ;	src/main.c:391: CLKSEL_CLKDIV__SYSCLK_DIV_1; 
      000558 75 A9 00         [24] 1677 	mov	_CLKSEL,#0x00
                                   1678 ;	src/main.c:399: P0SKIP_B7__SKIPPED;
      00055B 75 D4 CF         [24] 1679 	mov	_P0SKIP,#0xcf
                                   1680 ;	src/main.c:408: P1MDOUT_B7__OPEN_DRAIN;
      00055E 75 A5 10         [24] 1681 	mov	_P1MDOUT,#0x10
                                   1682 ;	src/main.c:415: P1SKIP_B5__SKIPPED;
      000561 75 D5 3F         [24] 1683 	mov	_P1SKIP,#0x3f
                                   1684 ;	src/main.c:418: XBR0_URT0E__ENABLED; 
      000564 75 E1 05         [24] 1685 	mov	_XBR0,#0x05
                                   1686 ;	src/main.c:420: XBR2_XBARE__ENABLED;
      000567 75 E3 C0         [24] 1687 	mov	_XBR2,#0xc0
                                   1688 ;	src/main.c:423: SCON0    = SCON0_REN__RECEIVE_ENABLED;
      00056A 75 98 10         [24] 1689 	mov	_SCON0,#0x10
                                   1690 ;	src/main.c:428: CKCON_T2MH__EXTERNAL_CLOCK;
      00056D 75 8E 08         [24] 1691 	mov	_CKCON,#0x08
                                   1692 ;	src/main.c:430: TMR2CN   = TMR2CN_T2XCLK__SYSCLK_DIV_12;
      000570 75 C8 00         [24] 1693 	mov	_TMR2CN,#0x00
                                   1694 ;	src/main.c:435: TMOD_T1M__MODE2;
      000573 75 89 22         [24] 1695 	mov	_TMOD,#0x22
                                   1696 ;	src/main.c:437: TCON_TR1__RUN; 
      000576 75 88 50         [24] 1697 	mov	_TCON,#0x50
                                   1698 ;	src/main.c:438: TH0      = 0xF5;  // 60KHz 
      000579 75 8C F5         [24] 1699 	mov	_TH0,#0xf5
                                   1700 ;	src/main.c:439: TL0      = 0x80;
      00057C 75 8A 80         [24] 1701 	mov	_TL0,#0x80
                                   1702 ;	src/main.c:440: TH1      = 0x96;  // Magic values from datasheet for 115200
      00057F 75 8D 96         [24] 1703 	mov	_TH1,#0x96
                                   1704 ;	src/main.c:441: TL1      = 0x96; 
      000582 75 8B 96         [24] 1705 	mov	_TL1,#0x96
                                   1706 ;	src/main.c:444: TMR2CN   = TMR2CN_TR2__RUN; 
      000585 75 C8 04         [24] 1707 	mov	_TMR2CN,#0x04
                                   1708 ;	src/main.c:445: TMR2L    = 0x00;
      000588 75 CC 00         [24] 1709 	mov	_TMR2L,#0x00
                                   1710 ;	src/main.c:446: TMR2H    = 0xD8;
      00058B 75 CD D8         [24] 1711 	mov	_TMR2H,#0xd8
                                   1712 ;	src/main.c:447: TMR2RLL  = 0x00;
      00058E 75 CA 00         [24] 1713 	mov	_TMR2RLL,#0x00
                                   1714 ;	src/main.c:448: TMR2RLH  = 0xD8;  // 200Hz/5ms 
      000591 75 CB D8         [24] 1715 	mov	_TMR2RLH,#0xd8
                                   1716 ;	src/main.c:451: TMR3CN   = TMR3CN_TR3__RUN; 
      000594 75 91 04         [24] 1717 	mov	_TMR3CN,#0x04
                                   1718 ;	src/main.c:452: TMR3L    = 0x00;
      000597 75 94 00         [24] 1719 	mov	_TMR3L,#0x00
                                   1720 ;	src/main.c:453: TMR3H    = 0xFC;
      00059A 75 95 FC         [24] 1721 	mov	_TMR3H,#0xfc
                                   1722 ;	src/main.c:454: TMR3RLL  = 0x00;
      00059D 75 92 00         [24] 1723 	mov	_TMR3RLL,#0x00
                                   1724 ;	src/main.c:455: TMR3RLH  = 0xFC;  // 2KHz/0.5ms       
      0005A0 75 93 FC         [24] 1725 	mov	_TMR3RLH,#0xfc
                                   1726 ;	src/main.c:461: SMB0CF_ENSMB__ENABLED; 
      0005A3 75 C1 C4         [24] 1727 	mov	_SMB0CF,#0xc4
                                   1728 ;	src/main.c:463: SMB0TC   = SMB0TC_SDD__ADD_8_SYSCLKS;
      0005A6 75 AC 03         [24] 1729 	mov	_SMB0TC,#0x03
                                   1730 ;	src/main.c:468: IE_ET2__ENABLED;
      0005A9 75 A8 B0         [24] 1731 	mov	_IE,#0xb0
                                   1732 ;	src/main.c:470: EIE1_ET3__ENABLED;
      0005AC 75 E6 81         [24] 1733 	mov	_EIE1,#0x81
                                   1734 ;	src/main.c:471: }
      0005AF 22               [24] 1735 	ret
                                   1736 	.area CSEG    (CODE)
                                   1737 	.area CONST   (CODE)
                                   1738 	.area XINIT   (CODE)
                                   1739 	.area CABS    (ABS,CODE)
