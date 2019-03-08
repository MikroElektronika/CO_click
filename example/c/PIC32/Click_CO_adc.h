#include "Click_CO_types.h"


void co_adcInit()
{
    ADC1_Init();
}

uint32_t co_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}