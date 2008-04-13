SET( EXTENSION_NAME "Extensions_StateManager")

ADD_LIBRARY( ${EXTENSION_NAME}
  Core/StateManager.cpp
)

TARGET_LINK_LIBRARIES( ${EXTENSION_NAME}
  OpenEngine_Core
)
