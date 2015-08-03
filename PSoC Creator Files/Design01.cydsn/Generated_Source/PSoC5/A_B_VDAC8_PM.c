/*******************************************************************************
* File Name: A_B_VDAC8_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "A_B_VDAC8.h"

static A_B_VDAC8_backupStruct A_B_VDAC8_backup;


/*******************************************************************************
* Function Name: A_B_VDAC8_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void A_B_VDAC8_SaveConfig(void) 
{
    if (!((A_B_VDAC8_CR1 & A_B_VDAC8_SRC_MASK) == A_B_VDAC8_SRC_UDB))
    {
        A_B_VDAC8_backup.data_value = A_B_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: A_B_VDAC8_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void A_B_VDAC8_RestoreConfig(void) 
{
    if (!((A_B_VDAC8_CR1 & A_B_VDAC8_SRC_MASK) == A_B_VDAC8_SRC_UDB))
    {
        if((A_B_VDAC8_Strobe & A_B_VDAC8_STRB_MASK) == A_B_VDAC8_STRB_EN)
        {
            A_B_VDAC8_Strobe &= (uint8)(~A_B_VDAC8_STRB_MASK);
            A_B_VDAC8_Data = A_B_VDAC8_backup.data_value;
            A_B_VDAC8_Strobe |= A_B_VDAC8_STRB_EN;
        }
        else
        {
            A_B_VDAC8_Data = A_B_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: A_B_VDAC8_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  A_B_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void A_B_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(A_B_VDAC8_ACT_PWR_EN == (A_B_VDAC8_PWRMGR & A_B_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        A_B_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        A_B_VDAC8_backup.enableState = 0u;
    }
    
    A_B_VDAC8_Stop();
    A_B_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: A_B_VDAC8_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  A_B_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void A_B_VDAC8_Wakeup(void) 
{
    A_B_VDAC8_RestoreConfig();
    
    if(A_B_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        A_B_VDAC8_Enable();

        /* Restore the data register */
        A_B_VDAC8_SetValue(A_B_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
