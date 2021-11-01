//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
  	double factorial(int k)
	{
		if(k<0) return 0;
		if(k==0) return 1;
		else return k*factorial(k-1);
	}
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	int n;
	double k, a, b, h, fak, sum, y, x;

	a=StrToFloat(Edit1->Text);
	b=StrToFloat(Edit2->Text);
	h=StrToFloat(Edit3->Text);
	n=StrToFloat(Edit4->Text);
	for (x=a; x<=b; x+=h)
	{
	 sum=1; y=cos(x);
			for (k=1; k<=n; k++)
		{
				sum+=pow(-1, k)*pow(x,2*k)/factorial(2*k);

		}

		Memo1->Lines->Add(" Y(x)= " +
		FloatToStr(y) + " 		S(x)= " + FloatToStr(sum) +
		"    	|Y(x)-S(x)|= " + FloatToStr(fabs(y-sum)));
	}





}//---------------------------------------------------------------------------

