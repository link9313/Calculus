// A sample opengl program that generates a display with default size but changes background color to white

#include <GL/glut.h>

void init (void)
{
	glClearColor(1.0,1.0,1.0,1.0);
}

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Create a window with defaults");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
