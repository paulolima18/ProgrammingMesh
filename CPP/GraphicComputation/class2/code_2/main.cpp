#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

float base1_x = 0;
float base2_x = 1;
float base3_x = 0;
float base4_x = 1;
float top_x = 0.5f;

float base1_y = 0;
float base2_y = 0;
float base3_y = 0;
float base4_y = 0;
float top_y = 1;

float base1_z = 0;
float base2_z = 0;
float base3_z = 1;
float base4_z = 1;
float top_z = 0.5f;

/* Geometric transformations variables */
float x,y,z=0;
float degree_x = 0;
float degree_y = 0;
float size = 1.0f;

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
	gluLookAt(5.0,5.0,5.0,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

    glBegin(GL_LINES);
    // X axis in red
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-100.0f, 0.0f, 0.0f);
        glVertex3f( 100.0f, 0.0f, 0.0f);
    // Y Axis in Green
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -100.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
    // Z Axis in Blue
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -100.0f);
        glVertex3f(0.0f, 0.0f,  100.0f);
    glEnd();

    // put the geometric transformations here
    glTranslatef(x,y,z);
    glRotatef(degree_x, 0.0f, 1.0f, 0.0f);
    glRotatef(degree_y, 1.0f, 0.0f, 0.0f);
    glScalef(size,size,size);

    // put drawing instructions here
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.9f, 0.0f);
        glVertex3f(base1_x, base1_y, base1_z);
        glVertex3f(base2_x, base2_y, base2_z);
        glVertex3f(base4_x, base4_y, base4_z);
    glColor3f(0.5f, 0.8f, 0.5f);
        glVertex3f(base4_x, base4_y, base4_z);
        glVertex3f(base3_x, base3_y, base3_z);
        glVertex3f(base1_x, base1_y, base1_z);
    glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(base3_x, base3_y, base3_z);
        glVertex3f(base4_x, base4_y, base4_z);
        glVertex3f(top_x, top_y, top_z);
    glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(base4_x, base4_y, base4_z);
        glVertex3f(base2_x, base2_y, base2_z);
        glVertex3f(top_x, top_y, top_z);
    glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(base2_x, base2_y, base2_z);
        glVertex3f(base1_x, base1_y, base1_z);
        glVertex3f(top_x, top_y, top_z);
    glColor3f(0.5f, 0.8f, 0.5f);
        glVertex3f(base1_x, base1_y, base1_z);
        glVertex3f(base3_x, base3_y, base3_z);
        glVertex3f(top_x, top_y, top_z);
    glEnd();
    fps();
	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events
void move(unsigned char key,int mx,int my)
{
    switch (key)
    {
        case 'a':
            x-=0.1f;
            break;
        case 's':
            z+=0.1f;
            break;
        case 'd':
            x+=0.1f;
            break;
        case 'w':
            z-=0.1f;
            break;
        case 'r':
            degree_x+=2.0f;
            break;
        case 'y':
            degree_y+=2.0f;
            break;
        case '+':
            top_y+=0.1f;
            break;
        case '-':
            top_y-=0.1f;
            break;
        case 'b':
            size-=0.1f;
            break;
        case 'm':
            size+=0.1f;
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
    glutPostRedisplay();
}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1920,1080);
	glutCreateWindow("TRIANGULO");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

// Required callback registry
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);


// put here the registration of the keyboard callbacks
    glutKeyboardFunc(move);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
