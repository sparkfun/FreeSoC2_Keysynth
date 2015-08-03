/*******************************************************************************
* File Name: E_F_PM.c  
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

#include "E_F.h"

static E_F_BACKUP_STRUCT  E_F_backup;


/*******************************************************************************
* Function Name: E_F_Sleep
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
*  E_F_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void E_F_Sleep(void) 
{
	/* Save DAC8's enable state */

	E_F_backup.enableState = (E_F_VDAC8_ACT_PWR_EN == 
		(E_F_VDAC8_PWRMGR_REG & E_F_VDAC8_ACT_PWR_EN)) ? 1u : 0u ;
	
	E_F_Stop();
	E_F_SaveConfig();
}


/*******************************************************************************
* Function Name: E_F_Wakeup
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
*  E_F_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void E_F_Wakeup(void) 
{
	E_F_RestoreConfig();

	if(E_F_backup.enableState == 1u)
	{
		E_F_Enable();
	}
}


/* [] END OF FILE */
