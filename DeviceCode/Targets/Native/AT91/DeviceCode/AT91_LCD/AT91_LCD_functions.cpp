////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////#include <cores\arm\include\cpu.h>
#include <cores\arm\include\cpu.h>
#include "AT91_LCD.h"

//--//

BOOL LCD_Controller_Initialize(DISPLAY_CONTROLLER_CONFIG& config)
{
    return AT91_LCD_Driver::Initialize(config);
}

BOOL LCD_Controller_Uninitialize()
{
    return AT91_LCD_Driver::Uninitialize();
}

BOOL LCD_Controller_Enable(BOOL fEnable)
{
    return AT91_LCD_Driver::Enable(fEnable);
}

UINT32* LCD_GetFrameBuffer()
{
    return AT91_LCD_Driver::GetScreenBuffer();
}

