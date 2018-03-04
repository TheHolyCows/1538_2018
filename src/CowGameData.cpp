#include "CowGameData.h"
#include <string>

CowGameData *CowGameData::m_SingletonInstance = NULL;

CowGameData *CowGameData::GetInstance()
{
    if(m_SingletonInstance == NULL)
    {
        m_SingletonInstance = new CowGameData();
    }
    return m_SingletonInstance;
}

CowGameData::CowGameData()
    :
    m_Switch(SWITCH_INVALID),
    m_Scale(SCALE_INVALID)
{
}

CowGameData::CowScaleOwnership CowGameData::GetScaleOwnership()
{
    return m_SingletonInstance->m_Scale;
}

CowGameData::CowSwitchOwnership CowGameData::GetSwitchOwnership()
{
    return m_SingletonInstance->m_Switch;
}

void CowGameData::DetermineOwnership()
{
    std::string gameData;
    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

    if(gameData.length() >= 2)
    {
        if(gameData[0] == 'L')
        {
            m_Switch = SWITCH_LEFT;
        }
        else
        {
            m_Switch = SWITCH_RIGHT;
        }

        if(gameData[1] == 'L')
        {
            m_Scale = SCALE_LEFT;
        }
        else
        {
            m_Scale = SCALE_RIGHT;
        }
    }
}
