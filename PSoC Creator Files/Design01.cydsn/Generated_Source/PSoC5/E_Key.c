/*******************************************************************************
* File Name: E_Key.c  
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
#include "E_Key.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 E_Key__PORT == 15 && ((E_Key__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: E_Key_Write
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
void E_Key_Write(uint8 value) 
{
    uint8 staticBits = (E_Key_DR & (uint8)(~E_Key_MASK));
    E_Key_DR = staticBits | ((uint8)(value << E_Key_SHIFT) & E_Key_MASK);
}


/*******************************************************************************
* Function Name: E_Key_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  E_Key_DM_STRONG     Strong Drive 
*  E_Key_DM_OD_HI      Open Drain, Drives High 
*  E_Key_DM_OD_LO      Open Drain, Drives Low 
*  E_Key_DM_RES_UP     Resistive Pull Up 
*  E_Key_DM_RES_DWN    Resistive Pull Down 
*  E_Key_DM_RES_UPDWN  Resistive Pull Up/Down 
*  E_Key_DM_DIG_HIZ    High Impedance Digital 
*  E_Key_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void E_Key_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(E_Key_0, mode);
}


/*******************************************************************************
* Function Name: E_Key_Read
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
*  Macro E_Key_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 E_Key_Read(void) 
{
    return (E_Key_PS & E_Key_MASK) >> E_Key_SHIFT;
}


/*******************************************************************************
* Function Name: E_Key_ReadDataReg
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
uint8 E_Key_ReadDataReg(void) 
{
    return (E_Key_DR & E_Key_MASK) >> E_Key_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(E_Key_INTSTAT) 

    /*******************************************************************************
    * Function Name: E_Key_ClearInterrupt
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
    uint8 E_Key_ClearInterrupt(void) 
    {
        return (E_Key_INTSTAT & E_Key_MASK) >> E_Key_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
