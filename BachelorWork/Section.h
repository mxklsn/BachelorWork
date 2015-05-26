#pragma once
#include "BaseObject.h"
#include "includes.h"

using namespace glm;

class Section : public BaseObject
{
	vec3 position;
	vec3 direction;
protected:
	virtual void init() override;
	virtual void initShaders() override;
	virtual void initGeometry() override;
	virtual void initCircuit() override;
public:
	Section();

	void Draw(float *MVP);

	~Section();
};

