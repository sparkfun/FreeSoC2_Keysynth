/*******************************************************************************
* File Name: G_A_VDAC8_PM.c  
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

#include "G_A_VDAC8.h"

static G_A_VDAC8_backupStruct G_A_VDAC8_backup;


/*******************************************************************************
* Function Name: G_A_VDAC8_SaveConfig
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
void G_A_VDAC8_SaveConfig(void) 
{
    if (!((G_A_VDAC8_CR1 & G_A_VDAC8_SRC_MASK) == G_A_VDAC8_SRC_UDB))
    {
        G_A_VDAC8_backup.data_value = G_A_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: G_A_VDAC8_RestoreConfig
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
void G_A_VDAC8_RestoreConfig(void) 
{
    if (!((G_A_VDAC8_CR1 & G_A_VDAC8_SRC_MASK) == G_A_VDAC8_SRC_UDB))
    {
        if((G_A_VDAC8_Strobe & G_A_VDAC8_STRB_MASK) == G_A_VDAC8_STRB_EN)
        {
            G_A_VDAC8_Strobe &= (uint8)(~G_A_VDAC8_STRB_MASK);
            G_A_VDAC8_Data = G_A_VDAC8_backup.data_value;
            G_A_VDAC8_Strobe |= G_A_VDAC8_STRB_EN;
        }
        else
        {
            G_A_VDAC8_Data = G_A_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: G_A_VDAC8_Sleep
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
*  G_A_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void G_A_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(G_A_VDAC8_ACT_PWR_EN == (G_A_VDAC8_PWRMGR & G_A_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        G_A_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        G_A_VDAC8_backup.enableState = 0u;
    }
    
    G_A_VDAC8_Stop();
    G_A_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: G_A_VDAC8_Wakeup
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
*  G_A_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void G_A_VDAC8_Wakeup(void) 
{
    G_A_VDAC8_RestoreConfig();
    
    if(G_A_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        G_A_VDAC8_Enable();

        /* Restore the data register */
        G_A_VDAC8_SetValue(G_A_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
