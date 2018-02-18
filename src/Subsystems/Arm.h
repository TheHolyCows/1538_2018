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



class Arm {
public:
	Arm(int motorController);
	void SetPosition(float position);
	void DisabledCalibration();
	void ResetConstants();
	void handle();
	virtual ~Arm();

private:
	CowLib::CowMotorController *m_Motor;
	float m_Position;
	float m_PlanetaryHardstop;
};

#endif /* SRC_SUBSYSTEMS_ARM_H_ */
