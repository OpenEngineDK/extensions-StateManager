#ifndef _STATE_INTERFACE_H_
#define _STATE_INTERFACE_H_

#include <Core/EngineEvents.h>

namespace OpenEngine {
namespace Core {

class IState {
public:
    IState() {}
    virtual ~IState() {}

    /**
     * Initialize state.
     */
    virtual void Initialize() = 0;

    /**
     * Process module.
     */
    virtual void Process(ProcessEventArg arg) = 0;
    
    /**
     * Deinitialize module.
     */
    virtual void Deinitialize() = 0;

};
} // NS Core
} // NS OpenEngine

#endif // _STATE_INTERFACE_H_
