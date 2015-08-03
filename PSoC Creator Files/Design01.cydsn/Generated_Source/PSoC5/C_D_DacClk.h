/*******************************************************************************
* File Name: C_D_DacClk.h
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

#if !defined(CY_CLOCK_C_D_DacClk_H)
#define CY_CLOCK_C_D_DacClk_H

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

void C_D_DacClk_Start(void) ;
void C_D_DacClk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void C_D_DacClk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void C_D_DacClk_StandbyPower(uint8 state) ;
void C_D_DacClk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 C_D_DacClk_GetDividerRegister(void) ;
void C_D_DacClk_SetModeRegister(uint8 modeBitMask) ;
void C_D_DacClk_ClearModeRegister(uint8 modeBitMask) ;
uint8 C_D_DacClk_GetModeRegister(void) ;
void C_D_DacClk_SetSourceRegister(uint8 clkSource) ;
uint8 C_D_DacClk_GetSourceRegister(void) ;
#if defined(C_D_DacClk__CFG3)
void C_D_DacClk_SetPhaseRegister(uint8 clkPhase) ;
uint8 C_D_DacClk_GetPhaseRegister(void) ;
#endif /* defined(C_D_DacClk__CFG3) */

#define C_D_DacClk_Enable()                       C_D_DacClk_Start()
#define C_D_DacClk_Disable()                      C_D_DacClk_Stop()
#define C_D_DacClk_SetDivider(clkDivider)         C_D_DacClk_SetDividerRegister(clkDivider, 1u)
#define C_D_DacClk_SetDividerValue(clkDivider)    C_D_DacClk_SetDividerRegister((clkDivider) - 1u, 1u)
#define C_D_DacClk_SetMode(clkMode)               C_D_DacClk_SetModeRegister(clkMode)
#define C_D_DacClk_SetSource(clkSource)           C_D_DacClk_SetSourceRegister(clkSource)
#if defined(C_D_DacClk__CFG3)
#define C_D_DacClk_SetPhase(clkPhase)             C_D_DacClk_SetPhaseRegister(clkPhase)
#define C_D_DacClk_SetPhaseValue(clkPhase)        C_D_DacClk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(C_D_DacClk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define C_D_DacClk_CLKEN              (* (reg8 *) C_D_DacClk__PM_ACT_CFG)
#define C_D_DacClk_CLKEN_PTR          ((reg8 *) C_D_DacClk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define C_D_DacClk_CLKSTBY            (* (reg8 *) C_D_DacClk__PM_STBY_CFG)
#define C_D_DacClk_CLKSTBY_PTR        ((reg8 *) C_D_DacClk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define C_D_DacClk_DIV_LSB            (* (reg8 *) C_D_DacClk__CFG0)
#define C_D_DacClk_DIV_LSB_PTR        ((reg8 *) C_D_DacClk__CFG0)
#define C_D_DacClk_DIV_PTR            ((reg16 *) C_D_DacClk__CFG0)

/* Clock MSB divider configuration register. */
#define C_D_DacClk_DIV_MSB            (* (reg8 *) C_D_DacClk__CFG1)
#define C_D_DacClk_DIV_MSB_PTR        ((reg8 *) C_D_DacClk__CFG1)

/* Mode and source configuration register */
#define C_D_DacClk_MOD_SRC            (* (reg8 *) C_D_DacClk__CFG2)
#define C_D_DacClk_MOD_SRC_PTR        ((reg8 *) C_D_DacClk__CFG2)

#if defined(C_D_DacClk__CFG3)
/* Analog clock phase configuration register */
#define C_D_DacClk_PHASE              (* (reg8 *) C_D_DacClk__CFG3)
#define C_D_DacClk_PHASE_PTR          ((reg8 *) C_D_DacClk__CFG3)
#endif /* defined(C_D_DacClk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define C_D_DacClk_CLKEN_MASK         C_D_DacClk__PM_ACT_MSK
#define C_D_DacClk_CLKSTBY_MASK       C_D_DacClk__PM_STBY_MSK

/* CFG2 field masks */
#define C_D_DacClk_SRC_SEL_MSK        C_D_DacClk__CFG2_SRC_SEL_MASK
#define C_D_DacClk_MODE_MASK          (~(C_D_DacClk_SRC_SEL_MSK))

#if defined(C_D_DacClk__CFG3)
/* CFG3 phase mask */
#define C_D_DacClk_PHASE_MASK         C_D_DacClk__CFG3_PHASE_DLY_MASK
#endif /* defined(C_D_DacClk__CFG3) */

#endif /* CY_CLOCK_C_D_DacClk_H */


/* [] END OF FILE */
