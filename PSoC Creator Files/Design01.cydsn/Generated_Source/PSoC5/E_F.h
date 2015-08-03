/*******************************************************************************
* File Name: E_F.h  
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

#if !defined(CY_WaveDAC8_E_F_H) 
#define CY_WaveDAC8_E_F_H

#include "cytypes.h"
#include "cyfitter.h"
#include <E_F_Wave1_DMA_dma.h>
#include <E_F_Wave2_DMA_dma.h>
#include <E_F_VDAC8.h>


/***************************************
*  Initial Parameter Constants
***************************************/

#define E_F_WAVE1_TYPE     (0u)     /* Waveform for wave1 */
#define E_F_WAVE2_TYPE     (0u)     /* Waveform for wave2 */
#define E_F_SINE_WAVE      (0u)
#define E_F_SQUARE_WAVE    (1u)
#define E_F_TRIANGLE_WAVE  (2u)
#define E_F_SAWTOOTH_WAVE  (3u)
#define E_F_ARB_DRAW_WAVE  (10u) /* Arbitrary (draw) */
#define E_F_ARB_FILE_WAVE  (11u) /* Arbitrary (from file) */

#define E_F_WAVE1_LENGTH   (303u)   /* Length for wave1 */
#define E_F_WAVE2_LENGTH   (286u)   /* Length for wave2 */
	
#define E_F_DEFAULT_RANGE    (0u) /* Default DAC range */
#define E_F_DAC_RANGE_1V     (0u)
#define E_F_DAC_RANGE_1V_BUF (16u)
#define E_F_DAC_RANGE_4V     (1u)
#define E_F_DAC_RANGE_4V_BUF (17u)
#define E_F_VOLT_MODE        (0u)
#define E_F_CURRENT_MODE     (1u)
#define E_F_DAC_MODE         (((E_F_DEFAULT_RANGE == E_F_DAC_RANGE_1V) || \
									  (E_F_DEFAULT_RANGE == E_F_DAC_RANGE_4V) || \
							  		  (E_F_DEFAULT_RANGE == E_F_DAC_RANGE_1V_BUF) || \
									  (E_F_DEFAULT_RANGE == E_F_DAC_RANGE_4V_BUF)) ? \
									   E_F_VOLT_MODE : E_F_CURRENT_MODE)

#define E_F_DACMODE E_F_DAC_MODE /* legacy definition for backward compatibility */

#define E_F_DIRECT_MODE (0u)
#define E_F_BUFFER_MODE (1u)
#define E_F_OUT_MODE    (((E_F_DEFAULT_RANGE == E_F_DAC_RANGE_1V_BUF) || \
								 (E_F_DEFAULT_RANGE == E_F_DAC_RANGE_4V_BUF)) ? \
								  E_F_BUFFER_MODE : E_F_DIRECT_MODE)

#if(E_F_OUT_MODE == E_F_BUFFER_MODE)
    #include <E_F_BuffAmp.h>
#endif /* E_F_OUT_MODE == E_F_BUFFER_MODE */

#define E_F_CLOCK_INT      (1u)
#define E_F_CLOCK_EXT      (0u)
#define E_F_CLOCK_SRC      (1u)

#if(E_F_CLOCK_SRC == E_F_CLOCK_INT)  
	#include <E_F_DacClk.h>
	#if defined(E_F_DacClk_PHASE)
		#define E_F_CLK_PHASE_0nS (1u)
	#endif /* defined(E_F_DacClk_PHASE) */
#endif /* E_F_CLOCK_SRC == E_F_CLOCK_INT */

#if (CY_PSOC3)
	#define E_F_HI16FLASHPTR   (0xFFu)
#endif /* CY_PSOC3 */

#define E_F_Wave1_DMA_BYTES_PER_BURST      (1u)
#define E_F_Wave1_DMA_REQUEST_PER_BURST    (1u)
#define E_F_Wave2_DMA_BYTES_PER_BURST      (1u)
#define E_F_Wave2_DMA_REQUEST_PER_BURST    (1u)


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
	uint8   enableState;
}E_F_BACKUP_STRUCT;


/***************************************
*        Function Prototypes 
***************************************/

void E_F_Start(void)             ;
void E_F_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)
                                        ;
void E_F_Init(void)              ;
void E_F_Enable(void)            ;
void E_F_Stop(void)              ;

void E_F_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;
void E_F_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
                                        ;

void E_F_Sleep(void)             ;
void E_F_Wakeup(void)            ;

#define E_F_SetSpeed(speed)      E_F_VDAC8_SetSpeed(speed)
#define E_F_SetRange(range)      E_F_VDAC8_SetRange(range)
#define E_F_SetValue(value)      E_F_VDAC8_SetValue(value)
#define E_F_DacTrim(void)        E_F_VDAC8_DacTrim()
#define E_F_SaveConfig(void)     E_F_VDAC8_SaveConfig()
#define E_F_RestoreConfig(void)  E_F_VDAC8_RestoreConfig()


/***************************************
*    Variable with external linkage 
***************************************/

extern uint8 E_F_initVar;

extern const uint8 CYCODE E_F_wave1[E_F_WAVE1_LENGTH];
extern const uint8 CYCODE E_F_wave2[E_F_WAVE2_LENGTH];


/***************************************
*            API Constants
***************************************/

/* SetRange constants */
#if(E_F_DAC_MODE == E_F_VOLT_MODE)
    #define E_F_RANGE_1V       (0x00u)
    #define E_F_RANGE_4V       (0x04u)
#else /* current mode */
    #define E_F_RANGE_32uA     (0x00u)
    #define E_F_RANGE_255uA    (0x04u)
    #define E_F_RANGE_2mA      (0x08u)
    #define E_F_RANGE_2048uA   E_F_RANGE_2mA
#endif /* E_F_DAC_MODE == E_F_VOLT_MODE */

/* Power setting for SetSpeed API */
#define E_F_LOWSPEED       (0x00u)
#define E_F_HIGHSPEED      (0x02u)


/***************************************
*              Registers        
***************************************/

#define E_F_DAC8__D E_F_VDAC8_viDAC8__D


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE */
#define E_F_HS_MASK        (0x02u)
#define E_F_HS_LOWPOWER    (0x00u)
#define E_F_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE */
#define E_F_MODE_MASK      (0x10u)
#define E_F_MODE_V         (0x00u)
#define E_F_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE */
#define E_F_RANGE_MASK     (0x0Cu)
#define E_F_RANGE_0        (0x00u)
#define E_F_RANGE_1        (0x04u)
#define E_F_RANGE_2        (0x08u)
#define E_F_RANGE_3        (0x0Cu)
#define E_F_IDIR_MASK      (0x04u)

#define E_F_DAC_RANGE      ((uint8)(0u << 2u) & E_F_RANGE_MASK)
#define E_F_DAC_POL        ((uint8)(0u >> 1u) & E_F_IDIR_MASK)


#endif /* CY_WaveDAC8_E_F_H  */

/* [] END OF FILE */
