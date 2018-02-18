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
	m_Speed = 0;
}

void Intake::SetSpeed(float speed)
{
	m_Speed = speed;
}

void Intake::handle()
{
	m_MotorRight->Set(-m_Speed);
	m_MotorLeft->Set(m_Speed);
}

Intake::~Intake()
{
	delete m_MotorRight;
	delete m_MotorLeft;
}

