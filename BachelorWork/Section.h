#pragma once
#include "includes.h"
#include "Helpers.h"
#include "Texture.h"
#include "BaseObject.h"
#include "Parallelepiped.h"

using namespace glm;
/*
class Section : public BaseObject
{
public:
	vec3 position;
	bool isEnableGridSection;
private:
	vec3 direction;
	vec3 maxSize;
	int step;
	int countPoint;

	float _getCubeSizeForShaders(vec3);
protected:
	virtual void init() override;
	virtual void initShaders() override;
	virtual void initGeometry() override;
	void initSectionGeomentry();

	GLfloat* _vertexListSection;
	int countPointSection;
	GLuint vertexSectionbuffer;

	GLfloat* _vertexListSectionColor;
	GLuint vertexSectionColorbuffer;

	GLuint vertexCubeArrays;
	GLuint shaderCubeID;
	GLuint matrixCubeID;
public:
	void Init();

	void Draw(float *MVP);
	void Update(vector<Parallelepiped*> lists);

	vec3 getPosition() const;
	void setMaxSize(vec3 size_);

	~Section();
};*/
