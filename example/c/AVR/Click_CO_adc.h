#include "Click_CO_types.h"


void co_adcInit()
{
    ADC_Init();
}

uint32_t co_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 7 );
    
    return readADC;
}