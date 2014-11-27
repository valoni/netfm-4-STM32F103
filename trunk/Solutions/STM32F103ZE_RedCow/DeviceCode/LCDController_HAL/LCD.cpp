////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyhal.h>
#include "ILI932x.h"
//--//

BOOL LCD_Controller_Initialize( DISPLAY_CONTROLLER_CONFIG& config )
{
	CILI932x::LCD_Init();
	CILI932x::LCD_Clear(ILI932x::Black);
	CILI932x::LCD_SetDisplayWindow(00, 00, config.Width, config.Height);	
	return TRUE;
}

BOOL LCD_Controller_Uninitialize()
{
	return TRUE;
}

BOOL LCD_Controller_Enable( BOOL fEnable )
{
	if(fEnable != FALSE)
	{
		CILI932x::LCD_DisplayOn();
	}
	else
	{
		CILI932x::LCD_DisplayOff();
	}
	return TRUE;
}
