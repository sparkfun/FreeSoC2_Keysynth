/*******************************************************************************
* File Name: G_A.c
* Version 2.0
*
* Description:
*  This file provides the source code for the 8-bit Waveform DAC 
*  (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "G_A.h"

uint8  G_A_initVar = 0u;

const uint8 CYCODE G_A_wave1[G_A_WAVE1_LENGTH] = { 128u,131u,134u,137u,140u,143u,146u,149u,152u,155u,158u,161u,164u,167u,170u,173u,176u,178u,181u,184u,187u,189u,192u,195u,197u,200u,202u,205u,207u,209u,212u,214u,216u,218u,220u,222u,224u,226u,228u,230u,232u,233u,235u,237u,238u,239u,241u,242u,243u,244u,245u,246u,247u,248u,249u,250u,250u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,251u,250u,249u,249u,248u,247u,246u,245u,244u,243u,241u,240u,239u,237u,236u,234u,233u,231u,229u,227u,225u,223u,221u,219u,217u,215u,213u,211u,208u,206u,203u,201u,198u,196u,193u,191u,188u,185u,183u,180u,177u,174u,171u,168u,165u,162u,159u,156u,153u,150u,147u,144u,141u,138u,135u,132u,129u,126u,123u,120u,117u,114u,111u,108u,105u,102u,99u,96u,93u,90u,87u,84u,81u,78u,75u,72u,70u,67u,64u,62u,59u,57u,54u,52u,49u,47u,44u,42u,40u,38u,36u,34u,32u,30u,28u,26u,24u,22u,21u,19u,18u,16u,15u,14u,12u,11u,10u,9u,8u,7u,6u,6u,5u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,5u,5u,6u,7u,8u,9u,10u,11u,12u,13u,14u,16u,17u,18u,20u,22u,23u,25u,27u,29u,31u,33u,35u,37u,39u,41u,43u,46u,48u,50u,53u,55u,58u,60u,63u,66u,68u,71u,74u,77u,79u,82u,85u,88u,91u,94u,97u,100u,103u,106u,109u,112u,115u,118u,121u,124u };
const uint8 CYCODE G_A_wave2[G_A_WAVE2_LENGTH] = { 128u,131u,134u,138u,141u,145u,148u,152u,155u,158u,162u,165u,168u,172u,175u,178u,181u,184u,187u,190u,193u,196u,199u,202u,205u,207u,210u,212u,215u,217u,220u,222u,224u,226u,229u,231u,232u,234u,236u,238u,239u,241u,242u,244u,245u,246u,247u,248u,249u,250u,250u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,250u,249u,248u,248u,246u,245u,244u,243u,242u,240u,239u,237u,235u,233u,231u,230u,227u,225u,223u,221u,219u,216u,214u,211u,209u,206u,203u,200u,198u,195u,192u,189u,186u,183u,179u,176u,173u,170u,167u,163u,160u,157u,153u,150u,146u,143u,140u,136u,133u,129u,126u,122u,119u,115u,112u,109u,105u,102u,98u,95u,92u,88u,85u,82u,79u,76u,72u,69u,66u,63u,60u,57u,55u,52u,49u,46u,44u,41u,39u,36u,34u,32u,30u,28u,25u,24u,22u,20u,18u,16u,15u,13u,12u,11u,10u,9u,7u,7u,6u,5u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,5u,5u,6u,7u,8u,9u,10u,11u,13u,14u,16u,17u,19u,21u,23u,24u,26u,29u,31u,33u,35u,38u,40u,43u,45u,48u,50u,53u,56u,59u,62u,65u,68u,71u,74u,77u,80u,83u,87u,90u,93u,97u,100u,103u,107u,110u,114u,117u,121u,124u };

static uint8  G_A_Wave1Chan;
static uint8  G_A_Wave2Chan;
static uint8  G_A_Wave1TD;
static uint8  G_A_Wave2TD;


/*******************************************************************************
* Function Name: G_A_Init
********************************************************************************
*
* Summary:
*  Initializes component with parameters set in the customizer.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void G_A_Init(void) 
{
	G_A_VDAC8_Init();
	G_A_VDAC8_SetSpeed(G_A_HIGHSPEED);
	G_A_VDAC8_SetRange(G_A_DAC_RANGE);

	#if(G_A_DAC_MODE == G_A_CURRENT_MODE)
		G_A_IDAC8_SetPolarity(G_A_DAC_POL);
	#endif /* G_A_DAC_MODE == G_A_CURRENT_MODE */

	#if(G_A_OUT_MODE == G_A_BUFFER_MODE)
	   G_A_BuffAmp_Init();
	#endif /* G_A_OUT_MODE == G_A_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	G_A_Wave1TD = CyDmaTdAllocate();
	G_A_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	G_A_Wave1Setup(G_A_wave1, G_A_WAVE1_LENGTH) ;
	G_A_Wave2Setup(G_A_wave2, G_A_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(G_A_DacClk_PHASE)
	   G_A_DacClk_SetPhase(G_A_CLK_PHASE_0nS);
	#endif /* defined(G_A_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: G_A_Enable
********************************************************************************
*  
* Summary: 
*  Enables the DAC block and DMA operation.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void G_A_Enable(void) 
{
	G_A_VDAC8_Enable();

	#if(G_A_OUT_MODE == G_A_BUFFER_MODE)
	   G_A_BuffAmp_Enable();
	#endif /* G_A_OUT_MODE == G_A_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(G_A_Wave1Chan, 1u);
	(void)CyDmaChEnable(G_A_Wave2Chan, 1u);
	
	/* set the initial value */
	G_A_SetValue(0u);
	
	#if(G_A_CLOCK_SRC == G_A_CLOCK_INT)  	
	   G_A_DacClk_Start();
	#endif /* G_A_CLOCK_SRC == G_A_CLOCK_INT */
}


/*******************************************************************************
* Function Name: G_A_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as 
*  executing the stop function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void G_A_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(G_A_initVar == 0u)
	{
		G_A_Init();
		G_A_initVar = 1u;
	}
	
	G_A_Enable();
}


/*******************************************************************************
* Function Name: G_A_StartEx
********************************************************************************
*
* Summary:
*  The StartEx function sets pointers and sizes for both waveforms
*  and then starts the component.
*
* Parameters:  
*   uint8 * wavePtr1:     Pointer to the waveform 1 array.
*   uint16  sampleSize1:  The amount of samples in the waveform 1.
*   uint8 * wavePtr2:     Pointer to the waveform 2 array.
*   uint16  sampleSize2:  The amount of samples in the waveform 2.
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void G_A_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	G_A_Wave1Setup(wavePtr1, sampleSize1);
	G_A_Wave2Setup(wavePtr2, sampleSize2);
	G_A_Start();
}


/*******************************************************************************
* Function Name: G_A_Stop
********************************************************************************
*
* Summary:
*  Stops the clock (if internal), disables the DMA channels
*  and powers down the DAC.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
*******************************************************************************/
void G_A_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(G_A_CLOCK_SRC == G_A_CLOCK_INT)  	
	   G_A_DacClk_Stop();
	#endif /* G_A_CLOCK_SRC == G_A_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(G_A_Wave1Chan);
	(void)CyDmaChDisable(G_A_Wave2Chan);

	/* Disable power to DAC */
	G_A_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: G_A_Wave1Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 1.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None 
*
*******************************************************************************/
void G_A_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (G_A_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		G_A_Wave1Chan = G_A_Wave1_DMA_DmaInitialize(
		G_A_Wave1_DMA_BYTES_PER_BURST, G_A_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		G_A_Wave1Chan = G_A_Wave1_DMA_DmaInitialize(
		G_A_Wave1_DMA_BYTES_PER_BURST, G_A_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(G_A_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(G_A_Wave1TD, sampleSize, G_A_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)G_A_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(G_A_Wave1TD, LO16((uint32)wavePtr), LO16(G_A_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(G_A_Wave1Chan, G_A_Wave1TD);
}


/*******************************************************************************
* Function Name: G_A_Wave2Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 2.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None
*
*******************************************************************************/
void G_A_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (G_A_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		G_A_Wave2Chan = G_A_Wave2_DMA_DmaInitialize(
		G_A_Wave2_DMA_BYTES_PER_BURST, G_A_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		G_A_Wave2Chan = G_A_Wave2_DMA_DmaInitialize(
		G_A_Wave2_DMA_BYTES_PER_BURST, G_A_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(G_A_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(G_A_Wave2TD, sampleSize, G_A_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)G_A_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(G_A_Wave2TD, LO16((uint32)wavePtr), LO16(G_A_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(G_A_Wave2Chan, G_A_Wave2TD);
}


/* [] END OF FILE */
