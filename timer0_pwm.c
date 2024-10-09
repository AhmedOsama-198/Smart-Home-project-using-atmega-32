#include "timer0_pwm.h"
#include <avr/io.h>
#include "common_macros.h"
#include "gpio.h"


void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* setting PWM OC0 pin as output pin */
	GPIO_setupPinDirection(TIMER0_PWM_PORT_ID,TIMER0_PWM_PIN_ID,PIN_OUTPUT);

	/* error checking as duty cycle should be:  0 <= duty cycle <= 100 */
	if(duty_cycle >100 || duty_cycle<0)
	{
		return;
	}

	/* clearing TCCR0 register */
	TCCR0 = 0;
	if(duty_cycle == 0)
	{
		/* do nothing */
	}
	else	/* configuring Timer0 to operate with Fast PWM mode */
	{
		/* configuring Timer0 */
		CLEAR_BIT(TCCR0,FOC0);
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);

		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		CLEAR_BIT(TCCR0,CS01);

		TCNT0 = 0;

		OCR0 = (uint8)(duty_cycle / 100.0) * 255;
	}
}
