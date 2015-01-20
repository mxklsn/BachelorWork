#pragma once
#include <memory>

using namespace std;

class Matrix
{
private:
	int _size;
	float **_elem;
public:
	// ������ ������� �� ��������� 4*4
	Matrix();
	// ������� ��������� �������
	Matrix(bool identity);
	Matrix(int size);
	Matrix(int size, bool identity);
	~Matrix(void);

	unique_ptr<float[]> getList();
	float** getMatrix();

	// �������� ������� ����������� �������
	int getSize() const;
private:
	void init(int size, bool idenity);
};

