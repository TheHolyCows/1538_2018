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
    m_AutoScoreForward = false;
    m_AutoScoreForwardTime = 0;

    m_IntakeModulation = 0;

	m_Elevator = NULL;

	m_AutoScoreReverse = false;
	m_AutoScoreReverseTime = 0;

	m_StartingConfigSet = false;
}

void Arm::SetPosition(float position)
{
	if(position < CONSTANT("ARM_DOWN"))
	{
		position = CONSTANT("ARM_DOWN");
	}

	if(position > CONSTANT("ARM_POS_SCORE_REV") && (m_Elevator->GetDistance() > CONSTANT("ELV_POS_SCORE_REV")))
	{
		position = CONSTANT("ARM_POS_SCORE_REV");
	}

	if(position > CONSTANT("ARM_POS_SCORE_REV") && !(m_Elevator->GetDistance() > CONSTANT("ELV_POS_SCORE_REV")))
	{
		position = CONSTANT("ARM_UP");
	}
	m_Position = position;
}

float Arm::GetSetpoint()
{
	return m_Position;
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

	//TODO: Make sure we move this -600 number into a constant

	//Only let this happen if the arm is pointing below the ground position
	//And we haven't ever done this before
	if(normalizedPosition < -600 && !m_StartingConfigSet)
	{
		if(m_Elevator->GetDistance() > 20)
		{
			//Enable Arm PID
			m_Motor->SetControlMode(CowLib::CowMotorController::POSITION);
		}
		else
		{
			//Ensure the Arm PID is disabled and we're outputting 0 volts
			m_Motor->SetControlMode(CowLib::CowMotorController::VOLTAGE);
			m_Motor->Set(0);
		}
	}
	else if(!m_StartingConfigSet)
	{
		if(normalizedPosition > -530)
		{
			//Make sure we never make it into here ever again
			m_StartingConfigSet = true;

			//Move the elevator carriage to the ground
			m_Elevator->SetPosition(CONSTANT("ELEVATOR_GROUND"));
		}
	}

	if(m_Motor)
	{
		m_Motor->Set(tempCalibratedPosition);
	}

    if(m_Intake)
    {
    		m_Intake->handle();
    }

    if(m_AutoScoreForward)
    {
    		if(fabs(-normalizedPosition + m_Position) < CONSTANT("ARM_AUTO_ERROR"))
    		{
    			float autoTime = Timer::GetFPGATimestamp() - m_AutoScoreForwardTime;
    			m_Intake->SetSpeed(CONSTANT("AUTO_SCORE_FWD_EXHAUST"));

    			if(autoTime > 0.6)
    			{
    				m_AutoScoreForward = false;
    				m_Elevator->SetPosition(CONSTANT("ELEVATOR_GROUND"));
    			}
    			else if(autoTime > 0.5)
    			{
    				SetPosition(CONSTANT("ARM_UP"));
    			}
    		}
    }
    if(m_AutoScoreReverse)
    {
		if(fabs(-normalizedPosition + m_Position) < CONSTANT("ARM_AUTO_ERROR"))
		{
			float autoTime = Timer::GetFPGATimestamp() - m_AutoScoreReverseTime;
			m_Intake->SetSpeed(CONSTANT("AUTO_SCORE_REV_EXHAUST"));

			if(autoTime > 0.6)
			{
				m_AutoScoreReverse = false;
				m_Elevator->SetPosition(CONSTANT("ELEVATOR_GROUND"));
			}
			else if(autoTime > 0.5)
			{
				SetPosition(CONSTANT("ARM_UP"));
			}
		}
    }
    SmartDashboard::PutNumber("Arm", (m_Motor->GetPosition()-m_PlanetaryHardstop));
	//std::cout << "Current arm_w/hardstop: " << m_Motor->GetPosition()-m_PlanetaryHardstop << std::endl;
}

void Arm::SetModulatedSpeed(float speed)
{
	if(!m_AutoScoreForward && !m_AutoScoreReverse)
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
	if(!m_AutoScoreForward && !m_AutoScoreReverse)
	{
		m_Intake->SetSpeed(speed);
	}
}

void Arm::ScoreForward()
{
	SetPosition(CONSTANT("ARM_POS_SCORE_FWD"));
	m_AutoScoreForwardTime = Timer::GetFPGATimestamp();
	m_AutoScoreForward = true;
}

void Arm::ScoreReverse()
{
	if(m_Elevator->GetDistance() > CONSTANT("ELV_POS_SCORE_REV"))
	{
		SetPosition(CONSTANT("ARM_POS_SCORE_REV"));
		m_AutoScoreReverseTime = Timer::GetFPGATimestamp();
		m_AutoScoreReverse = true;
	}
}


Arm::~Arm()
{
	delete m_Motor;
}

