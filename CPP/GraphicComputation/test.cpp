#include <GL/glut.h>
#include <stdio.h>

float posX,posY,posZ = 0;

void triangle(void)
{
  glBegin(GL_POLYGON);
  glVertex2f(-0.1, -0.2);
  glVertex2f(-0.1, 0.2);
  glVertex2f(0.1, 0.2);
  glVertex2f(0.1, -0.2);
  glEnd();
}
void displayMe(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(posX,posY,posZ);
  triangle();
  glPopMatrix();
  glFlush();
}
float move_unit = 0.1f;
void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutSpecialFunc(keyboardown);
    glutMainLoop();
    return 0;
}
//compile code with
//g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL
