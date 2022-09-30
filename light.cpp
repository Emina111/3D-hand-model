#include "vector.hpp"
#include "light.hpp"
#include <GL/glut.h>

void Light::setPosition(float x, float y, float z){
	Position = Vector3(x,y,z);
	}
void Light::setColor(float x, float y, float z){
	Color = Vector3(x,y,z);
	}
void Light::setAmbient(float x, float y, float z){
	Ambient=Vector3(x,y,z);
	}
void Light::setSpecular(float x, float y, float z){
	Specular=Vector3(x,y,z);
	}
void Light::setDiffuse(float x, float y, float z){
	Diffuse=Vector3(x,y,z);
	}
void Light::Draw(){
	GLfloat mat_ambient[]={Ambient.x, Ambient.y, Ambient.z, 1.0};
	GLfloat mat_specular[]={Specular.x, Specular.y, Specular.z, 1.0};
	GLfloat mat_diffuse[] = {Diffuse.x, Diffuse.y, Diffuse.z, 1.0};
    glClearColor(0.5, 0.2, 0.3, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_diffuse);
	
    GLfloat light_position[] = {Position.x, Position.y, Position.z, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	GLfloat white_light[] = {0, 0, 0, 1.0};
	GLfloat some_light[] = {Color.x, Color.y, Color.z, 1.0};
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightfv(GL_LIGHT0, GL_AMBIENT, some_light);
    
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	}
