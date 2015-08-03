/******************************************************************************
* File Name: A_B_Wave2_DMA_dma.h  
* Version 1.70
*
*  Description:
*   Provides the function definitions for the DMA Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(CY_DMA_A_B_Wave2_DMA_DMA_H__)
#define CY_DMA_A_B_Wave2_DMA_DMA_H__



#include <CYDMAC.H>
#include <CYFITTER.H>

#define A_B_Wave2_DMA__TD_TERMOUT_EN (((0 != A_B_Wave2_DMA__TERMOUT0_EN) ? TD_TERMOUT0_EN : 0) | \
    (A_B_Wave2_DMA__TERMOUT1_EN ? TD_TERMOUT1_EN : 0))

/* Zero based index of A_B_Wave2_DMA dma channel */
extern uint8 A_B_Wave2_DMA_DmaHandle;


uint8 A_B_Wave2_DMA_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) ;
void  A_B_Wave2_DMA_DmaRelease(void) ;


/* CY_DMA_A_B_Wave2_DMA_DMA_H__ */
#endif
