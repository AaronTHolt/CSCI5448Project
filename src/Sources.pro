# The files that qmake should build

# Template
HEADERS +=
SOURCES +=

SOURCES += main.cpp
HEADERS += mainwindow.h
SOURCES += mainwindow.cpp
HEADERS += menu/gamestate.h
SOURCES += menu/gamestate.cpp
HEADERS += menu/welcomestate.h
SOURCES += menu/welcomestate.cpp
HEADERS += gamestatecontext.h
SOURCES += gamestatecontext.cpp
HEADERS += menu/profileselectstate.h
SOURCES += menu/profileselectstate.cpp
HEADERS += menu/optionsstate.h
SOURCES += menu/optionsstate.cpp
HEADERS += menu/levelselectstate.h
SOURCES += menu/levelselectstate.cpp
HEADERS += menu/statsstate.h
SOURCES += menu/statsstate.cpp
HEADERS += menu/playablestate.h
SOURCES += menu/playablestate.cpp

# Utilities
HEADERS += playableObjects/cubeSides.h
SOURCES += playableObjects/cubeSides.cpp
HEADERS += playableObjects/physicsObjects/invalidOperationException.h
SOURCES += playableObjects/physicsObjects/invalidOperationException.cpp

# Shapes
HEADERS += playableObjects/gameObjects/shapes/cube.h
SOURCES += playableObjects/gameObjects/shapes/cube.cpp
HEADERS += playableObjects/gameObjects/shapes/GLDebugDrawer.h
SOURCES += playableObjects/gameObjects/shapes/GLDebugDrawer.cpp

# Game Objects
HEADERS += playableObjects/gameObjects/gameObject.h
SOURCES += playableObjects/gameObjects/gameObject.cpp
HEADERS += playableObjects/gameObjects/world.h
SOURCES += playableObjects/gameObjects/world.cpp
HEADERS += playableObjects/gameObjects/boundary.h
SOURCES += playableObjects/gameObjects/boundary.cpp

# Physics Objects
HEADERS += playableObjects/physicsObjects/physicsObject.h
SOURCES += playableObjects/physicsObjects/physicsObject.cpp
HEADERS += playableObjects/physicsObjects/physicsWorld.h
SOURCES += playableObjects/physicsObjects/physicsWorld.cpp
HEADERS += playableObjects/physicsObjects/boundaryPhysicsObject.h
SOURCES += playableObjects/physicsObjects/boundaryPhysicsObject.cpp
HEADERS += playableObjects/physicsObjects/shipPhysicsObject.h
SOURCES += playableObjects/physicsObjects/shipPhysicsObject.cpp
