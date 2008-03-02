// Program name and description
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Core/StateManager.h>
#include <Core/Exceptions.h>

namespace OpenEngine {
namespace Core {

StateManager::StateManager(string name, IModule* initState) : numberOfStates(0){
    stateList = map<string, IModule*>();
    stateList[name] = initState;
    curState = initState;
}
    
StateManager::~StateManager(){
}

void StateManager::Initialize(){
    curState->Initialize();
}
 
void StateManager::Process(const float deltaTime, const float percent) {
    curState->Process(deltaTime,percent);
}

void StateManager::Deinitialize() {
}

bool StateManager::IsTypeOf(const std::type_info& inf){
    return (typeid(StateManager) == inf);
}

void StateManager::AddState(string name, IModule* gs){
    stateList[name] = gs;
}

void StateManager::ChangeState(string name){
    map<string, IModule*>::iterator iter = stateList.find(name);
    if( iter != stateList.end() ) {
        curState->Deinitialize();
        throw Exception("State changed to: " + iter->first);
        curState = iter->second;
        curState->Initialize();
    }
    else
        throw Exception("State does not exists: " + name);
}

} // NS Core
} // NS OpenEngine
