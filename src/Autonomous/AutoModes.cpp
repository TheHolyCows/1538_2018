#include "AutoModes.h"
#include <WPILib.h>

AutoModes *AutoModes::m_SingletonInstance = NULL;

AutoModes *AutoModes::GetInstance()
{
    if(m_SingletonInstance == NULL)
    {
        m_SingletonInstance = new AutoModes();
    }
    return m_SingletonInstance;
}

AutoModes::AutoModes()
{    
    // Set up our selection order
	m_Modes["Nothing"];
	m_Modes["Nothing"].push_back(RobotCommand(CMD_WAIT, 0, 0, 0, CONSTANT("ELEVATOR_SCALE"), 0));

	m_Modes["Double Scale Right"];
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 10, -180, 0.6, 0, 0.5));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, 0, 0.01));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -165, -0.4, 0, 0.375));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -145, -165, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -210, -0.4, CONSTANT("ELEVATOR_SCALE"), 0.375));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -22, -210, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_AUTO_REV, -22, -210, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -22, -210, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -22, -210, 0.4, 0, 0.5));

	m_Modes["Double Scale Left"];
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2.3));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 1));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 0.9));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -200, 0.5, 0, .75));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -200, 0.5, 0, 0.7));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -60, -160, 0.2, (CONSTANT("ELEVATOR_SCALE")), 1.2));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_ARM_UP, -60, -160, 0.4, 0, 0.7));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_TURN, 0, -130, 0.4, 0, 0.5));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_AUTO_REV, 0, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.6));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 0, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 0, -130, 0.2, 0, 2));

	m_Modes["Scale Switch Left"];
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2.3));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 1));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 0.9));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 56, -180, 0.5, 0, .75));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_ARM_UP, 56, -180, 0.4, 0, 0.7));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 76, -180, 0.4, (CONSTANT("ELEVATOR_SWITCH")), 0.6));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_AUTO_FWD, 76, -180, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	m_Modes["Scale Switch Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 70, -180, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));

	m_Modes["Scale Switch Left Right"];
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
	// We edited the Hold Distance command below us to aim better for the AUTOSCORE, change all others if good
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.4, CONSTANT("ELEVATOR_SCALE"), 1.875));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.4, CONSTANT("ELEVATOR_SCALE"), 0.2));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 0.75));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 1));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 24, -180, 0.9, 0, 0.75));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_ARM_UP, 24, -180, 0.9, 0, 0.1));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_TURN, 0, -270, 0.85, 0, 0.6));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 150, -270, 0.85, (CONSTANT("ELEVATOR_SWITCH")), 1.75));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 182, -180, 0.93, (CONSTANT("ELEVATOR_SWITCH")), 1.55));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 230, -150, 0.6, (CONSTANT("ELEVATOR_SWITCH")), .75));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 266, -100, 0.6, (CONSTANT("ELEVATOR_SWITCH")), 0.2));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_AUTO_FWD, 266, -100, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 266, -100, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));

	m_Modes["Scale Switch Right"];
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 5, -180, 0.6, 0, 0.5));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, CONSTANT("ELEVATOR_SWITCH"), 1));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 34, -170, 0.75, CONSTANT("ELEVATOR_SWITCH"), .875));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_AUTO_FWD, 34, -170, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	m_Modes["Scale Switch Right"].push_back(RobotCommand(CMD_AUTO_FWD, 34, -170, 0.3, 0, 0.5));

	m_Modes["Scale Switch Right Left"];
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 5, -180, 0.6, 0, 0.5));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_ARM_UP, 5, -180, -0.4, 0, 0.125));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_TURN, 0, -90, 0.85, 0, 0.6));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 145, -90, 0.85, (CONSTANT("ELEVATOR_SWITCH")), 3));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 270, -180, 0.9, (CONSTANT("ELEVATOR_SWITCH")), 3));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 278, -210, 0.6, (CONSTANT("ELEVATOR_SWITCH")), .75));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 292, -260, 0.6, (CONSTANT("ELEVATOR_SWITCH")), 0.2));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_AUTO_FWD, 292, -260, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	m_Modes["Scale Switch Right Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 292, -260, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));

	m_Modes["R Scale Switch Right"];
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 85, 0, 0.875, 25, 2));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, 0, 0.45, 0, 2));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 200, -30, 0.25, 0, 2));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.2, CONSTANT("ELEVATOR_SCALE"), 2));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_AUTO_FWD, 265, -30, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.3, CONSTANT("ELEVATOR_SCALE"), .5));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 230, -30, 0.3, 0, .5));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 168, 90, 0.4, 0, 1.25));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 140, 180, 1, 0, 0.75));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_ARM_DOWN, 140, 180, 1, 0, 0.5));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 190, 180, 0.375, 0, 1));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 178, 180, 0.8, 0, .5));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_ARM_UP, 178, 180, 1, CONSTANT("ELEVATOR_SWITCH"), 0.5));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 212, 180, 0.4, CONSTANT("ELEVATOR_SWITCH"), 1));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_AUTO_FWD, 212, 180, 0.1, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	m_Modes["R Scale Switch Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 212, 180, 1, CONSTANT("ELEVATOR_SWITCH"), .5));

	m_Modes["R Double Scale Right"];
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 85, 0, 0.875, 25, 2));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, 0, 0.45, 0, 2));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 200, -30, 0.25, 0, 2));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.2, CONSTANT("ELEVATOR_SCALE"), 2));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_AUTO_FWD, 265, -30, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.3, CONSTANT("ELEVATOR_SCALE"), .5));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 230, -30, 0.3, 0, .5));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 168, 90, 0.4, 0, 1.25));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 140, 180, 1, 0, 0.75));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_ARM_DOWN, 140, 180, 1, 0, 0.5));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 190, 180, 0.375, 0, 1));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 178, 180, 0.8, 0, .5));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_ARM_UP, 178, 180, 1, 0, 0.5));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 90, 0.625, 0, 1));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, 0.4, 0, 1.2));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.9));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_AUTO_FWD, 315, -35, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, .25, CONSTANT("ELEVATOR_SCALE"), .5));
		m_Modes["R Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -35, .5, 0, 2));




	m_Modes["Cross Line Right Delay"];
	m_Modes["Cross Line Right Delay"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	m_Modes["Cross Line Right Delay"].push_back(RobotCommand(CMD_WAIT, 0, 0, .002, 25, 5));
	m_Modes["Cross Line Right Delay"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	m_Modes["Cross Line Right Delay"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	m_Modes["Cross Line Right Delay"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 209, 0, 0.875, 0, 2));

	m_Modes["Test"];
	m_Modes["Test"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	m_Modes["Test"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -100, -180, 1, 25, 2));

    m_Iterator = m_Modes.begin();
}

std::deque<RobotCommand> AutoModes::GetCommandList()
{
    return m_Iterator->second;
}

const char *AutoModes::GetName()
{
    return m_Iterator->first;
}

void AutoModes::NextMode()
{
    ++m_Iterator;
    if(m_Iterator == m_Modes.end())
    {
        m_Iterator = m_Modes.begin();
    }
    std::string str(GetName());
    std::string temp = "Auto mode: " + str;
    DriverStation::GetInstance().ReportError(temp);
}
