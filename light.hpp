#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <GL/glut.h>
#include "vector.hpp"

class Light{
	private:
	Vector3 Position;
	Vector3 Color;
	Vector3 Ambient;
	Vector3 Specular;
	Vector3 Diffuse;
	public:
	void Draw();
	void setPosition(float x, float y, float z);
	void setColor(float x, float y, float z);
	void setAmbient(float x, float y, float z);
	void setSpecular(float x, float y, float z);
	void setDiffuse(float x, float y, float z);
	};
#endif
