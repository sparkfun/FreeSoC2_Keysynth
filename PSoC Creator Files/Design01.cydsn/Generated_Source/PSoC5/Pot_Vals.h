/*******************************************************************************
* File Name: Pot_Vals.h
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

#if !defined(CY_AMUX_Pot_Vals_H)
#define CY_AMUX_Pot_Vals_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Pot_Vals_Start(void) ;
#define Pot_Vals_Init() Pot_Vals_Start()
void Pot_Vals_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Pot_Vals_Stop(void); */
/* void Pot_Vals_Select(uint8 channel); */
/* void Pot_Vals_Connect(uint8 channel); */
/* void Pot_Vals_Disconnect(uint8 channel); */
/* void Pot_Vals_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Pot_Vals_CHANNELS  2u
#define Pot_Vals_MUXTYPE   1
#define Pot_Vals_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Pot_Vals_NULL_CHANNEL 0xFFu
#define Pot_Vals_MUX_SINGLE   1
#define Pot_Vals_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Pot_Vals_MUXTYPE == Pot_Vals_MUX_SINGLE
# if !Pot_Vals_ATMOSTONE
#  define Pot_Vals_Connect(channel) Pot_Vals_Set(channel)
# endif
# define Pot_Vals_Disconnect(channel) Pot_Vals_Unset(channel)
#else
# if !Pot_Vals_ATMOSTONE
void Pot_Vals_Connect(uint8 channel) ;
# endif
void Pot_Vals_Disconnect(uint8 channel) ;
#endif

#if Pot_Vals_ATMOSTONE
# define Pot_Vals_Stop() Pot_Vals_DisconnectAll()
# define Pot_Vals_Select(channel) Pot_Vals_FastSelect(channel)
void Pot_Vals_DisconnectAll(void) ;
#else
# define Pot_Vals_Stop() Pot_Vals_Start()
void Pot_Vals_Select(uint8 channel) ;
# define Pot_Vals_DisconnectAll() Pot_Vals_Start()
#endif

#endif /* CY_AMUX_Pot_Vals_H */


/* [] END OF FILE */
