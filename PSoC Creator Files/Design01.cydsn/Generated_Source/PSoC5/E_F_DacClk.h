/*******************************************************************************
* File Name: E_F_DacClk.h
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

#if !defined(CY_CLOCK_E_F_DacClk_H)
#define CY_CLOCK_E_F_DacClk_H

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

void E_F_DacClk_Start(void) ;
void E_F_DacClk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void E_F_DacClk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void E_F_DacClk_StandbyPower(uint8 state) ;
void E_F_DacClk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 E_F_DacClk_GetDividerRegister(void) ;
void E_F_DacClk_SetModeRegister(uint8 modeBitMask) ;
void E_F_DacClk_ClearModeRegister(uint8 modeBitMask) ;
uint8 E_F_DacClk_GetModeRegister(void) ;
void E_F_DacClk_SetSourceRegister(uint8 clkSource) ;
uint8 E_F_DacClk_GetSourceRegister(void) ;
#if defined(E_F_DacClk__CFG3)
void E_F_DacClk_SetPhaseRegister(uint8 clkPhase) ;
uint8 E_F_DacClk_GetPhaseRegister(void) ;
#endif /* defined(E_F_DacClk__CFG3) */

#define E_F_DacClk_Enable()                       E_F_DacClk_Start()
#define E_F_DacClk_Disable()                      E_F_DacClk_Stop()
#define E_F_DacClk_SetDivider(clkDivider)         E_F_DacClk_SetDividerRegister(clkDivider, 1u)
#define E_F_DacClk_SetDividerValue(clkDivider)    E_F_DacClk_SetDividerRegister((clkDivider) - 1u, 1u)
#define E_F_DacClk_SetMode(clkMode)               E_F_DacClk_SetModeRegister(clkMode)
#define E_F_DacClk_SetSource(clkSource)           E_F_DacClk_SetSourceRegister(clkSource)
#if defined(E_F_DacClk__CFG3)
#define E_F_DacClk_SetPhase(clkPhase)             E_F_DacClk_SetPhaseRegister(clkPhase)
#define E_F_DacClk_SetPhaseValue(clkPhase)        E_F_DacClk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(E_F_DacClk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define E_F_DacClk_CLKEN              (* (reg8 *) E_F_DacClk__PM_ACT_CFG)
#define E_F_DacClk_CLKEN_PTR          ((reg8 *) E_F_DacClk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define E_F_DacClk_CLKSTBY            (* (reg8 *) E_F_DacClk__PM_STBY_CFG)
#define E_F_DacClk_CLKSTBY_PTR        ((reg8 *) E_F_DacClk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define E_F_DacClk_DIV_LSB            (* (reg8 *) E_F_DacClk__CFG0)
#define E_F_DacClk_DIV_LSB_PTR        ((reg8 *) E_F_DacClk__CFG0)
#define E_F_DacClk_DIV_PTR            ((reg16 *) E_F_DacClk__CFG0)

/* Clock MSB divider configuration register. */
#define E_F_DacClk_DIV_MSB            (* (reg8 *) E_F_DacClk__CFG1)
#define E_F_DacClk_DIV_MSB_PTR        ((reg8 *) E_F_DacClk__CFG1)

/* Mode and source configuration register */
#define E_F_DacClk_MOD_SRC            (* (reg8 *) E_F_DacClk__CFG2)
#define E_F_DacClk_MOD_SRC_PTR        ((reg8 *) E_F_DacClk__CFG2)

#if defined(E_F_DacClk__CFG3)
/* Analog clock phase configuration register */
#define E_F_DacClk_PHASE              (* (reg8 *) E_F_DacClk__CFG3)
#define E_F_DacClk_PHASE_PTR          ((reg8 *) E_F_DacClk__CFG3)
#endif /* defined(E_F_DacClk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define E_F_DacClk_CLKEN_MASK         E_F_DacClk__PM_ACT_MSK
#define E_F_DacClk_CLKSTBY_MASK       E_F_DacClk__PM_STBY_MSK

/* CFG2 field masks */
#define E_F_DacClk_SRC_SEL_MSK        E_F_DacClk__CFG2_SRC_SEL_MASK
#define E_F_DacClk_MODE_MASK          (~(E_F_DacClk_SRC_SEL_MSK))

#if defined(E_F_DacClk__CFG3)
/* CFG3 phase mask */
#define E_F_DacClk_PHASE_MASK         E_F_DacClk__CFG3_PHASE_DLY_MASK
#endif /* defined(E_F_DacClk__CFG3) */

#endif /* CY_CLOCK_E_F_DacClk_H */


/* [] END OF FILE */
