/* text.cpp
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

#include <gl/glut.h>
#include <string.h>

GLfloat glFontColor[][4] = { {0.0, 0.0, 0.0, 0.0}, {1.0, 0.0, 0.0, 0.0}, {0.0, 0.7, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {1.0, 1.0, 1.0, 0.0} };
GLfloat x, y;

void print_string(void* font, const char* string)
{
	if (string && strlen(string))
	{
		while (*string)
		{
			glutBitmapCharacter(font, *string);
			string++;
		}
	}
}

void display_text(GLfloat x, GLfloat y,  int text_color, const char* string)
{
	/* Draw the strings, according to the current mode and font. */
	glColor4fv(glFontColor[text_color]);
	glRasterPos2f(x, y);
	print_string(GLUT_BITMAP_HELVETICA_18, string);
}
