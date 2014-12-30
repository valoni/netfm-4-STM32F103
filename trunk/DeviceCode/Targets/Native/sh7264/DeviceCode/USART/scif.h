/***************************************************************************
* Tabs 5 9
* The carets in the following lines will match up if tabs are set properly
*   ^   ^   ^   ^   ^   ^   <== tabs
*   ^   ^   ^   ^   ^   ^   <== spaces
***************************************************************************/

////////////////////////////////////////////////////////////////////////////
//  Author:         Brandon Wong
//  Module:         SCIF
//  Version:        0.00
//  File:           scif.h
//  Creation Date:  3/7/2005 6:13PM
//  Last Modified:  3/7/2005 7:00PM
//
//  Summary:        
//
//  Version:        Note:
//  --------        --------------------------------------------------------
//  1.0             Created to make the commsh3.c a little more flexible
////////////////////////////////////////////////////////////////////////////

#ifndef     __SCIF_H__
#define     __SCIF_H__ 1

    
    // SCSMR
    #define SCIF_SMR_CA         (0x0080)
    #define SCIF_SMR_CHR        (0x0040)
    #define SCIF_SMR_PE         (0x0020)
    #define SCIF_SMR_OE         (0x0010)
    #define SCIF_SMR_STOP       (0x0008)
    #define SCIF_SMR_CKS1       (0x0002)
    #define SCIF_SMR_CKS0       (0x0001)
    
    // SCSCR
    #define SCIF_SCR_TIE        (0x0080)
    #define SCIF_SCR_RIE        (0x0040)
    #define SCIF_SCR_TE         (0x0020)
    #define SCIF_SCR_RE         (0x0010)
    #define SCIF_SCR_REIE       (0x0008)
    #define SCIF_SCR_CKE1       (0x0002)
    #define SCIF_SCR_CKE0       (0x0001)
    
    // SCFSR
    #define SCIF_SR_ER          (0x0080)
    #define SCIF_SR_TEND        (0x0040)
    #define SCIF_SR_TDFE        (0x0020)
    #define SCIF_SR_BRK         (0x0010)
    #define SCIF_SR_FER         (0x0008)
    #define SCIF_SR_PER         (0x0004)
    #define SCIF_SR_RDF         (0x0002)
    #define SCIF_SR_DR          (0x0001)
    
    // SCFCR
    #define SCIF_CR_RSTRG2      (0x0400)
    #define SCIF_CR_RSTRG1      (0x0200)
    #define SCIF_CR_RSTRG0      (0x0100)
    #define SCIF_CR_RTRG1       (0x0080)
    #define SCIF_CR_RTRG0       (0x0040)
    #define SCIF_CR_TTRG1       (0x0020)
    #define SCIF_CR_TTRG0       (0x0010)
    #define SCIF_CR_MCE         (0x0008)
    #define SCIF_CR_TFRST       (0x0004)
    #define SCIF_CR_RFRST       (0x0002)
    #define SCIF_CR_LOOP        (0x0001)
    
    // SCSPTR
    #define SCIF_PTR_RTSIO      (0x0080)
    #define SCIF_PTR_RTSDT      (0x0040)
    #define SCIF_PTR_CTSIO      (0x0020)
    #define SCIF_PTR_CTSDT      (0x0010)
    #define SCIF_PTR_SCKIO      (0x0008)
    #define SCIF_PTR_SCKDT      (0x0004)
    #define SCIF_PTR_SPBIO      (0x0002)
    #define SCIF_PTR_SPBDT      (0x0001)
    
    // SCLSR
    #define SCIF_LSR_ORER       (0x0001)

    typedef struct
    {
        volatile UINT16 smr;              // 0x00
        volatile UINT16 _reserved0;       // 0x02
        volatile UINT8  brr;              // 0x04
        volatile UINT8  _reserved1[3];    // 0x05 - 0x07
        volatile UINT16 scr;              // 0x08
        volatile UINT16 _reserved2;       // 0x0A
        volatile UINT8  tdr;              // 0x0C
        volatile UINT8  _reserved3[3];    // 0x0D - 0x0F
        volatile UINT16 sr;               // 0x10
        volatile UINT16 _reserved4;       // 0x12
        volatile UINT8  rdr;              // 0x14
        volatile UINT8  _reserved5[3];    // 0x15 - 0x17
        volatile UINT16 fcr;              // 0x18
        volatile UINT16 _reserved6;       // 0x1A
        volatile UINT16 fdr;              // 0x1C
        volatile UINT16 _reserved7;       // 0x1E
        volatile UINT16 sptr;             // 0x20
        volatile UINT16 _reserved8;       // 0x22
        volatile UINT16 lsr;              // 0x24
//      volatile UINT32 * _reserved9[0x3F6]   // 0x26 - 0x0FFC
    }scif_t;

/*///////////////////////////////////////////////////////////////////////////*/
/* Baud rate generator macros*/
/*///////////////////////////////////////////////////////////////////////////*/

/*  CKS 1:0 :   00  01  10  11*/
/*----------------------------*/
/*      cks :   0.5 2   8   32*/

#define cks .5  // 2^(2*n-1).. with n = 0
#define MHZ         144

#define ckf ( (unsigned)((float)64*cks) )
//#define ckf ( (unsigned)((float)8*cks) )      // Biscayne Changed Multiplier from 64 to 8 - synchronous

#define BRR_CALC(bps) (  (unsigned)(  ( pClock / (ckf*bps) )-1  )   )

#define xtal ( (float)MHZ*1e6 )

//#define pClock ((unsigned long)xtal)
#define pClock ((unsigned long)(xtal/2))    // pclock is half the bus speed


#endif