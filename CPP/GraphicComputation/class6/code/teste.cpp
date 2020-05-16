
#include<stdio.h>
#include<stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

#include <IL/il.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#endif

using namespace std;

//---------------------------------------------------------------------------

float camX = 00, camY = 0, camZ = 40, radius = 100.0f;
int startX, startY, tracking = 0;
int alfa = 0, beta = 45, r = 50;
int alpha = 0;

//---------------------------------------------------------------------------

//Image properties and pixel density array
unsigned int t, tw, th;
unsigned char *imageData;

//Grid vertices
float* gridVertices;

//VBOs
GLuint buffers[1];

//---------------------------------------------------------------------------
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the correct perspective
	gluPerspective(45,ratio,1,1000);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



//Colocar aqui o código de desenho do terreno usando VBOs com TRIANGLE_STRIPS
void drawTerrain() {

    for (int i = 0; i < th - 1 ; i++) {
        glDrawArrays(GL_TRIANGLE_STRIP, (tw) * 2 * i, (tw) * 2);
    }
}

void renderScene(void) {

	float pos[4] = {-1.0, 1.0, 1.0, 0.0};

	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	//Desenhar o terreno
	glPushMatrix();
	glColor3f(0.2,0.2,0.2);
	drawTerrain();
    glPopMatrix();

	// just so that it renders something before the terrain is built
	// to erase when the terrain is ready
	//glutWireTeapot(2.0);

    // End of frame
	glutSwapBuffers();
}

void spherical2Cartesian() {

    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
}

void processSpecialKeys(int key, int xx, int yy) {

    switch (key) {

        case GLUT_KEY_RIGHT:
            alpha -= 0.1; break;

        case GLUT_KEY_LEFT:
            alpha += 0.1; break;

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

        case GLUT_KEY_PAGE_DOWN: radius -= 1.0f;
            if (radius < 1.0f)
                radius = 1.0f;
            break;

        case GLUT_KEY_PAGE_UP: radius += 1.0f; break;
    }
    spherical2Cartesian();
    glutPostRedisplay();

}


void processKeys(unsigned char key, int xx, int yy) {

    switch(key) {

        case 'f':
            glPolygonMode(GL_FRONT, GL_FILL);
            break;
        case 'l':
            glPolygonMode(GL_FRONT, GL_LINE);
            break;
    }
}



void processMouseButtons(int button, int state, int xx, int yy) {

	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
		else
			tracking = 0;
	}
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha += (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {

			r -= yy - startY;
			if (r < 3)
				r = 3.0;
		}
		tracking = 0;
	}
}


void processMouseMotion(int xx, int yy) {

	int deltaX, deltaY;
	int alphaAux, betaAux;
	int rAux;

	if (!tracking)
		return;

	deltaX = xx - startX;
	deltaY = yy - startY;

	if (tracking == 1) {


		alphaAux = alpha + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0)
			betaAux = 85.0;
		else if (betaAux < -85.0)
			betaAux = -85.0;

		rAux = r;
	}
	else if (tracking == 2) {

		alphaAux = alpha;
		betaAux = beta;
		rAux = r - deltaY;
		if (rAux < 3)
			rAux = 3;
	}
	camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camY = rAux * 							     sin(betaAux * 3.14 / 180.0);
}

void init() {

    //---------------------------------------------------------
    //Load the height map "terreno.jpg"

    //Num = nr of images to load
    ilGenImages(1, &t);
    ilBindImage(t);

    ilLoadImage((ILstring) "terreno.jpg");

    ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);

    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);

    //imageData = linear array with the pixel values
    imageData = ilGetData();

    //---------------------------------------------------------
    //Build the vertex arrays

    gridVertices = (float*) malloc(sizeof(float) * tw * th * 2 * 3);

    int off_x = 0, off_z = 0;

    float half = (float) tw / 2;

    for (int vert = 0; vert < (tw * th * 2 * 3);) {

        //----------------------------------------------------
        //P0

        //Px
        gridVertices[vert++] = -half + 0.5 + off_x;
        //Py
        gridVertices[vert++] = ((int)imageData[off_x + off_z]) - 50;
        //Pz
        gridVertices[vert++] = -half + 0.5 + off_z;

        //----------------------------------------------------
        //P1

        //Px
        gridVertices[vert++] = -half + 0.5 + off_x;
        //Py
        gridVertices[vert++] = ((int)imageData[off_x + off_z * tw]) - 50;
        //Pz
        gridVertices[vert++] = -half + 0.5 + off_z + 1;

        //----------------------------------------------------

        off_x++;

        if (off_x == tw) {
            off_x = 0;
            off_z++;
        }

    }

    //---------------------------------------------------------
    //OpenGL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
    //glEnable(GL_LINE_SMOOTH);

    //---------------------------------------------------------
	//VBO initialization

    glEnableClientState(GL_VERTEX_ARRAY);

    glGenBuffers(1, buffers);

    glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, tw * th * 2 * 3 * sizeof(float), gridVertices, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT,0,0);

}


int main(int argc, char **argv) {

    system("clear");

    // init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("CG@DI-UM");

    // Required callback registry
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

    // Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
    glutSpecialFunc(processSpecialKeys);

	//Ver melhor
    glewInit();

    //Init DevIL
    ilInit();

    //load image, array pixels, ...
	init();

    // enter GLUT's main cycle
    glutMainLoop();

	return 0;
}
