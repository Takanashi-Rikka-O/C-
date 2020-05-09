#include<iostream>
using namespace std;

template<class T>
void Swap(T &a,T &b);

//	Define a function_template.Normal 'class' can be change to 'typename'.
//	g++ is not to make a function case when it detected a template for function.

int main(void)
{
	int a(10),b(11);
	cout<<"Use function Swap to change value for a=10 and b=11 - "<<endl;
	Swap(a,b);				//	Call Swap().
	cout<<"a= "<<a<<" b= "<<b<<endl;

	cout<<"Test template for double x=1.3,y=2.5 - "<<endl;
	double x(1.3),y(2.5);
	Swap(x,y);				//	Call Swap().
						//	cout.setf(ios_base::fixed,ios_base::floatfield);	Use mode fixed point counting to be view.
	cout.setf(ios_base::showpoint);		//	Change view mode for cout,show point.ios_base is a class.
	cout.precision(8);			//	Change view mode for cout,show lenght of suffix as value.value=8
	cout<<"x= "<<x<<" y= "<<y<<endl;

	return 0;

						//	Attention : cout.width(value) can change width of view but it is once setting.
}


//	Function template can make different case for prameter'type.


template<class T>
void Swap(T &a,T &b)
{
	T temp;		//	Temp var.
	cout<<"View class T' size(byte) = "<<sizeof(temp)<<endl;
	temp=a;		//	Save value of a.
	a=b;		//	Change value of a to b.
	b=temp;		//	Change value of b to temp.
	return;		//	return to main.
}

//	Definition for function.Use the template can make not as same type for function.
