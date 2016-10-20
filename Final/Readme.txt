*************************************************************
* Calculus Graph				*
* Version 1.0.0.0 [5/6/12]			*
* Copyright © 2012 Nick Lauber		*
*		link9313@gmail.com	*
*************************************************************


*************************************
* Table of Contents		*
*************************************
1. Overview
2. Interal Functions
3. Credits

*************************************
* 1. Overview		*
*************************************

	My AP Calculus Project is a computer program capable of performing various calculus operations to an equation selected from a coded list unmodifiable outside the source code.

	Pressing a number 1-4 will display a specified function. Pressing 0 will return to the first screen. ESCAPE or Q will allow you to exit the program at any time.

	The program utilizes GSL, the GNU Scientific Library, to perform calculus operations: derivatives and integrals. This library is licensed under the GNU GPL, version 2. More information is available here: http://www.gnu.org/software/gsl/

	The program also utilizes OpenGL for graphics display. More infromation is availble here: http://www.opengl.org/

	The program was written using Microsoft Visual C++ 2010 Express Edition. The program therefore requires the Microsoft Visual C++ 2010 x86 Redistributable. This has been bundled with the program to simplfy this process.

*************************************
* 2. Internal Functions	*
*************************************
The following is a list of calculus functions performed by the program:
	- Graph of a velocity function, v(t), and its acceleration derivative, a(t)
	- Integral to find the distance traveled, x(t) on set interval of [0,2] on
		polynomial functions, [1/2,2] for rational functions, or [0,pi]
		for trigonometric functions
	- Disk method of volume rotated about the x-axis on same intervals
	- Shell method of volume rotated about the y-axis on same intervals

*************************************
* 3. Credits		*
*************************************

Calculus Graph © 2012 Nick Lauber

GSL copyright © 1996-2010 Free Software Foundation

OpenGL copyright © 1992-2011 Silicon Graphics Inc., Khronos Group

Microsoft Visual C++ 2010 Express Edition and Microsoft Visual C++ 2010 x86 Redistributable © 2010 Microsoft Corporation

Licensed under the GNU GPL, version 2
