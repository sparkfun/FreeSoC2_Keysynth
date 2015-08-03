/*******************************************************************************
* File Name: E_Key.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_E_Key_H) /* Pins E_Key_H */
#define CY_PINS_E_Key_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "E_Key_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 E_Key__PORT == 15 && ((E_Key__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    E_Key_Write(uint8 value) ;
void    E_Key_SetDriveMode(uint8 mode) ;
uint8   E_Key_ReadDataReg(void) ;
uint8   E_Key_Read(void) ;
uint8   E_Key_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define E_Key_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define E_Key_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define E_Key_DM_RES_UP          PIN_DM_RES_UP
#define E_Key_DM_RES_DWN         PIN_DM_RES_DWN
#define E_Key_DM_OD_LO           PIN_DM_OD_LO
#define E_Key_DM_OD_HI           PIN_DM_OD_HI
#define E_Key_DM_STRONG          PIN_DM_STRONG
#define E_Key_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define E_Key_MASK               E_Key__MASK
#define E_Key_SHIFT              E_Key__SHIFT
#define E_Key_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define E_Key_PS                     (* (reg8 *) E_Key__PS)
/* Data Register */
#define E_Key_DR                     (* (reg8 *) E_Key__DR)
/* Port Number */
#define E_Key_PRT_NUM                (* (reg8 *) E_Key__PRT) 
/* Connect to Analog Globals */                                                  
#define E_Key_AG                     (* (reg8 *) E_Key__AG)                       
/* Analog MUX bux enable */
#define E_Key_AMUX                   (* (reg8 *) E_Key__AMUX) 
/* Bidirectional Enable */                                                        
#define E_Key_BIE                    (* (reg8 *) E_Key__BIE)
/* Bit-mask for Aliased Register Access */
#define E_Key_BIT_MASK               (* (reg8 *) E_Key__BIT_MASK)
/* Bypass Enable */
#define E_Key_BYP                    (* (reg8 *) E_Key__BYP)
/* Port wide control signals */                                                   
#define E_Key_CTL                    (* (reg8 *) E_Key__CTL)
/* Drive Modes */
#define E_Key_DM0                    (* (reg8 *) E_Key__DM0) 
#define E_Key_DM1                    (* (reg8 *) E_Key__DM1)
#define E_Key_DM2                    (* (reg8 *) E_Key__DM2) 
/* Input Buffer Disable Override */
#define E_Key_INP_DIS                (* (reg8 *) E_Key__INP_DIS)
/* LCD Common or Segment Drive */
#define E_Key_LCD_COM_SEG            (* (reg8 *) E_Key__LCD_COM_SEG)
/* Enable Segment LCD */
#define E_Key_LCD_EN                 (* (reg8 *) E_Key__LCD_EN)
/* Slew Rate Control */
#define E_Key_SLW                    (* (reg8 *) E_Key__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define E_Key_PRTDSI__CAPS_SEL       (* (reg8 *) E_Key__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define E_Key_PRTDSI__DBL_SYNC_IN    (* (reg8 *) E_Key__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define E_Key_PRTDSI__OE_SEL0        (* (reg8 *) E_Key__PRTDSI__OE_SEL0) 
#define E_Key_PRTDSI__OE_SEL1        (* (reg8 *) E_Key__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define E_Key_PRTDSI__OUT_SEL0       (* (reg8 *) E_Key__PRTDSI__OUT_SEL0) 
#define E_Key_PRTDSI__OUT_SEL1       (* (reg8 *) E_Key__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define E_Key_PRTDSI__SYNC_OUT       (* (reg8 *) E_Key__PRTDSI__SYNC_OUT) 


#if defined(E_Key__INTSTAT)  /* Interrupt Registers */

    #define E_Key_INTSTAT                (* (reg8 *) E_Key__INTSTAT)
    #define E_Key_SNAP                   (* (reg8 *) E_Key__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_E_Key_H */


/* [] END OF FILE */
