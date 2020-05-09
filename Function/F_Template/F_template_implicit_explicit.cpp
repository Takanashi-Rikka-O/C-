#include<iostream>
using namespace std;

//	Demonstrate materialize for template.

template<class Any>
void View(const Any* val);		//	Normal template.

template<>
void View<char>(const char* str);	//	explicit specialization a template for type=char.

template<>
void View<int>(const int* a);		//	explicit specialization a template for type=int.

template
void View<double>(const double* f);	//	explicit instantiation a template for type=double.

//	The definition of template is not as same as template-exlicit-specialization.
//	If prameter is match for template-exlicit-specialization,g++ will be using definition of template-exlicit-specialization to make a instantiation.
//	If at sametime have explicit-specialization and explicit-instantiation of same type in the same one code-unit,will throw a error.



int main(void)
{
	int a(2);			//	Initialize a int variable.
	const char* str="Test text!";	//	Initialize a string to point,must be using const type.
	double f(3.14159);		//	Initialize a double variable.
	View(str);			//	Call template<class Any>void View(const Any* str).	Implicit-instantiation.
	View(&a);			//	Call template<>void View<int>(const int* a).
//	|-------------------------------//	You could assignment a variable-point to a const-variable-point,but couldn't reverse.
	View(&f);			//	Call template View<double>(const double* f).

					//	If one point'memory is not from new,can not use delete to clear.

	return 0;
}

template<class Any>		//	Definition for normal template.
void View(const Any* val)
{
	cout<<"In normal-template View(const Any* val) - "<<endl;
	cout.precision(8);		//	Setup accuracy for float or double.
	cout.fill('#');			//	Change default filling-char to `#'.
//	cout.setf(ios_base::showpoint);	//	Setup showpoint.
	cout.setf(ios_base::fixed,ios_base::floatfield);	//	Setup view-mode to fixed.
	(cout<<"void View(const Any* val) = ").width(12);	//	Show hint and call width().
	cout<<*val<<endl;					//	Show value after formatted.
	cout<<"Exited void View(const Any* val)...\n";
	return;
}




template<>			//	template-explicit-specialization.Specialization'prototype is from the `template<class Any>void View(const Any* val)'.
void View<char>(const char* str)//	Show string.
{	
	cout<<"In template-explicit-specialization View(const Any* str) - "<<endl;
	cout<<"void View<char>(const char* str) str = "<<str<<" Address = "<<static_cast<const void*>(str)<<endl;	//	static_cast point.
	cout<<"Exited void View(const char* str)...\n";
	return;
}
template<>			//	template-explicit-specialization.Specialization'prototype is from the `template<class Any>void View(const Any* val)'.
void View<int>(const int* a)	//	Show a*2.
{
	cout<<"In template-explicit-specialization View(const int* a) - "<<endl;
	cout<<"void View<int>(const int* a) a*2 = "<<*a*2<<endl;
	cout<<"Exited void View<int>(int* a)...\n";
	return;
}
//	Specialization for template,must have a normal template,the specialization is from the normal template.




//	Remember,the cover order of function : 
//	1.Not template or template-specialization,normal function prototype; 
//	2.Template-exlicit-specialization of function; 
//	3.Template of function.

//	In code at statement,can not have ambiguity.

