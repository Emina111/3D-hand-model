#ifndef HAND_HPP
#define HAND_HPP

#include <GL/glut.h>
#include "vector.hpp"

class Hand{
	Vector3 Position;
	Vector3 Dimension;
	public:
	void draw();
	void setDimensions(GLfloat a, GLfloat b, GLfloat c);
	void setPosition(GLfloat a, GLfloat b, GLfloat c);
	};
#endif
