/*
 * Ramps.cpp
 *
 *  Created on: Mar 4, 2018
 *      Author: theholycows
 */
#include "../CowLib/CowMotorController.h"
#include "../CowConstants.h"
#include <Subsystems/Ramps.h>


Ramps::Ramps(int motorRight, int motorLeft, int rampServo)
{
	m_MotorRight = new CowLib::CowMotorController(motorRight);
	m_MotorLeft = new CowLib::CowMotorController(motorLeft);
	m_RampServo = new Servo(rampServo);

	m_RightSpeed = 0;
	m_LeftSpeed = 0;
	m_RampServoPosition = CONSTANT("RAMP_SERVO_CLOSED");
}

void Ramps::DeployRamps()
{
	m_RampServoPosition = CONSTANT("RAMP_SERVO_OPENED");
}

void Ramps::SetLeftRampSpeed(float speed)
{
	m_LeftSpeed = speed;
}

void Ramps::SetRightRampSpeed(float speed)
{
	m_RightSpeed = speed;
}

void Ramps::handle()
{
	//Set the motor speeds only if the ramps are deployed
	if(m_RampServoPosition !=  CONSTANT("RAMP_SERVO_CLOSED"))
	{
		m_MotorRight->Set(m_RightSpeed);
		m_MotorLeft->Set(m_LeftSpeed);
	}
	else
	{
		m_MotorRight->Set(0);
		m_MotorLeft->Set(0);
	}

	//Set the servo position
	m_RampServo->Set(m_RampServoPosition);
}

Ramps::~Ramps()
{
	delete m_MotorRight;
	delete m_MotorLeft;
	delete m_RampServo;
}

