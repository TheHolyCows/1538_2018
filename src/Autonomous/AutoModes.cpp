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
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 142, 55, 0.875, 0, 2));
    //We should be next to the switch?

    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, -20, 0.5, 0, 2));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_AUTO_FWD, 342, -20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 342, -20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.6));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 325, -20, 0.4, 0, 0.3));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -90, -0.4, 0, 0.5));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 16, -90, 0.4, 0, 0.5));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 10, -180, 0.6, 0, 0.5));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, 0, 0.01));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -165, -0.4, 0, 0.375));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -145, -165, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN, 0, -200, -0.4, CONSTANT("ELEVATOR_SCALE"), 0.375));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -32, -200, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_AUTO_REV, 0, -200, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -32, -200, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -32, -200, 0.4, 0, 0.5));

    m_Modes["Double Scale Left"];
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 140, -65, 0.875, 0, 2));
      //We should be next to the switch?

      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));


      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_TURN, 0, 110, 0.4, 0, 0.75));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_ARM_DOWN, 0, 110, 0.4, 0, 0.3));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 13, 110, 0.4, 0, 0.6));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 56, 200, 0.6, 0, 1.2));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, -15, 160, 0.4, 0, 0.5));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -2, 200, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_ARM_UP, -2, 200, 0.4, 0, 0.7));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_AUTO_REV, -2, 200, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.5));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -2, 200, 0.4, CONSTANT("ELEVATOR_SCALE"), 0.5));
      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -2, 200, 0.4, 0, 0.5));

      m_Modes["Double Scale Left 2"];
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, 25, 0.05));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 15, 0, 0.875, 25, 2));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, 0.875, 0, 2));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 2.3));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.4, 0, 0.6));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 1));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 0.9));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -200, 0.5, 0, .75));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -200, 0.5, 0, 0.7));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -60, -160, 0.2, (CONSTANT("ELEVATOR_SCALE")), 1.2));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_ARM_UP, -60, -160, 0.4, 0, 0.7));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_TURN, 0, -130, 0.4, 0, 0.5));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_AUTO_REV, 0, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.6));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 0, -130, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 0, -130, 0.2, 0, 2));


      //     // m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_ARM_UP, 227, -160, 0.4, 0, 0.01));
      //      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -160, 0.2, (CONSTANT("ELEVATOR_SCALE")), 1.2));
      //      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_AUTO_REV, -40, -160, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.6));
      //      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -160, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.5));
      //      m_Modes["Double Scale Left 2"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -40, -160, 0.2, 0, 2));



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
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 135, -65, .875, 0, 2));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 209, 0, 0.875, 0, 2));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 250, 20, 0.5, 0, 2));
                  // We edited the Hold Distance command below us to aim better for the AUTOSCORE, change all others if good
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.4, CONSTANT("ELEVATOR_SCALE"), 1.5));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_AUTO_FWD, 365, 20, 0.4, CONSTANT("ELEVATOR_SCALE"), 0.2));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 365, 20, 0.2, CONSTANT("ELEVATOR_SCALE"), 0.3));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 318, 20, 0.7, 0, 0.3));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 300, -90, 0.4, 0, 0.6));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 255, -180, 1, 0, 0.75));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_ARM_DOWN, 255, -180, 0.4, 0, 0.7));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, -180, 0, 25, 0.05));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.45, 0, 1));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 24, -180, 0.9, 0, 0.75));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_ARM_UP, 24, -180, 0.9, 0, 0.5));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_TURN, 0, -270, 0.85, 0, 0.6));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 150, -270, 0.85, (CONSTANT("ELEVATOR_SWITCH")), 1.75));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 182, -180, 0.93, (CONSTANT("ELEVATOR_SWITCH")), 1.55));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 230, -150, 0.6, (CONSTANT("ELEVATOR_SWITCH")), .75));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 266, -100, 0.6, (CONSTANT("ELEVATOR_SWITCH")), 0.2));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_AUTO_FWD, 266, -100, 0.3, CONSTANT("ELEVATOR_SWITCH"), 0.25));
                  m_Modes["Scale Switch Left Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 266, -100, 0.2, CONSTANT("ELEVATOR_SWITCH"), 0.5));


      m_Modes["Test"];
      m_Modes["Test"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, 25, 0.01));
      m_Modes["Test"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -100, -180, 1, 25, 2));

//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_TURN, 0, -180, -0.4, 0, 0.8));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -180, -0.4, 0, 0.3));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 20, -180, 0.6, 0, 0.7));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 10, -180, 0.6, 0, 0.5));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_ARM_UP, 0, -180, -0.4, 0, 0.01));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_TURN, 0, -165, -0.4, 0, 0.8));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -60, -165, 0.4, CONSTANT("ELEVATOR_SCALE"), 0.8));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_TURN, 0, -200, -0.4, CONSTANT("ELEVATOR_SCALE"), 0.375));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -35, -200, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_AUTO_REV, 0, -200, 0.3, CONSTANT("ELEVATOR_SCALE"), 0.25));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -35, -200, 0.4, CONSTANT("ELEVATOR_SCALE"), 1));
//      m_Modes["Double Scale Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -35, -200, 0.4, 0, 0.5));








//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 25, -100, 0.4, 0, 1.5));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 40, -180, 0.4, 0, 1.5));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -100, -0.4, 0, 0.01));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 62, -180, 0.4, 0, 1.5));



//put this after the turn to -130
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_DOWN, 0, -130, -0.4, 0, 0.01));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE_INTAKE, 25, -130, 0.4, 0, 1.5));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN_INTAKE, 25, -170, 0.4, 0, 0.5));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_TURN_INTAKE, 25, -130, 0.4, 0, 0.5));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -10, -130, 0.4, 0, 2));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_ARM_UP, 0, -130, -0.4, 0, 0.01));
//    m_Modes["Double Scale Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, -25, -190, 0.4, 0, 2));





//    m_Modes["Gear Straight - Left"];
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 80, 0, 0.375, true, 2));
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 75, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 45, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 10, 45, 0.5, true, 0.5));
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, -125, 90, 0.5, true, 1.25));
//    m_Modes["Gear Straight - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, -250, 180, 0.5, true, 2));
//
//    m_Modes["Gear Straight - Right"];
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 80, 0, 0.375, true, 2));
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 75, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 45, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 10, -45, 0.5, true, 0.5));
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, -25, -90, 0.5, true, 1.25));
//    m_Modes["Gear Straight - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, -250, -180, 0.5, true, 2));
//
//    m_Modes["Gear N Shoot - Right"];
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 57, 0, 0.4, true, 1.4));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 180, -60, 0.375, true, 2));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_SPOOL_SHOOTER_HOPPER, 180, -60, 0, false, 0.025));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, -60, 0.375, true, 1));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, -60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, -60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 140, -60, 0.375, false, 0.75));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, -98, 0.55, false, 1));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, -98, 0.375, true, 0.5));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 50, -90, 0.5, true, 0.5));
//    m_Modes["Gear N Shoot - Right"].push_back(RobotCommand(CMD_SHOOT, 50, -90, 0.5, true, 15));
//
//    m_Modes["Gear N Shoot - Left"];
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 65, 0, 0.4, true, 1.4));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 180, 60, 0.375, true, 2));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_SPOOL_SHOOTER_HOPPER, 180, 60, 0, false, 0.025));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, 60, 0.375, true, 1));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, 60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, 60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 140, 60, 0.375, false, 0.75));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, 98, 0.55, false, 1));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, 98, 0.375, true, 0.5));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 50, 90, 0.5, true, 0.5));
//    m_Modes["Gear N Shoot - Left"].push_back(RobotCommand(CMD_SHOOT, 50, 90, 0.5, true, 15));
//
//
//    m_Modes["Gear N Shoot - Pop Right"];
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 55, 0, 0.4, true, 1.25));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 180, -60, 0.375, true, 2));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, -60, 0.375, true, 1));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, -60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, -60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 140, -60, 0.375, false, 0.75));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 65, -128, 0.55, false, 1));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, -128, 0.375, true, 1));
//    m_Modes["Gear N Shoot - Pop Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 50, -90, 0.5, true, 0.5));
//
//    m_Modes["Gear N Shoot - Pop Left"];
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 55, 0, 0.4, true, 1.25));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 180, 60, 0.375, true, 2));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, 60, 0.375, true, 1));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, 60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 180, 60, 0.375, false, 0.25));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 140, 60, 0.375, false, 0.75));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 65, 128, 0.55, false, 1));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 50, 128, 0.375, true, 1));
//    m_Modes["Gear N Shoot - Pop Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 50, 90, 0.5, true, 0.5));
//
//    m_Modes["Gear Straight - Shoot Left"];
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_RIGHT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 80, 0, 0.375, true, 2));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 80, 0, 0.375, false, 0.5));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 70, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 70, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 55, 45, 0.5, true, 0.5));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_SPOOL_SHOOTER_MIDDLE, 55, 45, 0, false, 0.025));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 55, 45, 0.5, true, 2));
//    m_Modes["Gear Straight - Shoot Left"].push_back(RobotCommand(CMD_SHOOT, 55, 45, 0.5, true, 15));
//
//    m_Modes["Gear Straight - Shoot Right"];
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_LEFT_ENCODER, 0, 0, 0, true, 0.01));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 80, 0, 0.375, true, 2));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 80, 0, 0.375, false, 0.5));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 70, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 70, 0, 0.375, false, 1));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_DRIVE_DISTANCE, 55, -45, 0.5, true, 0.5));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_SPOOL_SHOOTER_MIDDLE, 55, -45, 0, false, 0.025));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_HOLD_DISTANCE, 55, -45, 0.5, true, 2));
//    m_Modes["Gear Straight - Shoot Right"].push_back(RobotCommand(CMD_SHOOT, 55, -45, 0.5, true, 15));

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
