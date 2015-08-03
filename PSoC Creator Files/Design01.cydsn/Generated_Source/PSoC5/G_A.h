/*******************************************************************************
* File Name: G_A.h  
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

#if !defined(CY_WaveDAC8_G_A_H) 
#define CY_WaveDAC8_G_A_H

#include "cytypes.h"
#include "cyfitter.h"
#include <G_A_Wave1_DMA_dma.h>
#include <G_A_Wave2_DMA_dma.h>
#include <G_A_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define G_A_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define G_A_WAVE2_TYPE     (0u)     /* Waveform for wave2 */
#define G_A_SINE_WAVE      (0u)
#define G_A_SQUARE_WAVE    (1u)
#define G_A_TRIANGLE_WAVE  (2u)
#define G_A_SAWTOOTH_WAVE  (3u)
#define G_A_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define G_A_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define G_A_WAVE1_LENGTH   (255u)   /* Length for wave1 */
#define G_A_WAVE2_LENGTH   (227u)   /* Length for wave2 */
	
#define G_A_DEFAULT_RANGE    (0u) /* Default DAC range */
#define G_A_DAC_RANGE_1V     (0u)
#define G_A_DAC_RANGE_1V_BUF (16u)
#define G_A_DAC_RANGE_4V     (1u)
#define G_A_DAC_RANGE_4V_BUF (17u)
#define G_A_VOLT_MODE        (0u)
#define G_A_CURRENT_MODE     (1u)
#define G_A_DAC_MODE         (((G_A_DEFAULT_RANGE == G_A_DAC_RANGE_1V) || \
									  (G_A_DEFAULT_RANGE == G_A_DAC_RANGE_4V) || \
							  		  (G_A_DEFAULT_RANGE == G_A_DAC_RANGE_1V_BUF) || \
									  (G_A_DEFAULT_RANGE == G_A_DAC_RANGE_4V_BUF)) ? \
									   G_A_VOLT_MODE : G_A_CURRENT_MODE)

#define G_A_DACMODE G_A_DAC_MODE /* legacy definition for backward compatibility */

#define G_A_DIRECT_MODE (0u)
#define G_A_BUFFER_MODE (1u)
#define G_A_OUT_MODE    (((G_A_DEFAULT_RANGE == G_A_DAC_RANGE_1V_BUF) || \
								 (G_A_DEFAULT_RANGE == G_A_DAC_RANGE_4V_BUF)) ? \
								  G_A_BUFFER_MODE : G_A_DIRECT_MODE)

#if(G_A_OUT_MODE == G_A_BUFFER_MODE)
    #include <G_A_BuffAmp.h>
#endif /* G_A_OUT_MODE == G_A_BUFFER_MODE */

#define G_A_CLOCK_INT      (1u)
#define G_A_CLOCK_EXT      (0u)
#define G_A_CLOCK_SRC      (1u)

#if(G_A_CLOCK_SRC == G_A_CLOCK_INT)  
	#include <G_A_DacClk.h>
	#if defined(G_A_DacClk_PHASE)
		#define G_A_CLK_PHASE_0nS (1u)
	#endif /* defined(G_A_DacClk_PHASE) */
#endif /* G_A_CLOCK_SRC == G_A_CLOCK_INT */

#if (CY_PSOC3)
	#define G_A_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define G_A_Wave1_DMA_BYTES_PER_BURST      (1u)
#define G_A_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define G_A_Wave2_DMA_BYTES_PER_BURST      (1u)
#define G_A_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}G_A_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void G_A_Start(void)             ;
void G_A_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void G_A_Init(void)              ;
void G_A_Enable(void)            ;
void G_A_Stop(void)              ;

void G_A_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void G_A_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void G_A_Sleep(void)             ;
void G_A_Wakeup(void)            ;

#define G_A_SetSpeed(speed)      G_A_VDAC8_SetSpeed(speed)
#define G_A_SetRange(range)      G_A_VDAC8_SetRange(range)
#define G_A_SetValue(value)      G_A_VDAC8_SetValue(value)
#define G_A_DacTrim(void)        G_A_VDAC8_DacTrim()
#define G_A_SaveConfig(void)     G_A_VDAC8_SaveConfig()
#define G_A_RestoreConfig(void)  G_A_VDAC8_RestoreConfig()


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 G_A_initVar;

extern const uint8 CYCODE G_A_wave1[G_A_WAVE1_LENGTH];
extern const uint8 CYCODE G_A_wave2[G_A_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(G_A_DAC_MODE == G_A_VOLT_MODE)
    #define G_A_RANGE_1V       (0x00u)
    #define G_A_RANGE_4V       (0x04u)
#else /* current mode */
    #define G_A_RANGE_32uA     (0x00u)
    #define G_A_RANGE_255uA    (0x04u)
    #define G_A_RANGE_2mA      (0x08u)
    #define G_A_RANGE_2048uA   G_A_RANGE_2mA
#endif /* G_A_DAC_MODE == G_A_VOLT_MODE */

/* Power setting for SetSpeed API */
#define G_A_LOWSPEED       (0x00u)
#define G_A_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define G_A_DAC8__D G_A_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define G_A_HS_MASK        (0x02u)
#define G_A_HS_LOWPOWER    (0x00u)
#define G_A_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define G_A_MODE_MASK      (0x10u)
#define G_A_MODE_V         (0x00u)
#define G_A_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define G_A_RANGE_MASK     (0x0Cu)
#define G_A_RANGE_0        (0x00u)
#define G_A_RANGE_1        (0x04u)
#define G_A_RANGE_2        (0x08u)
#define G_A_RANGE_3        (0x0Cu)
#define G_A_IDIR_MASK      (0x04u)

#define G_A_DAC_RANGE      ((uint8)(0u << 2u) & G_A_RANGE_MASK)
#define G_A_DAC_POL        ((uint8)(0u >> 1u) & G_A_IDIR_MASK)


#endif /* CY_WaveDAC8_G_A_H  */

/* [] END OF FILE */
