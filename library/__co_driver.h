/*
    __co_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __co_driver.h
@brief    CO Driver
@mainpage CO Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   CO
@brief      CO Click Driver
@{

| Global Library Prefix | **CO** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _CO_H_
#define _CO_H_

/** 
 * @macro T_CO_P
 * @brief Driver Abstract type 
 */
#define T_CO_P    const uint8_t*

/** @defgroup CO_COMPILE Compilation Config */              /** @{ */

//  #define   __CO_DRV_SPI__                            /**<     @macro __CO_DRV_SPI__  @brief SPI driver selector */
//  #define   __CO_DRV_I2C__                            /**<     @macro __CO_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __CO_DRV_UART__                           /**<     @macro __CO_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup CO_VAR Variables */                           /** @{ */


extern const float _CO_VREF_3_3;
extern const float _CO_VREF_5_0;
extern const float  _CO_COEFFICIENT_A;
extern const float  _CO_COEFFICIENT_B;
                                                                       /** @} */
/** @defgroup CO_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup CO_INIT Driver Initialization */              /** @{ */

#ifdef   __CO_DRV_SPI__
void co_spiDriverInit(T_CO_P gpioObj, T_CO_P spiObj);
#endif
#ifdef   __CO_DRV_I2C__
void co_i2cDriverInit(T_CO_P gpioObj, T_CO_P i2cObj, uint8_t slave);
#endif
#ifdef   __CO_DRV_UART__
void co_uartDriverInit(T_CO_P gpioObj, T_CO_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void co_gpioDriverInit(T_CO_P gpioObj);
                                                                       /** @} */
/** @defgroup CO_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Convert the voltage function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @param[in] vRef                           the VREF value ( 3.3V or 5V )
 *
 * @return
 * float value of the voltage
 *
 * Function returns voltage from the analog input value
 * refer ADC conversion for further reference
 * of MQ-7 sensor on CO Click.
*/
float co_voltageConversion( uint32_t adcValue, float vRef );

/**
 * @brief Get the sensor ratio function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @param[in] vRef                           the VREF value ( 3.3V or 5V )
 *
 * @return
 * float value of the sensor ratio
 *
 * Function get the ratio of MQ-7 sensor on CO Click.
*/
float co_getRatio( uint32_t adcValue, float vRef );

/**
 * @brief Get the sensor resistance
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @param[in] vRef                           the VREF value ( 3.3V or 5V )
 *
 * @return
 * float value of the sensor resistance
 *
 * Function get the resistance of MQ-7 sensor on CO Click.
*/
float co_getSensorResistance( uint32_t adcValue, float vRef );




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_CO_STM.c
    @example Click_CO_TIVA.c
    @example Click_CO_CEC.c
    @example Click_CO_KINETIS.c
    @example Click_CO_MSP.c
    @example Click_CO_PIC.c
    @example Click_CO_PIC32.c
    @example Click_CO_DSPIC.c
    @example Click_CO_AVR.c
    @example Click_CO_FT90x.c
    @example Click_CO_STM.mbas
    @example Click_CO_TIVA.mbas
    @example Click_CO_CEC.mbas
    @example Click_CO_KINETIS.mbas
    @example Click_CO_MSP.mbas
    @example Click_CO_PIC.mbas
    @example Click_CO_PIC32.mbas
    @example Click_CO_DSPIC.mbas
    @example Click_CO_AVR.mbas
    @example Click_CO_FT90x.mbas
    @example Click_CO_STM.mpas
    @example Click_CO_TIVA.mpas
    @example Click_CO_CEC.mpas
    @example Click_CO_KINETIS.mpas
    @example Click_CO_MSP.mpas
    @example Click_CO_PIC.mpas
    @example Click_CO_PIC32.mpas
    @example Click_CO_DSPIC.mpas
    @example Click_CO_AVR.mpas
    @example Click_CO_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __co_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */