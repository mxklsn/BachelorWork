#include "includes.h"

#include "Helpers.h"
#include "Camera.h"
#include "Mesh.h"
#include "SkyBox.h"
#include "Texture.h"
#include "Parallelepiped.h"
#include "Parallelepiped.h"

//#include "Grid.h"


using namespace std;

/************************************** Defined Constants ***************************************/

/*************************************** Global Variables ***************************************/
/* GLUT variables */

/* Shaders variables */

/* Bachelor variables */

Camera *camera;
//Mesh *mesh;
//SkyBox *skyBox;
vector<Parallelepiped*> cubes;
vector<Parallelepiped*> layers;
//vector<Grid*> grids;


int displayType = GL_LINES;
int displayTypeLayer = GL_LINES;
bool LayerColor = false;
/******************************************* Functions ******************************************/

void CreateGeometry()
{
}

/* GLUT callbacks */

void DisplayCallbackFunction(void)
{
	//Clear all the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	camera->Update();
	for (auto cube : cubes)
		cube->Draw(&camera->MVP[0][0], &camera->_model[0][0], &camera->_view[0][0], &camera->_projection[0][0], displayType, LayerColor);
	for (auto layer : layers)
		layer->Draw(&camera->MVP[0][0], &camera->_model[0][0], &camera->_view[0][0], &camera->_projection[0][0], displayTypeLayer, LayerColor);
//	for (auto grid : grids)
//		grid->Draw(&camera->MVP[0][0]);
	glutSwapBuffers();
}

void TimerCallbackFunction(int value)
{
	glutTimerFunc(30, TimerCallbackFunction, 0);

	// TODO
	glutPostRedisplay();
}

/*void ConsoleUsage() {
	string value;
	cout << "Enter command:" << endl;
	cin >> value;

	if (value == "grid")
	{
		float alpha;
		cout << "Enter alpha" << endl;
		cin >> alpha;
		grids[0]->setAlpha(alpha);
	}
}*/

void KeyboardCallbackFunction(unsigned char key, int x, int y)
{
	int addSpeed = 50;
	switch (key)
	{
	case 27:  /* Escape key */
		glutLeaveMainLoop();
		break;
	case 'q':
		camera->_position.x += addSpeed;
		break;
	case 'a':
		camera->_position.x -= addSpeed;
		break;
	case 'w':
		camera->_position.y += addSpeed;
		break;
	case 's':
		camera->_position.y -= addSpeed;
		break;
	case 'e':
		camera->_position.z += addSpeed;
		break;
	case 'd':
		camera->_position.z -= addSpeed;
		break;
	case 't':
		camera->_target.x += addSpeed;
		break;
	case 'g':
		camera->_target.x -= addSpeed;
		break;
	case 'y':
		camera->_target.y += addSpeed;
		break;
	case 'h':
		camera->_target.y -= addSpeed;
		break;
	case 'u':
		camera->_target.z += addSpeed;
		break;
	case 'j':
		camera->_target.z -= addSpeed;
		break;
	case '1':
		displayTypeLayer = GL_LINES;
		break;
	case '2':
		displayTypeLayer = GL_TRIANGLES;
		LayerColor = false;
		break;
	case '3':
		displayTypeLayer = GL_TRIANGLES;
		LayerColor = true;
		break;
	case '4':
		displayType = GL_LINES;
		break;
	case '5':
		displayType = GL_TRIANGLES;
		LayerColor = false;
		break;
	case '6':
		displayType = GL_TRIANGLES;
		LayerColor = true;
		break;
	/*case 'z':
		if (grids.size() > 0)
			grids[0]->isEnable = !grids[0]->isEnable;
		break;
	case 'x':
		section->isEnableGridSection = !section->isEnableGridSection;
		break;
	case 'c':
		section->isEnable = !section->isEnable;
		break;*/
	case 'i':
		for (auto cube : layers)
			cube->positionLighting.x = 0.5;
		break;
	case 'k':
		for (auto cube : layers)
			cube->positionLighting.x = -0.5;
		break;
	case 'o':
		for (auto cube : layers)
			cube->positionLighting.y = 0.5;
		break;
	case 'l':
		for (auto cube : layers)
			cube->positionLighting.y = -0.5;
		break;
	case 'p':
		for (auto cube : layers)
			cube->positionLighting.z = 0.5;
		break;
	case ';':
		for (auto cube : layers)
			cube->positionLighting.z = -0.5;
		break;
	/*case '5':
		section->position.y -= addSpeed;
		section->Init();
		section->Update(cubes);
		break;
	case '9':
		section->position.z += addSpeed;
		section->Init();
		section->Update(cubes);
		break;
	case '6':
		section->position.z -= addSpeed;
		section->Init();
		section->Update(cubes);
		break;
	case 'p':
		ConsoleUsage();
		break;
		camera->Update();*/
	case '0':
		for (auto cube : cubes)
			cube->section = !cube->section;
//		for (auto grid : grids)
//			grid->section = !grid->section;
		break;
	camera->Update();
	}
}

void SpecialKeyboardCallbackFunction(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:  /* Rotate up a little */
		break;
	}

	glutPostRedisplay();
}

void MouseCallbackFunction(int button, int updown, int x, int y)
{
	if (updown == GLUT_UP)
	{

	}
}

void ReshapeCallbackFunction(int width, int height)
{
	float ar;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	ar = (float)width / (float)height;
	glFrustum(-ar, ar, -1.0, 1.0, 10.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Init functions */

void InitGLStates()
{
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glReadBuffer(GL_BACK);
	glDrawBuffer(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(TRUE);
	glDisable(GL_STENCIL_TEST);
	glStencilMask(0xFFFFFFFF);
	glStencilFunc(GL_EQUAL, 0x00000000, 0x00000001);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glClearColor(1, 1, 1, 0);
	glClearDepth(1.0);
	glClearStencil(0);
	glEnable(GL_TEXTURE0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glDisable(GL_DITHER);
}


/*bool InitGrid()
{
	vector<int> pointX;
	vector<int> pointY;
	vector<int> pointZ;
	for (auto cube : cubes) {
		pointX.clear();
		pointY.clear();
		pointZ.clear();

		vec3 sizeGrid = cube->GlobalSize;

		pointX.push_back((cube->position.x - cube->size.x) * 2);
		pointX.push_back((cube->position.x + cube->size.x) * 2);

		pointY.push_back((cube->position.y - cube->size.y) * 2);
		pointY.push_back((cube->position.y + cube->size.y) * 2);

		pointZ.push_back((cube->position.z - cube->size.z) * 2);
		pointZ.push_back((cube->position.z + cube->size.z) * 2);

		int minNODX = NOD(pointX[0], pointX[1]);
		for (int i = 0; i < pointX.size(); i++)
		for (int j = 0; j < pointX.size(); j++)
		if (NOD(pointX[i], pointX[j]) != 0)
			minNODX = std::min(minNODX, NOD(pointX[i], pointX[j]));

		int minNODY = NOD(pointY[0], pointY[1]);
		for (int i = 0; i < pointY.size(); i++)
		for (int j = 0; j < pointY.size(); j++)
		if (NOD(pointY[i], pointY[j]) != 0)
			minNODY = std::min(minNODY, NOD(pointY[i], pointY[j]));

		int minNODZ = NOD(pointZ[0], pointZ[1]);
		for (int i = 0; i < pointZ.size(); i++)
		for (int j = 0; j < pointZ.size(); j++)
		if (NOD(pointZ[i], pointZ[j]) != 0)
			minNODZ = std::min(minNODZ, NOD(pointZ[i], pointZ[j]));

		vec3 new_sizeGrid = vec3(sizeGrid.x / 2, sizeGrid.y / 2, sizeGrid.z / 2);

		grids.push_back(new Grid(cube->position - cube->size, sizeGrid, vec3(cube->size.x / 5, cube->size.y / 5, cube->size.z / 5)));
	}
	return true;
}*/

void Light(void)
{
	/*
	float light0_diffuse[] = { 0.4, 0.7, 0.2 }; // устанавливаем диффузный цвет света 
	float light0_direction[] = { 0.0, 0.0, 1.0, 0.0 }; // устанавливаем направление света

	glEnable(GL_LIGHT0); // разрешаем использовать light0

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // устанавливаем источнику света light0 диффузный свет, который указали ранее 
	glLightfv(GL_LIGHT0, GL_POSITION, light0_direction); // устанавливаем направление источника света, указанное ранее 
	*/
}

Parallelepiped* getCube(ifstream* input)
{
	vec3 position, size;
	float material;
	(*input) >> position.x >> position.y >> position.z >> size.x >> size.y >> size.z >> material;
	return new Parallelepiped(position, size, material);
}

bool InitOther()
{
	camera = new Camera();
	//InitSection();

	//mesh = new Mesh("ElephantBody.3ds");
	//mesh->AddTexture("texture01.jpg", textureID1);
	//mesh->AddTexture("sun_tex.bmp", textureID1);

	ifstream input("cubes.api");
	int countLayers, countCubes;
	input >> countLayers;

	for (int i = 0; i < countLayers; i++)
		layers.push_back(getCube(&input));

	input >> countCubes;
	for (int j = 0; j < countCubes; j++)
		cubes.push_back(getCube(&input));

	Light();
	
	//InitGrid();
	//section->Init();
	//section->Update(cubes);

	return true;
}

/*void Section::initShadersSection()
{
	shaderCubeID = LoadShaders("sectionCube.vert", "sectionCube.frag");
	matrixCubeID = glGetUniformLocation(shaderID, "MVP");
}*/

/* The Main Program */
int main(int argc, char *argv[])
{
	/* Initialize GLUT */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	//glutInitContextVersion(4, 3);
	glutInitContextFlags(GLUT_CORE_PROFILE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitWindowSize(900, 900);

	/* Create the window */
	glutCreateWindow("Bachelor Work");

	/* Initialize GLEW */
	glewExperimental = TRUE;
	glewInit();

	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
	cout << "OpenGL Vendor: " << (char*)glGetString(GL_VENDOR) << "\n";
	cout << "OpenGL Renderer: " << (char*)glGetString(GL_RENDERER) << "\n";
	cout << "OpenGL Version: " << (char*)glGetString(GL_VERSION) << "\n\n";

	/* Initialize all objects */
	InitGLStates();
	bool init_ = InitOther();
	if (init_ == true) {
		CreateGeometry();
	}

	/* Initialize CALLBACK functions */
	glutKeyboardFunc(KeyboardCallbackFunction);
	glutMouseFunc(MouseCallbackFunction);
	glutSpecialFunc(SpecialKeyboardCallbackFunction);
	glutDisplayFunc(DisplayCallbackFunction);
	glutReshapeFunc(ReshapeCallbackFunction);
	glutTimerFunc(30, TimerCallbackFunction, 0);

	/* Enter the GLUT main loop */
	glutMainLoop();

	return 0;
}