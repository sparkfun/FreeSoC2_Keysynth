/*******************************************************************************
* File Name: Pot_A.c  
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
#include "Pot_A.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Pot_A__PORT == 15 && ((Pot_A__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Pot_A_Write
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
void Pot_A_Write(uint8 value) 
{
    uint8 staticBits = (Pot_A_DR & (uint8)(~Pot_A_MASK));
    Pot_A_DR = staticBits | ((uint8)(value << Pot_A_SHIFT) & Pot_A_MASK);
}


/*******************************************************************************
* Function Name: Pot_A_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Pot_A_DM_STRONG     Strong Drive 
*  Pot_A_DM_OD_HI      Open Drain, Drives High 
*  Pot_A_DM_OD_LO      Open Drain, Drives Low 
*  Pot_A_DM_RES_UP     Resistive Pull Up 
*  Pot_A_DM_RES_DWN    Resistive Pull Down 
*  Pot_A_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Pot_A_DM_DIG_HIZ    High Impedance Digital 
*  Pot_A_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Pot_A_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pot_A_0, mode);
}


/*******************************************************************************
* Function Name: Pot_A_Read
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
*  Macro Pot_A_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pot_A_Read(void) 
{
    return (Pot_A_PS & Pot_A_MASK) >> Pot_A_SHIFT;
}


/*******************************************************************************
* Function Name: Pot_A_ReadDataReg
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
uint8 Pot_A_ReadDataReg(void) 
{
    return (Pot_A_DR & Pot_A_MASK) >> Pot_A_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pot_A_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pot_A_ClearInterrupt
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
    uint8 Pot_A_ClearInterrupt(void) 
    {
        return (Pot_A_INTSTAT & Pot_A_MASK) >> Pot_A_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
