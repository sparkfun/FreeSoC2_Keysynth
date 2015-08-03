/*******************************************************************************
* File Name: Tremolo.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_Tremolo_H)
#define CY_AMUX_Tremolo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Tremolo_Start(void) ;
#define Tremolo_Init() Tremolo_Start()
void Tremolo_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Tremolo_Stop(void); */
/* void Tremolo_Select(uint8 channel); */
/* void Tremolo_Connect(uint8 channel); */
/* void Tremolo_Disconnect(uint8 channel); */
/* void Tremolo_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Tremolo_CHANNELS  2u
#define Tremolo_MUXTYPE   1
#define Tremolo_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Tremolo_NULL_CHANNEL 0xFFu
#define Tremolo_MUX_SINGLE   1
#define Tremolo_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Tremolo_MUXTYPE == Tremolo_MUX_SINGLE
# if !Tremolo_ATMOSTONE
#  define Tremolo_Connect(channel) Tremolo_Set(channel)
# endif
# define Tremolo_Disconnect(channel) Tremolo_Unset(channel)
#else
# if !Tremolo_ATMOSTONE
void Tremolo_Connect(uint8 channel) ;
# endif
void Tremolo_Disconnect(uint8 channel) ;
#endif

#if Tremolo_ATMOSTONE
# define Tremolo_Stop() Tremolo_DisconnectAll()
# define Tremolo_Select(channel) Tremolo_FastSelect(channel)
void Tremolo_DisconnectAll(void) ;
#else
# define Tremolo_Stop() Tremolo_Start()
void Tremolo_Select(uint8 channel) ;
# define Tremolo_DisconnectAll() Tremolo_Start()
#endif

#endif /* CY_AMUX_Tremolo_H */


/* [] END OF FILE */
