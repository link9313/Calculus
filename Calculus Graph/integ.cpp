/* integ.cpp
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include <gl/glut.h>
#include "text.h"
#include "func.h"

void int_f1_x(void)													// Performance of First Integral for distance
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f1;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The area from [0,2] is %.5g", result);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 315, 3, result_s);
	display_text(-325, 300, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f1_disks(void)												// Performance of First Integral for disk volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f1;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using disks rotated about the x-axis from [0,2] is %.5g", result * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 275, 3, result_s);
	display_text(-325, 260, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}
void int_f1_shells(void)											// Performance of First Integral for shell volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f1_shells;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using shells rotated about the y-axis from [0,2] is %.5g", result * 2 * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 235, 3, result_s);
	display_text(-325, 220, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}



void int_f2_x(void)													// Performance of Second Integral for distance
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f2;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The area from [0,2] is %.5g", result);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 315, 3, result_s);
	display_text(-325, 300, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f2_disks(void)												// Performance of Second Integral for disk volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f2;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using disks rotated about the x-axis from [0,2] is %.5g", result * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 275, 3, result_s);
	display_text(-325, 260, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f2_shells(void)											// Performance of Second Integral for shell volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f2_shells;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using shells rotated about the y-axis from [0,2] is %.5g", result * 2 * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 235, 3, result_s);
	display_text(-325, 220, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}



void int_f3_x(void)													// Performance of Third Integral for distance
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f3;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,.5,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The area from [1/2,2] is %.5g", result);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 315, 3, result_s);
	display_text(-325, 300, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f3_disks(void)												// Performance of Third Integral for disk volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f3;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,.5,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using disks rotated about the x-axis from [1/2,2] is %.5g", result * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 275, 3, result_s);
	display_text(-325, 260, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f3_shells(void)											// Performance of First Integral for shell volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f3_shells;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,.5,2,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using shells rotated about the y-axis from [1/2,2] is %.5g", result * 2 * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 235, 3, result_s);
	display_text(-325, 220, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}



void int_f4_x(void)													// Performance of Fourth Integral for distance
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f4;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,M_PI,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The area from [0,pi] is %.5g", result);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 315, 3, result_s);
	display_text(-325, 300, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f4_disks(void)												// Performance of Fourth Integral for disk volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f4;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,M_PI,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using disks rotated about the x-axis from [0,pi] is %.5g", result * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 275, 3, result_s);
	display_text(-325, 260, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}

void int_f4_shells(void)											// Performance of Fourth Integral for shell volume
{
	gsl_integration_workspace * wptr = gsl_integration_workspace_alloc(1000);
	
	double result, error;
	double alpha = 1.0;
	char* result_s = (char*) malloc(200);
	char* error_s = (char*) malloc(150);
	
	gsl_function fvar;
	
	fvar.function = &f1_shells;
	fvar.params = &alpha;
	
	gsl_integration_qags(&fvar,0,M_PI,0,1e-7,1000,wptr,&result,&error);

	sprintf_s(result_s, 200, "The volume of the solid using shells rotated about the y-axis from [0,pi] is %.5g", result * 2 * M_PI);
	sprintf_s(error_s, 100, "The actual value is in the range of the result + or - this: %.5g", error);
	display_text(-325, 235, 3, result_s);
	display_text(-325, 220, 3, error_s);

	free(result_s);
	free(error_s);

	glutPostRedisplay();
}
