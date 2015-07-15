////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GHI_OSHW_HAL_H_
#define _GHI_OSHW_HAL_H_

#include <tinyhal.h>

typedef UINT32 GPAL_ERROR;

// Software I2C
typedef struct
{
	GPIO_PIN sda;
	GPIO_PIN scl;
	UINT32 clockSpeed; // currently ignored
	BYTE address;	   // 7 bit address
	
} GHI_OSHW_HAL_SoftwareI2C;

BOOL GHI_OSHW_HAL_SoftwareI2C_WriteRead(GHI_OSHW_HAL_SoftwareI2C *i2c, BYTE *writeBuffer, UINT32 writeLength, BYTE *readBuffer, UINT32 readLength, UINT32 *numWritten, UINT32 *numRead);

// StorageDev
GPAL_ERROR GHI_OSHW_Mount(UINT32 ClockFrequencyInKHz);
void GHI_OSHW_Unmount();

#endif
