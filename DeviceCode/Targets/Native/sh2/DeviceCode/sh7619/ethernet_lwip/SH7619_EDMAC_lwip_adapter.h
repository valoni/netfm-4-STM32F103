////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tinyhal.h" 
#include "net_decl_lwip.h"
#include "lwip\dhcp.h"

#ifndef _SH7619_EDMAC_LWIP_ADAPTER_H_1
#define _SH7619_EDMAC_LWIP_ADAPTER_H_1 1

//extern int xn_bind_sh7619_mac(int minor_number);

// Data Structures
struct SH7619_EDMAC_LWIP_DRIVER_CONFIG
{
    GPIO_PIN            PHY_PD_GPIO_Pin;			// phy power down control
};

struct SH7619_EDMAC_LWIP_Driver
{

    //--//
    struct dhcp m_currentDhcpSession;


    static int  Open   (   int           );
    static BOOL Close  (   void          );
    static BOOL Bind   (   void          );
};

//
// SH7619_EDMAC_LWIP_ADAPTER
//////////////////////////////////////////////////////////////////////////////

#endif
