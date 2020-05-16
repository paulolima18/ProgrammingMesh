#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

float size = 0.0;
float change = 0.0;
float seconds;

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

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,
		      0.0,0.0,-1.0,
			  0.0f,1.0f,0.0f);

    // put drawing instructions here
    seconds = static_cast<float>(glutGet(GLUT_ELAPSED_TIME)) / 1000;
    // std::cout << seconds << '\n';
    seconds = sin(seconds);
    if(seconds < 0)
        seconds = -seconds;
    size = seconds;

    glutWireTeapot(size);

	// End of frame
	glutSwapBuffers();
}




int main(int argc, char **argv) {

// put GLUT init here
    glutInit(&argc, argv);

// put callback registration here
    glutInitDisplayMode(GLUT_DEPTH);
    glutInitWindowPosition(500,500);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI");
    glutDisplayFunc( renderScene );
    glutReshapeFunc( changeSize );
    glutIdleFunc( renderScene );

// OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f,0.0f,0.0f,0.0f);

// enter GLUT's main loop
	glutMainLoop();

	return 1;
}
