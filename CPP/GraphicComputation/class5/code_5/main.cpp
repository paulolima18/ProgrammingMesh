#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

/*-------------------------------------------------------------------------------*/

float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;

float alfa_inner_teapots = 0.0f;
float alfa_outer_teapots = 0.0f;

vector<float> treePositions;

/*-------------------------------------------------------------------------------*/

void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
}

void drawAxis() {

    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-50.0f, 0.0f, 0.0f);
    glVertex3f( 50.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -50.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -50.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd();
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

        if (!flag) {
            glTranslatef(radius * sin(i * alpha),
                         1.5f,
                         radius * cos(i * alpha));
            glRotatef(-(90.0f - offset * i), 0.0f, 1.0f, 0.0f);
        } else {
            glTranslatef(radius * cos(i * alpha),
                         1.5f,
                         radius * sin(i * alpha));
            glRotatef((90.0f - offset * i), 0.0f, 1.0f, 0.0f);
        }
        glutSolidTeapot(teapot_size);
        glPopMatrix();
    }
}

void drawTree(float pos_x, float pos_z) {

    glPushMatrix();
    glTranslatef(pos_x, 0.0f, pos_z);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    glColor3f(0.5f, 0.35f, 0.05f);
    glutSolidCone(1.0f, 5.0f, 5, 4);

    glColor3f(0.0f, 0.502f, 0.0f);
    glTranslatef(0.0f, 0.0f, 3.5f);
    glutSolidCone(4.0f, 10.0f, 5, 5);
    glPopMatrix();
}

void renderScene(void) {

    alfa_inner_teapots -= 0.8f;
    alfa_outer_teapots += 0.8f;

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	/*------------------------------------------------------------------------*/

	//Draw the green floor
	glColor3f(0.2f, 0.8f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);

		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);
		glVertex3f(100.0f, 0, 100.0f);
	glEnd();

    /*------------------------------------------------------------------------*/

    //Draw the middle torus
    glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidTorus(1.0f, 3.0f, 20, 20);

    /*------------------------------------------------------------------------*/

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

    /*------------------------------------------------------------------------*/
    //Draw all trees

    for(auto it = treePositions.begin(); it != treePositions.end(); it+=2) {

        drawTree(*(it.base()), *((it+1).base()));
    }

    /*------------------------------------------------------------------------*/

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

	case GLUT_KEY_PAGE_DOWN: radius -= 1.0f;
		if (radius < 1.0f)
			radius = 1.0f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 1.0f; break;
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

float float_rand( float min, float max ) {

    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

float distance_to_origin(float pos_x, float pos_z) {
    return sqrtf(pow(pos_x, 2) + pow(pos_z, 2));
}

void generate_tree_pos(int nr_trees) {

    int valid_trees = 0;
    int lower = -100.0f, upper = 100.0f;
    float pos_x, pos_z;
    while(valid_trees < nr_trees) {

        pos_x = float_rand(lower, upper);
        pos_z = float_rand(lower, upper);

        if (distance_to_origin(pos_x, pos_z) > 50.0f) {

            //Push X position
            treePositions.push_back(pos_x);
            //Push Z position
            treePositions.push_back(pos_z);

            valid_trees++;
        }
    }
}

int main(int argc, char **argv) {

    srand(time(NULL));

    generate_tree_pos(300);

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");

// Required callback registry
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	spherical2Cartesian();

	printInfo();

    glutIdleFunc(renderScene);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
