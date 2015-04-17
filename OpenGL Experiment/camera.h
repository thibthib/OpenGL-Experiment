#ifndef ProjetOpenGL_camera_h
#define ProjetOpenGL_camera_h

#include <GLUT/glut.h>

class camera
{
private:
    float _rotY, _rotX;
    float _distCam;
    float _Xg, _Yg, _Zg;

    float _motionSensivity;
    float _scrollSensivity;
    
    bool _hold;
    
    float _xStart;
    float _yStart;

    
public:
    camera();
    
    void initCamera();
    
    void setMotionSensivity(double sensivity);
    void setScrollSensivity(double sensivity);
    
    void OnMouseButton(int bouton, int etat, int x, int y);
    void OnMouseMotion(int x, int y);
    void OnKeyboard(unsigned char key, int x, int y);
    
    void setCameraPosition();
    
};

#endif
