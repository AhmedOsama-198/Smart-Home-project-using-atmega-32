#include "buzzer.h"
#include "led.h"
#include "lcd.h"
#include "ldr.h"
#include "dc_motor.h"
#include "flame.h"
#include "lm35_sensor.h"
#include "adc.h"



typedef enum{
	OFF,ON
}state;


uint8 lightIntensity = 0;
uint8 tempreture = 0;
uint8 fanSpeed = 0;
uint8 flameSensor = 0;

state fanState = OFF;

state alarm = OFF;

void display(void);
void lightSystemHandle(void);
void tempretureSystemHandle(void);
void smokeDetectionHandle(void);

int main(){

	LCD_init();
	BUZZER_init();
	DcMotor_Init();
	FlameSensor_init();
	LEDS_init();

	ADC_init();

	LCD_clearScreen();

	while(1){

		lightSystemHandle();

		tempretureSystemHandle();

		smokeDetectionHandle();

		display();
	}

}

void display(void)
{
	if(alarm == ON){
	}
	else if(alarm == OFF)
	{
		switch(fanState){
		case OFF:
			LCD_displayStringRowColumn(0,0,"Fan is OFF");
			break;
		case ON:
			LCD_displayStringRowColumn(0,0,"Fan is ON ");
			break;
		}

		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(tempreture);
		LCD_displayString("C-LDR=");
		LCD_intgerToString(lightIntensity);
		LCD_displayString("% ");

	}
}

void lightSystemHandle(void)
{
	lightIntensity = LDR_getLightIntensity();


	if(lightIntensity <= 15){
		LED_on(BLUE);
		LED_on(RED);
		LED_on(GREEN);

	}
	else if(lightIntensity <= 50){
		LED_off(BLUE);
		LED_on(RED);
		LED_on(GREEN);
	}
	else if(lightIntensity <= 70){
		LED_off(BLUE);
		LED_on(RED);
		LED_off(GREEN);
	}
	else{
		LED_off(BLUE);
		LED_off(RED);
		LED_off(GREEN);
	}
}
void tempretureSystemHandle(void)
{
	tempreture = LM35_getTemperature();

	if(tempreture < 25){
		fanState = OFF;
		fanSpeed = 0;
		DcMotor_Rotate(DC_MOTOR_STOP,fanSpeed);

	}
	else if(tempreture < 30){
		fanState = ON;
		fanSpeed = 25;
		DcMotor_Rotate(DC_MOTOR_CW,fanSpeed);


	}
	else if(tempreture < 35){
		fanState = ON;
		fanSpeed = 50;
		DcMotor_Rotate(DC_MOTOR_CW,fanSpeed);


	}
	else if(tempreture < 40){
		fanState = ON;
		fanSpeed = 75;
		DcMotor_Rotate(DC_MOTOR_CW,fanSpeed);

	}
	else{
		fanState = ON;
		fanSpeed = 100;
		DcMotor_Rotate(DC_MOTOR_CW,fanSpeed);

	}

}
void smokeDetectionHandle(void)
{
	flameSensor = FlameSensor_getValue();

	if(flameSensor == FLAME_SENSOR_DANGER && alarm == OFF){
		alarm = ON;
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"Critical alert!");
		BUZZER_on();
	}
	if(flameSensor == FLAME_SENSOR_NORMAL && alarm == ON){
		alarm = OFF;
		LCD_clearScreen();
		BUZZER_off();
	}
}
