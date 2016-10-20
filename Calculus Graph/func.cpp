/* func.cpp
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

#include <math.h>

double f1(double x, void * params)					//		First Function
{
	double alpha = * (double *) params;
	double f1 = alpha * x * x;
	return f1;
}

double f1_draw(double x)
{
	return x * x;
}

double f1_deriv(double x)
{
	return 2 * x;
}

double f1_shells(double x, void * params)
{
	double alpha = * (double *) params;
	double f1_shells = alpha * x * ( x * x);
	return f1_shells;
}



double f2(double x, void * params)					//		Second Function
{
	double alpha = * (double *) params;
	double f2 = alpha * x * x * x;
	return f2;
}

double f2_draw(double x)
{
	return x * x * x;
}

double f2_deriv(double x)
{
	return 3 * x * x;
}

double f2_shells(double x, void * params)
{
	double alpha = * (double *) params;
	double f2_shells = alpha * x * ( x * x * x);
	return f2_shells;
}


double f3(double x, void * params)					//		Third Function
{
	double alpha = * (double *) params;
	double f3 = alpha * 1 / x;
	return f3;
}

double f3_draw(double x)
{
	return 1 / x;
}

double f3_deriv(double x)
{
	return -1 / (x * x);
}

double f3_shells(double x, void * params)
{
	double alpha = * (double *) params;
	double f3_shells = alpha * x * ( 1 / x );
	return f3_shells;
}


double f4(double x, void * params)					//		Fourth Function
{
	double alpha = * (double *) params;
	double f4 = alpha * sin(2 * x) + 2;
	return f4;
}

double f4_draw(double x)
{
	return sin(2 * x) + 2;
}

double f4_deriv(double x)
{
	return 2 * cos(2 * x);
}

double f4_shells(double x, void * params)
{
	double alpha = * (double *) params;
	double f4_shells = alpha * x * ( sin (2 * x) + 2 );
	return f4_shells;
}
