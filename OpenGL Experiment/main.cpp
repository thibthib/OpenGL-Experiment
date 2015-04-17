#include <iostream>
#include <GLUT/glut.h>
#include "scene.h"
#include <math.h>
#include "camera.h"

scene s;
camera cam;

bool fog = false, tourne = true, ligne = false;
int selectedScene = 3;
int selectedLum = 1;

void display();
void reshape(int width, int height);
void idle();
void keyboard(unsigned char key, int x, int y);
void mouse(int bouton, int etat, int x, int y);
void motion(int x, int y);
void keyboardSpecial(int touche, int x, int y);
void initLight();
void initFog();
void initTransLum();

//=============================================================================

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if (selectedLum==1)
        s.setPositionLumiere();
    
    cam.setCameraPosition();
    
    if (selectedLum==2)
        s.setPositionLumiere();
    
    glPushMatrix();
    
    if (selectedScene == 1) {
        s.generateDeuxSpheres();
        s.generateDeuxCubes();
    }
    else if (selectedScene == 2) {
        if (ligne) {
            s.generateSystemeLigne();
        }
        else  {
            s.generateSysteme();
        }
    }
    else if (selectedScene == 3) {
        if (ligne) {
            s.generateTerreSatLigne();
        }
        else  {
            s.generateTerreSat();
        }
    }
    
    glPopMatrix();
        
    glutSwapBuffers();
    
    if (selectedScene == 2 && tourne)
    {
        s.rotationSysteme();
        glutPostRedisplay();
    }
    if (selectedScene == 3 && tourne)
    {
        s.rotationSatelite();
        glutPostRedisplay();
    }
}

//=============================================================================

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)width/height, 0.1, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

//=============================================================================

void idle()
{
    //glutPostRedisplay();
}

//=============================================================================

void keyboard(unsigned char key, int x, int y)
{
    if ('q' == key || 'Q' == key || 27 == key)
        exit(0);
    else if (key == 'f' || key == 'F')
    {
        if (fog)
        {
            glDisable(GL_FOG);
            fog = false;
        }
        else 
        {
            glEnable(GL_FOG);
            fog = true;
        }  
    }
    else if (key == 't' || key == 'T')
        tourne = tourne == true ? false : true;
    else if (key == 'l' || key == 'L')
        ligne = ligne == true ? false : true;
    else if (key == '&' || key == '1')
        selectedScene = 1;
    else if (key == 195 || key == '2')
        selectedScene = 2;
    else if (key == '"' || key == '3')
        selectedScene = 3;
    else if (key == 'i' || key == 'I')
    {   
        s.initTransLum();
        selectedLum = 1;
    }
    else if (key == 'm' || key == 'M')
    {   
        s.initTransLum();
        selectedLum = 2;
    }
    
    cam.OnKeyboard(key, x, y);
    glutPostRedisplay();

}

//=============================================================================

void mouse(int bouton, int etat, int x, int y)
{
    cam.OnMouseButton(bouton, etat, x, y);
    glutPostRedisplay();
}

//=============================================================================

void motion(int x, int y)
{
    cam.OnMouseMotion(x, y);
    glutPostRedisplay();
}

//=============================================================================

void keyboardSpecial(int touche, int x, int y)
{
    s.OnKeyboardSpecial(touche, x, y);
    glutPostRedisplay();
}

//=============================================================================

void initFog()
{
    GLfloat density = 0.2;
    GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
    
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, density);
    glFogf(GL_FOG_START, 3.0f);
    glFogf(GL_FOG_END, 6.0f); 
    glHint(GL_FOG_HINT, GL_NICEST);
}

//=============================================================================

void initLight()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

//=============================================================================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    
    glutCreateWindow("Projet OpenGL");
    
    initLight();
    initFog();
    s.initScene();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutSpecialFunc(keyboardSpecial);
    
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_CULL_FACE);
    
    glutMainLoop();
    return 0;
}

