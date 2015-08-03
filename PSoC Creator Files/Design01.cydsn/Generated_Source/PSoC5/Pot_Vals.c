/*******************************************************************************
* File Name: Pot_Vals.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Pot_Vals.h"

static uint8 Pot_Vals_lastChannel = Pot_Vals_NULL_CHANNEL;


/*******************************************************************************
* Function Name: Pot_Vals_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Pot_Vals_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < Pot_Vals_CHANNELS ; chan++)
    {
#if (Pot_Vals_MUXTYPE == Pot_Vals_MUX_SINGLE)
        Pot_Vals_Unset(chan);
#else
        Pot_Vals_CYAMUXSIDE_A_Unset(chan);
        Pot_Vals_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    Pot_Vals_lastChannel = Pot_Vals_NULL_CHANNEL;
}


#if (!Pot_Vals_ATMOSTONE)
/*******************************************************************************
* Function Name: Pot_Vals_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Pot_Vals_Select(uint8 channel) 
{
    Pot_Vals_DisconnectAll();        /* Disconnect all previous connections */
    Pot_Vals_Connect(channel);       /* Make the given selection */
    Pot_Vals_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: Pot_Vals_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Pot_Vals_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( Pot_Vals_lastChannel != Pot_Vals_NULL_CHANNEL)
    {
        Pot_Vals_Disconnect(Pot_Vals_lastChannel);
    }

    /* Make the new channel connection */
#if (Pot_Vals_MUXTYPE == Pot_Vals_MUX_SINGLE)
    Pot_Vals_Set(channel);
#else
    Pot_Vals_CYAMUXSIDE_A_Set(channel);
    Pot_Vals_CYAMUXSIDE_B_Set(channel);
#endif


    Pot_Vals_lastChannel = channel;   /* Update last channel */
}


#if (Pot_Vals_MUXTYPE == Pot_Vals_MUX_DIFF)
#if (!Pot_Vals_ATMOSTONE)
/*******************************************************************************
* Function Name: Pot_Vals_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Pot_Vals_Connect(uint8 channel) 
{
    Pot_Vals_CYAMUXSIDE_A_Set(channel);
    Pot_Vals_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: Pot_Vals_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Pot_Vals_Disconnect(uint8 channel) 
{
    Pot_Vals_CYAMUXSIDE_A_Unset(channel);
    Pot_Vals_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (Pot_Vals_ATMOSTONE)
/*******************************************************************************
* Function Name: Pot_Vals_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Pot_Vals_DisconnectAll(void) 
{
    if(Pot_Vals_lastChannel != Pot_Vals_NULL_CHANNEL) 
    {
        Pot_Vals_Disconnect(Pot_Vals_lastChannel);
        Pot_Vals_lastChannel = Pot_Vals_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
