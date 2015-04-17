#include <iostream>
#include "scene.h"

//=============================================================================

scene::scene()
{
}

//=============================================================================

void scene::initScene()
{
    cubeBleu_id = glGenLists(1);
    cubeVert_id = glGenLists(1);
    deuxCubes_id = glGenLists(1);
    sphereBleu_id = glGenLists(1);
    sphereVert_id = glGenLists(1);
    deuxSpheres_id = glGenLists(1);
    donut_id = glGenLists(1);
    terre_id = glGenLists(1);
    lune_id = glGenLists(1);
    soleil_id = glGenLists(1);
    ligneRevolutionTerre_id = glGenLists(1);
    ligneRevolutionLune_id = glGenLists(1);
    satelite_id = glGenLists(1);
    gTerre_id = glGenLists(1);
    ligneSat_id = glGenLists(1);
    
    compileCubeBleu();
    compileCubeVert();
    compileDeuxCubes();
    compileSphereBleu();
    compileSphereVert();
    compileDeuxSpheres();
    compileDonut();
    compileTerre();
    compileLune();
    compileSoleil();
    compileLigneRevolutionTerre();
    compileLigneRevolutionLune();
    compileSatelite();
    compileGTerre();
    compileLigneSat();
    
    initTransLum();
}

//=============================================================================

void scene::createCube()
{
    glNormal3f(0.f, 0.f, 1.f);
    
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 0.f, 0.5f);
    glVertex3f(0.f,  0.5f, 0.5f);
    glVertex3f(-0.5f,  0.5f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.5f,  0.5f, 0.5f);
    glVertex3f(0.f,  0.5f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.f, -0.5f, 0.5f);
    glVertex3f(0.f,  0.f, 0.5f);
    glVertex3f(-0.5f,  0.f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f,  0.f, 0.5f);
    glVertex3f(0.f,  0.f, 0.5f);
    glEnd();
    
    glNormal3f(0.f, 0.f, -1.f);
    
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, -0.5);
    glVertex3f(-0.5f,  0.5f, -0.5);
    glVertex3f(0.f,  0.5f, -0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 0.f, -0.5f);
    glVertex3f(0.f,  0.5f, -0.5f);
    glVertex3f(0.5f,  0.5f, -0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f,  0.f, -0.5);
    glVertex3f(0.f,  0.f, -0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.f, -0.5f, -0.5f);
    glVertex3f(0.f,  0.f, -0.5f);
    glVertex3f(0.5f,  0.f, -0.5f);
    glEnd();
    
    glNormal3f(1.f, 0.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, 0.f);
    glVertex3f(0.5f,  0.5f, 0.f);
    glVertex3f(0.5f,  0.5f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.5f,  0.f, 0.f);
    glVertex3f(0.5f,  0.f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f,  0.f, -0.5f);
    glVertex3f(0.5f,  0.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.f, 0.f);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.f);
    glEnd();
    
    glNormal3f(-1.f, 0.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.f, 0.f);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(-0.5f,  0.5f, 0.5f);
    glVertex3f(-0.5f,  0.5f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f,  0.f, 0.5f);
    glVertex3f(-0.5f,  0.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glVertex3f(-0.5f,  0.f, 0.f);
    glVertex3f(-0.5f,  0.f, -0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, 0.f);
    glVertex3f(-0.5f, 0.5f, 0.);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
    
    glNormal3f(0.f, -1.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.f, -0.5f, -0.5f);
    glVertex3f(0.f, -0.5f, 0.f);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.f, -0.5f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glVertex3f(0.f, -0.5f, 0.f);
    glVertex3f(0.f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.f, -0.5f, 0.5f);
    glEnd();
    
    glNormal3f(0.f, 1.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.f);
    glVertex3f(0.f, 0.5f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.f, 0.5f, -0.5f);
    glVertex3f(0.f, 0.5f, 0.f);
    glVertex3f(0.5f, 0.5f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.5f, 0.f);
    glVertex3f(-0.5f, 0.5f, 0.f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.f, 0.5f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.5f, 0.f);
    glVertex3f(0.f, 0.5f, 0.f);
    glVertex3f(0.f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();
}

//=============================================================================

void scene::createPetitCube()
{
    glNormal3f(0.f, 0.f, 1.f);
    
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.f, 0.1f);
    glVertex3f(0.f, 0.f, 0.1f);
    glVertex3f(0.f,  0.1f, 0.1f);
    glVertex3f(-0.1f,  0.1f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.f, 0.1f);
    glVertex3f(0.1f, 0.f, 0.1f);
    glVertex3f(0.1f,  0.1f, 0.1f);
    glVertex3f(0.f,  0.1f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.1f, 0.1f);
    glVertex3f(0.f, -0.1f, 0.1f);
    glVertex3f(0.f,  0.f, 0.1f);
    glVertex3f(-0.1f,  0.f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.1f, 0.1f);
    glVertex3f(0.1f, -0.1f, 0.1f);
    glVertex3f(0.1f,  0.f, 0.1f);
    glVertex3f(0.f,  0.f, 0.1f);
    glEnd();
    
    glNormal3f(0.f, 0.f, -1.f);
    
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.f, -0.1f);
    glVertex3f(-0.1f, 0.f, -0.1);
    glVertex3f(-0.1f,  0.1f, -0.1);
    glVertex3f(0.f,  0.1f, -0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, 0.f, -0.1f);
    glVertex3f(0.f, 0.f, -0.1f);
    glVertex3f(0.f,  0.1f, -0.1f);
    glVertex3f(0.1f,  0.1f, -0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.1f, -0.1f);
    glVertex3f(-0.1f, -0.1f, -0.1f);
    glVertex3f(-0.1f,  0.f, -0.1);
    glVertex3f(0.f,  0.f, -0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, -0.1f, -0.1f);
    glVertex3f(0.f, -0.1f, -0.1f);
    glVertex3f(0.f,  0.f, -0.1f);
    glVertex3f(0.1f,  0.f, -0.1f);
    glEnd();
    
    glNormal3f(1.f, 0.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(0.1f, 0.f, 0.1f);
    glVertex3f(0.1f, 0.f, 0.f);
    glVertex3f(0.1f,  0.1f, 0.f);
    glVertex3f(0.1f,  0.1f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, -0.1f, 0.1f);
    glVertex3f(0.1f, -0.1f, 0.f);
    glVertex3f(0.1f,  0.f, 0.f);
    glVertex3f(0.1f,  0.f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, -0.1f, 0.f);
    glVertex3f(0.1f, -0.1f, -0.1f);
    glVertex3f(0.1f,  0.f, -0.1f);
    glVertex3f(0.1f,  0.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, 0.f, 0.f);
    glVertex3f(0.1f, 0.f, -0.1f);
    glVertex3f(0.1f, 0.1f, -0.1f);
    glVertex3f(0.1f, 0.1f, 0.f);
    glEnd();
    
    glNormal3f(-1.f, 0.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.f, 0.f);
    glVertex3f(-0.1f, 0.f, 0.1f);
    glVertex3f(-0.1f,  0.1f, 0.1f);
    glVertex3f(-0.1f,  0.1f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.1f, 0.f);
    glVertex3f(-0.1f, -0.1f, 0.1f);
    glVertex3f(-0.1f,  0.f, 0.1f);
    glVertex3f(-0.1f,  0.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.1f, -0.1f);
    glVertex3f(-0.1f, -0.1f, 0.f);
    glVertex3f(-0.1f,  0.f, 0.f);
    glVertex3f(-0.1f,  0.f, -0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.f, -0.1f);
    glVertex3f(-0.1f, 0.f, 0.f);
    glVertex3f(-0.1f, 0.1f, 0.);
    glVertex3f(-0.1f, 0.1f, -0.1f);
    glEnd();
    
    glNormal3f(0.f, -1.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.1f, -0.1f);
    glVertex3f(0.f, -0.1f, -0.1f);
    glVertex3f(0.f, -0.1f, 0.f);
    glVertex3f(-0.1f, -0.1f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.1f, -0.1f);
    glVertex3f(0.1f, -0.1f, -0.1f);
    glVertex3f(0.1f, -0.1f, 0.f);
    glVertex3f(0.f, -0.1f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.1f, 0.f);
    glVertex3f(0.f, -0.1f, 0.f);
    glVertex3f(0.f, -0.1f, 0.1f);
    glVertex3f(-0.1f, -0.1f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, -0.1f, 0.f);
    glVertex3f(0.1f, -0.1f, 0.f);
    glVertex3f(0.1f, -0.1f, 0.1f);
    glVertex3f(0.f, -0.1f, 0.1f);
    glEnd();
    
    glNormal3f(0.f, 1.f, 0.f);
    
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.1f, -0.1f);
    glVertex3f(-0.1f, 0.1f, -0.1f);
    glVertex3f(-0.1f, 0.1f, 0.f);
    glVertex3f(0.f, 0.1f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, 0.1f, -0.1f);
    glVertex3f(0.f, 0.1f, -0.1f);
    glVertex3f(0.f, 0.1f, 0.f);
    glVertex3f(0.1f, 0.1f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.1f, 0.f);
    glVertex3f(-0.1f, 0.1f, 0.f);
    glVertex3f(-0.1f, 0.1f, 0.1f);
    glVertex3f(0.f, 0.1f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.1f, 0.1f, 0.f);
    glVertex3f(0.f, 0.1f, 0.f);
    glVertex3f(0.f, 0.1f, 0.1f);
    glVertex3f(0.1f, 0.1f, 0.1f);
    glEnd();
}

//=============================================================================

void scene::rotationSysteme()
{
    revolutionTerre += 0.02;
    rotationTerre += 7.5;
    revolutionLune -= 7.2;
}

//=============================================================================

void scene::rotationSatelite()
{
    rotSat1 += 0.1;
    rotSat2 -= 0.1;
    rotSat3 -= 0.1;
}

//=============================================================================

void scene::setPositionLumiere()
{
    glPushMatrix();
    
    glTranslatef(xLum, yLum, zLum);
    int LightPos0[4] = {0,0,0,1};
    glLightiv(GL_LIGHT0,GL_POSITION,LightPos0);
    
    glPopMatrix();
}

//=============================================================================

void scene::initTransLum()
{
    xLum = 0.f;
    yLum = 0.f;
    zLum = 0.f;
}

//=============================================================================

void scene::OnKeyboardSpecial(int touche, int x, int y)
{
    if (touche == GLUT_KEY_UP) yLum += .5f;
    else if (touche == GLUT_KEY_DOWN) yLum -= .5f;
    else if (touche == GLUT_KEY_RIGHT) xLum += .5f;
    else if (touche == GLUT_KEY_LEFT) xLum -= .5f;
}

//=============================================================================

void scene::compileCubeBleu()
{
    glNewList(cubeBleu_id, GL_COMPILE);
    
    GLfloat cyan[] = {0.2039f, 0.6313f, .9f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    createCube();
    
    glEndList();
}

//=============================================================================

void scene::compileCubeVert()
{
    glNewList(cubeVert_id, GL_COMPILE);
    
    GLfloat vert[] = {.5098f, 1.f, 0.f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, vert);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    createCube();
    
    glEndList();
}

//=============================================================================

void scene::compileDeuxCubes()
{
    glNewList(deuxCubes_id, GL_COMPILE);
    
        glTranslatef(1.f, 0.f, 0.f);
        generateCubeBleu();
        glTranslatef(-2.f, 0.f, 0.f);
        generateCubeVert();
        glTranslatef(1.f, 0.f, 0.f);
    
    glEndList();
}

//=============================================================================

void scene::compileSphereBleu()
{
    glNewList(sphereBleu_id, GL_COMPILE);
    
    GLfloat cyan[] = {0.2039f, 0.6313f, .9f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glutSolidSphere(0.5,50,50);
    
    glEndList();
}

//=============================================================================

void scene::compileSphereVert()
{
    glNewList(sphereVert_id, GL_COMPILE);
    
    GLfloat vert[] = {.5098f, 1.f, 0.f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, vert);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glutSolidSphere(0.5,50,50);
    
    glEndList();
}

//=============================================================================

void scene::compileDeuxSpheres()
{
    glNewList(deuxSpheres_id, GL_COMPILE);
    
        glTranslatef(0.f, 1.f, 0.f);
        generateSphereBleu();
        glTranslatef(0.f, -2.f, 0.f);
        generateSphereVert();
        glTranslatef(0.f, 1.f, 0.f);
    
    glEndList();
}

//=============================================================================

void scene::compileDonut()
{
    glNewList(donut_id, GL_COMPILE);
    
        GLfloat jaune[] = {1.f, 0.7843f, 0.3725f, 1.f};
        GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, jaune);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
        GLfloat shininess[] = {50};
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        glutSolidTorus(0.1, 0.3, 50, 50);
    
    glEndList();
}

//=============================================================================

void scene::compileTerre()
{
    glNewList(terre_id, GL_COMPILE);
    
    GLfloat cyan[] = {0.2039f, 0.6313f, .9f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glutSolidSphere(0.3,50,50);
    
    glEndList();
}

//=============================================================================

void scene::compileLune()
{
    glNewList(lune_id, GL_COMPILE);
    
    GLfloat gris[] = {0.4313f, 0.4313f, .4313f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, gris);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glutSolidSphere(0.1,50,50);
    
    glEndList();
}

//=============================================================================

void scene::compileSoleil()
{
    glNewList(soleil_id, GL_COMPILE);
    
    GLfloat jaune[] = {1.f, 0.7843f, .05f, 1.f};
    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, jaune);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glutSolidSphere(0.6,50,50);
    
    glEndList();
}

//=============================================================================

void scene::compileLigneRevolutionTerre()
{
    glNewList(ligneRevolutionTerre_id, GL_COMPILE);
    
    GLfloat cyan[] = {0.2039f, 0.6313f, .9f, .1f};
    GLfloat white[] = {0.f, 0.f, 0.f, 1.f};
    GLfloat shininess[] = {0};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(0.003, 1.5, 50, 50);
    glRotatef(90, 1, 0, 0);
    
    glEndList();
}

//=============================================================================

void scene::compileLigneRevolutionLune()
{
    glNewList(ligneRevolutionLune_id, GL_COMPILE);
    
    GLfloat gris[] = {0.4313f, 0.4313f, .4313f, 1.f};
    GLfloat white[] = {0.f, 0.f, 0.f, 1.f};
    GLfloat shininess[] = {0};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gris);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(0.003, 0.45, 50, 50);
    glRotatef(90, 1, 0, 0);
    
    glEndList();
}

//=============================================================================

void scene::compileSatelite()
{
    glNewList(satelite_id, GL_COMPILE);
    
    GLfloat dore[] = {1.f, 0.7843f, 0.f, 1.f};
    GLfloat bleu[] = {0.1960f, 0.3921f, 0.5490f, 1.f};
    GLfloat gris[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat white[] = {1.f, 1.f, 1.f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dore);
    glMaterialfv(GL_FRONT, GL_SPECULAR, gris);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    createPetitCube();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    
    glNormal3f(0.f, 0.f, -1.f);
    
    glBegin(GL_TRIANGLES);
    glVertex3f(0.1f, 0.f, 0.f);
    glVertex3f(0.15f, 0.1f, 0.f);
    glVertex3f(0.15f,  -0.1f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.1f, 0.f, 0.f);
    glVertex3f(-0.15f,  -0.1f, 0.f);
    glVertex3f(-0.15f, 0.1f, 0.f);
    glEnd();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bleu);
    
    glBegin(GL_QUADS);
    glVertex3f(0.36f, 0.11f, 0.f);
    glVertex3f(0.16f, 0.11f, 0.f);
    glVertex3f(0.16f,  0.21f, 0.f);
    glVertex3f(0.36f,  0.21f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.36f, 0.005f, 0.f);
    glVertex3f(0.16f, 0.005f, 0.f);
    glVertex3f(0.16f,  0.10f, 0.f);
    glVertex3f(0.36f,  0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.16f, -0.005f, 0.f);
    glVertex3f(0.36f, -0.005f, 0.f);
    glVertex3f(0.36f,  -0.10f, 0.f);
    glVertex3f(0.16f,  -0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.16f, -0.11f, 0.f);
    glVertex3f(0.36f, -0.11f, 0.f);
    glVertex3f(0.36f, -0.21f, 0.f);
    glVertex3f(0.16f, -0.21f, 0.f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-0.16f, 0.11f, 0.f);
    glVertex3f(-0.36f, 0.11f, 0.f);
    glVertex3f(-0.36f,  0.21f, 0.f);
    glVertex3f(-0.16f,  0.21f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.16f, 0.005f, 0.f);
    glVertex3f(-0.36f, 0.005f, 0.f);
    glVertex3f(-0.36f,  0.10f, 0.f);
    glVertex3f(-0.16f,  0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.36f, -0.005f, 0.f);
    glVertex3f(-0.16f, -0.005f, 0.f);
    glVertex3f(-0.16f,  -0.10f, 0.f);
    glVertex3f(-0.36f,  -0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.36f, -0.11f, 0.f);
    glVertex3f(-0.16f, -0.11f, 0.f);
    glVertex3f(-0.16f, -0.21f, 0.f);
    glVertex3f(-0.36f, -0.21f, 0.f);
    glEnd();
    
    glNormal3f(0.f, 0.f, 1.f);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
    
    glBegin(GL_TRIANGLES);
    glVertex3f(0.1f, 0.f, 0.f);
    glVertex3f(0.15f,  -0.1f, 0.f);
    glVertex3f(0.15f, 0.1f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.1f, 0.f, 0.f);
    glVertex3f(-0.15f, 0.1f, 0.f);
    glVertex3f(-0.15f,  -0.1f, 0.f);
    glEnd();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bleu);
    
    glBegin(GL_QUADS);
    glVertex3f(0.16f, 0.11f, 0.f);
    glVertex3f(0.36f, 0.11f, 0.f);
    glVertex3f(0.36f,  0.21f, 0.f);
    glVertex3f(0.16f,  0.21f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.16f, 0.005f, 0.f);
    glVertex3f(0.36f, 0.005f, 0.f);
    glVertex3f(0.36f,  0.10f, 0.f);
    glVertex3f(0.16f,  0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.36f, -0.005f, 0.f);
    glVertex3f(0.16f, -0.005f, 0.f);
    glVertex3f(0.16f,  -0.10f, 0.f);
    glVertex3f(0.36f,  -0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.36f, -0.11f, 0.f);
    glVertex3f(0.16f, -0.11f, 0.f);
    glVertex3f(0.16f, -0.21f, 0.f);
    glVertex3f(0.36f, -0.21f, 0.f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-0.36f, 0.11f, 0.f);
    glVertex3f(-0.16f, 0.11f, 0.f);
    glVertex3f(-0.16f,  0.21f, 0.f);
    glVertex3f(-0.36f,  0.21f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.36f, 0.005f, 0.f);
    glVertex3f(-0.16f, 0.005f, 0.f);
    glVertex3f(-0.16f,  0.10f, 0.f);
    glVertex3f(-0.36f,  0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.16f, -0.005f, 0.f);
    glVertex3f(-0.36f, -0.005f, 0.f);
    glVertex3f(-0.36f,  -0.10f, 0.f);
    glVertex3f(-0.16f,  -0.10f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.16f, -0.11f, 0.f);
    glVertex3f(-0.36f, -0.11f, 0.f);
    glVertex3f(-0.36f, -0.21f, 0.f);
    glVertex3f(-0.16f, -0.21f, 0.f);
    glEnd();
    

    
    glEndList();
}

//=============================================================================

void scene::compileGTerre()
{
    glNewList(gTerre_id, GL_COMPILE);
    
    GLfloat bleu[] = {0.f, 0.3921f, 1.f, 1.f};
    GLfloat gris[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bleu);
    glMaterialfv(GL_FRONT, GL_SPECULAR, gris);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glutSolidSphere(1,50,50);
    
    glEndList();
}

//=============================================================================

void scene::compileLigneSat()
{
    glNewList(ligneSat_id, GL_COMPILE);
    
    GLfloat bleu[] = {0.1960f, 0.3921f, 0.5490f, 1.f};
    GLfloat gris[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat shininess[] = {50};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, bleu);
    glMaterialfv(GL_FRONT, GL_SPECULAR, gris);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(0.003, 1.5, 50, 50);
    glRotatef(90, 1, 0, 0);
    
    glEndList();
}

//=============================================================================

void scene::generateCubeBleu()
{
    glCallList(cubeBleu_id);
}

//=============================================================================

void scene::generateCubeVert()
{
    glCallList(cubeVert_id);
}

//=============================================================================

void scene::generateDeuxCubes()
{
    glCallList(deuxCubes_id);
}

//=============================================================================

void scene::generateSphereBleu()
{
    glCallList(sphereBleu_id);
}

//=============================================================================

void scene::generateSphereVert()
{
    glCallList(sphereVert_id);
}

//=============================================================================

void scene::generateDeuxSpheres()
{
    glCallList(deuxSpheres_id);
}

//=============================================================================

void scene::generateDonut()
{
    glCallList(donut_id);
}

//=============================================================================

void scene::generateTerre()
{
    glCallList(terre_id);
}

//=============================================================================

void scene::generateLune()
{
    glCallList(lune_id);
}

//=============================================================================

void scene::generateSoleil()
{
    glCallList(soleil_id);
}

//=============================================================================

void scene::generateLigneRevolutionTerre()
{
    glCallList(ligneRevolutionTerre_id);
}

//=============================================================================

void scene::generateLigneRevolutionLune()
{
    glCallList(ligneRevolutionLune_id);
}

//=============================================================================

void scene::generateSysteme()
{
    generateSoleil();
    
    glRotatef(revolutionTerre, 0, 1, 0);
    glTranslatef(1.5f, 0.f, 0.f);
    glRotatef(rotationTerre, 0, 1, 0);
    
    generateTerre();
    
    glRotatef(revolutionLune, 0, 1, 0);
    glTranslatef(-0.45f, 0.f, 0.f);
    
    generateLune();
}

//=============================================================================

void scene::generateSystemeLigne()
{
    generateSoleil();
    generateLigneRevolutionTerre();
    
    glRotatef(revolutionTerre, 0, 1, 0);
    glTranslatef(1.5f, 0.f, 0.f);
    glRotatef(rotationTerre, 0, 1, 0);
    
    generateTerre();
    generateLigneRevolutionLune();
    
    glRotatef(revolutionLune, 0, 1, 0);
    glTranslatef(-0.45f, 0.f, 0.f);
    
    generateLune();
}

//=============================================================================

void scene::generateSatelite()
{
    glCallList(satelite_id);
}

//=============================================================================

void scene::generateGTerre()
{
    glCallList(gTerre_id);
}

//=============================================================================

void scene::generateTerreSat()
{
    generateGTerre();
    
    glPushMatrix();
    
    glRotatef(45, 0, 0, 1);
    glRotatef(rotSat1, 0, 1, 0);
    glTranslatef(1.5f, 0.f, 0.f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    
    generateSatelite();
    
    glPopMatrix();
    
    glPushMatrix();
    
    glRotatef(-45, 0, 0, 1);
    glRotatef(rotSat2, 0, 1, 0);
    glTranslatef(1.5f, 0.f, 0.f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    
    generateSatelite();
    
    glPopMatrix();
    
    glPushMatrix();
    
    glRotatef(rotSat3, 0, 1, 0);
    glTranslatef(0.f, 0.f, 1.5f);
    glRotatef(90, 0, 0, 1);
    
    generateSatelite();
    
    glPopMatrix();
}

//=============================================================================

void scene::generateLigneSat()
{
    glCallList(ligneSat_id);
}

//=============================================================================

void scene::generateTerreSatLigne()
{
    generateGTerre();
    
    glPushMatrix();
    
    glRotatef(45, 0, 0, 1);
    generateLigneSat();
    
    glRotatef(rotSat1, 0, 1, 0);
    glTranslatef(1.5f, 0.f, 0.f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    
    generateSatelite();
    
    glPopMatrix();
    
    glPushMatrix();
    
    glRotatef(-45, 0, 0, 1);
    generateLigneSat();
    
    glRotatef(rotSat2, 0, 1, 0);
    glTranslatef(1.5f, 0.f, 0.f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    
    generateSatelite();
    
    glPopMatrix();
    
    glPushMatrix();
    
    generateLigneSat();
    
    glRotatef(rotSat3, 0, 1, 0);
    glTranslatef(0.f, 0.f, 1.5f);
    glRotatef(90, 0, 0, 1);
    
    generateSatelite();
    
    glPopMatrix();
}
