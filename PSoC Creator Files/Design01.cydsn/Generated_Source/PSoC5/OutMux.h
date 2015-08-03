/*******************************************************************************
* File Name: OutMux.h
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

#if !defined(CY_AMUX_OutMux_H)
#define CY_AMUX_OutMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void OutMux_Start(void) ;
#define OutMux_Init() OutMux_Start()
void OutMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void OutMux_Stop(void); */
/* void OutMux_Select(uint8 channel); */
/* void OutMux_Connect(uint8 channel); */
/* void OutMux_Disconnect(uint8 channel); */
/* void OutMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define OutMux_CHANNELS  4u
#define OutMux_MUXTYPE   1
#define OutMux_ATMOSTONE 1

/***************************************
*             API Constants
***************************************/

#define OutMux_NULL_CHANNEL 0xFFu
#define OutMux_MUX_SINGLE   1
#define OutMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if OutMux_MUXTYPE == OutMux_MUX_SINGLE
# if !OutMux_ATMOSTONE
#  define OutMux_Connect(channel) OutMux_Set(channel)
# endif
# define OutMux_Disconnect(channel) OutMux_Unset(channel)
#else
# if !OutMux_ATMOSTONE
void OutMux_Connect(uint8 channel) ;
# endif
void OutMux_Disconnect(uint8 channel) ;
#endif

#if OutMux_ATMOSTONE
# define OutMux_Stop() OutMux_DisconnectAll()
# define OutMux_Select(channel) OutMux_FastSelect(channel)
void OutMux_DisconnectAll(void) ;
#else
# define OutMux_Stop() OutMux_Start()
void OutMux_Select(uint8 channel) ;
# define OutMux_DisconnectAll() OutMux_Start()
#endif

#endif /* CY_AMUX_OutMux_H */


/* [] END OF FILE */
