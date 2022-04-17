#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;

double factorial(int k){
  if(k<0) return 0;
  if (k==0) return 1;
  else return k*factorial(k-1);

}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,k;
	double a,b,h,sum,y,x;

	cout<<"Enter a,b,h,n:\n";
	cout<<"a= ";
	cin>>a;
	cout<<"b= ";
	cin>>b;
	cout<<"h= ";
	cin>>h;
	cout<<"n= ";
	cin>>n;
	cout<<" Y(x)       S(x)       |Y(x)-S(x)|\n";
	for (x=a; x<=b; x+=h)
	{
		sum=1; y=cos(x);
			for(k=1;k<=n;k++)
			{
				sum+=pow(-1,k) * pow(x,2*k) / factorial(2*k);

			}
	cout<< y << "   " << sum << "   " <<fabs(y-sum)<< "\n";
	}

getch();
return 0;
}

