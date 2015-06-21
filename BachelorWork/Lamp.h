#pragma once
#include "includes.h"
#include "BaseObject.h"
#include "Helpers.h"
#include "Parallelepiped.h"

using namespace glm;

class Parallelepiped;

class Lamp
{
public:
	Parallelepiped *LampDraw;
public:
	vec3 _target;
	vec3 _position;
	vec3 _size;
public:
	Lamp(void);
	~Lamp(void);
	vec3 GetVector();
	void Draw(float *MVP, float *M, float *V, float *P);

};

