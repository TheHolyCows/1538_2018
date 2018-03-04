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
    /*
     * our_switch scale their_swtich i.e., RLR
     * start_position scale|switch scale|switch drive_direction
     */

    /*
     * ***
     * nothing
     */
	AutoModePermutation nothing;
	nothing.commands.push_back(RobotCommand(CMD_WAIT, 0, 0, 0, CONSTANT("ELEVATOR_SCALE"), 0));
	nothing.ourScale = CowGameData::SCALE_INVALID;
	nothing.ourSwitch = CowGameData::SWITCH_INVALID;
	nothing.isDefaultMode = true;

	std::vector<AutoModePermutation> nothings;
	nothings.push_back(nothing);
	m_Modes["nothing"] = nothings;

	/*
	 * RR*
	 * center scale scale
	 */
	AutoModePermutation doubleScaleRight;
	doubleScaleRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 10, -180, 0.6, 0, 0.5));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, 0, 0.01));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_TURN, 0, -165, -0.4, 0, 0.375));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -145, -165, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_TURN, 0, -210, -0.4, CONSTANT("ELEVATOR_SCALE"), 0.375));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -22, -210, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_REV, -22, -210, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -22, -210, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -22, -210, 0.4, 0, 0.5));

    doubleScaleRight.ourScale = CowGameData::SCALE_RIGHT;
    doubleScaleRight.ourSwitch = CowGameData::SWITCH_RIGHT;
    doubleScaleRight.isDefaultMode = true;

    std::vector<AutoModePermutation> centerScaleScales;
    centerScaleScales.push_back(doubleScaleRight);

    /*
     * LL*
     * center scale scale
     */
    AutoModePermutation doubleScaleLeft;
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2.3));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 1));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 0.9));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -200, 0.5, 0, .75));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -200, 0.5, 0, 0.7));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -60, -160, 0.2, (CONSTANT("ELEVATOR_SCALE")), 1.2));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_ARM_UP, -60, -160, 0.4, 0, 0.7));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_TURN, 0, -130, 0.4, 0, 0.5));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_AUTO_REV, 0, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.6));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 0, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 0, -130, 0.2, 0, 2));
	
    doubleScaleLeft.ourScale = CowGameData::SCALE_LEFT;
    doubleScaleLeft.ourSwitch = CowGameData::SWITCH_LEFT;
    doubleScaleLeft.isDefaultMode = false;

    centerScaleScales.push_back(doubleScaleLeft);

	m_Modes["center scale scale"] = centerScaleScales;

    /*
     * LL*
     * center scale switch
     */
    AutoModePermutation scaleSwitchLeft;
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2.3));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 1));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 0.9));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 56, -180, 0.5, 0, .75));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_ARM_UP, 56, -180, 0.4, 0, 0.7));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 76, -180, 0.4, (CONSTANT("ELEVATOR_SWITCH")), 0.6));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD, 76, -180, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 70, -180, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));

    scaleSwitchLeft.ourScale = CowGameData::SCALE_LEFT;
    scaleSwitchLeft.ourSwitch = CowGameData::SWITCH_LEFT;
    scaleSwitchLeft.isDefaultMode = true;

    std::vector<AutoModePermutation> centerScaleSwitches;
    centerScaleSwitches.push_back(scaleSwitchLeft);

    /*
     * RL*
     * center scale switch
     */
    AutoModePermutation scaleSwitchLeftRight;
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
	// We edited the Hold Distance command below us to aim better for the AUTOSCORE, change all others if good
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.4, CONSTANT("ELEVATOR_SCALE"), 1.875));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 365, 20, 0.4, CONSTANT("ELEVATOR_SCALE"), 0.2));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 0.75));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 1));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 24, -180, 0.9, 0, 0.75));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_ARM_UP, 24, -180, 0.9, 0, 0.1));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_TURN, 0, -270, 0.85, 0, 0.6));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 150, -270, 0.85, (CONSTANT("ELEVATOR_SWITCH")), 1.75));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 182, -180, 0.93, (CONSTANT("ELEVATOR_SWITCH")), 1.55));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 230, -150, 0.6, (CONSTANT("ELEVATOR_SWITCH")), .75));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 266, -100, 0.6, (CONSTANT("ELEVATOR_SWITCH")), 0.2));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 266, -100, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 266, -100, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));

    scaleSwitchLeftRight.ourScale = CowGameData::SCALE_LEFT;
    scaleSwitchLeftRight.ourSwitch = CowGameData::SWITCH_RIGHT;
    scaleSwitchLeftRight.isDefaultMode = true;

    centerScaleSwitches.push_back(scaleSwitchLeftRight);

    /*
     * RR*
     * center scale switch
     */
    AutoModePermutation scaleSwitchRight;
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 5, -180, 0.6, 0, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, CONSTANT("ELEVATOR_SWITCH"), 1));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 34, -170, 0.75, CONSTANT("ELEVATOR_SWITCH"), .875));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 34, -170, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 34, -170, 0.3, 0, 0.5));
    scaleSwitchRight.ourScale = CowGameData::SCALE_RIGHT;
    scaleSwitchRight.ourSwitch = CowGameData::SWITCH_RIGHT;
    scaleSwitchRight.isDefaultMode = false;

    centerScaleSwitches.push_back(scaleSwitchRight);

    /*
     * LR*
     * center scale switch
     */
    AutoModePermutation scaleSwitchRightLeft;
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 5, -180, 0.6, 0, 0.5));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_ARM_UP, 5, -180, -0.4, 0, 0.125));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_TURN, 0, -90, 0.85, 0, 0.6));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 145, -90, 0.85, (CONSTANT("ELEVATOR_SWITCH")), 3));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 270, -180, 0.9, (CONSTANT("ELEVATOR_SWITCH")), 3));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 278, -210, 0.6, (CONSTANT("ELEVATOR_SWITCH")), .75));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 292, -260, 0.6, (CONSTANT("ELEVATOR_SWITCH")), 0.2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD, 292, -260, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 292, -260, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));
	scaleSwitchRightLeft.ourScale = CowGameData::SCALE_RIGHT;
	scaleSwitchRightLeft.ourSwitch = CowGameData::SWITCH_LEFT;
	scaleSwitchRightLeft.isDefaultMode = false;

    centerScaleSwitches.push_back(scaleSwitchRightLeft);

    m_Modes["center scale switch"] = centerScaleSwitches;

    /*
     * RR*
     * right scale switch
     */
    AutoModePermutation rScaleSwitchRight;
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 85, 0, 0.875, 25, 2));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, 0, 0.45, 0, 2));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 200, -30, 0.25, 0, 2));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.2, CONSTANT("ELEVATOR_SCALE"), 2));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 265, -30, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.3, CONSTANT("ELEVATOR_SCALE"), .5));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 230, -30, 0.3, 0, .5));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 168, 90, 0.4, 0, 1.25));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 140, 180, 1, 0, 0.75));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 140, 180, 1, 0, 0.5));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 190, 180, 0.375, 0, 1));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 178, 180, 0.8, 0, .5));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_ARM_UP, 178, 180, 1, CONSTANT("ELEVATOR_SWITCH"), 0.5));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 212, 180, 0.4, CONSTANT("ELEVATOR_SWITCH"), 1));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 212, 180, 0.1, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 212, 180, 1, CONSTANT("ELEVATOR_SWITCH"), .5));
	rScaleSwitchRight.ourScale = CowGameData::SCALE_RIGHT;
	rScaleSwitchRight.ourSwitch = CowGameData::SWITCH_RIGHT;
	rScaleSwitchRight.isDefaultMode = true;

	std::vector<AutoModePermutation> rightScaleSwitches;
	rightScaleSwitches.push_back(rScaleSwitchRight);
	m_Modes["right scale switch"] = rightScaleSwitches;

    /*
     * *R*
     * right scale scale
     */ 
    AutoModePermutation rDoubleScaleRight;
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 85, 0, 0.875, 25, 2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, 0, 0.45, 0, 2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 200, -30, 0.25, 0, 2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.2, CONSTANT("ELEVATOR_SCALE"), 2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 265, -30, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.3, CONSTANT("ELEVATOR_SCALE"), .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 230, -30, 0.3, 0, .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 168, 90, 0.4, 0, 1.25));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 140, 180, 1, 0, 0.75));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 140, 180, 1, 0, 0.5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 190, 180, 0.375, 0, 1));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 178, 180, 0.8, 0, .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_ARM_UP, 178, 180, 1, 0, 0.5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 90, 0.625, 0, 1));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, 0.4, 0, 1.2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.9));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 315, -35, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, .25, CONSTANT("ELEVATOR_SCALE"), .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -35, .5, 0, 2));
    rDoubleScaleRight.ourScale = CowGameData::SCALE_RIGHT;
    rDoubleScaleRight.ourSwitch = CowGameData::SWITCH_INVALID;
    rDoubleScaleRight.isDefaultMode = true;

    std::vector<AutoModePermutation> rightScaleScales;
    rightScaleScales.push_back(rDoubleScaleRight);
    m_Modes["right scale scale"] = rightScaleScales;

	/*
     * ***
     * center * * right
     */
    AutoModePermutation crossLineRightDelay;
    crossLineRightDelay.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    crossLineRightDelay.commands.push_back(RobotCommand(CMD_WAIT, 0, 0, .002, 25, 5));
    crossLineRightDelay.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
    crossLineRightDelay.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, 55, 0.875, 0, 2));
    crossLineRightDelay.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 209, 0, 0.875, 0, 2));
    crossLineRightDelay.ourScale = CowGameData::SCALE_INVALID;
    crossLineRightDelay.ourSwitch = CowGameData::SWITCH_INVALID;
    crossLineRightDelay.isDefaultMode = true;

    std::vector<AutoModePermutation> centerNothingNothingRights;
    centerNothingNothingRights.push_back(crossLineRightDelay);
    m_Modes["center nothing nothing right"] = centerNothingNothingRights;

    AutoModePermutation test;
	test.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
	test.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -100, -180, 1, 25, 2));
	test.ourScale = CowGameData::SCALE_INVALID;
	test.ourSwitch = CowGameData::SWITCH_INVALID;
	test.isDefaultMode = true;

	std::vector<AutoModePermutation> tests;
	tests.push_back(test);
	m_Modes["test"] = tests;

	m_ModesIterator = m_Modes.begin();
}

std::deque<RobotCommand> AutoModes::GetCommandList(CowGameData::CowScaleOwnership inputScale,
                                                   CowGameData::CowSwitchOwnership inputSwitch)
{
    std::deque<RobotCommand> commands;

    std::vector<AutoModePermutation>::iterator permutationIterator = m_ModesIterator->second.begin();
    while(permutationIterator != m_ModesIterator->second.end())
    {
        if((permutationIterator->ourScale == inputScale) &&
           (permutationIterator->ourSwitch == inputSwitch))
        {
            /*
             * Found our match and get out
             */
            commands = permutationIterator->commands;
            break;
        }
        else if(permutationIterator->isDefaultMode)
        {
            /*
             * We see a default so save it in case we don't find a match
             */
            commands = permutationIterator->commands;
        }

        permutationIterator++;
    }

    return commands;
}

std::string AutoModes::GetModeName()
{
    return m_ModesIterator->first;
}

void AutoModes::NextMode()
{
    ++m_ModesIterator;
    if(m_ModesIterator == m_Modes.end())
    {
        m_ModesIterator = m_Modes.begin();
    }

    std::string str(GetModeName());
    std::string temp = "Auto mode: " + str;
    DriverStation::GetInstance().ReportError(temp);
}
