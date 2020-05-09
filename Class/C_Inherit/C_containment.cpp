#include<iostream>
#include<string>				//	Type string class

namespace CLASS{
	using namespace std;

	//	Define a Base class,and it is containment a  string class object.

	class BASE
	{
		private:			//	private members.
			string STR;		//	Statement a string object.		has-a .
		public:				//	public members.
			BASE();			//	Default build function for BASE,you can use the build function at members-list to initialize that STR.
			~BASE();		//	Clear function.
			string & Get_string(void);	//	Get string object.
			void Change_string(void);	//	Change string object with its data.
	};



BASE::BASE():STR("NULL")			//	Build other item of BASE is have to build other object at the front.
{
	cout<<"Hint,string object has been created..."<<endl;
}

BASE::~BASE()					//	The class string is have a clear function of itself.
{
	cout<<"Hint,~BASE() has been called..."<<endl;
}

string & BASE::Get_string(void)			//	'const' is can not be wrote at here,because throw error "invlide initialization of reference." away.
{
	return STR;				//	Return the string object.
						//	Because outside of class is can not to access it.
}

void BASE::Change_string(void)
{
	cout<<"Please enter string for object : ";
	cin>>STR;				//	'>>' has be overloaded by method of string-class.
	cout<<"Input over..."<<endl;
}

}
//	Define a namesapce.

int main(void)
{
	using namespace CLASS;			//	Import item from namespace-CLASS.
	
	BASE temp;				//	Build a object of BASE by default build function.

	cout<<"First,show the string of initialization with BASE' - "<<endl;
	cout<<"String = "<<temp.Get_string()<<endl;
	cout<<"Second,change string to BASE object - "<<endl;
	temp.Change_string();
	cout<<"Third,show the string again - "<<endl;
	cout<<"String = "<<temp.Get_string()<<endl;

	cout<<"Over...Exitting..."<<endl;

	return 0;
}

