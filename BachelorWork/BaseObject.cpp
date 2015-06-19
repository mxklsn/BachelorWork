#include "BaseObject.h"


BaseObject::BaseObject()
{
	enable = true;
}

void BaseObject::AddTexture(const char *textureFile, GLuint shaderTextureId) {
	auto cash = _texture.find(textureFile);
	if (cash == _texture.end())
		_texture[textureFile] = new Texture(textureFile, shaderTextureId);
}


BaseObject::~BaseObject()
{
}
