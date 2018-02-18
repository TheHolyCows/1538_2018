/*
 * Arm.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: kchau
 */

#include <Subsystems/Arm.h>
#include <String>
#include <iostream>

Arm::Arm(int motorController)
{
	m_Motor = new CowLib::CowMotorController(motorController);
	m_Motor->SetControlMode(CowLib::CowMotorController::POSITION);
	m_Position = 0;
	m_PlanetaryHardstop = 0;
}

void Arm::SetPosition(float position)
{
	m_Position = position;
}

void Arm::ResetConstants()
{
	m_Motor->SetPIDGains(CONSTANT("ARM_P"), CONSTANT("ARM_I"), CONSTANT("ARM_D"), 0);
	std::cout << "In the arm reset constants" << std::endl;
}

void Arm::DisabledCalibration()
{
	//std::cout << "Current hardstop value: " << m_PlanetaryHardstop << " ArmPos: " << m_Motor->GetPosition() << std::endl;
	if(m_Motor->GetPosition() > m_PlanetaryHardstop)
	{
		m_PlanetaryHardstop = m_Motor->GetPosition();
	}
}

void Arm::handle()
{
	float tempCalibratedPosition = m_Position+m_PlanetaryHardstop;
	if(m_Motor)
	{
		m_Motor->Set(tempCalibratedPosition);
	}
	//std::cout << "Current arm_w/hardstop: " << m_Motor->GetPosition()-m_PlanetaryHardstop << std::endl;
}

Arm::~Arm()
{
	delete m_Motor;
}

