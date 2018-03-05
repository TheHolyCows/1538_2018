/*
 * Ramps.h
 *
 *  Created on: Mar 4, 2018
 *      Author: theholycows
 */

#ifndef SRC_SUBSYSTEMS_RAMPS_H_
#define SRC_SUBSYSTEMS_RAMPS_H_
#include <WPILib.h>


class Ramps {
public:
	Ramps(int motorRight, int motorLeft, int rampServo);
	void DeployRamps();
	void SetLeftRampSpeed(float speed);
	void SetRightRampSpeed(float speed);
	void handle();
	virtual ~Ramps();
private:
	CowLib::CowMotorController *m_MotorRight;
	CowLib::CowMotorController *m_MotorLeft;
	Servo *m_RampServo;

	float m_RightSpeed;
	float m_LeftSpeed;
	float m_RampServoPosition;

};

#endif /* SRC_SUBSYSTEMS_RAMPS_H_ */
