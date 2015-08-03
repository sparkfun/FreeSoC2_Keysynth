/*******************************************************************************
* File Name: A_B.h  
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

#if !defined(CY_WaveDAC8_A_B_H) 
#define CY_WaveDAC8_A_B_H

#include "cytypes.h"
#include "cyfitter.h"
#include <A_B_Wave1_DMA_dma.h>
#include <A_B_Wave2_DMA_dma.h>
#include <A_B_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define A_B_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define A_B_WAVE2_TYPE     (0u)     /* Waveform for wave2 */
#define A_B_SINE_WAVE      (0u)
#define A_B_SQUARE_WAVE    (1u)
#define A_B_TRIANGLE_WAVE  (2u)
#define A_B_SAWTOOTH_WAVE  (3u)
#define A_B_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define A_B_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define A_B_WAVE1_LENGTH   (454u)   /* Length for wave1 */
#define A_B_WAVE2_LENGTH   (405u)   /* Length for wave2 */
	
#define A_B_DEFAULT_RANGE    (0u) /* Default DAC range */
#define A_B_DAC_RANGE_1V     (0u)
#define A_B_DAC_RANGE_1V_BUF (16u)
#define A_B_DAC_RANGE_4V     (1u)
#define A_B_DAC_RANGE_4V_BUF (17u)
#define A_B_VOLT_MODE        (0u)
#define A_B_CURRENT_MODE     (1u)
#define A_B_DAC_MODE         (((A_B_DEFAULT_RANGE == A_B_DAC_RANGE_1V) || \
									  (A_B_DEFAULT_RANGE == A_B_DAC_RANGE_4V) || \
							  		  (A_B_DEFAULT_RANGE == A_B_DAC_RANGE_1V_BUF) || \
									  (A_B_DEFAULT_RANGE == A_B_DAC_RANGE_4V_BUF)) ? \
									   A_B_VOLT_MODE : A_B_CURRENT_MODE)

#define A_B_DACMODE A_B_DAC_MODE /* legacy definition for backward compatibility */

#define A_B_DIRECT_MODE (0u)
#define A_B_BUFFER_MODE (1u)
#define A_B_OUT_MODE    (((A_B_DEFAULT_RANGE == A_B_DAC_RANGE_1V_BUF) || \
								 (A_B_DEFAULT_RANGE == A_B_DAC_RANGE_4V_BUF)) ? \
								  A_B_BUFFER_MODE : A_B_DIRECT_MODE)

#if(A_B_OUT_MODE == A_B_BUFFER_MODE)
    #include <A_B_BuffAmp.h>
#endif /* A_B_OUT_MODE == A_B_BUFFER_MODE */

#define A_B_CLOCK_INT      (1u)
#define A_B_CLOCK_EXT      (0u)
#define A_B_CLOCK_SRC      (1u)

#if(A_B_CLOCK_SRC == A_B_CLOCK_INT)  
	#include <A_B_DacClk.h>
	#if defined(A_B_DacClk_PHASE)
		#define A_B_CLK_PHASE_0nS (1u)
	#endif /* defined(A_B_DacClk_PHASE) */
#endif /* A_B_CLOCK_SRC == A_B_CLOCK_INT */

#if (CY_PSOC3)
	#define A_B_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define A_B_Wave1_DMA_BYTES_PER_BURST      (1u)
#define A_B_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define A_B_Wave2_DMA_BYTES_PER_BURST      (1u)
#define A_B_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}A_B_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void A_B_Start(void)             ;
void A_B_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void A_B_Init(void)              ;
void A_B_Enable(void)            ;
void A_B_Stop(void)              ;

void A_B_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void A_B_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void A_B_Sleep(void)             ;
void A_B_Wakeup(void)            ;

#define A_B_SetSpeed(speed)      A_B_VDAC8_SetSpeed(speed)
#define A_B_SetRange(range)      A_B_VDAC8_SetRange(range)
#define A_B_SetValue(value)      A_B_VDAC8_SetValue(value)
#define A_B_DacTrim(void)        A_B_VDAC8_DacTrim()
#define A_B_SaveConfig(void)     A_B_VDAC8_SaveConfig()
#define A_B_RestoreConfig(void)  A_B_VDAC8_RestoreConfig()


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 A_B_initVar;

extern const uint8 CYCODE A_B_wave1[A_B_WAVE1_LENGTH];
extern const uint8 CYCODE A_B_wave2[A_B_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(A_B_DAC_MODE == A_B_VOLT_MODE)
    #define A_B_RANGE_1V       (0x00u)
    #define A_B_RANGE_4V       (0x04u)
#else /* current mode */
    #define A_B_RANGE_32uA     (0x00u)
    #define A_B_RANGE_255uA    (0x04u)
    #define A_B_RANGE_2mA      (0x08u)
    #define A_B_RANGE_2048uA   A_B_RANGE_2mA
#endif /* A_B_DAC_MODE == A_B_VOLT_MODE */

/* Power setting for SetSpeed API */
#define A_B_LOWSPEED       (0x00u)
#define A_B_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define A_B_DAC8__D A_B_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define A_B_HS_MASK        (0x02u)
#define A_B_HS_LOWPOWER    (0x00u)
#define A_B_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define A_B_MODE_MASK      (0x10u)
#define A_B_MODE_V         (0x00u)
#define A_B_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define A_B_RANGE_MASK     (0x0Cu)
#define A_B_RANGE_0        (0x00u)
#define A_B_RANGE_1        (0x04u)
#define A_B_RANGE_2        (0x08u)
#define A_B_RANGE_3        (0x0Cu)
#define A_B_IDIR_MASK      (0x04u)

#define A_B_DAC_RANGE      ((uint8)(0u << 2u) & A_B_RANGE_MASK)
#define A_B_DAC_POL        ((uint8)(0u >> 1u) & A_B_IDIR_MASK)


#endif /* CY_WaveDAC8_A_B_H  */

/* [] END OF FILE */
