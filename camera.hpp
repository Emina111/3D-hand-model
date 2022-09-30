#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glut.h>
#include "vector.hpp"

class Camera {
  Vector3 Position;
  Vector3 Target;
  float Left, Right, Bottom, Top, NearClip, FarClip;

  public:
  void SetPosition(float x, float y, float z);
  void SetTarget(float x, float y, float z);
  void SetFrustum(float l, float r, float b, float t, float n, float f);
  void DrawBegin();
};

#endif

