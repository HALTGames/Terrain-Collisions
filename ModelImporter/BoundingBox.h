#pragma once
#define GLUT_DISABLE_ATEXIT_HACK

#include <GL\freeglut.h>
#include <iostream>

#include "Vector3.h"

using namespace std;


class BoundingBox
{
public:
	Vector3 max;
	Vector3 min;

	BoundingBox();

	bool Collision(GLfloat x, GLfloat y, GLfloat z);

	void DrawBox();

	inline friend ostream& operator<<(ostream& os, const BoundingBox& box);
};

ostream& operator<<(ostream& os, const BoundingBox& box)
{
	os << "Minimum" << std::endl;
	os << "x = " << box.min.x << std::endl;
	os << "y = " << box.min.y << std::endl;
	os << "z = " << box.min.z << std::endl;
	os << "Maximum" << std::endl;
	os << "x = " << box.max.x << std::endl;
	os << "y = " << box.max.y << std::endl;
	os << "z = " << box.max.z << std::endl;
	return os;
}