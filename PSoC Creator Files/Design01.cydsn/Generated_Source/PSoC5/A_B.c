/*******************************************************************************
* File Name: A_B.c
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

#include "A_B.h"

uint8  A_B_initVar = 0u;

const uint8 CYCODE A_B_wave1[A_B_WAVE1_LENGTH] = { 128u,129u,131u,133u,134u,136u,138u,140u,141u,143u,145u,146u,148u,150u,152u,153u,155u,157u,158u,160u,162u,163u,165u,167u,168u,170u,172u,173u,175u,176u,178u,179u,181u,183u,184u,186u,187u,189u,190u,192u,193u,195u,196u,198u,199u,200u,202u,203u,205u,206u,207u,209u,210u,211u,212u,214u,215u,216u,217u,219u,220u,221u,222u,223u,224u,225u,226u,227u,229u,230u,231u,231u,232u,233u,234u,235u,236u,237u,238u,239u,239u,240u,241u,242u,242u,243u,244u,244u,245u,245u,246u,246u,247u,248u,248u,248u,249u,249u,250u,250u,250u,251u,251u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,251u,251u,250u,250u,250u,249u,249u,248u,248u,248u,247u,246u,246u,245u,245u,244u,244u,243u,242u,242u,241u,240u,239u,239u,238u,237u,236u,235u,234u,233u,232u,231u,231u,230u,229u,227u,226u,225u,224u,223u,222u,221u,220u,219u,217u,216u,215u,214u,212u,211u,210u,209u,207u,206u,205u,203u,202u,200u,199u,198u,196u,195u,193u,192u,190u,189u,187u,186u,184u,183u,181u,179u,178u,176u,175u,173u,172u,170u,168u,167u,165u,163u,162u,160u,158u,157u,155u,153u,152u,150u,148u,146u,145u,143u,141u,140u,138u,136u,134u,133u,131u,129u,128u,126u,124u,122u,121u,119u,117u,115u,114u,112u,110u,109u,107u,105u,103u,102u,100u,98u,97u,95u,93u,92u,90u,88u,87u,85u,83u,82u,80u,79u,77u,76u,74u,72u,71u,69u,68u,66u,65u,63u,62u,60u,59u,57u,56u,55u,53u,52u,50u,49u,48u,46u,45u,44u,43u,41u,40u,39u,38u,36u,35u,34u,33u,32u,31u,30u,29u,28u,26u,25u,24u,24u,23u,22u,21u,20u,19u,18u,17u,16u,16u,15u,14u,13u,13u,12u,11u,11u,10u,10u,9u,9u,8u,7u,7u,7u,6u,6u,5u,5u,5u,4u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,4u,4u,5u,5u,5u,6u,6u,7u,7u,7u,8u,9u,9u,10u,10u,11u,11u,12u,13u,13u,14u,15u,16u,16u,17u,18u,19u,20u,21u,22u,23u,24u,24u,25u,26u,28u,29u,30u,31u,32u,33u,34u,35u,36u,38u,39u,40u,41u,43u,44u,45u,46u,48u,49u,50u,52u,53u,55u,56u,57u,59u,60u,62u,63u,65u,66u,68u,69u,71u,72u,74u,76u,77u,79u,80u,82u,83u,85u,87u,88u,90u,92u,93u,95u,97u,98u,100u,102u,103u,105u,107u,109u,110u,112u,114u,115u,117u,119u,121u,122u,124u,126u };
const uint8 CYCODE A_B_wave2[A_B_WAVE2_LENGTH] = { 128u,129u,131u,133u,135u,137u,139u,141u,143u,145u,147u,149u,151u,153u,154u,156u,158u,160u,162u,164u,166u,168u,169u,171u,173u,175u,177u,178u,180u,182u,184u,185u,187u,189u,190u,192u,194u,195u,197u,199u,200u,202u,203u,205u,206u,208u,209u,211u,212u,214u,215u,216u,218u,219u,220u,222u,223u,224u,225u,227u,228u,229u,230u,231u,232u,233u,234u,235u,236u,237u,238u,239u,240u,241u,241u,242u,243u,244u,244u,245u,246u,246u,247u,248u,248u,249u,249u,249u,250u,250u,251u,251u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,251u,250u,250u,250u,249u,249u,248u,248u,247u,247u,246u,245u,245u,244u,243u,243u,242u,241u,240u,239u,239u,238u,237u,236u,235u,234u,233u,232u,231u,229u,228u,227u,226u,225u,224u,222u,221u,220u,218u,217u,216u,214u,213u,212u,210u,209u,207u,206u,204u,203u,201u,199u,198u,196u,195u,193u,191u,190u,188u,186u,184u,183u,181u,179u,177u,176u,174u,172u,170u,168u,167u,165u,163u,161u,159u,157u,155u,153u,152u,150u,148u,146u,144u,142u,140u,138u,136u,134u,132u,130u,128u,127u,125u,123u,121u,119u,117u,115u,113u,111u,109u,107u,105u,103u,102u,100u,98u,96u,94u,92u,90u,88u,87u,85u,83u,81u,79u,78u,76u,74u,72u,71u,69u,67u,65u,64u,62u,60u,59u,57u,56u,54u,52u,51u,49u,48u,46u,45u,43u,42u,41u,39u,38u,37u,35u,34u,33u,31u,30u,29u,28u,27u,26u,24u,23u,22u,21u,20u,19u,18u,17u,16u,16u,15u,14u,13u,12u,12u,11u,10u,10u,9u,8u,8u,7u,7u,6u,6u,5u,5u,5u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,4u,4u,5u,5u,6u,6u,6u,7u,7u,8u,9u,9u,10u,11u,11u,12u,13u,14u,14u,15u,16u,17u,18u,19u,20u,21u,22u,23u,24u,25u,26u,27u,28u,30u,31u,32u,33u,35u,36u,37u,39u,40u,41u,43u,44u,46u,47u,49u,50u,52u,53u,55u,56u,58u,60u,61u,63u,65u,66u,68u,70u,71u,73u,75u,77u,78u,80u,82u,84u,86u,87u,89u,91u,93u,95u,97u,99u,101u,102u,104u,106u,108u,110u,112u,114u,116u,118u,120u,122u,124u,126u };

static uint8  A_B_Wave1Chan;
static uint8  A_B_Wave2Chan;
static uint8  A_B_Wave1TD;
static uint8  A_B_Wave2TD;


/*******************************************************************************
* Function Name: A_B_Init
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
void A_B_Init(void) 
{
	A_B_VDAC8_Init();
	A_B_VDAC8_SetSpeed(A_B_HIGHSPEED);
	A_B_VDAC8_SetRange(A_B_DAC_RANGE);

	#if(A_B_DAC_MODE == A_B_CURRENT_MODE)
		A_B_IDAC8_SetPolarity(A_B_DAC_POL);
	#endif /* A_B_DAC_MODE == A_B_CURRENT_MODE */

	#if(A_B_OUT_MODE == A_B_BUFFER_MODE)
	   A_B_BuffAmp_Init();
	#endif /* A_B_OUT_MODE == A_B_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	A_B_Wave1TD = CyDmaTdAllocate();
	A_B_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	A_B_Wave1Setup(A_B_wave1, A_B_WAVE1_LENGTH) ;
	A_B_Wave2Setup(A_B_wave2, A_B_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(A_B_DacClk_PHASE)
	   A_B_DacClk_SetPhase(A_B_CLK_PHASE_0nS);
	#endif /* defined(A_B_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: A_B_Enable
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
void A_B_Enable(void) 
{
	A_B_VDAC8_Enable();

	#if(A_B_OUT_MODE == A_B_BUFFER_MODE)
	   A_B_BuffAmp_Enable();
	#endif /* A_B_OUT_MODE == A_B_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(A_B_Wave1Chan, 1u);
	(void)CyDmaChEnable(A_B_Wave2Chan, 1u);
	
	/* set the initial value */
	A_B_SetValue(0u);
	
	#if(A_B_CLOCK_SRC == A_B_CLOCK_INT)  	
	   A_B_DacClk_Start();
	#endif /* A_B_CLOCK_SRC == A_B_CLOCK_INT */
}


/*******************************************************************************
* Function Name: A_B_Start
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
void A_B_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(A_B_initVar == 0u)
	{
		A_B_Init();
		A_B_initVar = 1u;
	}
	
	A_B_Enable();
}


/*******************************************************************************
* Function Name: A_B_StartEx
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
void A_B_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	A_B_Wave1Setup(wavePtr1, sampleSize1);
	A_B_Wave2Setup(wavePtr2, sampleSize2);
	A_B_Start();
}


/*******************************************************************************
* Function Name: A_B_Stop
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
void A_B_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(A_B_CLOCK_SRC == A_B_CLOCK_INT)  	
	   A_B_DacClk_Stop();
	#endif /* A_B_CLOCK_SRC == A_B_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(A_B_Wave1Chan);
	(void)CyDmaChDisable(A_B_Wave2Chan);

	/* Disable power to DAC */
	A_B_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: A_B_Wave1Setup
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
void A_B_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (A_B_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		A_B_Wave1Chan = A_B_Wave1_DMA_DmaInitialize(
		A_B_Wave1_DMA_BYTES_PER_BURST, A_B_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		A_B_Wave1Chan = A_B_Wave1_DMA_DmaInitialize(
		A_B_Wave1_DMA_BYTES_PER_BURST, A_B_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(A_B_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(A_B_Wave1TD, sampleSize, A_B_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)A_B_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(A_B_Wave1TD, LO16((uint32)wavePtr), LO16(A_B_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(A_B_Wave1Chan, A_B_Wave1TD);
}


/*******************************************************************************
* Function Name: A_B_Wave2Setup
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
void A_B_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (A_B_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		A_B_Wave2Chan = A_B_Wave2_DMA_DmaInitialize(
		A_B_Wave2_DMA_BYTES_PER_BURST, A_B_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		A_B_Wave2Chan = A_B_Wave2_DMA_DmaInitialize(
		A_B_Wave2_DMA_BYTES_PER_BURST, A_B_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(A_B_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(A_B_Wave2TD, sampleSize, A_B_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)A_B_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(A_B_Wave2TD, LO16((uint32)wavePtr), LO16(A_B_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(A_B_Wave2Chan, A_B_Wave2TD);
}


/* [] END OF FILE */
