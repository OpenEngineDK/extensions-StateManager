// Program name and description
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include <Core/IListener.h>
#include <Core/IModule.h>
#include <Core/IState.h>
#include <Core/EngineEvents.h>
#include <map>
#include <string>

namespace OpenEngine{
namespace Core{

using namespace std;

class StateManager : public IModule {
public:
    int numberOfStates;
    IState* curState;
    map<string, IState*> stateList;

public:
    StateManager();
    ~StateManager();

    void AddState(string name, IState* gs);
    void AddStateAsInitial(string name, IState* gs);
    void ChangeState(string name);
    
    void Handle(InitializeEventArg arg);
    void Handle(ProcessEventArg arg);
    void Handle(DeinitializeEventArg arg);
};

} // NS Core
} // NS OpenEngine

#endif
