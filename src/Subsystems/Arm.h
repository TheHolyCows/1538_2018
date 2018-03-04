/*
 * Arm.h
 *
 *  Created on: Feb 18, 2018
 *      Author: kchau
 */

#ifndef SRC_SUBSYSTEMS_ARM_H_
#define SRC_SUBSYSTEMS_ARM_H_

#include "../CowLib/CowMotorController.h"
#include "../CowConstants.h"
#include "Intake.h"
#include <WPILib.h>
#include <Timer.h>
#include "Elevator.h"



class Arm {
public:
	Arm(int motorController);
	void SetPosition(float position);
	float GetSetpoint();
	void DisabledCalibration();
	void ResetConstants();
	void handle();
	void SetModulatedSpeed(float speed);
	void SetIntakeSpeed(float speed);



	Intake* GetIntake()
	{
		return m_Intake;
	}

	void SetElevatorInstance(Elevator* elevator)
	{
		m_Elevator = elevator;
	}

	void ScoreForward(double autoSpeed);
	void ScoreReverse(double autoSpeed);
	virtual ~Arm();

private:
	CowLib::CowMotorController *m_Motor;
	Intake* m_Intake;
	float m_Position;
	float m_PlanetaryHardstop;
	bool m_AutoScoreForward;
	float m_AutoScoreForwardTime;
	bool m_AutoScoreReverse;
	float m_AutoScoreReverseTime;
	float m_AutoScoreSpeed;

	int m_IntakeModulation;

	Elevator *m_Elevator;
	bool m_StartingConfigSet;
};

#endif /* SRC_SUBSYSTEMS_ARM_H_ */
