/* main.cpp
 * 
 * Calculus Graph
 *
 * Copyright (C) 2012 Nick Lauber
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

// Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include <gl/glut.h>
#include "text.h"
#include "func.h"
#include "integ.h"

// Define coordinate grid & display width/height
const GLint displayWidth = 800;
const GLint displayHeight = 600;
GLdouble objectLeft = -250;
GLdouble objectRight = 550;
GLdouble objectLower = -250;
GLdouble objectUpper = 350;

unsigned char calcFrameBuffer[displayWidth][displayHeight][3];

// Define Graph Colors & Previous Mouse Location
GLfloat glVertexColor[][4] = { {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.7, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 1.0} };

// Pixel Drawing Method
void drawPixel(GLdouble x, GLdouble y)
{
	glBegin(GL_POINTS);
		glVertex2f(x * 20, y * 20);
	glEnd();
}

void putPixel(int x, int y, int r, int g, int b)
{
	unsigned char *p;

	if ((x < 0) || (y < 0) || (displayWidth <= x) || (displayHeight <= y))
		return;

	p = (unsigned char *) calcFrameBuffer + 3 * x + y * (3 * displayWidth);

	*p = r;
	p++;

	*p = g;
	p++;

	*p = b;
}

void getPixel(int x, int y, int *r, int *g, int *b)
{
	unsigned char *p;

	if ((x < 0) || (y < 0) || (displayWidth <= x) || (displayHeight <= y))
	{
		*r = 0;
		*g = 0;
		*b = 0;
	}
	else
	{
		p = (unsigned char *) calcFrameBuffer + 3 * x + y * (3 * displayWidth);
		*r = (unsigned char) *p++;
		*g = (unsigned char) *p++;
		*b = (unsigned char) *p;
	}
}

void FloodFill(int x, int y, int r, int g, int b)
{
	int r1, g1, b1;

	getPixel(x,y,&r1,&g1,&b1);

	printf ("R: %d G: %d B: %d\n", r1, g1, b1);

	if ((r1 == 255) && (g1 == 255) && (b1 == 255))
	{
		putPixel(x,y,r,g,b);

		FloodFill(x+1,y,r,g,b);
		FloodFill(x-1,y,r,g,b);
		FloodFill(x,y+1,r,g,b);
		FloodFill(x,y-1,r,g,b);
	}
}

void do_FloodFill(int x, int y, int color)
{
	int r, g, b;
	//int foo;

	r = (int) (glVertexColor[color][0] * 255);
	g = (int) (glVertexColor[color][1] * 255);
	b = (int) (glVertexColor[color][2] * 255);

	glReadPixels(0,0,displayWidth,displayHeight,GL_RGB,GL_UNSIGNED_BYTE,calcFrameBuffer);
	
	for (int j = y-50; j < y + 50; j++)
	{
		for (int i = x-50; i < x + 50; i++)
			printf ("RGB: %d %d %d ", calcFrameBuffer[i][j][0], calcFrameBuffer[i][j][1], calcFrameBuffer[i][j][2]);

		printf ("\n");

		//scanf_s("%d", &foo);
	}
	
	
	//FloodFill(x,y,r,g,b);
	
	
	
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0, 0);
	glDrawPixels(displayWidth,displayHeight,GL_RGB,GL_UNSIGNED_BYTE,calcFrameBuffer);

	glFlush();
}

/*
// Boundary Fill Method
void boundaryFill(double x, double y, int boundaryColor, int newColor)
{
	GLfloat c[][3] = { { 0.0, 0.0, 0.0 } };
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,c);

	if (((c[0][0] != glVertexColor[0][boundaryColor]) &&
		 (c[1][1] != glVertexColor[1][boundaryColor]) &&
		 (c[2][2] != glVertexColor[2][boundaryColor])) &&
		((c[0][0] != glVertexColor[0][newColor]) &&
		 (c[1][1] != glVertexColor[1][newColor]) &&
		 (c[2][2] != glVertexColor[2][newColor])))
	{
		glColor3fv(glVertexColor[newColor]);
		
		drawPixel(x,y);

		boundaryFill(x,y - 1,boundaryColor,newColor);
		boundaryFill(x,y + 1,boundaryColor,newColor);
		boundaryFill(x - 1,y,boundaryColor,newColor);
		boundaryFill(x + 1,y,boundaryColor,newColor);
	}
}
*/

// Initialization of Display
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(objectLeft,objectRight,objectLower,objectUpper);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Draw our function f
void draw_func1(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f1_draw(x) <= 10 && f1_draw(x) >= -10)
		{
			drawPixel(x, f1_draw(x) );
		}

	glBegin(GL_LINES);
		glVertex2f(40,80);
		glVertex2f(40,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f1_deriv(x) <= 10 && f1_deriv(x) >= -10)
		{
			drawPixel(x, f1_deriv(x) );
		}
}

void draw_func2(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f2_draw(x) <= 10 && f2_draw(x) >= -10)
		{
			drawPixel(x, f2_draw(x) );
		}

	glBegin(GL_LINES);
		glVertex2f(40,160);
		glVertex2f(40,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f2_deriv(x) <= 10 && f2_deriv(x) >= -10)
		{
			drawPixel(x, f2_deriv(x) );
		}
}

void draw_func3(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f3_draw(x) <= 10 && f3_draw(x) >= -10)
		{
			drawPixel(x, f3_draw(x) );
		}

	glBegin(GL_LINES);
		glVertex2f(10,40);
		glVertex2f(10,0);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(40,10);
		glVertex2f(40,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f3_deriv(x) <= 10 && f3_deriv(x) >= -10)
		{
			drawPixel(x, f3_deriv(x) );
		}
}

void draw_func4(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f4_draw(x) <= 10 && f3_draw(x) >= -10)
		{
			drawPixel(x, f4_draw(x) );
		}

	glBegin(GL_LINES);
		glVertex2f(M_PI * 20,40);
		glVertex2f(M_PI * 20,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -10; x <= 10; x += 0.0005)
		if (f4_deriv(x) <= 10 && f4_deriv(x) >= -10)
		{
			drawPixel(x, f4_deriv(x) );
		}
}

// Creation Display
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3fv(glVertexColor[0]);

	// Draw the y-axis
	glBegin(GL_LINES);
		glVertex2f(0,200);
		glVertex2f(0,-200);
	glEnd();

	// Draw the x-axis
	glBegin(GL_LINES);
		glVertex2f(200,0);
		glVertex2f(-200,0);
	glEnd();

	draw_func4();

	//do_FloodFill(251,189,3);
	//do_FloodFill(262, 350, 3);
	//do_FloodFill(1, 1, 3);

	// Integrate the function
	int_f1_x();
	int_f2_x();

	glFlush();

	//do_FloodFill(262, displayHeight - 350, 3);
}

void myMouse(int button, int state, int x, int y)
{
	if ((state == GLUT_DOWN) && (button == GLUT_LEFT_BUTTON))
	{
		printf ("x: %d y: %d\n", x, y);
		do_FloodFill(x, y, 3);
	}
}

// Main Executional Code
int main(int argc, char ** argv)
{
	// Init Display & Mouse Functions
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(displayWidth,displayHeight);
	glutInitWindowPosition(150,150);
	glutCreateWindow("Calculus Graph");
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	init();

	glutMainLoop();

	return 0;
}
