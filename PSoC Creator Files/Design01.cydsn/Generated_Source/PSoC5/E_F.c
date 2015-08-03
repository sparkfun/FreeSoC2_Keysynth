/*******************************************************************************
* File Name: E_F.c
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

#include "E_F.h"

uint8  E_F_initVar = 0u;

const uint8 CYCODE E_F_wave1[E_F_WAVE1_LENGTH] = { 128u,130u,133u,135u,138u,140u,143u,146u,148u,151u,153u,156u,158u,161u,163u,166u,168u,171u,173u,175u,178u,180u,183u,185u,187u,189u,192u,194u,196u,198u,200u,202u,204u,207u,209u,210u,212u,214u,216u,218u,220u,221u,223u,225u,226u,228u,229u,231u,232u,234u,235u,236u,238u,239u,240u,241u,242u,243u,244u,245u,246u,247u,247u,248u,249u,249u,250u,250u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,251u,250u,250u,249u,248u,248u,247u,246u,245u,245u,244u,243u,242u,241u,239u,238u,237u,236u,234u,233u,232u,230u,229u,227u,226u,224u,222u,221u,219u,217u,215u,213u,211u,209u,208u,206u,203u,201u,199u,197u,195u,193u,191u,188u,186u,184u,181u,179u,177u,174u,172u,169u,167u,165u,162u,160u,157u,155u,152u,149u,147u,144u,142u,139u,137u,134u,131u,129u,126u,124u,121u,118u,116u,113u,111u,108u,106u,103u,100u,98u,95u,93u,90u,88u,86u,83u,81u,78u,76u,74u,71u,69u,67u,64u,62u,60u,58u,56u,54u,52u,49u,47u,46u,44u,42u,40u,38u,36u,34u,33u,31u,29u,28u,26u,25u,23u,22u,21u,19u,18u,17u,16u,14u,13u,12u,11u,10u,10u,9u,8u,7u,7u,6u,5u,5u,4u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,5u,5u,6u,6u,7u,8u,8u,9u,10u,11u,12u,13u,14u,15u,16u,17u,19u,20u,21u,23u,24u,26u,27u,29u,30u,32u,34u,35u,37u,39u,41u,43u,45u,46u,48u,51u,53u,55u,57u,59u,61u,63u,66u,68u,70u,72u,75u,77u,80u,82u,84u,87u,89u,92u,94u,97u,99u,102u,104u,107u,109u,112u,115u,117u,120u,122u,125u };
const uint8 CYCODE E_F_wave2[E_F_WAVE2_LENGTH] = { 128u,130u,133u,136u,138u,141u,144u,147u,149u,152u,155u,157u,160u,163u,165u,168u,171u,173u,176u,178u,181u,183u,186u,188u,190u,193u,195u,197u,200u,202u,204u,206u,208u,210u,212u,214u,216u,218u,220u,222u,224u,225u,227u,229u,230u,232u,233u,235u,236u,238u,239u,240u,241u,242u,243u,244u,245u,246u,247u,248u,249u,249u,250u,250u,251u,251u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,252u,251u,251u,250u,250u,249u,249u,248u,247u,246u,245u,244u,243u,242u,241u,240u,239u,238u,236u,235u,233u,232u,230u,229u,227u,225u,224u,222u,220u,218u,216u,214u,212u,210u,208u,206u,204u,202u,200u,197u,195u,193u,190u,188u,186u,183u,181u,178u,176u,173u,171u,168u,165u,163u,160u,157u,155u,152u,149u,147u,144u,141u,138u,136u,133u,130u,128u,125u,122u,119u,117u,114u,111u,108u,106u,103u,100u,98u,95u,92u,90u,87u,84u,82u,79u,77u,74u,72u,69u,67u,65u,62u,60u,58u,55u,53u,51u,49u,47u,45u,43u,41u,39u,37u,35u,33u,31u,30u,28u,26u,25u,23u,22u,20u,19u,17u,16u,15u,14u,13u,12u,11u,10u,9u,8u,7u,6u,6u,5u,5u,4u,4u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,3u,4u,4u,5u,5u,6u,6u,7u,8u,9u,10u,11u,12u,13u,14u,15u,16u,17u,19u,20u,22u,23u,25u,26u,28u,30u,31u,33u,35u,37u,39u,41u,43u,45u,47u,49u,51u,53u,55u,58u,60u,62u,65u,67u,69u,72u,74u,77u,79u,82u,84u,87u,90u,92u,95u,98u,100u,103u,106u,108u,111u,114u,117u,119u,122u,125u };

static uint8  E_F_Wave1Chan;
static uint8  E_F_Wave2Chan;
static uint8  E_F_Wave1TD;
static uint8  E_F_Wave2TD;


/*******************************************************************************
* Function Name: E_F_Init
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
void E_F_Init(void) 
{
	E_F_VDAC8_Init();
	E_F_VDAC8_SetSpeed(E_F_HIGHSPEED);
	E_F_VDAC8_SetRange(E_F_DAC_RANGE);

	#if(E_F_DAC_MODE == E_F_CURRENT_MODE)
		E_F_IDAC8_SetPolarity(E_F_DAC_POL);
	#endif /* E_F_DAC_MODE == E_F_CURRENT_MODE */

	#if(E_F_OUT_MODE == E_F_BUFFER_MODE)
	   E_F_BuffAmp_Init();
	#endif /* E_F_OUT_MODE == E_F_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	E_F_Wave1TD = CyDmaTdAllocate();
	E_F_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	E_F_Wave1Setup(E_F_wave1, E_F_WAVE1_LENGTH) ;
	E_F_Wave2Setup(E_F_wave2, E_F_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(E_F_DacClk_PHASE)
	   E_F_DacClk_SetPhase(E_F_CLK_PHASE_0nS);
	#endif /* defined(E_F_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: E_F_Enable
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
void E_F_Enable(void) 
{
	E_F_VDAC8_Enable();

	#if(E_F_OUT_MODE == E_F_BUFFER_MODE)
	   E_F_BuffAmp_Enable();
	#endif /* E_F_OUT_MODE == E_F_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(E_F_Wave1Chan, 1u);
	(void)CyDmaChEnable(E_F_Wave2Chan, 1u);
	
	/* set the initial value */
	E_F_SetValue(0u);
	
	#if(E_F_CLOCK_SRC == E_F_CLOCK_INT)  	
	   E_F_DacClk_Start();
	#endif /* E_F_CLOCK_SRC == E_F_CLOCK_INT */
}


/*******************************************************************************
* Function Name: E_F_Start
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
void E_F_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(E_F_initVar == 0u)
	{
		E_F_Init();
		E_F_initVar = 1u;
	}
	
	E_F_Enable();
}


/*******************************************************************************
* Function Name: E_F_StartEx
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
void E_F_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	E_F_Wave1Setup(wavePtr1, sampleSize1);
	E_F_Wave2Setup(wavePtr2, sampleSize2);
	E_F_Start();
}


/*******************************************************************************
* Function Name: E_F_Stop
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
void E_F_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(E_F_CLOCK_SRC == E_F_CLOCK_INT)  	
	   E_F_DacClk_Stop();
	#endif /* E_F_CLOCK_SRC == E_F_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(E_F_Wave1Chan);
	(void)CyDmaChDisable(E_F_Wave2Chan);

	/* Disable power to DAC */
	E_F_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: E_F_Wave1Setup
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
void E_F_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (E_F_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		E_F_Wave1Chan = E_F_Wave1_DMA_DmaInitialize(
		E_F_Wave1_DMA_BYTES_PER_BURST, E_F_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		E_F_Wave1Chan = E_F_Wave1_DMA_DmaInitialize(
		E_F_Wave1_DMA_BYTES_PER_BURST, E_F_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(E_F_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(E_F_Wave1TD, sampleSize, E_F_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)E_F_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(E_F_Wave1TD, LO16((uint32)wavePtr), LO16(E_F_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(E_F_Wave1Chan, E_F_Wave1TD);
}


/*******************************************************************************
* Function Name: E_F_Wave2Setup
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
void E_F_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (E_F_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		E_F_Wave2Chan = E_F_Wave2_DMA_DmaInitialize(
		E_F_Wave2_DMA_BYTES_PER_BURST, E_F_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		E_F_Wave2Chan = E_F_Wave2_DMA_DmaInitialize(
		E_F_Wave2_DMA_BYTES_PER_BURST, E_F_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(E_F_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(E_F_Wave2TD, sampleSize, E_F_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)E_F_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(E_F_Wave2TD, LO16((uint32)wavePtr), LO16(E_F_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(E_F_Wave2Chan, E_F_Wave2TD);
}


/* [] END OF FILE */
