#pragma once
#include "includes.h"
#include "glm\gtx\euler_angles.hpp"

using namespace glm;

class Camera
{
public:
	mat4 MVP;
public:
	mat4 _projection;
	mat4 _view;
	mat4 _model;
	
	vec3 _up;
public:
	vec3 _position;
	vec3 _target;
public:
	Camera(void);

	void Update();

	~Camera(void);

private:
	void calcProjection();
	void calcView();
	void calcModel();
};

