#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glut.h>
#include "vector.hpp"

class Camera {
	  public:
  Vector3 Position;
  Vector3 Target;
  float Left, Right, Bottom, Top, NearClip, FarClip;

  void SetPosition(float x, float y, float z);
  void SetTarget(float x, float y, float z);
  void SetFrustum(float l, float r, float b, float t, float n, float f);
  float getX();
  float getY();
  void vrti();
  void DrawBegin();
  void specialKeys(int key, int x, int y);
};

#endif

