/*
 * Arm.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: kchau
 */

#include <Subsystems/Arm.h>
#include <String>
#include <iostream>
#include <Timer.h>

Arm::Arm(int motorController)
{
	m_Motor = new CowLib::CowMotorController(motorController);
	m_Motor->SetControlMode(CowLib::CowMotorController::POSITION);
	m_Position = CONSTANT("ARM_UP");
	m_PlanetaryHardstop = 0;

    m_Intake = new Intake(5, 4);
    m_AutoScore = false;
    m_AutoScoreTime = 0;

    m_IntakeModulation = 0;
}

void Arm::SetPosition(float position)
{
	m_Position = position;
}

void Arm::ResetConstants()
{
	m_Position = CONSTANT("ARM_UP");
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
	float normalizedPosition = m_Motor->GetPosition()-m_PlanetaryHardstop;
	float autoScoreError = fabs(-normalizedPosition + m_Position);
	if(m_Motor)
	{
		m_Motor->Set(tempCalibratedPosition);
	}

    if(m_Intake)
    {
    		m_Intake->handle();
    }

    if(m_AutoScore)
    {
    		if(fabs(-normalizedPosition + m_Position) < CONSTANT("ARM_AUTO_ERROR"))
    		{
    			float autoTime = Timer::GetFPGATimestamp() - m_AutoScoreTime;
    			m_Intake->SetSpeed(CONSTANT("AUTO_SCORE_EXHAUST"));

    			if(autoTime > 0.5)
    			{
    				m_AutoScore = false;
    				SetPosition(CONSTANT("ARM_UP"));
    			}
    		}
    }
    SmartDashboard::PutNumber("Arm", (m_Motor->GetPosition()-m_PlanetaryHardstop));
	//std::cout << "Current arm_w/hardstop: " << m_Motor->GetPosition()-m_PlanetaryHardstop << std::endl;
}

void Arm::SetModulatedSpeed(float speed)
{
	if(!m_AutoScore)
	{
		m_IntakeModulation ++;

		if(m_IntakeModulation % (int)CONSTANT("INTAKE_MODULATION") == 0)
		{
			m_IntakeModulation = 0;
			m_Intake->SetSpeed(-speed*CONSTANT("INTAKE_MODULATION_LEFT") , -speed*CONSTANT("INTAKE_MODULATION_RIGHT"));
		}
		else
		{
			m_Intake->SetSpeed(speed);
		}
	}
}

void Arm::SetIntakeSpeed(float speed)
{
	if(!m_AutoScore)
	{
		m_Intake->SetSpeed(speed);
	}
}

void Arm::ScoreForward()
{
	SetPosition(CONSTANT("ARM_POS_SCORE_FWD"));
	m_AutoScoreTime = Timer::GetFPGATimestamp();
	m_AutoScore = true;
}


Arm::~Arm()
{
	delete m_Motor;
}

