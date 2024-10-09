#include "led.h"

void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_RED_PORT_ID,LED_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,PIN_OUTPUT);

	if(LED_CONNCETION_TYPE == POSTIVE_LOGIC){
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
	}
	else if(LED_CONNCETION_TYPE == NEGATIVE_LOGIC){
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
	}

}
void LED_on(LED_ID id)
{
	if(LED_CONNCETION_TYPE == POSTIVE_LOGIC){
		switch(id){
		case BLUE:
			GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
			break;
		case RED:
			GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
			break;
		case GREEN:
			GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
			break;
		}
	}
	else
	{
		switch(id){
		case BLUE:
			GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
			break;
		case RED:
			GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
			break;
		case GREEN:
			GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
			break;
		}
	}
}
void LED_off(LED_ID id)
{
	switch(id){
	case BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
		break;
	case RED:
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
		break;
	case GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
		break;
	}
}
