//==================================================
// Copyright (C) 2018 Team 1538 / The Holy Cows
//==================================================

#ifndef __COW_GAME_DATA_H__
#define __COW_GAME_DATA_H__

#include <WPILib.h>

class CowGameData
{    

public:
    typedef enum
    {
        SWITCH_LEFT,
        SWITCH_RIGHT,
        SWITCH_INVALID,
    } CowSwitchOwnership;

    typedef enum
    {
        SCALE_LEFT,
        SCALE_RIGHT,
        SCALE_INVALID,
    } CowScaleOwnership;

    typedef enum
    {
        AUTO_LEFT,
        AUTO_CENTER,
        AUTO_RIGHT,
    } CowAutoPosition;

private:
    CowSwitchOwnership m_Switch;
    CowScaleOwnership m_Scale;

    static CowGameData *m_SingletonInstance;
    CowGameData();

public:
    static CowGameData *GetInstance();
    void DetermineOwnership();
    CowScaleOwnership GetScaleOwnership();
    CowSwitchOwnership GetSwitchOwnership();
};

#endif /* __COW_GAME_DATA_H__ */
