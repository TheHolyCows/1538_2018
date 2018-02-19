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



class Arm {
public:
	Arm(int motorController);
	void SetPosition(float position);
	void DisabledCalibration();
	void ResetConstants();
	void handle();
	void SetModulatedSpeed(float speed);
	void SetIntakeSpeed(float speed);


	Intake* GetIntake()
	{
		return m_Intake;
	}

	void ScoreForward();
//	void ScoreReverse();
	virtual ~Arm();

private:
	CowLib::CowMotorController *m_Motor;
	Intake* m_Intake;
	float m_Position;
	float m_PlanetaryHardstop;
	bool m_AutoScore;
	float m_AutoScoreTime;

	int m_IntakeModulation;
};

#endif /* SRC_SUBSYSTEMS_ARM_H_ */
