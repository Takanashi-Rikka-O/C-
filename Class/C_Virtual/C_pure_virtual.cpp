#include<iostream>

namespace CLASS{

using namespace std;

	class BASE	//	Abstract Base Class.	Abstract Base Class must least have a pure virtual function,otherwise can not as abstract base class.
	{
		protected:		//	protected members.They are could be accessed by inherit class.
			int L_value;
			int R_value;
		public:			//	public members.
			BASE();		//	Default build function.
			~BASE();	//	Clear function.

			//	Defined a pure virtual function.

			virtual int Calculation(void)const =0;		//	Prototype of a pure virtual function.
			
			//	virtual type FuncNAME(vars-list)=0;	'=0' will set this function become a pure virtual function.
	
			//	The pure virtual function is doesn't to defined at the base class.But C++ is allow to define it.
	};

	class INHERIT:public BASE
	{
		private:		//	private members.
			//	Here using NULL,data members will be using the BASE's.
			//	INHERIT is succeed the protected members of BASE.
		public:			//	public members.
			//	Because is not have data members in this class,so use default build from g++ to build object.

			virtual int Calculation(void)const;		//	Redefine the pure virtual function in the INHERIT class,
									//	The virtual function in the inherit class isn't need '=0'.
	};

///////////////////////////////////
//	Definition of BASE

BASE::BASE()				//	Default build function.
{
	L_value=33;
	R_value=44;	
	cout<<"Hint,build function BASE() was finished..."<<endl;
}

BASE::~BASE()				//	Clear function.
{
	cout<<"Hint,clear function ~BASE() was finished..."<<endl;
}

//	Because the function- virtual int Calculation(void)const =0; is a pure virtual function,so don't to define it.

//	Definition of INHERIT

int INHERIT::Calculation(void)const	//	Redefine virtual function,the prototype is from a pure virtual function of BASE.
{
	cout<<"Calculation - Adding : "<<endl;
	cout<<"Left_Value - "<<L_value<<" Right_Value - "<<R_value<<endl;
	cout<<"Adding..."<<endl;
	return L_value+R_value;
}

///////////////////////////////////

}

//	Define a namespace.


int main(void)
{
	using namespace CLASS;
	
	INHERIT* inherit=new class INHERIT;		//	Create a object of INHERIT class,use new.
	if (inherit == NULL)				//	Test pointer.
	{
		cerr<<"Creat INHERIT class by new was failed..."<<endl;		//	Error.
		return -1;
	}
	else;

	cout<<"Use pointer of INHERIT to call function Calculation - "<<endl;	//	Hint message.
	int real=inherit->Calculation();						//	Call method.And assignment value to real.
	cout<<"Real= "<<real<<endl;						//	Print.
	cout<<endl<<"Over...Exitting..."<<endl;
	delete inherit;					//	Recycle 

	return 0;
}
