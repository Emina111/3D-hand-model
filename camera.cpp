#include "camera.h"
#include "vector.hpp"
#include <iostream>
void Camera::SetPosition(float x, float y, float z) {
  Position = Vector3(x, y, z);
}

float Camera::getX(){
	return Position.x;
	}

float Camera::getY(){
	return Position.y;
	}

void Camera::SetTarget(float x, float y, float z) { Target = Vector3(x, y, z); }

void Camera::SetFrustum(float l, float r, float b, float t, float n, float f) {
  Left = l;
  Right = r;
  Bottom = b;
  Top = t;
  NearClip = n;
  FarClip = f;
}

void Camera::DrawBegin() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(Left, Right, Bottom, Top, NearClip, FarClip);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Position.x, Position.y, Position.z, Target.x, Target.y, Target.z, 0, 0, 1);
}





