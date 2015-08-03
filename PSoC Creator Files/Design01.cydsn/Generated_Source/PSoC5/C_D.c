/*******************************************************************************
* File Name: C_D.c
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

#include "C_D.h"

uint8  C_D_initVar = 0u;

const uint8 CYCODE C_D_wave1[C_D_WAVE1_LENGTH] = { 128u,130u,132u,134u,136u,138u,140u,142u,144u,146u,148u,150u,152u,154u,156u,158u,160u,162u,164u,166u,168u,170u,172u,174u,176u,177u,179u,181u,183u,185u,187u,189u,190u,192u,194u,196u,197u,199u,201u,202u,204u,206u,207u,209u,210u,212u,213u,215u,216u,218u,219u,220u,222u,223u,224u,226u,227u,228u,229u,231u,232u,233u,234u,235u,236u,237u,238u,239u,240u,241u,242u,242u,243u,244u,245u,245u,246u,247u,247u,248u,248u,249u,249u,250u,250u,251u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,251u,250u,250u,249u,249u,248u,248u,247u,247u,246u,245u,245u,244u,243u,242u,242u,241u,240u,239u,238u,237u,236u,235u,234u,233u,232u,231u,229u,228u,227u,226u,224u,223u,222u,220u,219u,218u,216u,215u,213u,212u,210u,209u,207u,206u,204u,202u,201u,199u,197u,196u,194u,192u,190u,189u,187u,185u,183u,181u,179u,177u,176u,174u,172u,170u,168u,166u,164u,162u,160u,158u,156u,154u,152u,150u,148u,146u,144u,142u,140u,138u,136u,134u,132u,130u,128u,125u,123u,121u,119u,117u,115u,113u,111u,109u,107u,105u,103u,101u,99u,97u,95u,93u,91u,89u,87u,85u,83u,81u,79u,78u,76u,74u,72u,70u,68u,66u,65u,63u,61u,59u,58u,56u,54u,53u,51u,49u,48u,46u,45u,43u,42u,40u,39u,37u,36u,35u,33u,32u,31u,29u,28u,27u,26u,24u,23u,22u,21u,20u,19u,18u,17u,16u,15u,14u,13u,13u,12u,11u,10u,10u,9u,8u,8u,7u,7u,6u,6u,5u,5u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,4u,5u,5u,6u,6u,7u,7u,8u,8u,9u,10u,10u,11u,12u,13u,13u,14u,15u,16u,17u,18u,19u,20u,21u,22u,23u,24u,26u,27u,28u,29u,31u,32u,33u,35u,36u,37u,39u,40u,42u,43u,45u,46u,48u,49u,51u,53u,54u,56u,58u,59u,61u,63u,65u,66u,68u,70u,72u,74u,76u,78u,79u,81u,83u,85u,87u,89u,91u,93u,95u,97u,99u,101u,103u,105u,107u,109u,111u,113u,115u,117u,119u,121u,123u,125u };
const uint8 CYCODE C_D_wave2[C_D_WAVE2_LENGTH] = { 128u,130u,132u,134u,137u,139u,141u,144u,146u,148u,150u,153u,155u,157u,159u,162u,164u,166u,168u,170u,173u,175u,177u,179u,181u,183u,185u,187u,189u,191u,193u,195u,197u,199u,201u,203u,204u,206u,208u,210u,212u,213u,215u,216u,218u,220u,221u,223u,224u,226u,227u,228u,230u,231u,232u,234u,235u,236u,237u,238u,239u,240u,241u,242u,243u,244u,245u,245u,246u,247u,248u,248u,249u,249u,250u,250u,251u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,250u,250u,250u,249u,249u,248u,247u,247u,246u,245u,244u,243u,243u,242u,241u,240u,239u,238u,237u,235u,234u,233u,232u,230u,229u,228u,226u,225u,223u,222u,220u,219u,217u,216u,214u,212u,211u,209u,207u,205u,204u,202u,200u,198u,196u,194u,192u,190u,188u,186u,184u,182u,180u,178u,176u,174u,171u,169u,167u,165u,163u,161u,158u,156u,154u,152u,149u,147u,145u,142u,140u,138u,136u,133u,131u,129u,126u,124u,122u,119u,117u,115u,113u,110u,108u,106u,103u,101u,99u,97u,94u,92u,90u,88u,86u,84u,81u,79u,77u,75u,73u,71u,69u,67u,65u,63u,61u,59u,57u,55u,53u,51u,50u,48u,46u,44u,43u,41u,39u,38u,36u,35u,33u,32u,30u,29u,27u,26u,25u,23u,22u,21u,20u,18u,17u,16u,15u,14u,13u,12u,12u,11u,10u,9u,8u,8u,7u,6u,6u,5u,5u,5u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,4u,5u,5u,6u,6u,7u,7u,8u,9u,10u,10u,11u,12u,13u,14u,15u,16u,17u,18u,19u,20u,21u,23u,24u,25u,27u,28u,29u,31u,32u,34u,35u,37u,39u,40u,42u,43u,45u,47u,49u,51u,52u,54u,56u,58u,60u,62u,64u,66u,68u,70u,72u,74u,76u,78u,80u,82u,85u,87u,89u,91u,93u,96u,98u,100u,102u,105u,107u,109u,111u,114u,116u,118u,121u,123u,125u };

static uint8  C_D_Wave1Chan;
static uint8  C_D_Wave2Chan;
static uint8  C_D_Wave1TD;
static uint8  C_D_Wave2TD;


/*******************************************************************************
* Function Name: C_D_Init
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
void C_D_Init(void) 
{
	C_D_VDAC8_Init();
	C_D_VDAC8_SetSpeed(C_D_HIGHSPEED);
	C_D_VDAC8_SetRange(C_D_DAC_RANGE);

	#if(C_D_DAC_MODE == C_D_CURRENT_MODE)
		C_D_IDAC8_SetPolarity(C_D_DAC_POL);
	#endif /* C_D_DAC_MODE == C_D_CURRENT_MODE */

	#if(C_D_OUT_MODE == C_D_BUFFER_MODE)
	   C_D_BuffAmp_Init();
	#endif /* C_D_OUT_MODE == C_D_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	C_D_Wave1TD = CyDmaTdAllocate();
	C_D_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	C_D_Wave1Setup(C_D_wave1, C_D_WAVE1_LENGTH) ;
	C_D_Wave2Setup(C_D_wave2, C_D_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(C_D_DacClk_PHASE)
	   C_D_DacClk_SetPhase(C_D_CLK_PHASE_0nS);
	#endif /* defined(C_D_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: C_D_Enable
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
void C_D_Enable(void) 
{
	C_D_VDAC8_Enable();

	#if(C_D_OUT_MODE == C_D_BUFFER_MODE)
	   C_D_BuffAmp_Enable();
	#endif /* C_D_OUT_MODE == C_D_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(C_D_Wave1Chan, 1u);
	(void)CyDmaChEnable(C_D_Wave2Chan, 1u);
	
	/* set the initial value */
	C_D_SetValue(0u);
	
	#if(C_D_CLOCK_SRC == C_D_CLOCK_INT)  	
	   C_D_DacClk_Start();
	#endif /* C_D_CLOCK_SRC == C_D_CLOCK_INT */
}


/*******************************************************************************
* Function Name: C_D_Start
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
void C_D_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(C_D_initVar == 0u)
	{
		C_D_Init();
		C_D_initVar = 1u;
	}
	
	C_D_Enable();
}


/*******************************************************************************
* Function Name: C_D_StartEx
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
void C_D_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	C_D_Wave1Setup(wavePtr1, sampleSize1);
	C_D_Wave2Setup(wavePtr2, sampleSize2);
	C_D_Start();
}


/*******************************************************************************
* Function Name: C_D_Stop
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
void C_D_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(C_D_CLOCK_SRC == C_D_CLOCK_INT)  	
	   C_D_DacClk_Stop();
	#endif /* C_D_CLOCK_SRC == C_D_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(C_D_Wave1Chan);
	(void)CyDmaChDisable(C_D_Wave2Chan);

	/* Disable power to DAC */
	C_D_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: C_D_Wave1Setup
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
void C_D_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (C_D_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		C_D_Wave1Chan = C_D_Wave1_DMA_DmaInitialize(
		C_D_Wave1_DMA_BYTES_PER_BURST, C_D_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		C_D_Wave1Chan = C_D_Wave1_DMA_DmaInitialize(
		C_D_Wave1_DMA_BYTES_PER_BURST, C_D_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(C_D_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(C_D_Wave1TD, sampleSize, C_D_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)C_D_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(C_D_Wave1TD, LO16((uint32)wavePtr), LO16(C_D_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(C_D_Wave1Chan, C_D_Wave1TD);
}


/*******************************************************************************
* Function Name: C_D_Wave2Setup
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
void C_D_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (C_D_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		C_D_Wave2Chan = C_D_Wave2_DMA_DmaInitialize(
		C_D_Wave2_DMA_BYTES_PER_BURST, C_D_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		C_D_Wave2Chan = C_D_Wave2_DMA_DmaInitialize(
		C_D_Wave2_DMA_BYTES_PER_BURST, C_D_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(C_D_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(C_D_Wave2TD, sampleSize, C_D_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)C_D_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(C_D_Wave2TD, LO16((uint32)wavePtr), LO16(C_D_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(C_D_Wave2Chan, C_D_Wave2TD);
}


/* [] END OF FILE */
