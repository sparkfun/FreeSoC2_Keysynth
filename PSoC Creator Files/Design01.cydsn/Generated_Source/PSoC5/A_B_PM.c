/*******************************************************************************
* File Name: A_B_PM.c  
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

#include "A_B.h"

static A_B_BACKUP_STRUCT  A_B_backup;


/*******************************************************************************
* Function Name: A_B_Sleep
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
*  A_B_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void A_B_Sleep(void) 
{
	/* Save DAC8's enable state */

	A_B_backup.enableState = (A_B_VDAC8_ACT_PWR_EN == 
		(A_B_VDAC8_PWRMGR_REG & A_B_VDAC8_ACT_PWR_EN)) ? 1u : 0u ;
	
	A_B_Stop();
	A_B_SaveConfig();
}


/*******************************************************************************
* Function Name: A_B_Wakeup
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
*  A_B_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void A_B_Wakeup(void) 
{
	A_B_RestoreConfig();

	if(A_B_backup.enableState == 1u)
	{
		A_B_Enable();
	}
}


/* [] END OF FILE */
