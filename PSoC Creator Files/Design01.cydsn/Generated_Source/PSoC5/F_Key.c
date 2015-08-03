/*******************************************************************************
* File Name: F_Key.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "F_Key.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 F_Key__PORT == 15 && ((F_Key__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: F_Key_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void F_Key_Write(uint8 value) 
{
    uint8 staticBits = (F_Key_DR & (uint8)(~F_Key_MASK));
    F_Key_DR = staticBits | ((uint8)(value << F_Key_SHIFT) & F_Key_MASK);
}


/*******************************************************************************
* Function Name: F_Key_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  F_Key_DM_STRONG     Strong Drive 
*  F_Key_DM_OD_HI      Open Drain, Drives High 
*  F_Key_DM_OD_LO      Open Drain, Drives Low 
*  F_Key_DM_RES_UP     Resistive Pull Up 
*  F_Key_DM_RES_DWN    Resistive Pull Down 
*  F_Key_DM_RES_UPDWN  Resistive Pull Up/Down 
*  F_Key_DM_DIG_HIZ    High Impedance Digital 
*  F_Key_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void F_Key_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(F_Key_0, mode);
}


/*******************************************************************************
* Function Name: F_Key_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro F_Key_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 F_Key_Read(void) 
{
    return (F_Key_PS & F_Key_MASK) >> F_Key_SHIFT;
}


/*******************************************************************************
* Function Name: F_Key_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 F_Key_ReadDataReg(void) 
{
    return (F_Key_DR & F_Key_MASK) >> F_Key_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(F_Key_INTSTAT) 

    /*******************************************************************************
    * Function Name: F_Key_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 F_Key_ClearInterrupt(void) 
    {
        return (F_Key_INTSTAT & F_Key_MASK) >> F_Key_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
