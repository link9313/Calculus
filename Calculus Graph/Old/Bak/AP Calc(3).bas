/' +---------------------------------------------------+
   |                   Calculus Graph                  |
   |               Written by Nick Lauber              |
   |     Code licensced under the GNU GPL License      |
   +---------------------------------------------------+
   |                 Main Program Code                 |
   +---------------------------------------------------+'/

' Open eq.lst for reading the equations from within.
'Open "eq.lst" for binary Access Read as #1

' Include Header File
#Include Once "AP Calc.bi"

'Initialize Variables
Dim fvar As gsl_function
Dim wptr As gsl_integration_workspace Ptr
Dim result As Double
Dim result_error As Double
Dim A As Double

A = 1.0

' Create Integration workspace
wptr = gsl_integration_workspace_alloc(1000)

' Assign data to GSL function
fvar.function = @f
fvar.params = @A

Print "Address of f "; Hex(wptr)

' Integrate function (function, lower limit, upper limit, absolute error, relative error, size of workspace,
' integration workspace, result, error of result)
gsl_integration_qags(@fvar,0,2,0,1.0E-8,1000,wptr,@result,@result_error)

Print "The integral of the function x^2 on interval [0,2] is " ; result
Print "the error of the integral is + or - " ; result_error
Sleep

gsl_integration_workspace_free(wptr)

Function f Cdecl Alias "f" (ByVal x As Double, ByRef params As Any Ptr) As Double
	Dim a As Double
	Dim fret As Double 
	
	a = *(Cast(Double Ptr, params))
	fret = a*x*x
	
	Return fret
End Function
