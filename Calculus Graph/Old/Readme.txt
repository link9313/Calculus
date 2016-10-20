*************************************************************
* Calculus Graph				*
* Version 0.0.0.1 [4/18/12]			*
* Copyright © 2012 Nick Lauber		*
*		link9313@gmail.com	*
*************************************************************


*************************************
* Table of Contents		*
*************************************
1. Overview
2. Interal Functions
3. EQ.LST
4. Credits

*************************************
* 1. Overview		*
*************************************

	My AP Calculus Project is a computer program capable of performing various calculus operations to an equation selected from a provided list read by the file. Other equations are easily added to the list, but a first and second derivative must be provided in the file following the original function f(x).

	Pressing ENTER will advance to the next screen while the program is running. Once the last screen is displayed, the program will exit. while running, pressing ESCAPE will also allow you to exit the program, and pressing A will bring up an about screen.

	The program utilizes GSL, the GNU Scientific Library, to perform calculus operations: derivatives and integrals. This library is licensed under the GNU GPL, version 2. More information is available here: http://www.gnu.org/software/gsl/

*************************************
* 2. Internal Functions	*
*************************************
The following is a list of calculus functions performed by the program:
	- Graph of f(x), f'(x), and f"(x)
	- Integral to find the area on set interval of [0,2] or
		[0,pi] for trigonometric functions
	- Disk method of volume rotated about the ?-axis on same intervals
	- Shell method of volume rotated about the ?-axis on same intervals

*************************************
* 3. EQ.LST		*
*************************************
	The eq.lst file is a text file that stores the equations utilized in the program, therefore this file is abosultely necessary. Without this, the program will have no equations to use. The format for these files is simple: the original function is provided first followed by the first and second derivatives, respectively. After entering one of the functions, you must hit ENTER and type the next function. If edited in standard windows notepad the list would look like this:

				x^22*x2

	This is because the text files are stored in UNIX format to maintain greater compatibility with non-windows-based operating systems. A text editor other than notepad is recommended when adding equations to the file. In a UNIX format-supporting program the list will appear similar to this:

				x^2
				2*x
				2

	Standard C syntax for equations is used, and may be different from what you are used to using.

*************************************
* 4. Credits		*
*************************************

Calculus Graph was created by Nick Lauber and is Copyright © 2012 Nick Lauber

GSL copyright © 1997-2010 Free Software Foundation

Licensed under the GNU GPL, version 2
