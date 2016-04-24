#ifndef _PLAYABLESTATE_H
#define _PLAYABLESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"
#include "world.h"
#include "playerShipControls.h"
#include "vector3.h"

#include <QtOpenGL>
#include <GL/glu.h>
#include <memory>

class PlayableState : public GameState
{
public:
    PlayableState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void view();
    void projection();

private:
    void calculateCameraPosition();
    double degreeToRadian(double degree);
    double radianToDegree(double radian);

    void loadTextures();

    std::weak_ptr<World> theWorld;
    PlayerShipControls playerControls;

    Vector3 shipPosition;
    Vector3 shipForward;
    Vector3 shipUp;

    double cameraDistance;
    double cameraHeight;

    Vector3 cameraPosition;

};

#endif // _PLAYABLESTATE_H
