#include <iostream>
#include "camera.h"

//=============================================================================

camera::camera()
{
    initCamera();
    
    _motionSensivity = 1;
    _scrollSensivity = 0.1;
}

//=============================================================================

void camera::initCamera()
{
    _hold = false;
    _rotX = 0;
    _rotY = 0;
    _xStart = 0;
    _yStart = 0;
    _distCam = 5;
}

//=============================================================================

void camera::setMotionSensivity(double sensivity)
{
    _motionSensivity = sensivity;
}

//=============================================================================

void camera::setScrollSensivity(double sensivity)
{
    _scrollSensivity = sensivity;
}

//=============================================================================

void camera::OnMouseMotion(int x, int y)
{
    if (_hold)
    {
        _rotX += (x-_xStart)*_motionSensivity; 
        _rotY += (y-_yStart)*_motionSensivity;

        _xStart = x;
        _yStart = y;
    }
}

//=============================================================================

void camera::OnMouseButton(int bouton, int etat, int x, int y)
{
    _xStart = x;
    _yStart = y;
    
    if (bouton == GLUT_LEFT_BUTTON)
        _hold = etat == GLUT_UP ? false : true;
}

//=============================================================================

void camera::OnKeyboard(unsigned char key, int x, int y)
{
    if (key == 'r')
        initCamera();
    else if (key == 'z')
        _distCam = _distCam <= 0.1 ? 0.1 : _distCam-_scrollSensivity;

    else if (key == 'd')
        _distCam += _scrollSensivity;
}

//=============================================================================

void camera::setCameraPosition()
{
    glTranslatef(0,0,-_distCam);
    glRotatef(_rotY,1,0,0);
    glRotatef(_rotX,0,0,1);
}



