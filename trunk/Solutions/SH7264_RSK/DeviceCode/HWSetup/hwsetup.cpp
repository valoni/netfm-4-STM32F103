/***********************************************************************/
/*                                                                     */
/*  FILE        :hwsetup.cpp                                           */
/*  DATE        :Wed, Apr 22, 2009                                     */
/*  DESCRIPTION :Hardware Setup file                                   */
/*  CPU TYPE    :SH7264                                                */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.9).     */
/*                                                                     */
/***********************************************************************/


#include <machine.h>
#include <tinyhal.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void HardwareSetup(void);
#ifdef __cplusplus
}
#endif

#pragma section ResetPRG

#define SDRAM_MODE      (*(volatile unsigned short *)(0xfffc5040))

void HardwareSetup(void)
{
    long addr;
    /*====CPG setting====*/ 
    CPG.FRQCR.WORD = 0x1003;

    /* ---- The clock of all modules is permitted. ---- */
    CPG.STBCR3.BYTE = 0x02; 
                            
    CPG.STBCR4.BYTE = 0x00; 
    CPG.STBCR5.BYTE = 0x10; 
    CPG.STBCR6.BYTE = 0x02; 
    CPG.STBCR7.BYTE = 0x2a; 
    CPG.STBCR8.BYTE = 0x7e;     
    
    /*====CS0 initialization====*/  
    
    /* ==== PFC settings ==== */
    PORT.PBCR5.WORD = 0x0111;
    PORT.PCCR0.WORD = 0x1011;
    
    PORT.PDCR0.WORD = 0x1111;
    PORT.PDCR1.WORD = 0x1111;
    PORT.PDCR2.WORD = 0x1111;
    PORT.PDCR3.WORD = 0x1111;

    PORT.PBCR0.WORD = 0x1110;
    PORT.PBCR1.WORD = 0x1111;
    PORT.PBCR2.WORD = 0x1111;
    PORT.PBCR3.WORD = 0x1111;
    PORT.PBCR4.WORD = 0x1111;
    PORT.PBCR5.WORD = 0x0111;

    PORT.PJCR0.WORD = 0x0300;

    /* WDT setting */
    WDT.WTCSR.WORD = 0xA502;
    
    /* Cache setting */
    CCNT.CCR1.LONG = 0x00000909;

    /* ==== CS0WCR settings ====  */
    BSC.CS0WCR.NORMAL.LONG = 0x00000b41;
                                    
    /* ==== CS0BCR settings ==== */
    BSC.CS0BCR.LONG = 0x10000400;       
    
    /*====SDRAM area initialization====*/
    /* ==== PFC settings ==== */
    PORT.PCCR2.WORD = 0x0001;
    PORT.PCCR1.WORD = 0x1111;   
    PORT.PCCR0.WORD = 0x1111;   

    nop();
    nop();
    nop();
    nop();
    nop();

    /* ==== CS3BCR settings ==== */
    BSC.CS3BCR.LONG = 0x00004400;

    /* ==== CS3WCR settings ==== */
    BSC.CS3WCR.SDRAM.LONG = 0x0000288a;

    /* ==== SDCR settings ==== */
    BSC.SDCR.LONG = 0x00000812;
    

    /* ==== RTCOR settings ==== */
    BSC.RTCOR = 0xa55a0046;
    
    /* ==== RTCSR settings ==== */
    BSC.RTCSR.LONG = 0xa55a0010;    

    /* ==== Written in SDRAM Mode Register ==== */
    (*(volatile unsigned short *)(0xfffc5040)) = 0; 

    /*  RAM clear from 0c000000 to 0c0fffff */
    for (addr = 0x2C000000; addr<0x2C100000; addr+=4) (*(volatile long *)addr) = 0x00000000;
}