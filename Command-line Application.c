//==============================================================================
//
// Title:		Command-line Application
// Purpose:		A short description of the command-line tool.
//
// Created on:	8/20/2022 at 7:51:47 PM by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include "nixnet.h"
#include <windows.h>
#include <utility.h>

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

/// HIFN  Explain how to use this command-line tool.
/// HIPAR name/The name of the command-line tool.
static void usage (char *name)
{
	fprintf (stderr, "usage: %s <argument>\n", name);
	fprintf (stderr, "A short summary of the functionality.\n");
	fprintf (stderr, "    <argument>    is an argument\n");
	exit (1);
}

//==============================================================================
// Global variables

static nxSessionRef_t m_InputSessionRef = 0;
static nxSessionRef_t m_OutputSessionRef = 0;

//==============================================================================
// Global functions

/// HIFN  The main entry-point function.
/// HIPAR argc/The number of command-line arguments.
/// HIPAR argc/This number includes the name of the command-line tool.
/// HIPAR argv/An array of command-line arguments.
/// HIPAR argv/Element 0 contains the name of the command-line tool.
/// HIRET Returns 0 if successful.
int main (int argc, char *argv[])
{
	char *l_pSelectedInterface1 = "CAN1";
	char *l_pSelectedDatabase = "NIXNET_example";
	char *l_pSelectedCluster = "CAN_Cluster";
	char *l_pSelectedInputSignalList = "CANEventSignal1,CANEventSignal2";
	char *l_pSelectedOutputSignalList = "CANEventSignal1,CANEventSignal2";
	nxStatus_t l_Status = 0;
	
	l_Status = nxCreateSession(l_pSelectedDatabase, l_pSelectedCluster,l_pSelectedInputSignalList, l_pSelectedInterface1, nxMode_SignalInSinglePoint, &m_InputSessionRef);
	//l_Status = nxCreateSession(l_pSelectedDatabase, l_pSelectedCluster,l_pSelectedOutputSignalList, l_pSelectedInterface1,nxMode_SignalOutSinglePoint, &m_OutputSessionRef);
	l_Status = nxStart(m_InputSessionRef, nxStartStop_Normal);
	
	if (nxSuccess == l_Status)
   {
      printf("PASS\n");
   }
   	//Delay(2);
   	l_Status = nxClear(m_InputSessionRef);
   	
	return 0;
}

