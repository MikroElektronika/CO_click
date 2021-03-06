/*
Example for CO Click

    Date          : Jan 2019.
    Author        : Nenad Filipovic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures, sets AN pin as input.
- Application Initialization - Initialization driver enables GPIO and ADC, also starts write log.
- Application Task - (code snippet) This is a example which demonstrates the use of CO Click board.
     CO Click reads ADC value.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart changes for every 1 sec.

Additional Functions :

- void co_adcInit() - Function ADC initialization.
- uint32_t co_readADC() - Function read ADC value.

*/

#include "Click_CO_types.h"
#include "Click_CO_config.h"
#include "Click_CO_adc.h"


uint32_t valueADC;
char logText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    co_gpioDriverInit( (T_CO_P)&_MIKROBUS1_GPIO );
    Delay_100ms();

    mikrobus_logWrite( "---------------------", _LOG_LINE );
    mikrobus_logWrite( "      CO  click      ", _LOG_LINE );
    mikrobus_logWrite( "---------------------", _LOG_LINE );

    co_adcInit();
    Delay_100ms();

    mikrobus_logWrite( "    Initializated    ", _LOG_LINE );
    mikrobus_logWrite( "---------------------", _LOG_LINE );
}

void applicationTask()
{
    valueADC = co_readADC();

    IntToStr( valueADC, logText );
    mikrobus_logWrite( " ADC value: ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "---------------------", _LOG_LINE );

    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}