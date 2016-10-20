/* func.h
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

#ifndef FUNC_H
#define FUNC_H

double f1(double x, void * params);			//		First Function
double f1_draw(double x);
double f1_deriv(double x);
double f1_shells(double x, void * params);

double f2(double x, void * params);			//		Second Function
double f2_draw(double x);
double f2_deriv(double x);
double f2_shells(double x, void * params);

double f3(double x, void * params);			//		Third Function
double f3_draw(double x);
double f3_deriv(double x);
double f3_shells(double x, void * params);

double f4(double x, void * params);			//		Fourth Function
double f4_draw(double x);
double f4_deriv(double x);
double f4_shells(double x, void * params);

#endif
