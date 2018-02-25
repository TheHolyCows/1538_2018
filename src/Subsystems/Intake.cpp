/*
 * Intake.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: kchau
 */

#include <Subsystems/Intake.h>
#include "../CowLib/CowMotorController.h"
#include "../CowConstants.h"

Intake::Intake(int motorRight, int motorLeft)
{
	m_MotorRight = new CowLib::CowMotorController(motorRight);
	m_MotorLeft = new CowLib::CowMotorController(motorLeft);
	m_SpeedRight = -0.2;
	m_SpeedLeft = -0.2;
}

void Intake::SetSpeed(float speed)
{
	m_SpeedLeft = speed;
	m_SpeedRight = speed;
}

void Intake::SetSpeed(float speedLeft, float speedRight)
{
	m_SpeedLeft = speedLeft;
	m_SpeedRight = speedRight;
}

void Intake::handle()
{
	SmartDashboard::PutNumber("Intake Motor Voltage Left", m_MotorLeft->GetInternalMotor()->GetMotorOutputVoltage());
	SmartDashboard::PutNumber("Intake Motor Voltage Right", m_MotorRight->GetInternalMotor()->GetMotorOutputVoltage());
	m_MotorRight->Set(-m_SpeedRight);
	m_MotorLeft->Set(m_SpeedLeft);
}

Intake::~Intake()
{
	delete m_MotorRight;
	delete m_MotorLeft;
}

