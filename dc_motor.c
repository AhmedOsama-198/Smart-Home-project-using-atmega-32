
#include "dc_motor.h"
#include "gpio.h"
#include "timer0_pwm.h"


void DcMotor_Init(void)
{
	/* setting two control pins of motor as output pins */
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, PIN_OUTPUT);

	/* stopping the motor at first */
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, DC_MOTOR_STOP);
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, DC_MOTOR_STOP);
}


void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{

	switch(state)
	{
	case DC_MOTOR_STOP: 	/* stopping the motor */
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case DC_MOTOR_CW:		/* rotating the motor clockwise */
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case DC_MOTOR_CCW:		/* rotating the motor counter clockwise */
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}

	/* initializing timer with specific configurations */
	PWM_Timer0_Start(speed);
}

