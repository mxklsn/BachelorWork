#pragma once
#include "includes.h"
#include "Helpers.h"
#include "Texture.h"


class BaseObject
{
protected:
	string name;

	GLfloat* _vertexList;

	/* ������� ������� */
	GLuint vertexArrays;
	GLuint vertexbuffer;

	map<const char*, Texture*> _texture;


	/* ������ */
	GLuint shaderID;
	GLuint matrixID;
	GLuint textureID1;
protected:
	virtual void init()=0;
	virtual void initShaders()=0;
	virtual void initGeometry()=0;
public:
	BaseObject();

	void AddTexture(const char *textureFile, GLuint shaderTextureId);
	bool enable;
	~BaseObject();
};

