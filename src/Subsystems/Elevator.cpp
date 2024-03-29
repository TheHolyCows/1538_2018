/*
 * Elevator.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: theholycows
 */

#include <Subsystems/Elevator.h>
#include <String>
#include <iostream>

Elevator::Elevator(int motorRight, int motorLeft, int encoderA, int encoderB)
{
	m_MotorRight = new CowLib::CowMotorController(motorRight);
	m_MotorLeft = new CowLib::CowMotorController(motorLeft);
	m_Speed = 0;
	m_Encoder = new Encoder(encoderA, encoderB, false, Encoder::k1X);
	m_Encoder->SetDistancePerPulse(0.019);
	m_PID = new CowLib::CowPID(CONSTANT("ELEVATOR_P"), CONSTANT("ELEVATOR_I"), CONSTANT("ELEVATOR_D"), 0);
	m_Position = 25;
	m_PID->SetSetpoint(m_Position);
}

void Elevator::SetSpeed(float speed)
{
	m_Speed = speed;
}

void Elevator::SetPosition(float position)
{
	m_Position = position;
	if(m_Position < 0)
	{
		m_Position = 0;
	}
	m_PID->SetSetpoint(m_Position);
}

float Elevator::GetDistance()
{
	return m_Encoder->GetDistance();
}

void Elevator::ResetConstants()
{
	m_PID->UpdateConstants(CONSTANT("ELEVATOR_P"), CONSTANT("ELEVATOR_I"), CONSTANT("ELEVATOR_D"), 0);
	std::cout << "In the elevator reset constants" << std::endl;
}
void Elevator::handle()
{
	float currentPosition = m_Encoder->GetDistance();
	float pidOutput = m_PID->Calculate(currentPosition);

	if (m_Position < currentPosition)
	{
		pidOutput *= 0.38;
	}

	m_MotorRight->Set(-pidOutput);
	m_MotorLeft->Set(pidOutput);

	//std::cout << "Current elevator: " << currentPosition << " PID: " << pidOutput << std::endl;
}


Elevator::~Elevator()
{
	delete m_MotorRight;
	delete m_MotorLeft;
	delete m_Encoder;
}

