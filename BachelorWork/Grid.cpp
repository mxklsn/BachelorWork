#include "Grid.h"


Grid::Grid(vec3 start_, vec3 size_, vec3 step_) : start(start_), size(size_), step(step_)
{
	name = "                                                     ";
	section = false;

	init();
	initShaders();
	initGeometry();
}

// TODO ������� ������� � ���������� static
void Grid::init()
{
	int iterX = size.x / step.x+1;
	int iterY = size.y / step.y+1;
	int iterZ = size.z / step.z+1;

	_vertexList = new GLfloat[iterZ*iterX * 6 + iterZ*iterY * 6 + iterX*iterY * 6];
	int i = 0;
	// �����������
	for (int z = 0; z < iterZ; z++)
		for (int x = 0; x < iterX; x++)
		{
			// ���
			_vertexList[i + 0] = start.x + x*step.x;
			_vertexList[i + 1] = start.y;
			_vertexList[i + 2] = start.z + z*step.z;
			// ����
			_vertexList[i + 3] = start.x + x*step.x;
			_vertexList[i + 4] = start.y + size.y;
			_vertexList[i + 5] = start.z + z*step.z;
			i += 6;
		}

	// ��������������
	for (int z = 0; z < iterZ; z++)
		for (int y = 0; y < iterY; y++)
		{
			// ����
			_vertexList[i + 0] = start.x;
			_vertexList[i + 1] = start.y + y*step.y;
			_vertexList[i + 2] = start.z + z*step.z;
			// �����
			_vertexList[i + 3] = start.x + size.x;
			_vertexList[i + 4] = start.y + y*step.y;
			_vertexList[i + 5] = start.z + z*step.z;
			i += 6;
		}

	// ��������
	for (int x = 0; x < iterX; x++)
		for (int y = 0; y < iterY; y++)
		{
			// ����
			_vertexList[i + 0] = start.x + x*step.x;
			_vertexList[i + 1] = start.y + y*step.y;
			_vertexList[i + 2] = start.z;
			// �����
			_vertexList[i + 3] = start.x + x*step.x;
			_vertexList[i + 4] = start.y + y*step.y;
			_vertexList[i + 5] = start.z + size.z;
			i += 6;
		}


	countPoint = i;
}

void Grid::initShaders()
{
	shaderID = LoadShaders("grid.vert", "grid.frag");
	matrixID = glGetUniformLocation(shaderID, "MVP");
	sectionID = glGetUniformLocation(shaderID, "section");
	sectionCenterID = glGetUniformLocation(shaderID, "centerSection");

	textureID1 = glGetUniformLocation(shaderID, "mainSampler");

	AddTexture("asfalt.jpg", textureID1);
}

void Grid::initGeometry()
{
	// ����� ��� ������� �� ������
	glGenVertexArrays(1, &vertexArrays);
	glBindVertexArray(vertexArrays);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, countPoint * sizeof(GLuint), _vertexList, GL_STATIC_DRAW);
}


void Grid::Draw(float *MVP)
{
	glUseProgram(shaderID);
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, MVP);
	glUniform1f(sectionID, section);
	vec3 temp = vec3(size.x / 2, size.y / 2, size.z / 2);
	vec3 center = start + temp;
	glUniform3f(sectionCenterID, center.x, center.y, center.z);

	int index = 0;
	map<const char*, Texture*>::iterator item;
	for (item = _texture.begin(), index; item != _texture.end(); item++, index++)
		item->second->BindTexture(index);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);

	
	// Draw the triangle !
	glDrawArrays(GL_LINES, 0, countPoint / 2);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}


Grid::~Grid()
{
}
