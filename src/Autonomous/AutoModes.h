//==================================================
// Copyright (C) 2018 Team 1538 / The Holy Cows
//==================================================

#ifndef __AUTO_MODES_H__
#define __AUTO_MODES_H__

#include <map>
#include <deque>
#include "../Controllers/AutoModeController.h"
#include "../CowGameData.h"

class AutoModes
{
private:
    typedef struct
    {
        std::deque<RobotCommand> commands;
        CowGameData::CowScaleOwnership ourScale;
        CowGameData::CowSwitchOwnership ourSwitch;
        bool isDefaultMode;
    } AutoModePermutation;

    static AutoModes *m_SingletonInstance;
    //std::map<const char *, std::deque<RobotCommand> > m_Modes;
    //std::map<const char *, std::deque<RobotCommand> >::iterator m_Iterator;
    std::map<std::string, std::vector<AutoModePermutation> > m_Modes;
    std::map<std::string, std::vector<AutoModePermutation> >::iterator m_ModesIterator;
    
    AutoModes();
public:
    static AutoModes *GetInstance();
//    std::deque<RobotCommand> GetCommandList();
    std::deque<RobotCommand> GetCommandList(CowGameData::CowScaleOwnership,
                                            CowGameData::CowSwitchOwnership);
    std::string GetModeName();
    void NextMode();
};

#endif /* __AUTO_MODES_H__ */
