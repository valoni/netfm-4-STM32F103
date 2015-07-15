﻿/*
 * 该文件主要用于声明一些固件库所要使用的东西
 * 因为STM32固件库是通过外链引用进来的，不方便直接修改原有代码
 */   
  
/* Define to prevent recursive inclusion -------------------------------------*/  
#ifndef __STM32F10x_CONF_H  
#define __STM32F10x_CONF_H  

// 声明使用STM32固件库
//#if !defined USE_STDPERIPH_DRIVER
//	#define USE_STDPERIPH_DRIVER
//#endif

// 声明HD，高密度Flash，我们是STM32F103ZET6，也就是512K啦
//#if !defined STM32F10X_LD && !defined STM32F10X_MD && !defined STM32F10X_HD && !defined STM32F10X_CL
//	#define STM32F10X_HD
//#endif

/* Includes ------------------------------------------------------------------*/  
/* Uncomment the line below to enable peripheral header file inclusion */  
#include "stm32f10x_adc.h"   
#include "stm32f10x_bkp.h"   
#include "stm32f10x_can.h"   
#include "stm32f10x_crc.h"   
#include "stm32f10x_dac.h"   
#include "stm32f10x_dbgmcu.h"   
#include "stm32f10x_dma.h"   
#include "stm32f10x_exti.h"  
#include "stm32f10x_flash.h"   
#include "stm32f10x_fsmc.h"  
#include "stm32f10x_gpio.h"  
#include "stm32f10x_i2c.h"   
#include "stm32f10x_iwdg.h"   
#include "stm32f10x_pwr.h"   
#include "stm32f10x_rcc.h"  
#include "stm32f10x_rtc.h"   
#include "stm32f10x_sdio.h"   
#include "stm32f10x_spi.h"  
#include "stm32f10x_tim.h"   
#include "stm32f10x_usart.h"  
#include "stm32f10x_wwdg.h"   
#include "misc.h" /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */  
  
/* Exported types ------------------------------------------------------------*/  
/* Exported constants --------------------------------------------------------*/  
/* Uncomment the line below to expanse the "assert_param" macro in the  
   Standard Peripheral Library drivers code */  
/* #define USE_FULL_ASSERT    1 */  
  
/* Exported macro ------------------------------------------------------------*/  
#ifdef  USE_FULL_ASSERT  
  
/** 
  * @brief  The assert_param macro is used for function's parameters check. 
  * @param  expr: If expr is false, it calls assert_failed function 
  *   which reports the name of the source file and the source 
  *   line number of the call that failed.  
  *   If expr is true, it returns no value. 
  * @retval None 
  */  
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))  
/* Exported functions ------------------------------------------------------- */  
  void assert_failed(uint8_t* file, uint32_t line);  
#else  
  #define assert_param(expr) ((void)0)  
#endif /* USE_FULL_ASSERT */  
  
#endif /* __STM32F10x_CONF_H */  
  
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
