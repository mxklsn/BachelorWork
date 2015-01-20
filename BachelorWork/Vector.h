#pragma once
class Vector
{
private:
	float _x;
	float _y;
	float _z;
	// ���� w == 1, �� ��� �����, ���� w == 0, �� ��� �������
	float _w;
public:
	Vector(void);
	Vector(float x, float y);
	Vector(float x, float y, float z);
	Vector(float x, float y, float z, float w);

	float& X();
	float& Y();
	float& Z();
	float& W();

	~Vector(void);
private:
	void init(float x, float y, float z, float w);
};

