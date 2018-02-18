/*
 * Intake.h
 *
 *  Created on: Feb 18, 2018
 *      Author: kchau
 */

#ifndef SRC_SUBSYSTEMS_INTAKE_H_
#define SRC_SUBSYSTEMS_INTAKE_H_
#include "../CowLib/CowMotorController.h"
#include "../CowConstants.h"

class Intake {
public:
	Intake(int motorRight, int motorLeft);
	virtual ~Intake();
	void handle();
	void SetSpeed(float speed);
private:
	CowLib::CowMotorController *m_MotorRight;
	CowLib::CowMotorController *m_MotorLeft;
	float m_Speed;

};

#endif /* SRC_SUBSYSTEMS_INTAKE_H_ */
