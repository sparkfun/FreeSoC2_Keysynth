/*******************************************************************************
* File Name: C_D_PM.c  
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

#include "C_D.h"

static C_D_BACKUP_STRUCT  C_D_backup;


/*******************************************************************************
* Function Name: C_D_Sleep
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
*  C_D_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void C_D_Sleep(void) 
{
	/* Save DAC8's enable state */

	C_D_backup.enableState = (C_D_VDAC8_ACT_PWR_EN == 
		(C_D_VDAC8_PWRMGR_REG & C_D_VDAC8_ACT_PWR_EN)) ? 1u : 0u ;
	
	C_D_Stop();
	C_D_SaveConfig();
}


/*******************************************************************************
* Function Name: C_D_Wakeup
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
*  C_D_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void C_D_Wakeup(void) 
{
	C_D_RestoreConfig();

	if(C_D_backup.enableState == 1u)
	{
		C_D_Enable();
	}
}


/* [] END OF FILE */
