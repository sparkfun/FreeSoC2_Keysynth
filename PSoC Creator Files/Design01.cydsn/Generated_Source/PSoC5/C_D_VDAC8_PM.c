/*******************************************************************************
* File Name: C_D_VDAC8_PM.c  
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

#include "C_D_VDAC8.h"

static C_D_VDAC8_backupStruct C_D_VDAC8_backup;


/*******************************************************************************
* Function Name: C_D_VDAC8_SaveConfig
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
void C_D_VDAC8_SaveConfig(void) 
{
    if (!((C_D_VDAC8_CR1 & C_D_VDAC8_SRC_MASK) == C_D_VDAC8_SRC_UDB))
    {
        C_D_VDAC8_backup.data_value = C_D_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: C_D_VDAC8_RestoreConfig
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
void C_D_VDAC8_RestoreConfig(void) 
{
    if (!((C_D_VDAC8_CR1 & C_D_VDAC8_SRC_MASK) == C_D_VDAC8_SRC_UDB))
    {
        if((C_D_VDAC8_Strobe & C_D_VDAC8_STRB_MASK) == C_D_VDAC8_STRB_EN)
        {
            C_D_VDAC8_Strobe &= (uint8)(~C_D_VDAC8_STRB_MASK);
            C_D_VDAC8_Data = C_D_VDAC8_backup.data_value;
            C_D_VDAC8_Strobe |= C_D_VDAC8_STRB_EN;
        }
        else
        {
            C_D_VDAC8_Data = C_D_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: C_D_VDAC8_Sleep
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
*  C_D_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void C_D_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(C_D_VDAC8_ACT_PWR_EN == (C_D_VDAC8_PWRMGR & C_D_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        C_D_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        C_D_VDAC8_backup.enableState = 0u;
    }
    
    C_D_VDAC8_Stop();
    C_D_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: C_D_VDAC8_Wakeup
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
*  C_D_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void C_D_VDAC8_Wakeup(void) 
{
    C_D_VDAC8_RestoreConfig();
    
    if(C_D_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        C_D_VDAC8_Enable();

        /* Restore the data register */
        C_D_VDAC8_SetValue(C_D_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
