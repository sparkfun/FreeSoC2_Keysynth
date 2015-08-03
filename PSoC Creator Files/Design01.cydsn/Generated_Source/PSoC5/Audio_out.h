/*******************************************************************************
* File Name: Audio_out.h  
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

#if !defined(CY_PINS_Audio_out_H) /* Pins Audio_out_H */
#define CY_PINS_Audio_out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Audio_out_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Audio_out__PORT == 15 && ((Audio_out__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Audio_out_Write(uint8 value) ;
void    Audio_out_SetDriveMode(uint8 mode) ;
uint8   Audio_out_ReadDataReg(void) ;
uint8   Audio_out_Read(void) ;
uint8   Audio_out_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Audio_out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Audio_out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Audio_out_DM_RES_UP          PIN_DM_RES_UP
#define Audio_out_DM_RES_DWN         PIN_DM_RES_DWN
#define Audio_out_DM_OD_LO           PIN_DM_OD_LO
#define Audio_out_DM_OD_HI           PIN_DM_OD_HI
#define Audio_out_DM_STRONG          PIN_DM_STRONG
#define Audio_out_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Audio_out_MASK               Audio_out__MASK
#define Audio_out_SHIFT              Audio_out__SHIFT
#define Audio_out_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Audio_out_PS                     (* (reg8 *) Audio_out__PS)
/* Data Register */
#define Audio_out_DR                     (* (reg8 *) Audio_out__DR)
/* Port Number */
#define Audio_out_PRT_NUM                (* (reg8 *) Audio_out__PRT) 
/* Connect to Analog Globals */                                                  
#define Audio_out_AG                     (* (reg8 *) Audio_out__AG)                       
/* Analog MUX bux enable */
#define Audio_out_AMUX                   (* (reg8 *) Audio_out__AMUX) 
/* Bidirectional Enable */                                                        
#define Audio_out_BIE                    (* (reg8 *) Audio_out__BIE)
/* Bit-mask for Aliased Register Access */
#define Audio_out_BIT_MASK               (* (reg8 *) Audio_out__BIT_MASK)
/* Bypass Enable */
#define Audio_out_BYP                    (* (reg8 *) Audio_out__BYP)
/* Port wide control signals */                                                   
#define Audio_out_CTL                    (* (reg8 *) Audio_out__CTL)
/* Drive Modes */
#define Audio_out_DM0                    (* (reg8 *) Audio_out__DM0) 
#define Audio_out_DM1                    (* (reg8 *) Audio_out__DM1)
#define Audio_out_DM2                    (* (reg8 *) Audio_out__DM2) 
/* Input Buffer Disable Override */
#define Audio_out_INP_DIS                (* (reg8 *) Audio_out__INP_DIS)
/* LCD Common or Segment Drive */
#define Audio_out_LCD_COM_SEG            (* (reg8 *) Audio_out__LCD_COM_SEG)
/* Enable Segment LCD */
#define Audio_out_LCD_EN                 (* (reg8 *) Audio_out__LCD_EN)
/* Slew Rate Control */
#define Audio_out_SLW                    (* (reg8 *) Audio_out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Audio_out_PRTDSI__CAPS_SEL       (* (reg8 *) Audio_out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Audio_out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Audio_out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Audio_out_PRTDSI__OE_SEL0        (* (reg8 *) Audio_out__PRTDSI__OE_SEL0) 
#define Audio_out_PRTDSI__OE_SEL1        (* (reg8 *) Audio_out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Audio_out_PRTDSI__OUT_SEL0       (* (reg8 *) Audio_out__PRTDSI__OUT_SEL0) 
#define Audio_out_PRTDSI__OUT_SEL1       (* (reg8 *) Audio_out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Audio_out_PRTDSI__SYNC_OUT       (* (reg8 *) Audio_out__PRTDSI__SYNC_OUT) 


#if defined(Audio_out__INTSTAT)  /* Interrupt Registers */

    #define Audio_out_INTSTAT                (* (reg8 *) Audio_out__INTSTAT)
    #define Audio_out_SNAP                   (* (reg8 *) Audio_out__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Audio_out_H */


/* [] END OF FILE */
