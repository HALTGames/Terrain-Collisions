#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
	min.x = 1000000;
	min.y = 1000000;
	min.z = 1000000;

	max.x = -1000000;
	max.y = -1000000;
	max.z = -1000000;
}

bool BoundingBox::Collision(GLfloat x, GLfloat y, GLfloat z)
{
	return  x <= max.x && x >= min.x &&
			y <= max.y && y >= min.y &&
			z <= max.z && z >= min.z;
}

void BoundingBox::DrawBox()
{
	glLineWidth(5);

	glColor4f(1.0, 0.0, 0.0, 1.0);

	glBegin (GL_LINE_LOOP); 
	glVertex3f(max.x, max.y, min.z); // 0
	glVertex3f(min.x, max.y, min.z); // 1
	glVertex3f(min.x, min.y, min.z); // 2
	glVertex3f(max.x, min.y, min.z); // 3
	glEnd();

	glBegin (GL_LINE_LOOP); 
	glVertex3f(max.x, min.y, max.z); // 4
	glVertex3f(max.x, max.y, max.z); // 5
	glVertex3f(min.x, max.y, max.z); // 6
	glVertex3f(min.x, min.y, max.z); // 7
	glEnd();

	glBegin (GL_LINE_LOOP); 
	glVertex3f(max.x, max.y, min.z); // 0
	glVertex3f(max.x, max.y, max.z); // 5
	glVertex3f(min.x, max.y, max.z); // 6
	glVertex3f(min.x, max.y, min.z); // 1
	glEnd();

	glBegin (GL_LINE_LOOP); 
	glVertex3f(max.x, min.y, max.z); // 4
	glVertex3f(min.x, min.y, max.z); // 7
	glVertex3f(min.x, min.y, min.z); // 2 
	glVertex3f(max.x, min.y, min.z); // 3

	glEnd();

	glColor4f(1.0, 1.0, 1.0, 1.0);
}

