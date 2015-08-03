/*******************************************************************************
* File Name: E_F_VDAC8_PM.c  
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

#include "E_F_VDAC8.h"

static E_F_VDAC8_backupStruct E_F_VDAC8_backup;


/*******************************************************************************
* Function Name: E_F_VDAC8_SaveConfig
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
void E_F_VDAC8_SaveConfig(void) 
{
    if (!((E_F_VDAC8_CR1 & E_F_VDAC8_SRC_MASK) == E_F_VDAC8_SRC_UDB))
    {
        E_F_VDAC8_backup.data_value = E_F_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: E_F_VDAC8_RestoreConfig
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
void E_F_VDAC8_RestoreConfig(void) 
{
    if (!((E_F_VDAC8_CR1 & E_F_VDAC8_SRC_MASK) == E_F_VDAC8_SRC_UDB))
    {
        if((E_F_VDAC8_Strobe & E_F_VDAC8_STRB_MASK) == E_F_VDAC8_STRB_EN)
        {
            E_F_VDAC8_Strobe &= (uint8)(~E_F_VDAC8_STRB_MASK);
            E_F_VDAC8_Data = E_F_VDAC8_backup.data_value;
            E_F_VDAC8_Strobe |= E_F_VDAC8_STRB_EN;
        }
        else
        {
            E_F_VDAC8_Data = E_F_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: E_F_VDAC8_Sleep
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
*  E_F_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void E_F_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(E_F_VDAC8_ACT_PWR_EN == (E_F_VDAC8_PWRMGR & E_F_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        E_F_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        E_F_VDAC8_backup.enableState = 0u;
    }
    
    E_F_VDAC8_Stop();
    E_F_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: E_F_VDAC8_Wakeup
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
*  E_F_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void E_F_VDAC8_Wakeup(void) 
{
    E_F_VDAC8_RestoreConfig();
    
    if(E_F_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        E_F_VDAC8_Enable();

        /* Restore the data register */
        E_F_VDAC8_SetValue(E_F_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
