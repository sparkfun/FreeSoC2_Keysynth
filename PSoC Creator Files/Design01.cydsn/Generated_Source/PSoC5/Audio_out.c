/*******************************************************************************
* File Name: Audio_out.c  
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
#include "Audio_out.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Audio_out__PORT == 15 && ((Audio_out__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Audio_out_Write
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
void Audio_out_Write(uint8 value) 
{
    uint8 staticBits = (Audio_out_DR & (uint8)(~Audio_out_MASK));
    Audio_out_DR = staticBits | ((uint8)(value << Audio_out_SHIFT) & Audio_out_MASK);
}


/*******************************************************************************
* Function Name: Audio_out_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Audio_out_DM_STRONG     Strong Drive 
*  Audio_out_DM_OD_HI      Open Drain, Drives High 
*  Audio_out_DM_OD_LO      Open Drain, Drives Low 
*  Audio_out_DM_RES_UP     Resistive Pull Up 
*  Audio_out_DM_RES_DWN    Resistive Pull Down 
*  Audio_out_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Audio_out_DM_DIG_HIZ    High Impedance Digital 
*  Audio_out_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Audio_out_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Audio_out_0, mode);
}


/*******************************************************************************
* Function Name: Audio_out_Read
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
*  Macro Audio_out_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Audio_out_Read(void) 
{
    return (Audio_out_PS & Audio_out_MASK) >> Audio_out_SHIFT;
}


/*******************************************************************************
* Function Name: Audio_out_ReadDataReg
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
uint8 Audio_out_ReadDataReg(void) 
{
    return (Audio_out_DR & Audio_out_MASK) >> Audio_out_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Audio_out_INTSTAT) 

    /*******************************************************************************
    * Function Name: Audio_out_ClearInterrupt
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
    uint8 Audio_out_ClearInterrupt(void) 
    {
        return (Audio_out_INTSTAT & Audio_out_MASK) >> Audio_out_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
