#include<iostream>

namespace CLASS{

	using namespace std;
	
	class Base_Class				//	Defined a class.
	{
		private:				//	private members.
			int value;
		public:					//	public members.
			Base_Class(int var);		//	Statement a build method with default.
			~Base_Class();			//	Statement a clear method.

			//	Use friend method to operator '<<'.

			friend ostream & operator << (ostream &os,const Base_Class &temp);
	
			//	friend function is declare in the scope of class,but it would be defining outside of class.
			//	And friend function can access to private members.Doesn't need method of class.
			//	Keyword 'friend' only be wrote front of prototype.
	};

	Base_Class::Base_Class(int var=12):value(var)	//	Definition for default build method.
	{
		cout<<"Hint,object of Base_Class was created by default build method!"<<endl
			<<"value= "<<value<<endl;
	}

	Base_Class::~Base_Class()			//	Definition for clear method.
	{
		cout<<"Hint,object of Base_Class was expired,clear method have been called!"<<endl;
		value=0;
	}

	ostream & operator << (ostream &os,const Base_Class &temp)	//	Definition for friend function with Base_Class.
	{
		os<<"Cout : friend function have been called."<<endl
			<<"value= "<<temp.value<<endl;
			//	Access to private member.
		return os;
		//	return os with &,could be called by after of objects.
	}
	//	'friend' didn't write at front of function definition.
}
//	Defined a namespace.

int main(void)
{
	using namespace CLASS;
	Base_Class temp1(1024);			//	Built a object of Base_Class by build method with default.
	Base_Class temp2(2048);			//	Built a object of Base_Class by build method with default.

	cout<<"View : "<<endl;			//	Hint.
	cout<<temp1<<"##########"<<endl<<temp2<<endl;	//	Using friend function with operator << .


	return 0;
}

