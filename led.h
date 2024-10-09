#ifndef LED_H_
#define LED_H_

#include "gpio.h"


#define LED_CONNCETION_TYPE POSTIVE_LOGIC

#define LED_BLUE_PORT_ID	PORTB_ID
#define LED_RED_PORT_ID		PORTB_ID
#define LED_GREEN_PORT_ID	PORTB_ID

#define LED_BLUE_PIN_ID		PIN7_ID
#define LED_RED_PIN_ID		PIN5_ID
#define LED_GREEN_PIN_ID	PIN6_ID




typedef enum{
	NEGATIVE_LOGIC,POSTIVE_LOGIC
}LEDs_connectionType;

typedef enum{
	BLUE,RED,GREEN
}LED_ID	;

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /* LED_H_ */
