#pragma once
#include "includes.h"

using namespace std;

class Texture
{
private:
	// ������������� ��������
	GLuint _id;
	// ��� ��������� �����
	const char *_filename;
	// ������� � �������
	GLuint _shaderIndex;

	GLuint Texture::loadTexture();
public:
	Texture(const char *filename);
	Texture(const char *filename, GLuint shaderIndex);

	void BindTexture(GLuint shaderIndex, int textureNumber);
	void BindTexture(int textureNumber);
	
	~Texture();
};

