#pragma once
#include "includes.h"
#include "Helpers.h"
#include "Texture.h"
#include "BaseObject.h"
#include "Lamp.h"

class Lamp;

using namespace glm;

class Parallelepiped : public BaseObject
{
protected:
	GLfloat* _mapcoordList;
	GLfloat* _normalList;
	GLfloat* _vertexListForCircuit;

	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint vertexbufferForCircuit;

	GLuint shaderPosID;
	GLuint shaderSizeID;
	GLuint sectionID;
	GLuint shaderLayerID;
	GLuint shaderLayerColorRGBAID;
	GLuint shaderPositionID;
	GLuint shadersLightPosition_worldspaceID;


protected:
	virtual void init() override;
	virtual void initCircuit();
	virtual void initShaders() override;
	virtual void initGeometry() override;
public:

	/* Позиционирование */
	vec3 position;
	vec3 size;
	vec3 GlobalSize;
	vec4 color;
	vec3 positionLighting;

	float material;
	Lamp* lamp;
	bool section;

	Parallelepiped(vec3 position, vec3 size, float material);
	void SetPositionLighting(vec3 positionLighting_);
	void Draw(float *MVP, float *M, float *V, float *P, int displayType, bool LayerColor);

	~Parallelepiped();
};

