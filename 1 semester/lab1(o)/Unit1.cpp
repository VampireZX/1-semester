//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
double x,y,z,w;
x=StrToFloat(Edit1->Text);
y=StrToFloat(Edit2->Text);
z=StrToFloat(Edit3->Text);
w= (pow(fabs(cos(x)- cos(y)), (1+2*sin(y)*sin(y)))) *
(1+z+(pow(z,2)/2)+(z*z*z/3)+(z*z*z*z/4));
 Memo1->Lines->Add(
 "При x= "+ FloatToStr(x)+
 ", y= " + FloatToStr(y) +
 ", z= " + FloatToStr(z) + ";\nРезультат: " + FloatToStrF(w,ffFixed,6,4));

}
//---------------------------------------------------------------------------

