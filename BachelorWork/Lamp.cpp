#include "Lamp.h"
#include "glm\gtc\matrix_transform.hpp"

Lamp::Lamp(void)
{
	_position = vec3(0, 30, 0);
	_size = vec3(2,2,2);
	_target = vec3(0, 0, 0);
	LampDraw = new Parallelepiped(_position, _size, 2);
	LampDraw->lamp = this;
	glEnable(GL_LIGHT0);

}

vec3 Lamp::GetVector()
{
	return _position - _target;
}

void Lamp::Draw(float *MVP, float *M, float *V, float *P)
{
	LampDraw->position = _position;
	LampDraw->Draw(MVP, M, V, P, GL_TRIANGLES, false);
}


Lamp::~Lamp(void)
{
}
