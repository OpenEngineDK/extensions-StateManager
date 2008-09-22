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
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Core {

using namespace OpenEngine::Logging;

StateManager::StateManager() 
  : numberOfStates(0) {
    stateList = map<string, IState*>();
}
    
StateManager::~StateManager() {
}

void StateManager::Handle(InitializeEventArg arg) {
    curState->Initialize();
}
 
void StateManager::Handle(ProcessEventArg arg) {
    curState->Process(arg);;
}

void StateManager::Handle(DeinitializeEventArg arg) {
    //@todo: what to do here?
}

void StateManager::AddState(string name, IState* gs) {
    stateList[name] = gs;
}

void StateManager::AddStateAsInitial(string name, IState* gs) {
    curState = gs;
    AddState(name,gs);
}

void StateManager::ChangeState(string name) {
    curState->Deinitialize();

    map<string, IState*>::iterator iter = stateList.find(name);
    if (iter != stateList.end()) {
        curState = iter->second;
        curState->Initialize();
        logger.info << "State changed to: " << iter->first << logger.end;
    }
    else
        throw Exception("State does not exists: " + name);
}

} // NS Core
} // NS OpenEngine
