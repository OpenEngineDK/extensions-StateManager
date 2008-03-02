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

#include <Core/IModule.h>
#include <map>
#include <string>

namespace OpenEngine{
namespace Core{

using namespace std;

class StateManager : public IModule {
public:
    int numberOfStates;
    IModule* curState;
    map<string, IModule*> stateList;

public:
    StateManager(string name, IModule* initState);
    ~StateManager();

    void AddState(string name, IModule* gs);
    void ChangeState(string name);
    
    void Initialize();
    void Process(const float deltaTime, const float percent);
    void Deinitialize();
    bool IsTypeOf(const std::type_info& inf);


};

} // NS Core
} // NS OpenEngine

#endif
