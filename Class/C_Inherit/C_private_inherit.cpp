#include<iostream>

namespace CLASS{

	using namespace std;

	class BASE
	{
		private:			//	private members.
			int value;
		public:				//	public members.
			BASE();
			~BASE();
			int Get_Value(void)const;
			void Change_Value(int temp);
	};

	class INHERIT:private BASE
	{
		private:
			//	Here isn't to define any members with private.

		public:
			//	Here isn't to define Build function and Clear function.
			//	Using default function of BASE.
		
			int View_Value(void)const;
			void Update_Value(void);
	};

	//		has-a		private succeed will succeed public members and protected members of BASE as private members of INHERIT.
	//				--------------------------------------------------------------------------------------------------------
	//				Using public methods of Inherit-class to access the public methods of Base-class.Because the Base-class is
	//				not have name,must use Name_Class::Function_Name(); to call it.

///////////////////////////////////////
BASE::BASE()
{
	cout<<"Hint,BASE subject has been created..."<<endl;
	value=11;
}

BASE::~BASE()
{
	cout<<"Hint,BASE subject has been cleaned..."<<endl;
	value=1;
}

int BASE::Get_Value(void)const
{
	return value;
}

void BASE::Change_Value(int temp)
{
	value=temp;
}
///////////////////////////////////////


int INHERIT::View_Value(void)const
{
	return BASE::Get_Value();		//	Call function of BASE class,private inherit must be using public method to call private function.
}

void INHERIT::Update_Value(void)
{
	int temp=0;
	cout<<"Please input value : ";
	cin>>temp;
	BASE::Change_Value(temp);		//	Call function of BASE as private members.	
	cout<<"Changed..."<<endl;
}


}
//	Define a namespace.

int main(void)
{
	using namespace CLASS;			//	Import items from CLASS.
	INHERIT temp;				//	Build a INHERIT subject.
	
	cout<<"First,show value with default - "<<endl;
	cout<<temp.View_Value()<<endl;		//	Call function
	cout<<"Second,change value - "<<endl;
	temp.Update_Value();			//	Call function
	cout<<"Third,show value again - "<<endl;
	cout<<temp.View_Value()<<endl;

	cout<<"Over...Exitting..."<<endl;


	return 0;
}

