#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])

{
double x,y,z,w;
	cout<<("Enter x\n")  ;
	cin>>x ;
	cout<<("Enter y\n")  ;
	cin>>y;
	cout<<("Enter z\n")  ;


	cin>>z;
w= (pow(fabs(cos(x)- cos(y)), (1+2*sin(y)*sin(y)))) * (1+z+(pow(z,2)/2)+(z*z*z/3)+(z*z*z*z/4));
	cout<<w;
getch()   ;
	return 0;
}
