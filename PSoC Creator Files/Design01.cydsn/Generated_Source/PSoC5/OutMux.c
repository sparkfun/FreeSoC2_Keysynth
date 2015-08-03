/*******************************************************************************
* File Name: OutMux.c
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

#include "OutMux.h"

static uint8 OutMux_lastChannel = OutMux_NULL_CHANNEL;


/*******************************************************************************
* Function Name: OutMux_Start
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
void OutMux_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < OutMux_CHANNELS ; chan++)
    {
#if (OutMux_MUXTYPE == OutMux_MUX_SINGLE)
        OutMux_Unset(chan);
#else
        OutMux_CYAMUXSIDE_A_Unset(chan);
        OutMux_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    OutMux_lastChannel = OutMux_NULL_CHANNEL;
}


#if (!OutMux_ATMOSTONE)
/*******************************************************************************
* Function Name: OutMux_Select
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
void OutMux_Select(uint8 channel) 
{
    OutMux_DisconnectAll();        /* Disconnect all previous connections */
    OutMux_Connect(channel);       /* Make the given selection */
    OutMux_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: OutMux_FastSelect
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
void OutMux_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( OutMux_lastChannel != OutMux_NULL_CHANNEL)
    {
        OutMux_Disconnect(OutMux_lastChannel);
    }

    /* Make the new channel connection */
#if (OutMux_MUXTYPE == OutMux_MUX_SINGLE)
    OutMux_Set(channel);
#else
    OutMux_CYAMUXSIDE_A_Set(channel);
    OutMux_CYAMUXSIDE_B_Set(channel);
#endif


    OutMux_lastChannel = channel;   /* Update last channel */
}


#if (OutMux_MUXTYPE == OutMux_MUX_DIFF)
#if (!OutMux_ATMOSTONE)
/*******************************************************************************
* Function Name: OutMux_Connect
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
void OutMux_Connect(uint8 channel) 
{
    OutMux_CYAMUXSIDE_A_Set(channel);
    OutMux_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: OutMux_Disconnect
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
void OutMux_Disconnect(uint8 channel) 
{
    OutMux_CYAMUXSIDE_A_Unset(channel);
    OutMux_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (OutMux_ATMOSTONE)
/*******************************************************************************
* Function Name: OutMux_DisconnectAll
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
void OutMux_DisconnectAll(void) 
{
    if(OutMux_lastChannel != OutMux_NULL_CHANNEL) 
    {
        OutMux_Disconnect(OutMux_lastChannel);
        OutMux_lastChannel = OutMux_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
