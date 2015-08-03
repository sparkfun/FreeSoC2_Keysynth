/*******************************************************************************
* FILENAME: cyfitter_cfg.h
* 
* PSoC Creator  3.2
*
* DESCRIPTION:
* This file provides basic startup and mux configration settings
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2015 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef CYFITTER_CFG_H
#define CYFITTER_CFG_H

#include "cytypes.h"

extern void cyfitter_cfg(void);

/* Analog Set/Unset methods */
extern void SetAnalogRoutingPumps(uint8 enabled);
extern void OutMux_Set(uint8 channel);
extern void OutMux_Unset(uint8 channel);
/* OutMux__addrTable is an implementation detail of the AMux.
   Code that depends on it may be incompatible with other versions
   of PSoC Creator. */
extern uint8 CYXDATA * const CYCODE OutMux__addrTable[8];
/* OutMux__maskTable is an implementation detail of the AMux.
   Code that depends on it may be incompatible with other versions
   of PSoC Creator. */
extern const uint8 CYCODE OutMux__maskTable[8];
extern void Pot_Vals_Set(uint8 channel);
extern void Pot_Vals_Unset(uint8 channel);
/* Pot_Vals__addrTable is an implementation detail of the AMux.
   Code that depends on it may be incompatible with other versions
   of PSoC Creator. */
extern uint8 CYXDATA * const CYCODE Pot_Vals__addrTable[4];
/* Pot_Vals__maskTable is an implementation detail of the AMux.
   Code that depends on it may be incompatible with other versions
   of PSoC Creator. */
extern const uint8 CYCODE Pot_Vals__maskTable[4];
extern void Tremolo_Set(uint8 channel);
extern void Tremolo_Unset(uint8 channel);
/* Tremolo__addrTable is an implementation detail of the AMux.
   Code that depends on it may be incompatible with other versions
   of PSoC Creator. */
extern uint8 CYXDATA * const CYCODE Tremolo__addrTable[4];
/* Tremolo__maskTable is an implementation detail of the AMux.
   Code that depends on it may be incompatible with other versions
   of PSoC Creator. */
extern const uint8 CYCODE Tremolo__maskTable[4];


#endif /* CYFITTER_CFG_H */

/*[]*/
