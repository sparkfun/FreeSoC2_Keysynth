/*******************************************************************************
* File Name: A_B_VDAC8.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "A_B_VDAC8.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 A_B_VDAC8_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 A_B_VDAC8_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static A_B_VDAC8_backupStruct A_B_VDAC8_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: A_B_VDAC8_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_Init(void) 
{
    A_B_VDAC8_CR0 = (A_B_VDAC8_MODE_V );

    /* Set default data source */
    #if(A_B_VDAC8_DEFAULT_DATA_SRC != 0 )
        A_B_VDAC8_CR1 = (A_B_VDAC8_DEFAULT_CNTL | A_B_VDAC8_DACBUS_ENABLE) ;
    #else
        A_B_VDAC8_CR1 = (A_B_VDAC8_DEFAULT_CNTL | A_B_VDAC8_DACBUS_DISABLE) ;
    #endif /* (A_B_VDAC8_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(A_B_VDAC8_DEFAULT_STRB != 0)
        A_B_VDAC8_Strobe |= A_B_VDAC8_STRB_EN ;
    #endif/* (A_B_VDAC8_DEFAULT_STRB != 0) */

    /* Set default range */
    A_B_VDAC8_SetRange(A_B_VDAC8_DEFAULT_RANGE); 

    /* Set default speed */
    A_B_VDAC8_SetSpeed(A_B_VDAC8_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: A_B_VDAC8_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_Enable(void) 
{
    A_B_VDAC8_PWRMGR |= A_B_VDAC8_ACT_PWR_EN;
    A_B_VDAC8_STBY_PWRMGR |= A_B_VDAC8_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(A_B_VDAC8_restoreVal == 1u) 
        {
             A_B_VDAC8_CR0 = A_B_VDAC8_backup.data_value;
             A_B_VDAC8_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: A_B_VDAC8_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  A_B_VDAC8_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void A_B_VDAC8_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(A_B_VDAC8_initVar == 0u)
    { 
        A_B_VDAC8_Init();
        A_B_VDAC8_initVar = 1u;
    }

    /* Enable power to DAC */
    A_B_VDAC8_Enable();

    /* Set default value */
    A_B_VDAC8_SetValue(A_B_VDAC8_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: A_B_VDAC8_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_Stop(void) 
{
    /* Disble power to DAC */
    A_B_VDAC8_PWRMGR &= (uint8)(~A_B_VDAC8_ACT_PWR_EN);
    A_B_VDAC8_STBY_PWRMGR &= (uint8)(~A_B_VDAC8_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        A_B_VDAC8_backup.data_value = A_B_VDAC8_CR0;
        A_B_VDAC8_CR0 = A_B_VDAC8_CUR_MODE_OUT_OFF;
        A_B_VDAC8_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: A_B_VDAC8_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    A_B_VDAC8_CR0 &= (uint8)(~A_B_VDAC8_HS_MASK);
    A_B_VDAC8_CR0 |=  (speed & A_B_VDAC8_HS_MASK);
}


/*******************************************************************************
* Function Name: A_B_VDAC8_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_SetRange(uint8 range) 
{
    A_B_VDAC8_CR0 &= (uint8)(~A_B_VDAC8_RANGE_MASK);      /* Clear existing mode */
    A_B_VDAC8_CR0 |= (range & A_B_VDAC8_RANGE_MASK);      /*  Set Range  */
    A_B_VDAC8_DacTrim();
}


/*******************************************************************************
* Function Name: A_B_VDAC8_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 A_B_VDAC8_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    A_B_VDAC8_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        A_B_VDAC8_Data = value;
        CyExitCriticalSection(A_B_VDAC8_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: A_B_VDAC8_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void A_B_VDAC8_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((A_B_VDAC8_CR0 & A_B_VDAC8_RANGE_MASK) >> 2) + A_B_VDAC8_TRIM_M7_1V_RNG_OFFSET;
    A_B_VDAC8_TR = CY_GET_XTND_REG8((uint8 *)(A_B_VDAC8_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
