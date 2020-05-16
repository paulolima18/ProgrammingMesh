#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

float radius = 5.0f;
float degree_B = 0.0f;
float degree_A = 0.0f;
float degree_x = 0.0f;
float px = radius * cos(degree_B) * sin(degree_A);
float py = radius * sin(degree_B);
float pz = radius * cos(degree_B) * cos(degree_A);
float lx = 0.0f;
float ly = 0.0f;
float lz = 0.0f;
float ux = 0.0f;
float uy = 1.0f;
float uz = 0.0f;

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


void drawCylinder(float radius, float height, int slices) {

    float _temp_A = 2*M_PI/slices;
    // float _temp_B = height/radius;

// put code to draw cylinder in here
    glRotatef(degree_x, 0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    for(int i=0; i < slices;i++) {
        // green
        glVertex3f( 0.0f, 0.0f, 0.0f);
        glVertex3f( radius * sin(_temp_A*(i+1)), 0.0f, radius * cos(_temp_A*(i+1)));
        glVertex3f( radius * sin(_temp_A*i), 0.0f, radius * cos(_temp_A*i));
    }

    glColor3f(0.0f, 1.0f, 1.0f);
    for(int i=0; i < slices;i++) {
        // blue
        glVertex3f( radius * sin(_temp_A*(i+1)), height, radius * cos(_temp_A*(i+1)));
        glVertex3f( 0.0f, height, 0.0f);
        glVertex3f( radius * sin(_temp_A*i), height, radius * cos(_temp_A*i));
    }

    glColor3f(1.0f, 0.0f, 1.0f);
    for(int i=0; i < slices;i++) {
        // red
        glVertex3f( radius * sin(_temp_A*i), height, radius * cos(_temp_A*i));
        glVertex3f( radius * sin(_temp_A*i), 0.0f, radius * cos(_temp_A*i));
        glVertex3f( radius * sin(_temp_A*(i+1)), 0.0f, radius * cos(_temp_A*(i+1)));

        glVertex3f( radius * sin(_temp_A*i), height, radius * cos(_temp_A*i));
        glVertex3f( radius * sin(_temp_A*(i+1)), 0.0f, radius * cos(_temp_A*(i+1)));
        glVertex3f( radius * sin(_temp_A*(i+1)), height, radius * cos(_temp_A*(i+1)));
    }

    glEnd();
}

void referencial()
{
    glBegin(GL_LINES);
    // X axis in red
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-100.0f, 0.0f, 0.0f);
        glVertex3f( 100.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, -100.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, -100.0f);
        glVertex3f(0.0f, 0.0f,  100.0f);
    glEnd();

}

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(px, py, pz,
		      lx, ly, lz,
			  ux, uy, uz);



	drawCylinder(1,2,20);
	// End of frame
	glutSwapBuffers();
}

float alpha = 0.0f;
float beta = 0.0f;
void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here
    switch (c)
    {
        case 'a':
            if(beta < M_PI/2)
                beta+=0.1f;
            break;
        case 'd':
            if(beta > -M_PI/2)
                beta-=0.1f;
            break;
        case 's':
            alpha += 0.1f;
            break;
        case 'w':
            alpha -= 0.1f;
            break;
        case 'r':
            degree_x +=2.0f;
            break;
        case 'z':
            px = 5.0f;
            py = 5.0f;
            pz = 5.0f;
            break;
        case 'f'://fill view
            glPolygonMode(GL_FRONT,GL_FILL);
            break;
        case 'l'://line view
            glPolygonMode(GL_FRONT,GL_LINE);
            break;
        case 'p'://point view
            glPolygonMode(GL_FRONT,GL_POINT);
    }
    px = radius * cos(beta) * sin(alpha);
    py = radius * sin(beta);
    pz = radius * cos(beta) * cos(alpha);
    glutPostRedisplay();
}


void processSpecialKeys(int key, int xx, int yy) {

// put code to process special keys in here

}


int main(int argc, char **argv) {

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
	glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
