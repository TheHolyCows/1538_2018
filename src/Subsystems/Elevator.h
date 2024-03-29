/*
 * Elevator.h
 *
 *  Created on: Feb 18, 2018
 *      Author: theholycows
 */

#ifndef SRC_SUBSYSTEMS_ELEVATOR_H_
#define SRC_SUBSYSTEMS_ELEVATOR_H_
#include "../CowLib/CowMotorController.h"
#include "../CowConstants.h"
#include <WPILib.h>
#include "../CowLib/CowPid.h"

class Elevator {
public:
	Elevator(int motorRight, int motorLeft, int encoderA, int encoderB);
	virtual ~Elevator();
	void handle();
	void SetSpeed(float speed);
	void SetPosition(float position);
	float GetDistance();
	void ResetConstants();
private:
	CowLib::CowMotorController *m_MotorRight;
	CowLib::CowMotorController *m_MotorLeft;
	float m_Speed;
	Encoder *m_Encoder;
	CowLib::CowPID *m_PID;
	float m_Position;
};

#endif /* SRC_SUBSYSTEMS_ELEVATOR_H_ */
