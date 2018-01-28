//==================================================
// Copyright (C) 2018 Team 1538 / The Holy Cows
//==================================================

#ifndef __AUTO_MODES_H__
#define __AUTO_MODES_H__

#include <map>
#include <deque>
#include "../Controllers/AutoModeController.h"

class AutoModes
{
private:
    static AutoModes *m_SingletonInstance;
    std::map<const char *, std::deque<RobotCommand> > m_Modes;
    std::map<const char *, std::deque<RobotCommand> >::iterator m_Iterator;
    
    AutoModes();
public:
    static AutoModes *GetInstance();
    std::deque<RobotCommand> GetCommandList();
    const char *GetName();
    void NextMode();
};

#endif /* __AUTO_MODES_H__ */
