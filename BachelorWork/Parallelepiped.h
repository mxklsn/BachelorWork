#pragma once
#include "includes.h"
#include "Helpers.h"
#include "Texture.h"
#include "BaseObject.h"

using namespace glm;

class Parallelepiped : public BaseObject
{
protected:
	GLfloat* _mapcoordList;
	GLfloat* _normalList;

	GLuint uvbuffer;
	GLuint normalbuffer;

	GLuint shaderPosID;
	GLuint shaderSizeID;
protected:
	virtual void init() override;
	virtual void initShaders() override;
	virtual void initGeometry() override;
public:

	// TODO so bad
	/* ���������������� */
	vec3 position;
	vec3 size;
	int layer;

	Parallelepiped(vec3 position, vec3 size, int layer);

	void Draw(float *MVP, int displayType);

	~Parallelepiped();
};

