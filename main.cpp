#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "camera.h"
#include "camera.cpp"
#include "vector.cpp"
#include "light.cpp"
#include "light.hpp"
#include "hand.cpp"
#include "hand.hpp"
Camera kamera=Camera();
static GLfloat Ltheta1 = 0;
static float Ltheta2 = 0;
GLfloat a = kamera.Position.x=0.05;
GLfloat b = kamera.Position.y=0.4;
GLfloat ugao=0;
GLfloat ugao2=0;
void draw_fingers(){// funkcija koja crta svih 5 prstiju. Svi prsti osim palca se sastoje od 3 cinidra-zgloba koji su pomocu gl
	//translate stavljeni na pravu poziciju i pomocu glRotatef stavljeni u pravi polozaj. 
GLUquadricObj *ldp1 = gluNewQuadric();
	
	glPushMatrix();
	glRotatef( -(90-Ltheta1-Ltheta2), 1, 0, 0);
	glTranslatef(0.15,0,0.25);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);	
	glTranslatef(0.0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.15, 7, 7);
	glTranslatef(0.0,0,0.1);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.15, 7, 7);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef( -(90-Ltheta1-Ltheta2), 1, 0, 0);
	glTranslatef(0.07,0,0.25);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);
	glTranslatef(0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);
	glTranslatef(0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.15, 7, 7);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef( -(90-Ltheta1-Ltheta2), 1, 0, 0);
	glTranslatef(-0.01,0,0.25);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);
	glTranslatef(0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);
	glTranslatef(0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.18, 7, 7);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef( -(90-Ltheta1-Ltheta2), 1, 0, 0);
	glTranslatef(-0.09,0,0.25);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);
	glTranslatef(0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.2, 7, 7);
	glTranslatef(0,0,0.2);
	glRotatef(ugao,1,0,0);
	gluCylinder(ldp1, 0.04, 0.04, 0.10, 7, 7);
	glPopMatrix();
	
	glPushMatrix();
	GLUquadricObj *ldp13 = gluNewQuadric();
	GLUquadricObj *ldp14 = gluNewQuadric();
	glRotatef( -(90-Ltheta1-Ltheta2), 1, 0, 0);
	glRotatef(-8, 0, 1, 0);
	glTranslatef(-0.17,0,-0.23);
    glRotatef(ugao2,1,0.5,0.2);
	gluCylinder(ldp13, 0.04, 0.04, 0.3, 7, 7);
	glTranslatef(0,0.0,0.3);
	glRotatef(ugao2,0.5,0.7,0.2);
	gluCylinder(ldp14, 0.04, 0.04, 0.2, 7, 7);
	glPopMatrix();
	gluDeleteQuadric(ldp1);
		}
void display(){
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    kamera.SetPosition(kamera.Position.x,kamera.Position.y,0.0);//Napravljen je globalni objekat tipa Camera, postavljene su vrijednosti 
    //da bi se mogla pozvati fja gluLookat() u sastavu metode DrawBegin();
    kamera.SetTarget(0.05,0.3,1.0);
    kamera.SetFrustum(1.0,0.0,0.0,0.0,0.1,0.0);
    kamera.DrawBegin();
    Light svjetlo=Light();//napravljena su dva objekta tipa Light koji postavljaju dva razlicita izvora svjetlosti. Postavljena je 
    //odgovarajuca boja, izvor spekularna komponenta...
    svjetlo.setPosition(0.5,.2,0.1);
    svjetlo.setColor(1.0,0.5,0.5);
    svjetlo.setAmbient(0.6,0.6,0.6);
    svjetlo.setSpecular(1,1,1);
    svjetlo.setDiffuse(0.8,0.8,0.5);
    svjetlo.Draw();
    Light svjetlo2=Light();
    svjetlo2.setPosition(-0.3,0.2,0.1);
    svjetlo2.setColor(0.5,0.5,0.5);
    svjetlo2.setAmbient(0.6,0.6,0.6);
    svjetlo2.setSpecular(0.7,0.7,1);
    svjetlo2.setDiffuse(0.8,0.8,0.5);
    svjetlo2.Draw();   
	Hand ruka=Hand();//napravljen je objekat tipa Hand i pozvan je metod koji crta samo šaku u vidu skaliranje kocke
	glPushMatrix(); 
	ruka.setDimensions(1.1,1.7,-0.28);
	ruka.setPosition(0.025,0.0,0);
	ruka.draw();
	draw_fingers();
	glPopMatrix();
	glFlush();
}

void specialKeys(int key, int x, int y) {//mijenjamo polozaj kamere pomoću navigacijskih tipki
  switch (key) {
    case GLUT_KEY_UP:
      kamera.Position.y += 0.05;
      break;
    case GLUT_KEY_DOWN:
      kamera.Position.y -= 0.05;
      break;
    case GLUT_KEY_RIGHT:
      kamera.Position.x += 0.01;
      break;
    case GLUT_KEY_LEFT:
      kamera.Position.x -= 0.01;
      break;
  }
  glutPostRedisplay();
} 
int animating =0;
void animate(int value){
	if(animating){
	if(ugao <=80){
	ugao+=3;
	ugao2+=1.8;
    }
	else{
	while(ugao > 0){
		ugao-=3;
		ugao2-=1.8;
		}}
		  glutPostRedisplay();
	glutTimerFunc(60,animate,0);}
}
void startAnimation() {
      // call this to start or restart the animation
   if ( ! animating ) {
       animating = 1;
       glutTimerFunc(150, animate, 0);
   }
}
void pauseAnimation() {
       // call this to pause the animation
    animating = 0;
}
void kbd(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'o'://pokrećemo animaciju tipkom 'o' a zaustavljamo tipkom 'O' koja otvara i zatvara šaku
	startAnimation();
    break;
  case 'O':
	pauseAnimation();
    break;
   case 'a'://osim animacije, mozemo otvarati i zatvarati šaku pomoću tipki 'a' i 'A'
   if(ugao<=80){
	ugao+=2;
	ugao2+=1.2;}
    break;
  case 'A':
  if(ugao>=0){
	ugao-=2;
	ugao2-=1.2;}
    break;
}  glutPostRedisplay();}	
     
int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Projekat");
  glutDisplayFunc(display);
  glutKeyboardFunc(kbd);  
  glutSpecialFunc(specialKeys);
  glutMainLoop();
	return 0;
}
