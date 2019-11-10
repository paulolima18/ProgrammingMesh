#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

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
float a=0.1f,b=0.5f,r=10.0f;
/*	float r=0,g=0,b=0;
	float d = M_PI/slices; //degree
	for (int i = 1; i <= slices; i++)
	{
		glColor3f(1,1,1);//white
		glBegin(GL_TRIANGLES);//bot
			glVertex3f(radius*cos(2*d*i),(-height/2),radius*sin(2*d*i));
			glVertex3f(radius*cos(2*d*(i-1)),(-height/2),radius*sin(2*d*(i-1)));
			glVertex3f(0.0f,(-height/2),0.0f);
		glEnd();

		glColor3f(1,0,0);//red
		glBegin(GL_TRIANGLES);//middle/2
			glVertex3f(radius*cos(2*d*i),(-height/2),radius*sin(2*d*i));
			glVertex3f(radius*cos(2*d*(i-1)),(-height/2),radius*sin(2*d*(i-1)));
			glVertex3f(radius*cos(2*d*i),(height/2),radius*sin(2*d*i));
		glEnd();

		glColor3f(0,1,0);//green
		glBegin(GL_TRIANGLES);//middle/2
			glVertex3f(radius*cos(2*d*i),(height/2),radius*sin(2*d*i));
			glVertex3f(radius*cos(2*d*(i-1)),(-height/2),radius*sin(2*d*(i-1)));
			glVertex3f(radius*cos(2*d*(i-1)),(height/2),radius*sin(2*d*(i-1)));
		glEnd();

		glColor3f(0,1,1);//cyan
		glBegin(GL_TRIANGLES);//top
			glVertex3f(radius*cos(2*d*i),(height/2),radius*sin(2*d*i));
			glVertex3f(radius*cos(2*d*(i-1)),(height/2),radius*sin(2*d*(i-1)));
			glVertex3f(0.0f,(height/2),0.0f);
		glEnd();
	}*/
void drawCylinder(float radius, float height, int slices)
{
	float r=0,g=0,b=0;
	float d = M_PI/slices; //degree
	d *=2;
	for (int i = 1; i <= slices; i++)
	{
		glColor3f(1,1,1);//white
		glBegin(GL_TRIANGLES);//bot
			glVertex3f(radius*cos(d*(i-1)),(-height/2),radius*sin(d*(i-1)));
			glVertex3f(radius*cos(d*i),(-height/2),radius*sin(d*i));
			glVertex3f(0.0f,(-height/2),0.0f);
		glEnd();

		glColor3f(1,0,0);//red
		glBegin(GL_TRIANGLES);//middle/2
			glVertex3f(radius*cos(d*i),(-height/2),radius*sin(d*i));
			glVertex3f(radius*cos(d*(i-1)),(-height/2),radius*sin(d*(i-1)));
			glVertex3f(0.0f,(height/2),0.0f);
		glEnd();

	}
}

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(r*sin(a)*cos(b),r*sin(b),r*cos(a)*cos(b),
		      0.0f,0.0f,0.0f,
			  0.0f,1.0f,0.0f);

	glPolygonMode(GL_FRONT,GL_LINE);
	//drawCylinder(2,4,50);
	glutWireCone(1,2,360,360);
	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy)
{
	// put code to process regular keys in here
	switch (c)
	{
		case 'a':
			a=a-0.1f;
			break;
		case 'd':
			a=a+0.1f;
			break;
		case 'w':
			b=b+0.1f;
			break;
		case 's':
			b=b-0.1f;
			break;
		default:
			break;
	}
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
	glutCreateWindow("Camera");

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
