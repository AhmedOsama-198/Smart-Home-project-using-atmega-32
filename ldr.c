#include "ldr.h"

#include "adc.h"
#include <util/delay.h>
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LDR_getLightIntensity(void)
{
	_delay_ms(50);
	uint8 intencity_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	intencity_value = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));


	if(intencity_value > 100){
		intencity_value = 100;
	}
	else if(intencity_value < 0){
		intencity_value = 0;
	}
	return intencity_value;
}
