/*******************************************************************************
* File Name: Amp.c  
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the PGA 
*  User Module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Amp.h"

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static Amp_BACKUP_STRUCT  Amp_P5backup;
#endif /* (CY_ PSOC5A) */

uint8 Amp_initVar = 0u;


/*******************************************************************************   
* Function Name: Amp_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  Amp_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Amp_Init(void) 
{
    /* Set PGA mode */
    Amp_CR0_REG = Amp_MODE_PGA;      
    /* Set non-inverting PGA mode and reference mode */
    Amp_CR1_REG |= Amp_PGA_NINV;  
    /* Set default gain and ref mode */
    Amp_CR2_REG = Amp_VREF_MODE;
    /* Set gain and compensation */
    Amp_SetGain(Amp_DEFAULT_GAIN);
    /* Set power */
    Amp_SetPower(Amp_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: Amp_Enable
********************************************************************************
*
* Summary:
*  Enables the PGA block operation.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Amp_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(Amp_P5backup.enableState == 1u)
        {
            Amp_CR1_REG = Amp_P5backup.scCR1Reg;
            Amp_CR2_REG = Amp_P5backup.scCR2Reg;
            Amp_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */   

    /* Enable power to the Amp in Active mode*/
    Amp_PM_ACT_CFG_REG |= Amp_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative Active mode*/
    Amp_PM_STBY_CFG_REG |= Amp_STBY_PWR_EN;
    
    Amp_PUMP_CR1_REG |= Amp_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                Amp_BSTCLK_REG &= (uint8)(~Amp_BST_CLK_INDEX_MASK);
                Amp_BSTCLK_REG |= Amp_BST_CLK_EN | CyScBoostClk__INDEX;
                Amp_SC_MISC_REG |= Amp_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                Amp_BSTCLK_REG &= (uint8)(~Amp_BST_CLK_EN);
                Amp_SC_MISC_REG &= (uint8)(~Amp_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: Amp_Start
********************************************************************************
*
* Summary:
*  The start function initializes the PGA with the default values and sets
*  the power to the given level. A power level of 0, is same as executing
*  the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Amp_Start(void) 
{

    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modification in stop() API */

    if(Amp_initVar == 0u)
    {
        Amp_Init();
        Amp_initVar = 1u;
    }

    Amp_Enable();
}


/*******************************************************************************
* Function Name: Amp_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Amp_Stop(void) 
{ 
    /* Disble power to the Amp in Active mode template */
    Amp_PM_ACT_CFG_REG &= (uint8)(~Amp_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative Active mode template */
    Amp_PM_STBY_CFG_REG &= (uint8)(~Amp_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            Amp_BSTCLK_REG &= (uint8)(~Amp_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((Amp_PM_ACT_CFG_REG & Amp_PM_ACT_CFG_MASK) == 0u)
            {
                Amp_SC_MISC_REG &= (uint8)(~Amp_PUMP_FORCE);
                Amp_PUMP_CR1_REG &= (uint8)(~Amp_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        Amp_P5backup.scCR1Reg = Amp_CR1_REG;
        Amp_P5backup.scCR2Reg = Amp_CR2_REG;
        Amp_CR1_REG = 0x00u;
        Amp_CR2_REG = 0x00u;
        Amp_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Amp_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the PGA.
*
* Parameters:
*  power: Sets power level between (0) and (3) high power
*
* Return:
*  void
*
*******************************************************************************/
void Amp_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = Amp_CR1_REG & (uint8)(~Amp_DRIVE_MASK);
    tmpCR |= (power & Amp_DRIVE_MASK);
    Amp_CR1_REG = tmpCR;  
}


/*******************************************************************************
* Function Name: Amp_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Gain value of PGA (See header file for gain values.)
*
* Return:
*  void 
*
*******************************************************************************/
void Amp_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 Amp_GainArray[9] = { 
        (Amp_RVAL_0K   | Amp_R20_40B_40K | Amp_BIAS_LOW), /* G=1  */
        (Amp_RVAL_40K  | Amp_R20_40B_40K | Amp_BIAS_LOW), /* G=2  */
        (Amp_RVAL_120K | Amp_R20_40B_40K | Amp_BIAS_LOW), /* G=4  */
        (Amp_RVAL_280K | Amp_R20_40B_40K | Amp_BIAS_LOW), /* G=8  */
        (Amp_RVAL_600K | Amp_R20_40B_40K | Amp_BIAS_LOW), /* G=16 */
        (Amp_RVAL_460K | Amp_R20_40B_40K | Amp_BIAS_LOW), /* G=24, Sets Rin as 20k */
        (Amp_RVAL_620K | Amp_R20_40B_20K | Amp_BIAS_LOW), /* G=32 */
        (Amp_RVAL_470K | Amp_R20_40B_20K | Amp_BIAS_LOW), /* G=48, Sets Rin as 10k */
        (Amp_RVAL_490K | Amp_R20_40B_20K | Amp_BIAS_LOW)  /* G=50, Sets Rin as 10k */
    };
    
    /* Constant array for gain compenstion settings */
    const uint8 Amp_GainComp[9] = { 
        ( Amp_COMP_4P35PF  | (uint8)( Amp_REDC_00 >> 2 )), /* G=1  */
        ( Amp_COMP_4P35PF  | (uint8)( Amp_REDC_01 >> 2 )), /* G=2  */
        ( Amp_COMP_3P0PF   | (uint8)( Amp_REDC_01 >> 2 )), /* G=4  */
        ( Amp_COMP_3P0PF   | (uint8)( Amp_REDC_01 >> 2 )), /* G=8  */
        ( Amp_COMP_3P6PF   | (uint8)( Amp_REDC_01 >> 2 )), /* G=16 */
        ( Amp_COMP_3P6PF   | (uint8)( Amp_REDC_11 >> 2 )), /* G=24 */
        ( Amp_COMP_3P6PF   | (uint8)( Amp_REDC_11 >> 2 )), /* G=32 */
        ( Amp_COMP_3P6PF   | (uint8)( Amp_REDC_00 >> 2 )), /* G=48 */
        ( Amp_COMP_3P6PF   | (uint8)( Amp_REDC_00 >> 2 ))  /* G=50 */
    };
    
    /* Only set new gain if it is a valid gain */
    if( gain <= Amp_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        Amp_CR2_REG &= (uint8)(~(Amp_RVAL_MASK | Amp_R20_40B_MASK | 
                                Amp_REDC_MASK | Amp_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        Amp_CR2_REG |= (Amp_GainArray[gain] |
                                ((uint8)(Amp_GainComp[gain] << 2 ) & Amp_REDC_MASK));

        /* Clear sc_comp  */
        Amp_CR1_REG &= (uint8)(~Amp_COMP_MASK);
        /* Set sc_comp  */
        Amp_CR1_REG |= ( Amp_GainComp[gain] | Amp_COMP_MASK );
    }
}


/* [] END OF FILE */
