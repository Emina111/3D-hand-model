#include "vector.hpp"
#include "hand.hpp"
#include <GL/glut.h>

void Hand::setDimensions(GLfloat a, GLfloat b, GLfloat c){
	Dimension = Vector3(a,b,c);//sets dimensions of cube
	}
	
void Hand::setPosition(GLfloat a, GLfloat b, GLfloat c){
	Position = Vector3(a,b,c);
	}

void Hand::draw(){
	glColor3f(1,0,0);
    glPushMatrix();
    glScalef(Dimension.x, Dimension.y, Dimension.z);
	glTranslatef(Position.x, Position.y, Position.z);
    glutSolidCube(0.30);//sets scale of wire cube
    glPopMatrix();
	}
