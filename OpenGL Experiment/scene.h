#ifndef ProjetOpenGL_scene_h
#define ProjetOpenGL_scene_h

#include <vector>
#include <GLUT/glut.h>

using namespace std;

class scene {
		
public:
    
    GLuint cubeBleu_id, cubeVert_id, deuxCubes_id;
    GLuint sphereBleu_id, sphereVert_id, deuxSpheres_id;
    GLuint donut_id;
    GLuint terre_id, lune_id, soleil_id, ligneRevolutionTerre_id, ligneRevolutionLune_id;
    GLuint satelite_id, gTerre_id, ligneSat_id;
    
    GLfloat revolutionTerre, rotationTerre, revolutionLune;
    GLfloat rotSat1, rotSat2, rotSat3;
    
    GLfloat xLum, yLum, zLum;
    
	scene();
    
    void initScene();
    
    void createCube();
    void createPetitCube();
    void rotationSysteme();
    void rotationSatelite();
    void setPositionLumiere();
    void initTransLum();
    void OnKeyboardSpecial(int touche, int x, int y);
    
    void compileCubeBleu();
    void compileCubeVert();
	void compileDeuxCubes();
    void compileSphereBleu();
    void compileSphereVert();
	void compileDeuxSpheres();
    void compileDonut();
    void compileTerre();
    void compileLune();
    void compileSoleil();
    void compileLigneRevolutionTerre();
    void compileLigneRevolutionLune();
    void compileSatelite();
    void compileGTerre();
    void compileLigneSat();
    
    void generateCubeBleu();
    void generateCubeVert();
    void generateDeuxCubes();
    void generateSphereBleu();
    void generateSphereVert();
    void generateDeuxSpheres();
    void generateDonut();
    void generateTerre();
    void generateLune();
    void generateSoleil();
    void generateLigneRevolutionTerre();
    void generateLigneRevolutionLune();
    void generateSysteme();
    void generateSystemeLigne();
    void generateSatelite();
    void generateGTerre();
    void generateTerreSat();
    void generateLigneSat();
    void generateTerreSatLigne();
};


#endif
