#include<iostream>
#include<typeinfo>

using namespace std;

namespace{
	
	class BASE{
		public:
	
			virtual void HINT(void)const
			{
				cout<<"There is 'class BASE' !\n";
			}
	};

	//	Class INHERIT is inherit from BASE with public method.
	class INHERIT:public BASE{	
		public:
	
			virtual void HINT(void)const
			{
				cout<<"There is 'class INHERIT' !\n";
			}


	};




}

int main(void)
{

	class BASE base;	//	Object
	class INHERIT inherit;	//	Object

	class BASE* baseP(&base);	//	Pointer
	class INHERIT* inheritP(&inherit);	//	Pointer.


	//	Use typeinfo to check type.
	
	if (typeid(class BASE) == typeid(inherit))	//	If inherit is a class BASE
	{
		cout<<"inherit is a object of class INHERIT,and also is a class BASE object!\n";
		inherit.HINT();
	}
	else
	{
		cout<<"inherit is not a class BASE object!\n";
		cout<<"Check type is "<<typeid(inherit).name()<<endl;
	}
	if (typeid(class INHERIT) == typeid(*baseP))	//	If *baseP is a class INHERIT
	{
		cout<<"baseP is a pointer and point to base,but is pass check that if it is a INHERIT object.This is a error.\n"
			<<"Because class INHERIT is inherit from class BASE with public!!!\n";
	}
	else
	{
		cout<<"baseP is a pointer and point to base,it is not a class INHERIT object !!!\n";
		cout<<"Check type is "<<typeid(inherit).name()<<endl;
		baseP->HINT();
	}

	
	



	return 0;

}
