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
GLdouble objectLeft = -400;
GLdouble objectRight = 400;
GLdouble objectLower = -250;
GLdouble objectUpper = 350;

// Define Graph Colors
GLfloat glVertexColor[][4] = { {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.7, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 1.0} };

// Define Keyboard elements
int func_num = 0;

// glut keyboard function callback registered on key press (not release)
// Returned values: key pressed
void keys(unsigned char key, int x, int y)
{
	if		(key == '0') func_num = 0;
	else if	(key == '1') func_num = 1;
	else if (key == '2') func_num = 2;
	else if (key == '3') func_num = 3;
	else if (key == '4') func_num = 4;
	else if (key == 27) exit(0);
	else if (key == 'q') exit(0);
	glutPostRedisplay();
}

// Pixel Drawing Method
void drawPixel(GLdouble x, GLdouble y)
{
	glBegin(GL_POINTS);
		glVertex2f(x * 25, y * 25);
	glEnd();
}

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

	for (float x = -8; x <= 8; x += 0.0005)
		if (f1_draw(x) <= 8 && f1_draw(x) >= -8)
		{
			drawPixel(x, f1_draw(x) );
		}

	glColor3fv(glVertexColor[3]);

	glBegin(GL_LINES);
		glVertex2f(50,100);
		glVertex2f(50,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f1_deriv(x) <= 8 && f1_deriv(x) >= -8)
		{
			drawPixel(x, f1_deriv(x) );
		}
}

void draw_func2(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f2_draw(x) <= 8 && f2_draw(x) >= -8)
		{
			drawPixel(x, f2_draw(x) );
		}

	glColor3fv(glVertexColor[3]);

	glBegin(GL_LINES);
		glVertex2f(50,200);
		glVertex2f(50,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f2_deriv(x) <= 8 && f2_deriv(x) >= -8)
		{
			drawPixel(x, f2_deriv(x) );
		}
}

void draw_func3(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f3_draw(x) <= 8 && f3_draw(x) >= -8)
		{
			drawPixel(x, f3_draw(x) );
		}

	glColor3fv(glVertexColor[3]);

	glBegin(GL_LINES);
		glVertex2f(12.5,50);
		glVertex2f(12.5,0);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(50,12.5);
		glVertex2f(50,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f3_deriv(x) <= 8 && f3_deriv(x) >= -8)
		{
			drawPixel(x, f3_deriv(x) );
		}
}

void draw_func4(void)
{
	glColor3fv(glVertexColor[1]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f4_draw(x) <= 8 && f3_draw(x) >= -8)
		{
			drawPixel(x, f4_draw(x) );
		}

	glColor3fv(glVertexColor[3]);

	glBegin(GL_LINES);
		glVertex2f(M_PI * 25,50);
		glVertex2f(M_PI * 25,0);
	glEnd();

	glColor3fv(glVertexColor[2]);

	for (float x = -8; x <= 8; x += 0.0005)
		if (f4_deriv(x) <= 8 && f4_deriv(x) >= -8)
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

	if (func_num == 0)
	{
		display_text(-125, 330, 3, "Welcome to Calculus Graph!");
		display_text(-325, 290, 3, "Pressing 0 will bring up this screen.");
		display_text(-325, 270, 3, "Pressing 1 will bring up the x^2 function.");
		display_text(-325, 250, 3, "Pressing 2 will bring up the x^3 function.");
		display_text(-325, 230, 3, "Pressing 3 will bring up the x^(-1) function.");
		display_text(-325, 210, 3, "Pressing 4 will bring up the sin (2 * x) + 2 function.");
	}

	else if (func_num == 1)
	{
		draw_func1();
		int_f1_x();
		int_f1_disks();
		int_f1_shells();
	}
	else if (func_num == 2)
	{
		draw_func2();
		int_f2_x();
		int_f2_disks();
		int_f2_shells();
	}
	else if (func_num == 3)
	{
		draw_func3();
		int_f3_x();
		int_f3_disks();
		int_f3_shells();
	}
	else if (func_num == 4)
	{
		draw_func4();
		int_f4_x();
		int_f4_disks();
		int_f4_shells();
	}

	glFlush();
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
	glutKeyboardFunc(keys);
	init();

	glutMainLoop();

	return 0;
}
