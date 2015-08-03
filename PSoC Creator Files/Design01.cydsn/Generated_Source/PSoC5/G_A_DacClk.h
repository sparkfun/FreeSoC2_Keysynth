/*******************************************************************************
* File Name: G_A_DacClk.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_G_A_DacClk_H)
#define CY_CLOCK_G_A_DacClk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void G_A_DacClk_Start(void) ;
void G_A_DacClk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void G_A_DacClk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void G_A_DacClk_StandbyPower(uint8 state) ;
void G_A_DacClk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 G_A_DacClk_GetDividerRegister(void) ;
void G_A_DacClk_SetModeRegister(uint8 modeBitMask) ;
void G_A_DacClk_ClearModeRegister(uint8 modeBitMask) ;
uint8 G_A_DacClk_GetModeRegister(void) ;
void G_A_DacClk_SetSourceRegister(uint8 clkSource) ;
uint8 G_A_DacClk_GetSourceRegister(void) ;
#if defined(G_A_DacClk__CFG3)
void G_A_DacClk_SetPhaseRegister(uint8 clkPhase) ;
uint8 G_A_DacClk_GetPhaseRegister(void) ;
#endif /* defined(G_A_DacClk__CFG3) */

#define G_A_DacClk_Enable()                       G_A_DacClk_Start()
#define G_A_DacClk_Disable()                      G_A_DacClk_Stop()
#define G_A_DacClk_SetDivider(clkDivider)         G_A_DacClk_SetDividerRegister(clkDivider, 1u)
#define G_A_DacClk_SetDividerValue(clkDivider)    G_A_DacClk_SetDividerRegister((clkDivider) - 1u, 1u)
#define G_A_DacClk_SetMode(clkMode)               G_A_DacClk_SetModeRegister(clkMode)
#define G_A_DacClk_SetSource(clkSource)           G_A_DacClk_SetSourceRegister(clkSource)
#if defined(G_A_DacClk__CFG3)
#define G_A_DacClk_SetPhase(clkPhase)             G_A_DacClk_SetPhaseRegister(clkPhase)
#define G_A_DacClk_SetPhaseValue(clkPhase)        G_A_DacClk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(G_A_DacClk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define G_A_DacClk_CLKEN              (* (reg8 *) G_A_DacClk__PM_ACT_CFG)
#define G_A_DacClk_CLKEN_PTR          ((reg8 *) G_A_DacClk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define G_A_DacClk_CLKSTBY            (* (reg8 *) G_A_DacClk__PM_STBY_CFG)
#define G_A_DacClk_CLKSTBY_PTR        ((reg8 *) G_A_DacClk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define G_A_DacClk_DIV_LSB            (* (reg8 *) G_A_DacClk__CFG0)
#define G_A_DacClk_DIV_LSB_PTR        ((reg8 *) G_A_DacClk__CFG0)
#define G_A_DacClk_DIV_PTR            ((reg16 *) G_A_DacClk__CFG0)

/* Clock MSB divider configuration register. */
#define G_A_DacClk_DIV_MSB            (* (reg8 *) G_A_DacClk__CFG1)
#define G_A_DacClk_DIV_MSB_PTR        ((reg8 *) G_A_DacClk__CFG1)

/* Mode and source configuration register */
#define G_A_DacClk_MOD_SRC            (* (reg8 *) G_A_DacClk__CFG2)
#define G_A_DacClk_MOD_SRC_PTR        ((reg8 *) G_A_DacClk__CFG2)

#if defined(G_A_DacClk__CFG3)
/* Analog clock phase configuration register */
#define G_A_DacClk_PHASE              (* (reg8 *) G_A_DacClk__CFG3)
#define G_A_DacClk_PHASE_PTR          ((reg8 *) G_A_DacClk__CFG3)
#endif /* defined(G_A_DacClk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define G_A_DacClk_CLKEN_MASK         G_A_DacClk__PM_ACT_MSK
#define G_A_DacClk_CLKSTBY_MASK       G_A_DacClk__PM_STBY_MSK

/* CFG2 field masks */
#define G_A_DacClk_SRC_SEL_MSK        G_A_DacClk__CFG2_SRC_SEL_MASK
#define G_A_DacClk_MODE_MASK          (~(G_A_DacClk_SRC_SEL_MSK))

#if defined(G_A_DacClk__CFG3)
/* CFG3 phase mask */
#define G_A_DacClk_PHASE_MASK         G_A_DacClk__CFG3_PHASE_DLY_MASK
#endif /* defined(G_A_DacClk__CFG3) */

#endif /* CY_CLOCK_G_A_DacClk_H */


/* [] END OF FILE */
