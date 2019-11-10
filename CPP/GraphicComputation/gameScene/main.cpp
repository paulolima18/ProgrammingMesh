#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#define trees 300
#define size 100

float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;
float rotation = 0.5f;
float v[trees][2];

void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
}

void idleFunc()
{
	rotation += 0.5f;
}
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void drawTree()
{
	glPushMatrix();
	//glutSolidCone(float baseRadius,float height, int slices,int stacks)
	glColor3f((139/255.0f),(69/255.0f),(19/255.0f));
	glRotatef(-90, 2,0,0);
	glutSolidCone(1,2, 4, 4); // base (small tree)
	glTranslatef(0, 0, 1);
	glColor3f(0,(128/255.0f),0);
	glutSolidCone(2,4, 10, 10); // leafs (big cone)
	glPopMatrix();
}

void drawForest(float v[][2])
{
	//void srand(int seed); // start the random number sequence
	//int rand(void); // returns a number between 0 and RAND_MAX
	int i;
	for (i=0;i < trees;i++)
	{
		glPushMatrix();
		glTranslatef(v[i][0],0,v[i][1]);
		drawTree();
		glPopMatrix();
	}
}

int insideBattle(float xMap, float zMap)
{
	int result = 1;

	if (size - abs(xMap) < abs(70) || size - abs(zMap) < abs(70))
		result  = 0;
	return result;
}

void createArray(float v[][2])
{
	srand(time(NULL));
	int lowest = 0,highest = size;
	float xMap,zMap;
	int i;
	for (i = 0; i < trees; i++)
	{
		xMap = lowest+(rand()%(highest-lowest));
		zMap = lowest+(rand()%(highest-lowest));
		if (!insideBattle(xMap,zMap))
		{
			if (i >= 0 && i <= trees/4 )
			{
				v[i][0] = xMap;
				v[i][1] = zMap;
			}
			else if (i >= trees/4 && i <= trees/2 )
			{
				v[i][0] = -xMap;
				v[i][1] = zMap;
			}
			else if (i >= trees/2 && i <= 3*trees/4 )
			{
				v[i][0] = xMap;
				v[i][1] = -zMap;
			}
			else
			{
				v[i][0] = -xMap;
				v[i][1] = -zMap;
			}
		}
		else
		{
			v[i][0] = abs(xMap) + 30;
			v[i][1] = - abs(zMap) - 30;
		}
	}
}
void drawRedArmy()
{
	int i;
	float warriors = 10.0;
	for(i = 0; i < warriors ; i++)
	{
		glPushMatrix();
		glRotatef((360/warriors)*i+ rotation,0,1,0);
		glTranslatef(warriors,1,warriors);
		glutSolidTeapot(1);
		glPopMatrix();
	}
}
void drawBlueArmy()
{
	glColor3f(0,0,1);
	int i;
	float warriors = 20.0;
	for(i = 0; i < warriors ; i++)
	{
		glPushMatrix();
		glRotatef( ((360/warriors)*i) - rotation,0,1,0);
		glTranslatef(warriors,1,warriors);
		glutSolidTeapot(1);
		glPopMatrix();
	}
}

void drawPrize()
{
	glPushMatrix();
	glTranslatef(0,2,0);
	glColor3f(1, 0,0);
	glutSolidTorus(1, 2, 10,10);
	glPopMatrix();
}
void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	glColor3f(0.2f, 0.8f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);

		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);
		glVertex3f(100.0f, 0, 100.0f);
	glEnd();
	idleFunc();
	drawForest(v);
	drawPrize();
	drawRedArmy();
	drawBlueArmy();
	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here

}


void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

	case GLUT_KEY_LEFT:
		alfa += 0.1; break;

	case GLUT_KEY_UP:
		beta += 0.1f;
		if (beta > 1.5f)
			beta = 1.5f;
		break;

	case GLUT_KEY_DOWN:
		beta -= 0.1f;
		if (beta < -1.5f)
			beta = -1.5f;
		break;

	case GLUT_KEY_PAGE_DOWN: radius -= 5.0f;
		if (radius < 5.0f)
			radius = 5.0f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 5.0f; break;
	}
	spherical2Cartesian();
	glutPostRedisplay();

}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));

	printf("\nUse Arrows to move the camera up/down and left/right\n");
	printf("Home and End control the distance from the camera to the origin\n");
}


int main(int argc, char **argv)
{
	createArray(v);
// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("scene");

// Required callback registry
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	spherical2Cartesian();

	printInfo();
// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
