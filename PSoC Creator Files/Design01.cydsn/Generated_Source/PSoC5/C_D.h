/*******************************************************************************
* File Name: C_D.h  
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the 8-bit Waveform DAC (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_WaveDAC8_C_D_H) 
#define CY_WaveDAC8_C_D_H

#include "cytypes.h"
#include "cyfitter.h"
#include <C_D_Wave1_DMA_dma.h>
#include <C_D_Wave2_DMA_dma.h>
#include <C_D_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define C_D_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define C_D_WAVE2_TYPE     (0u)     /* Waveform for wave2 */
#define C_D_SINE_WAVE      (0u)
#define C_D_SQUARE_WAVE    (1u)
#define C_D_TRIANGLE_WAVE  (2u)
#define C_D_SAWTOOTH_WAVE  (3u)
#define C_D_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define C_D_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define C_D_WAVE1_LENGTH   (382u)   /* Length for wave1 */
#define C_D_WAVE2_LENGTH   (341u)   /* Length for wave2 */
	
#define C_D_DEFAULT_RANGE    (0u) /* Default DAC range */
#define C_D_DAC_RANGE_1V     (0u)
#define C_D_DAC_RANGE_1V_BUF (16u)
#define C_D_DAC_RANGE_4V     (1u)
#define C_D_DAC_RANGE_4V_BUF (17u)
#define C_D_VOLT_MODE        (0u)
#define C_D_CURRENT_MODE     (1u)
#define C_D_DAC_MODE         (((C_D_DEFAULT_RANGE == C_D_DAC_RANGE_1V) || \
									  (C_D_DEFAULT_RANGE == C_D_DAC_RANGE_4V) || \
							  		  (C_D_DEFAULT_RANGE == C_D_DAC_RANGE_1V_BUF) || \
									  (C_D_DEFAULT_RANGE == C_D_DAC_RANGE_4V_BUF)) ? \
									   C_D_VOLT_MODE : C_D_CURRENT_MODE)

#define C_D_DACMODE C_D_DAC_MODE /* legacy definition for backward compatibility */

#define C_D_DIRECT_MODE (0u)
#define C_D_BUFFER_MODE (1u)
#define C_D_OUT_MODE    (((C_D_DEFAULT_RANGE == C_D_DAC_RANGE_1V_BUF) || \
								 (C_D_DEFAULT_RANGE == C_D_DAC_RANGE_4V_BUF)) ? \
								  C_D_BUFFER_MODE : C_D_DIRECT_MODE)

#if(C_D_OUT_MODE == C_D_BUFFER_MODE)
    #include <C_D_BuffAmp.h>
#endif /* C_D_OUT_MODE == C_D_BUFFER_MODE */

#define C_D_CLOCK_INT      (1u)
#define C_D_CLOCK_EXT      (0u)
#define C_D_CLOCK_SRC      (1u)

#if(C_D_CLOCK_SRC == C_D_CLOCK_INT)  
	#include <C_D_DacClk.h>
	#if defined(C_D_DacClk_PHASE)
		#define C_D_CLK_PHASE_0nS (1u)
	#endif /* defined(C_D_DacClk_PHASE) */
#endif /* C_D_CLOCK_SRC == C_D_CLOCK_INT */

#if (CY_PSOC3)
	#define C_D_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define C_D_Wave1_DMA_BYTES_PER_BURST      (1u)
#define C_D_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define C_D_Wave2_DMA_BYTES_PER_BURST      (1u)
#define C_D_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}C_D_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void C_D_Start(void)             ;
void C_D_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void C_D_Init(void)              ;
void C_D_Enable(void)            ;
void C_D_Stop(void)              ;

void C_D_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void C_D_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void C_D_Sleep(void)             ;
void C_D_Wakeup(void)            ;

#define C_D_SetSpeed(speed)      C_D_VDAC8_SetSpeed(speed)
#define C_D_SetRange(range)      C_D_VDAC8_SetRange(range)
#define C_D_SetValue(value)      C_D_VDAC8_SetValue(value)
#define C_D_DacTrim(void)        C_D_VDAC8_DacTrim()
#define C_D_SaveConfig(void)     C_D_VDAC8_SaveConfig()
#define C_D_RestoreConfig(void)  C_D_VDAC8_RestoreConfig()


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 C_D_initVar;

extern const uint8 CYCODE C_D_wave1[C_D_WAVE1_LENGTH];
extern const uint8 CYCODE C_D_wave2[C_D_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(C_D_DAC_MODE == C_D_VOLT_MODE)
    #define C_D_RANGE_1V       (0x00u)
    #define C_D_RANGE_4V       (0x04u)
#else /* current mode */
    #define C_D_RANGE_32uA     (0x00u)
    #define C_D_RANGE_255uA    (0x04u)
    #define C_D_RANGE_2mA      (0x08u)
    #define C_D_RANGE_2048uA   C_D_RANGE_2mA
#endif /* C_D_DAC_MODE == C_D_VOLT_MODE */

/* Power setting for SetSpeed API */
#define C_D_LOWSPEED       (0x00u)
#define C_D_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define C_D_DAC8__D C_D_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define C_D_HS_MASK        (0x02u)
#define C_D_HS_LOWPOWER    (0x00u)
#define C_D_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define C_D_MODE_MASK      (0x10u)
#define C_D_MODE_V         (0x00u)
#define C_D_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define C_D_RANGE_MASK     (0x0Cu)
#define C_D_RANGE_0        (0x00u)
#define C_D_RANGE_1        (0x04u)
#define C_D_RANGE_2        (0x08u)
#define C_D_RANGE_3        (0x0Cu)
#define C_D_IDIR_MASK      (0x04u)

#define C_D_DAC_RANGE      ((uint8)(0u << 2u) & C_D_RANGE_MASK)
#define C_D_DAC_POL        ((uint8)(0u >> 1u) & C_D_IDIR_MASK)


#endif /* CY_WaveDAC8_C_D_H  */

/* [] END OF FILE */
