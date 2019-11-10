#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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

void draw(void)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0,800,0.0,800);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0,1,1);//yellow

	void * font = GLUT_BITMAP_9_BY_15;
	glRasterPos2i(440,10);
	glutBitmapCharacter(font,'R');
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

}

float degree = 0;
float x=0,y=0,z = 0;
float size=1.0f;

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// set the camera
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here
	glTranslatef(x,y,z);
	glRotatef(degree,0.0f,1.0f,0.0f);
	glScalef(size,size,size);
	//gluLookAt(5.0,5.0,5.0, 0.0f,0.0f,0.0f, 0.0f,1.0f,0.0f);

// put drawing instructions here
	glColor3f(1,1,1);//white
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
	glEnd();
	glColor3f(1,0,0);//red
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,1.0f+z);
	glEnd();
	glColor3f(0,1,1);//cyan
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(0.0f+x,2.0f+y,0.0f+z);//top
		glVertex3f(-1.0f+x,0.0f+y,1.0f+z);
	glEnd();
	glColor3f(0,1,0);//green
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(0.0f+x,2.0f+y,0.0f+z);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
	glEnd();
	glColor3f(0,0,1);//blue
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f+x,2.0f+y,0.0f+z);
		glVertex3f(1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
	glEnd();
	glColor3f(1,1,0);//yellow
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f+x,2.0f+y,0.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,1.0f+z);
	glEnd();

	glColor3f(1,1,1);//white
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
	glEnd();
	glColor3f(1,0,0);//red
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,1.0f+z);
	glEnd();
	glColor3f(0,1,1);//cyan
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(0.0f+x,-2.0f+y,0.0f+z);//top
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
	glEnd();
	glColor3f(0,1,0);//green
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f+x,0.0f+y,1.0f+z);
		glVertex3f(0.0f+x,-2.0f+y,0.0f+z);
		glVertex3f(1.0f+x,0.0f+y,-1.0f+z);
	glEnd();
	glColor3f(0,0,1);//blue
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(0.0f+x,-2.0f+y,0.0f+z);
	glEnd();
	glColor3f(1,1,0);//yellow
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f+x,0.0f+y,-1.0f+z);
		glVertex3f(0.0f+x,-2.0f-y,0.0f+z);
		glVertex3f(-1.0f+x,0.0f+y,1.0f+z);
	glEnd();


	// End of frame
	glutSwapBuffers();
}


// write function to process keyboard events
void move(unsigned char key,int mx,int my)
{
	switch (key)
	{
		case 'a':
			x=x-0.1f;
			break;
		case 'd':
			x=x+0.1f;
			break;
		case 's':
			z=z+0.1f;
			break;
		case 'w':
			z=z-0.1f;
			break;
		case 'f'://fill view
			glPolygonMode(GL_FRONT,GL_FILL);
			break;
		case 'l'://line view
			glPolygonMode(GL_FRONT,GL_LINE);
			break;
		case 'p'://point view
			glPolygonMode(GL_FRONT,GL_POINT);
			break;
		case 'r'://rotate
			degree = degree+1.0f;
			break;
		case 'b'://size +
			size = size+0.1f;
			break;
		case 'm'://size -
			size = size-0.1f;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}






int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("input");

// Required callback registry
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);


// put here the registration of the keyboard callbacks
	glutKeyboardFunc(move);
	//glutMouseFunc();
//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
