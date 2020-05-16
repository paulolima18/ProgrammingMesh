
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

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

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

float camX = 0.0f, camY = 0.0f, camZ = 0.0f, radius = 100.0f;
float upX = 0.0f, upY = 1.0f, upZ = 0.0f;
int startX, startY, tracking = 0;
int alfa = 0, beta = 45, r = 50;
float alphaCam = 0.0f;

//----------------------------------------------------------------------------------------------------------------------
//Camera placement

float eyeHeight = 12.0f;

float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;

//Move foward/backwards
float kFB = 0.0f;
float kSD = 0.0f;

float Dx = 0.0f, Dy = 0.0f, Dz = 0.0f;
float Rx = 0.0f, Ry = 0.0f, Rz = 0.0f;

//----------------------------------------------------------------------------------------------------------------------

//Image properties and pixel density array
unsigned int t, tw, th;
unsigned char *imageData;

//Grid vertices
float* gridVertices;

//VBOs
GLuint buffers[1];

//----------------------------------------------------------------------------------------------------------------------

//Teapot rotation angles
float alfa_inner_teapots = 0.0f;
float alfa_outer_teapots = 0.0f;

//Tree positions
vector<float> treePositions;

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//Calcular a altura

float height(int x, int z) {

    int x_min = -floor(tw/2);
    int z_min = -floor(th/2);

    //return (imageData[abs(x) + abs(z) * tw]) * (100.0/255.0);
    return imageData[(x-x_min) * tw + (z-z_min)] * (100.0/255.0);
}

float hf(float px, float pz) {

    float x1 = floor(px);
    float x2 = x1 + 1;
    float z1 = floor(pz);
    float z2 = z1 + 1;

    float fz = pz - z1;
    float h_x1_z = height(x1, z1) * (1 - fz) + height(x1, z2) * fz;
    float h_x2_z = height(x2, z1) * (1 - fz) + height(x2, z2) * fz;

    float fx = x1 - px;

    float height_xz = h_x1_z * (1 - fx) + h_x2_z * fx;

    return height_xz;
}

//----------------------------------------------------------------------------------------------------------------------

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

void drawTree(float pos_x, float pos_y, float pos_z) {

    glPushMatrix();

    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

        glColor3f(0.5f, 0.35f, 0.05f);
        glutSolidCone(1.0f, 5.0f, 5, 4);

        glPushMatrix();

            glColor3f(0.0f, 0.502f, 0.0f);
            glTranslatef(0.0f, 0.0f, 3.5f);
            glutSolidCone(4.0f, 10.0f, 5, 5);

        glPopMatrix();

    glPopMatrix();
}

void drawCircleTeapotFacedOutside(int teapot_size,
                                  int radius,
                                  int nr_teapots,
                                  float color_x, float color_y, float color_z,
                                  int flag) {
    glColor3f(color_x, color_y, color_z);

    float alpha = (2.0f * M_PI)/nr_teapots;
    float offset = 360.0f / nr_teapots;

    for(int i = 0; i < nr_teapots; i++) {

        glPushMatrix();

        float x = radius * sin(i * alpha);
        float z = radius * cos(i * alpha);
        float y = hf(x, z);

        if (!flag) {
            glTranslatef(x,
                         1.5f + y,
                         z);
            glRotatef(-(90.0f - offset * i), 0.0f, 1.0f, 0.0f);
        } else {
            glTranslatef(x,
                         1.5f + y,
                         z);
            glRotatef((90.0f - offset * i), 0.0f, 1.0f, 0.0f);
        }
        glutSolidTeapot(teapot_size);
        glPopMatrix();
    }
}

//----------------------------------------------------------------------------------------------------------------------

void printInfo() {

    cout << endl << "Comandos disponiveis:" << endl;
    cout << "\tW | A | S | D : movimentar;" << endl;
    cout << "\tq | e : Rotação" << endl;
    cout << "\tl | f : glPolygonMode(GL_FRONT, GL_LINE | GL_FILL);" << endl;
}

//----------------------------------------------------------------------------------------------------------------------

void renderScene(void) {

    //------------------------------------------------------------------------------------------------------------------
    //Camera settings

	float pos[4] = {-1.0, 1.0, 1.0, 0.0};

	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

    //------------------------------------------------------------------------------------------------------------------
    //Foward/Backward motion

    //Camera Placement
    camY = eyeHeight + hf(camX, camZ);

    //Camera Orientation
    centerX = (camX + sin(alphaCam));
    centerY = camY;
    centerZ = (camZ + cos(alphaCam));

    //------------------------------------------------------------------------------------------------------------------

	gluLookAt(camX, camY, camZ,
		      centerX, centerY, centerZ,
			  upX, upY,upZ);

	kSD = kFB = 0;

    //------------------------------------------------------------------------------------------------------------------
    //Draw from pl06 - TERRENO
    //------------------------------------------------------------------------------------------------------------------

	//Desenhar o terreno
	glPushMatrix();
	    glColor3f(0.2,0.3,0);
	    drawTerrain();
    glPopMatrix();

	// just so that it renders something before the terrain is built
	// to erase when the terrain is ready
	//glutWireTeapot(2.0);

	//------------------------------------------------------------------------------------------------------------------
    //Draw from pl05 - TEAPOTS, ARVORES, ...
    //------------------------------------------------------------------------------------------------------------------

    //Draw the middle torus
    glPushMatrix();
        float pos_y = hf(0.0f, 0.0f);
        glTranslatef(0.0f, pos_y, 0.0f);
        glColor3f(1.0f, 0.0f, 1.0f);
        glutSolidTorus(1.0f, 3.0f, 20, 20);
    glPopMatrix();

    //------------------------------------------------------------------------------------------------------------------

    //Aumentar o angulo de rotacao dos teapots
    alfa_inner_teapots -= 0.8f;
    alfa_outer_teapots += 0.8f;

    //Radius 15
    glPushMatrix();
        glRotatef(alfa_inner_teapots, 0.0f, 1.0f, 0.0f);
        drawCircleTeapotFacedOutside(2.0f, 15.0f, 8, 0.0f, 0.0f, 1.0f, 0);
    glPopMatrix();

    //Radius 35
    glPushMatrix();
        glRotatef(alfa_outer_teapots, 0.0f, 1.0f, 0.0f);
        drawCircleTeapotFacedOutside(2.0f, 35.0f, 16, 1.0f, 0.0f, 0.0f, 1);
    glPopMatrix();

    //------------------------------------------------------------------------------------------------------------------
    //Draw all trees


    for(auto it = treePositions.begin(); it != treePositions.end(); it+=3) {

        drawTree(*(it.base()), *((it+1).base()), *((it+2).base()));
    }

    //-----------------------------------------------------------------------

    // End of frame
	glutSwapBuffers();
}

//----------------------------------------------------------------------------------------------------------------------

void spherical2Cartesian() {

    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
}

//---------------------------------------------------------------------------------------------------------------------

void processSpecialKeys(int key, int xx, int yy) {

    switch (key) {

        case GLUT_KEY_RIGHT:
            alphaCam -= 0.1; break;

        case GLUT_KEY_LEFT:
            alphaCam += 0.1; break;

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

//----------------------------------------------------------------------------------------------------------------------

void processKeys(unsigned char key, int xx, int yy) {

    if (tolower(key) == 'f') {

        glPolygonMode(GL_FRONT, GL_FILL);

    }

    if (tolower(key) == 'l') {

        glPolygonMode(GL_FRONT, GL_LINE);

    }

    if (tolower(key) == 'w') {

        kFB = 0.9f;

        //Foward/Backward motion
        Dx = centerX - camX;
        Dy = 0.0f;
        Dz = centerZ - camZ;

        camX += kFB * Dx;
        camY += kFB * Dy;
        camZ += kFB * Dz;

        centerX += kFB * Dx;
        centerY += kFB * Dy;
        centerZ += kFB * Dz;

    }

    if (tolower(key) == 's') {

        kFB = -0.9f;

        //Foward/Backward motion
        Dx = centerX - camX;
        Dy = 0.0f;
        Dz = centerZ - camZ;

        camX += kFB * Dx;
        camY += kFB * Dy;
        camZ += kFB * Dz;

        centerX += kFB * Dx;
        centerY += kFB * Dy;
        centerZ += kFB * Dz;

    }

    if (tolower(key) == 'a') {

        kSD = -0.9f;

        Rx = Dy * upZ - Dz * upY;
        Ry = Dz * upX - Dx * upZ;
        Rz = Dx * upY - Dy * upX;

        camX += kSD * Rx;
        camY += kSD * Ry;
        camZ += kSD * Rz;

        centerX += kSD * Rx;
        centerY += kSD * Ry;
        centerZ += kSD * Rz;

    }

    if (tolower(key) == 'd') {

        kSD = 0.9f;

        Rx = Dy * upZ - Dz * upY;
        Ry = Dz * upX - Dx * upZ;
        Rz = Dx * upY - Dy * upX;

        camX += kSD * Rx;
        camY += kSD * Ry;
        camZ += kSD * Rz;

        centerX += kSD * Rx;
        centerY += kSD * Ry;
        centerZ += kSD * Rz;

    }

    if (tolower(key) == 'q') {

        alphaCam -= M_PI/64;

    }

    if (tolower(key) == 'e') {

        alphaCam += M_PI/64;
    }

}

//----------------------------------------------------------------------------------------------------------------------

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
            alphaCam += (xx - startX);
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

//----------------------------------------------------------------------------------------------------------------------

void processMouseMotion(int xx, int yy) {

	int deltaX, deltaY;
	int alphaAux, betaAux;
	int rAux;

	if (!tracking)
		return;

	deltaX = xx - startX;
	deltaY = yy - startY;

	if (tracking == 1) {


		alphaAux = alphaCam + deltaX;
		betaAux = beta + deltaY;

		if (betaAux > 85.0)
			betaAux = 85.0;
		else if (betaAux < -85.0)
			betaAux = -85.0;

		rAux = r;
	}
	else if (tracking == 2) {

		alphaAux = alphaCam;
		betaAux = beta;
		rAux = r - deltaY;
		if (rAux < 3)
			rAux = 3;
	}
	camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
	camY = rAux * 							     sin(betaAux * 3.14 / 180.0);
}

//----------------------------------------------------------------------------------------------------------------------
//Inicializar a imagem num array de bytes, triangulos do terreno e VBOs

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

        float P0x = -half + 0.5 + off_x;
        float P0z = -half + 0.5 + off_z;
        float P0y = height(P0x, P0z);

        gridVertices[vert++] = P0x;
        gridVertices[vert++] = P0y;
        gridVertices[vert++] = P0z;

        //----------------------------------------------------
        //P1

        float P1x = -half + 0.5 + off_x;
        float P1z = -half + 0.5 + off_z + 1;
        float P1y = height(P1x, P1z);

        gridVertices[vert++] = P1x;
        gridVertices[vert++] = P1y;
        gridVertices[vert++] = P1z;

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
	//VBOs initialization

    glEnableClientState(GL_VERTEX_ARRAY);

    glGenBuffers(1, buffers);

    glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, tw * th * 2 * 3 * sizeof(float), gridVertices, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT,0,0);

}

//----------------------------------------------------------------------------------------------------------------------
//Gerar um float random

float float_rand( float min, float max ) {

    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

//----------------------------------------------------------------------------------------------------------------------
//Distância cartersiana entre dois pontos

float distance_to_origin(float pos_x, float pos_z) {
    return sqrtf(pow(pos_x, 2) + pow(pos_z, 2));
}

//----------------------------------------------------------------------------------------------------------------------
//Gerar as posições das árvores

void generate_tree_pos(int nr_trees) {

    int valid_trees = 0;
    int lower = -100.0f, upper = 100.0f;
    float pos_x, pos_y, pos_z;

    while(valid_trees < nr_trees) {

        pos_x = float_rand(lower, upper);
        pos_z = float_rand(lower, upper);
        pos_y = hf(pos_x, pos_z);

        if (distance_to_origin(pos_x, pos_z) > 50.0f) {

            //Push X position
            treePositions.push_back(pos_x);
            //Push Y position
            treePositions.push_back(pos_y);
            //Push Z position
            treePositions.push_back(pos_z);

            valid_trees++;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

int main(int argc, char **argv) {

    //------------------------------------------------------------------------------------------------------------------

    //Clear the screen
    system("clear");

    //------------------------------------------------------------------------------------------------------------------

    //Set the seed to generate random float
    time_t t;
    srand((unsigned) time(&t));

    //------------------------------------------------------------------------------------------------------------------

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

    //------------------------------------------------------------------------------------------------------------------

	//Inicializar o gewl
    glewInit();

    //Inicializar o DevIL
    ilInit();

    //Carregar a imagem do terreno e gerar o array de posições para as alturas
	init();

    //Generate random positions for trees
    generate_tree_pos(300);

    printInfo();

    // enter GLUT's main cycle
    glutMainLoop();

    //------------------------------------------------------------------------------------------------------------------

	return 0;
}

