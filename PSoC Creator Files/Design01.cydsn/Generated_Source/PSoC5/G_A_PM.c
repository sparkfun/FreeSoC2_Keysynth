/*******************************************************************************
* File Name: G_A_PM.c  
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for 
*  the WaveDAC8 component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "G_A.h"

static G_A_BACKUP_STRUCT  G_A_backup;


/*******************************************************************************
* Function Name: G_A_Sleep
********************************************************************************
*
* Summary:
*  Stops the component and saves its configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  G_A_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void G_A_Sleep(void) 
{
	/* Save DAC8's enable state */

	G_A_backup.enableState = (G_A_VDAC8_ACT_PWR_EN == 
		(G_A_VDAC8_PWRMGR_REG & G_A_VDAC8_ACT_PWR_EN)) ? 1u : 0u ;
	
	G_A_Stop();
	G_A_SaveConfig();
}


/*******************************************************************************
* Function Name: G_A_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component configuration. Should be called
*  just after awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  void
*
* Global variables:
*  G_A_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void G_A_Wakeup(void) 
{
	G_A_RestoreConfig();

	if(G_A_backup.enableState == 1u)
	{
		G_A_Enable();
	}
}


/* [] END OF FILE */
