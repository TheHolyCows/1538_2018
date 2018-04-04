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
	nothing.ignoreSwitch = false;
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
	doubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
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
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -8, -210, 0.4, CONSTANT("ELEVATOR_SCALE"), 1.25));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_REV, -10, -210, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -8, -210, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
	doubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -8, -210, 0.4, 0, 0.5));

    doubleScaleRight.ourScale = CowGameData::SCALE_RIGHT;
    doubleScaleRight.ourSwitch = CowGameData::SWITCH_INVALID;
    doubleScaleRight.ignoreSwitch = true;
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
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, 52, 2.3));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 365, 20, 0.3, 52, 0.25));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, 52, 0.5));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -190, 0.5, 0, 1));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_ARM_DOWN, 255, -190, 0.4, 0, 0.7));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -190, 0, 25, 0.05));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 68, -190, 0.37, 0, 0.9));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -200, 0.6, 0, .75));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -200, 0.5, 0, 0.7));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_ARM_UP, -60, -160, 0.4, 0, 0.1));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -60, -160, 0.2, (CONSTANT("ELEVATOR_SCALE")), 1.2));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_TURN, 0, -130, 0.4, (CONSTANT("ELEVATOR_SCALE")), 0.5));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -4.5, -130, 0.375, CONSTANT("ELEVATOR_SCALE"), 0.8));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_AUTO_REV, -4.5, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.6));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -4.5, -130, 0.375, CONSTANT("ELEVATOR_SCALE"), 0.5));
    	doubleScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 5, -180, 0.375, 0, 2));

    	doubleScaleLeft.ourScale = CowGameData::SCALE_LEFT;
    doubleScaleLeft.ourSwitch = CowGameData::SWITCH_LEFT;
    doubleScaleLeft.ignoreSwitch = true;
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
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, 52, 2.3));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 365, 20, 0.3, 52, 0.25));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, 52, 0.5));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 1));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 31, -180, 0.45, 0, 0.9));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 15, -180, 0.5, 0, .75));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_ARM_UP, 15, -180, 0.4, 0, 0.7));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 36, -180, 0.4, (CONSTANT("ELEVATOR_SWITCH")), 0.6));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD, 36, -180, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 15, -180, 0.2, 0, 0.5));

    scaleSwitchLeft.ourScale = CowGameData::SCALE_LEFT;
    scaleSwitchLeft.ourSwitch = CowGameData::SWITCH_LEFT;
    scaleSwitchLeft.ignoreSwitch = false;
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
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.4, 52, 1.875));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 365, 20, 0.4, 52, 0.2));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, 52, 0.5));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 0.75));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 1));
	scaleSwitchLeftRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 24, -180, 0.9, 0, 0.75));
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
    scaleSwitchLeftRight.ignoreSwitch = false;
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
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, 52, 2));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, 52, 0.25));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, 52, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 20, -90, 0.4, 0, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 5, -180, 0.6, 0, 0.5));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 26, -178, 0.3, CONSTANT("ELEVATOR_SWITCH"), .875));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD_LOW, 26, -178, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	scaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 26, -178, 0.3, 0, 0.5));
    scaleSwitchRight.ourScale = CowGameData::SCALE_RIGHT;
    scaleSwitchRight.ourSwitch = CowGameData::SWITCH_RIGHT;
    scaleSwitchRight.ignoreSwitch = false;
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
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, 52, 2));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, 52, 0.25));
	scaleSwitchRightLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, 52, 0.5));
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
	scaleSwitchRightLeft.ignoreSwitch = false;
	scaleSwitchRightLeft.isDefaultMode = false;

    centerScaleSwitches.push_back(scaleSwitchRightLeft);

    m_Modes["center scale switch"] = centerScaleSwitches;

    AutoModePermutation switchScaleScaleRRR;
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, .8, 25, 0.5));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, 55, .8, 0, 0.75));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 90, 0, .8, 0, 0.75));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 130, 0, .377, CONSTANT("ELEVATOR_SWITCH"), 0.51));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_AUTO_FWD, 130, 0, .2, CONSTANT("ELEVATOR_SWITCH"), 0.5));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 130, 0, .377, CONSTANT("ELEVATOR_SWITCH"), 0.2));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 120, -30, .377, CONSTANT("ELEVATOR_SWITCH"), 1));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 95, -130, .5, 0, 1));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -55, -180, .9, 0, 1.75));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_ARM_DOWN, -40, -180, -0.4, 0, 0.3));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, -8, -145, .377, 0, 2));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, -25, -125, .9, 0, 1.25));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_ARM_UP, -25, -125, -0.4, 0, 0.3));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, -65, -170, .77, 0, 1.25));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -65, -170, .52, 0, .5));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -175, -230, .375, CONSTANT("ELEVATOR_SCALE"), 1));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_AUTO_REV, -175, -230, .2, CONSTANT("ELEVATOR_SCALE"), 0.5));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -175, -230, .2, CONSTANT("ELEVATOR_SCALE"), .5));
    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -110, -230, .2, 0, 2));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -166, -195, .2, CONSTANT("ELEVATOR_SCALE"), 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_AUTO_REV, -166, -230, .2, CONSTANT("ELEVATOR_SCALE"), 0.5));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -166, -230, .2, CONSTANT("ELEVATOR_SCALE"), 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -166, -230, .2, 0, .1));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, -36, -90, .75, 0, 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 24, -90, .75, 0, 1.25));
//	switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_ARM_DOWN, 32, -180, -0.4, 0, 0.3));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 32, -180, .2, 0, 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 26, -180, .2, 0, 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_ARM_UP, 26, -180, -0.4, 0, 0.3));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, -36, -90, .75, 0, 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, -70, -90, .75, 0, 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -80, -200, .2, CONSTANT("ELEVATOR_SCALE"), .25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_AUTO_REV, -80, -200, .2, CONSTANT("ELEVATOR_SCALE"), 0.5));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -70, -200, .2, CONSTANT("ELEVATOR_SCALE"), 1.25));
//    switchScaleScaleRRR.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, -70, -200, .2, 0, .1));
    switchScaleScaleRRR.ourScale = CowGameData::SCALE_RIGHT;
    switchScaleScaleRRR.ourSwitch = CowGameData::SWITCH_RIGHT;
    switchScaleScaleRRR.ignoreSwitch = false;
    switchScaleScaleRRR.isDefaultMode = false;

    std::vector<AutoModePermutation> centerThreeCubes;
    centerThreeCubes.push_back(switchScaleScaleRRR);

    m_Modes["3 cube center"] = centerThreeCubes;


    // Left autos
     AutoModePermutation lTripleScaleL;
     lTripleScaleL.commands.push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.01));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 85, 0, 0.875, 25, 2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, 0, 0.6, 52, 2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 200, 35, 0.375, 52, 2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 273, 35, 0.2, 52, .92));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_AUTO_FWD, 273, 35, 0.1, 52, 0.25));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 273, 35, 0.25, 52, .3));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 269, 35, 0.25, 0, .5));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 194, -205, 0.375, 0, .75));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_ARM_DOWN, 194, -205, 0.375, 0, 0.2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 236, -205, 0.375, 0, 2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 194, -205, 0.65, 0, 2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_ARM_UP, 194, -205, 0.375, 0, 0.2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 180, -155, 0.25, 0, .5));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 170, -155, 0.25, 0, 1));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 170, -155, 0.25, CONSTANT("ELEVATOR_SCALE"), .8));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_AUTO_REV, 170, -155, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 170, -155, 0.25, CONSTANT("ELEVATOR_SCALE"), .3));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 180, -155, 0.3, 0, 2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, -240, 0.25, 0, 3));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_ARM_DOWN, 185, -240, 0.375, 0, 0.2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 190, -200, 0.25, 0, 5));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE_INTAKE, 185, -200, 0.25, 0, 5));
    	 lTripleScaleL.commands.push_back(RobotCommand(CMD_ARM_UP, 185, -200, 0.375, 0, 0.2));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 160, -170, 0.25, CONSTANT("ELEVATOR_SCALE"), 3));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 170, -170, 0.25, CONSTANT("ELEVATOR_SCALE"), .3));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_AUTO_REV, 170, -170, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 170, -170, 0.25, CONSTANT("ELEVATOR_SCALE"), .3));
     lTripleScaleL.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 160, -170, 0.3, 0, 2));


     lTripleScaleL.ourScale = CowGameData::SCALE_LEFT;
     lTripleScaleL.ourSwitch = CowGameData::SWITCH_LEFT;
     lTripleScaleL.ignoreSwitch = true;
	 lTripleScaleL.isDefaultMode = true;

  	std::vector<AutoModePermutation> left;
  	left.push_back(lTripleScaleL);

  	m_Modes["left"] = left;


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
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 224, 180, 0.4, CONSTANT("ELEVATOR_SWITCH"), 1));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 224, 180, 0.1, CONSTANT("ELEVATOR_SWITCH"), 0.25));
	rScaleSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 224, 180, 1, CONSTANT("ELEVATOR_SWITCH"), .5));
	rScaleSwitchRight.ourScale = CowGameData::SCALE_RIGHT;
	rScaleSwitchRight.ourSwitch = CowGameData::SWITCH_RIGHT;
	rScaleSwitchRight.ignoreSwitch = false;
	rScaleSwitchRight.isDefaultMode = false;


    AutoModePermutation rScaleRight;
    rScaleRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    rScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 85, 0, 0.875, 25, 2));
    rScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 185, 0, 0.45, 0, 2));
    rScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 200, -30, 0.25, 0, 2));
    rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.2, CONSTANT("ELEVATOR_SCALE"), 2));
    rScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 265, -30, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
    rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 265, -30, 0.3, CONSTANT("ELEVATOR_SCALE"), .5));
    rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 230, -30, 0.3, 0, .5));
    rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 168, 90, 0.4, 0, 1.25));
    rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 140, 180, 1, 0, 0.75));
    rScaleRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 140, 180, 1, 0, 0.5));
	rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 190, 180, 0.375, 0, 1));
	rScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 178, 180, 0.8, 0, .5));
	rScaleRight.commands.push_back(RobotCommand(CMD_ARM_UP, 178, 180, 1, CONSTANT("ELEVATOR_SWITCH"), 0.5));

	rScaleRight.ourScale = CowGameData::SCALE_RIGHT;
	rScaleRight.ourSwitch = CowGameData::SWITCH_LEFT;
	rScaleRight.ignoreSwitch = false;
	rScaleRight.isDefaultMode = false;

    AutoModePermutation rScaleLeft;
    rScaleLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    rScaleLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 100, 0, 0.75, 25, 2));
    rScaleLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 150, 0, 0.2, 0, 2));
    rScaleLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 155, 0, 0.2, 0, 2));
    rScaleLeft.ourScale = CowGameData::SCALE_LEFT;
    rScaleLeft.ourSwitch = CowGameData::SWITCH_LEFT;
    rScaleLeft.ignoreSwitch = false;
    rScaleLeft.isDefaultMode = true;

	std::vector<AutoModePermutation> rightScaleSwitches;
	rightScaleSwitches.push_back(rScaleSwitchRight);
	rightScaleSwitches.push_back(rScaleRight);
	rightScaleSwitches.push_back(rScaleLeft);
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
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 278, -30, 0.2, CONSTANT("ELEVATOR_SCALE"), 2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 278, -30, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 278, -30, 0.3, CONSTANT("ELEVATOR_SCALE"), .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 230, -30, 0.3, 0, .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 168, 90, 0.4, 0, 1.25));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 140, 180, 1, 0, 0.75));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_ARM_DOWN, 140, 180, 1, 0, 0.5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 190, 180, 0.375, 0, 1));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 178, 180, 0.8, 0, .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_ARM_UP, 178, 180, 1, 0, 0.5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 90, 0.625, 0, 1));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 330, -35, 0.4, 0, 1.2));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 330, -35, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.9));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 330, -35, 0.1, CONSTANT("ELEVATOR_SCALE"), 0.25));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 330, -35, .25, CONSTANT("ELEVATOR_SCALE"), .5));
    rDoubleScaleRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 315, -35, .5, 0, 2));
    rDoubleScaleRight.ourScale = CowGameData::SCALE_RIGHT;
    rDoubleScaleRight.ourSwitch = CowGameData::SWITCH_INVALID;
    rDoubleScaleRight.ignoreSwitch = false;
    rDoubleScaleRight.isDefaultMode = true;

    AutoModePermutation rDoubleScaleLeftSwitchLeft;
    rDoubleScaleLeftSwitchLeft.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    rDoubleScaleLeftSwitchLeft.commands.push_back(RobotCommand(CMD_WAIT, 0, 0, 0.75, 25, 8));
    rDoubleScaleLeftSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 100, 0, 0.75, 25, 2));
    rDoubleScaleLeftSwitchLeft.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 150, 0, 0.5, 0, 2));
    rDoubleScaleLeftSwitchLeft.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 155, 0, 0.2, 0, 2));
    rDoubleScaleLeftSwitchLeft.ourScale = CowGameData::SCALE_LEFT;
    rDoubleScaleLeftSwitchLeft.ourSwitch = CowGameData::SWITCH_LEFT;
    rDoubleScaleLeftSwitchLeft.ignoreSwitch = false;
    rDoubleScaleLeftSwitchLeft.isDefaultMode = false;

    AutoModePermutation rSwitchRight;
    rSwitchRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    rSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 100, 0, 0.75, 25, 2));
    rSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 150, 0, 0.2, 0, 2));
    rSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 155, 0, 0.2, 0, 2));
    rSwitchRight.ourScale = CowGameData::SCALE_LEFT;
    rSwitchRight.ourSwitch = CowGameData::SWITCH_RIGHT;
    rSwitchRight.ignoreSwitch = false;
    rSwitchRight.isDefaultMode = false;


    AutoModePermutation rDoubleScaleLeftSwitchRight;
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 100, 0, 0.75, 25, 2));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 160, 0, 0.375, 0, 2));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_TURN, 160, -90, 0.375, 0, 1));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 59, -90, 0.25, CONSTANT("ELEVATOR_SWITCH"), 2));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_AUTO_FWD, 59, -90, 0.2, CONSTANT("ELEVATOR_SWITCH"), .5));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 59,-90, 0.2, 0, 1));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 49, -90, 0.375, 0, 2));
    rDoubleScaleLeftSwitchRight.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 49, -90, 0.375, 0, 2));

    rDoubleScaleLeftSwitchRight.ourScale = CowGameData::SCALE_LEFT;
    rDoubleScaleLeftSwitchRight.ourSwitch = CowGameData::SWITCH_RIGHT;
    rDoubleScaleLeftSwitchRight.ignoreSwitch = false;
    rDoubleScaleLeftSwitchRight.isDefaultMode = false;

    std::vector<AutoModePermutation> rightScaleScales;
    rightScaleScales.push_back(rDoubleScaleRight);
    rightScaleScales.push_back(rDoubleScaleLeftSwitchLeft);
    rightScaleScales.push_back(rDoubleScaleLeftSwitchRight);
    rightScaleScales.push_back(rSwitchRight);


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
    crossLineRightDelay.ignoreSwitch = false;
    crossLineRightDelay.isDefaultMode = true;

    std::vector<AutoModePermutation> centerNothingNothingRights;
    centerNothingNothingRights.push_back(crossLineRightDelay);
    m_Modes["center nothing nothing right"] = centerNothingNothingRights;

    AutoModePermutation centerSwitchRight_R;
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_WAIT, 0, 0, 0.875, 25, 2));
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 62, 55, 0.5, 0, 2));
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 120, 0, 0.375, CONSTANT("ELEVATOR_SWITCH"), 2));
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_AUTO_FWD, 120, 0, 0.2, CONSTANT("ELEVATOR_SWITCH"), .5));
    centerSwitchRight_R.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 120, 0, 0.375, CONSTANT("ELEVATOR_SWITCH"), 2));

    centerSwitchRight_R.ourScale = CowGameData::SCALE_RIGHT;
    centerSwitchRight_R.ourSwitch = CowGameData::SWITCH_RIGHT;
    centerSwitchRight_R.ignoreSwitch = false;
    centerSwitchRight_R.isDefaultMode = false;

    AutoModePermutation centerSwitchRight_L;
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_WAIT, 0, 0, 0.875, 25, 2));
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 62, 55, 0.5, 0, 2));
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 120, 0, 0.375, CONSTANT("ELEVATOR_SWITCH"), 2));
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_AUTO_FWD, 120, 0, 0.2, CONSTANT("ELEVATOR_SWITCH"), .5));
    centerSwitchRight_L.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 120, 0, 0.375, CONSTANT("ELEVATOR_SWITCH"), 2));

    centerSwitchRight_L.ourScale = CowGameData::SCALE_LEFT;
    centerSwitchRight_L.ourSwitch = CowGameData::SWITCH_RIGHT;
    centerSwitchRight_L.ignoreSwitch = false;
    centerSwitchRight_L.isDefaultMode = false;

    AutoModePermutation centerSwitchLeft_R;
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 65, -65, 0.875, 0, 2));
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 120, 0, 0.5, 0, 2));
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 120, 0, 0.375, CONSTANT("ELEVATOR_SWITCH"), 2));
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_AUTO_FWD, 120, 0, 0.2, CONSTANT("ELEVATOR_SWITCH"), .5));
    centerSwitchLeft_R.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 120, 0, 0.375, CONSTANT("ELEVATOR_SWITCH"), 2));

    centerSwitchLeft_R.ourScale = CowGameData::SCALE_RIGHT;
    centerSwitchLeft_R.ourSwitch = CowGameData::SWITCH_LEFT;
    centerSwitchLeft_R.ignoreSwitch = false;
    centerSwitchLeft_R.isDefaultMode = false;

    AutoModePermutation centerSwitchLeft_L;
    centerSwitchLeft_L.commands.push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.01));
    centerSwitchLeft_L.commands.push_back(RobotCommand(CMD_WAIT, 0, 0, .002, 25, 5));
    centerSwitchLeft_L.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
    centerSwitchLeft_L.commands.push_back(RobotCommand(CMD_DRIVE_DISTANCE, 138, -55, 0.875, 0, 2));
    centerSwitchLeft_L.commands.push_back(RobotCommand(CMD_HOLD_DISTANCE, 209, 0, 0.875, 0, 2));
    centerSwitchLeft_L.ourScale = CowGameData::SCALE_LEFT;
    centerSwitchLeft_L.ourSwitch = CowGameData::SWITCH_LEFT;
    centerSwitchLeft_L.ignoreSwitch = false;
    centerSwitchLeft_L.isDefaultMode = true;

    std::vector<AutoModePermutation> centerSwitches;
    centerSwitches.push_back(centerSwitchRight_R);
    centerSwitches.push_back(centerSwitchRight_L);
    centerSwitches.push_back(centerSwitchLeft_R);
    centerSwitches.push_back(centerSwitchLeft_L);
    m_Modes["center switches"] = centerSwitches;


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
           (permutationIterator->ourSwitch == inputSwitch) && !permutationIterator->ignoreSwitch)
        {
            /*
             * Found our match and get out
             */
            commands = permutationIterator->commands;
            break;
        }
        else if ((permutationIterator->ourScale == inputScale) && permutationIterator->ignoreSwitch)
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
