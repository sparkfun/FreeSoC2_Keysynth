/*******************************************************************************
* File Name: B_Key.c  
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
#include "B_Key.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 B_Key__PORT == 15 && ((B_Key__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: B_Key_Write
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
void B_Key_Write(uint8 value) 
{
    uint8 staticBits = (B_Key_DR & (uint8)(~B_Key_MASK));
    B_Key_DR = staticBits | ((uint8)(value << B_Key_SHIFT) & B_Key_MASK);
}


/*******************************************************************************
* Function Name: B_Key_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  B_Key_DM_STRONG     Strong Drive 
*  B_Key_DM_OD_HI      Open Drain, Drives High 
*  B_Key_DM_OD_LO      Open Drain, Drives Low 
*  B_Key_DM_RES_UP     Resistive Pull Up 
*  B_Key_DM_RES_DWN    Resistive Pull Down 
*  B_Key_DM_RES_UPDWN  Resistive Pull Up/Down 
*  B_Key_DM_DIG_HIZ    High Impedance Digital 
*  B_Key_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void B_Key_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(B_Key_0, mode);
}


/*******************************************************************************
* Function Name: B_Key_Read
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
*  Macro B_Key_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 B_Key_Read(void) 
{
    return (B_Key_PS & B_Key_MASK) >> B_Key_SHIFT;
}


/*******************************************************************************
* Function Name: B_Key_ReadDataReg
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
uint8 B_Key_ReadDataReg(void) 
{
    return (B_Key_DR & B_Key_MASK) >> B_Key_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(B_Key_INTSTAT) 

    /*******************************************************************************
    * Function Name: B_Key_ClearInterrupt
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
    uint8 B_Key_ClearInterrupt(void) 
    {
        return (B_Key_INTSTAT & B_Key_MASK) >> B_Key_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
