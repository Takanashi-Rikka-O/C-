#include<iostream>

namespace CLASS{
	using namespace std;			//	import elements from namespace std.
	
	class Base_Class			//	Defined a class.
	{
		private:			//	members are private.
			int value;
		public:				//	members are public.
			Base_Class();		//	Default build method.
			Base_Class(const int tmp);	//	Overload with default build method.
			~Base_Class();		//	Clear method for Base_Class.

			int operator + (const Base_Class &C);	//	Overload the adding-operator at the class Base_Class as method.
						//	Overload operator can't resive with attribues of it.
			int Get_value(void)const;	//	Get value from private member.
						//	Beacuse the operator + isn't a friend method.
	
		//	Don't to define other method for Base_Class.
		//	Test adding behavior with object1 + object2.
		
	};
						//	Overload operator is could be defined as class-method only.
						//	Also,you could using friend class/method to overload it.

	Base_Class::Base_Class():value(13)	//	Define default build method.
	{
		cout<<"Hint,Base_Class Object was created by build method with default!"<<endl;
	}
	Base_Class::Base_Class(const int tmp):value(tmp)	//	Define build method with overloaded.
	{
		cout<<"Hint,Base_Class Object was created by build method with overloaded!"<<endl;
	}
	//	Remember that members-list-initialize only be usage by build method.
	Base_Class::~Base_Class()		//	Define clear method.
	{
		value=-1;
		cout<<"Hint,Base_Class Object was clean by cleaner"<<endl;
	}

	int Base_Class::Get_value(void)const		//	Define Get_value method,it's interface for operator + .
	{
		return value;
	}

	int Base_Class::operator + (const Base_Class &C)	//	Define operator with + .
	{
		return value+C.Get_value();			//	Get_value() must be defined to const,because the Base_Class &C is const.
								//	You can not send const argument to 'this' with that it isn't const.
	}		

}
//	Defined a namespace.

int main(void)
{
	using namespace CLASS;			//	Import namespace.
	Base_Class C1;				//	Built a Object of Base_Class by build method with default.
	Base_Class C2(10);			//	Built a Object of Base_Class by build method with overloaded.
	
	//	Test C1 + C2.
	
	cout<<"Object C1= "<<C1.Get_value()<<endl;
	cout<<"Object C2= "<<C2.Get_value()<<endl;
	cout<<"C1 + C2 = "<<C1+C2<<endl;	//	Call mode of operator
						//	Also can use mode C1.operator+(C2) to call method.

	cout<<"Exitting..."<<endl;

	return 0;
}

