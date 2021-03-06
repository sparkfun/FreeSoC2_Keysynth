/*******************************************************************************
* File Name: A2_Key.h  
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

#if !defined(CY_PINS_A2_Key_H) /* Pins A2_Key_H */
#define CY_PINS_A2_Key_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "A2_Key_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 A2_Key__PORT == 15 && ((A2_Key__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    A2_Key_Write(uint8 value) ;
void    A2_Key_SetDriveMode(uint8 mode) ;
uint8   A2_Key_ReadDataReg(void) ;
uint8   A2_Key_Read(void) ;
uint8   A2_Key_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define A2_Key_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define A2_Key_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define A2_Key_DM_RES_UP          PIN_DM_RES_UP
#define A2_Key_DM_RES_DWN         PIN_DM_RES_DWN
#define A2_Key_DM_OD_LO           PIN_DM_OD_LO
#define A2_Key_DM_OD_HI           PIN_DM_OD_HI
#define A2_Key_DM_STRONG          PIN_DM_STRONG
#define A2_Key_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define A2_Key_MASK               A2_Key__MASK
#define A2_Key_SHIFT              A2_Key__SHIFT
#define A2_Key_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A2_Key_PS                     (* (reg8 *) A2_Key__PS)
/* Data Register */
#define A2_Key_DR                     (* (reg8 *) A2_Key__DR)
/* Port Number */
#define A2_Key_PRT_NUM                (* (reg8 *) A2_Key__PRT) 
/* Connect to Analog Globals */                                                  
#define A2_Key_AG                     (* (reg8 *) A2_Key__AG)                       
/* Analog MUX bux enable */
#define A2_Key_AMUX                   (* (reg8 *) A2_Key__AMUX) 
/* Bidirectional Enable */                                                        
#define A2_Key_BIE                    (* (reg8 *) A2_Key__BIE)
/* Bit-mask for Aliased Register Access */
#define A2_Key_BIT_MASK               (* (reg8 *) A2_Key__BIT_MASK)
/* Bypass Enable */
#define A2_Key_BYP                    (* (reg8 *) A2_Key__BYP)
/* Port wide control signals */                                                   
#define A2_Key_CTL                    (* (reg8 *) A2_Key__CTL)
/* Drive Modes */
#define A2_Key_DM0                    (* (reg8 *) A2_Key__DM0) 
#define A2_Key_DM1                    (* (reg8 *) A2_Key__DM1)
#define A2_Key_DM2                    (* (reg8 *) A2_Key__DM2) 
/* Input Buffer Disable Override */
#define A2_Key_INP_DIS                (* (reg8 *) A2_Key__INP_DIS)
/* LCD Common or Segment Drive */
#define A2_Key_LCD_COM_SEG            (* (reg8 *) A2_Key__LCD_COM_SEG)
/* Enable Segment LCD */
#define A2_Key_LCD_EN                 (* (reg8 *) A2_Key__LCD_EN)
/* Slew Rate Control */
#define A2_Key_SLW                    (* (reg8 *) A2_Key__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define A2_Key_PRTDSI__CAPS_SEL       (* (reg8 *) A2_Key__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define A2_Key_PRTDSI__DBL_SYNC_IN    (* (reg8 *) A2_Key__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define A2_Key_PRTDSI__OE_SEL0        (* (reg8 *) A2_Key__PRTDSI__OE_SEL0) 
#define A2_Key_PRTDSI__OE_SEL1        (* (reg8 *) A2_Key__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define A2_Key_PRTDSI__OUT_SEL0       (* (reg8 *) A2_Key__PRTDSI__OUT_SEL0) 
#define A2_Key_PRTDSI__OUT_SEL1       (* (reg8 *) A2_Key__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define A2_Key_PRTDSI__SYNC_OUT       (* (reg8 *) A2_Key__PRTDSI__SYNC_OUT) 


#if defined(A2_Key__INTSTAT)  /* Interrupt Registers */

    #define A2_Key_INTSTAT                (* (reg8 *) A2_Key__INTSTAT)
    #define A2_Key_SNAP                   (* (reg8 *) A2_Key__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_A2_Key_H */


/* [] END OF FILE */
