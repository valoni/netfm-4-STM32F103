////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cores\arm\include\cpu.h>



UINT32 CPU_CMU_ReadPeripheralClock()
{
    NATIVE_PROFILE_HAL_PROCESSOR_CMU();
    return MC9328MXL_Clock_Driver::ReadClockDivisor( MC9328MXL_Clock_Driver::PERCLK1 );
}

void CPU_CMU_ClockDivisor( UINT32 Peripheral, UINT32 Divisor )
{
    NATIVE_PROFILE_HAL_PROCESSOR_CMU();
    MC9328MXL_Clock_Driver::ClockDivisor( Peripheral, Divisor );
}

void CPU_CMU_PeripheralClock( UINT32 Peripheral, BOOL On )
{
    NATIVE_PROFILE_HAL_PROCESSOR_CMU();
}


