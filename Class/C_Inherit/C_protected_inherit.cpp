#include<iostream>

namespace CLASS{

	using namespace std;

	class BASE
	{
		private:				//	private members.
			int value;
		public:					//	public members.
			BASE();
			~BASE();			
			void View_Value(void)const;
			void Change_Value(void);
	};

	class INHERIT:protected BASE			//	has-a.protected inherit,the public and protected members of BASE will become to the protected -
							//	-members of INHERIT.
	{
		private:
			///
		public:
			///

		//	The second heir isn't to define any data or function.Because it will succeed the protected members and the public members of BASE as
		//	protected members.The build function of BASE will be using default build function.
	};

	class INHERIT_SEC:public INHERIT		//	is-a.public inherit,the public members of INHERIT will become to the public mem-
							//	-bers of INHERIT_SEC.
	{
		private:
			///
		//	Here isn't define any members.
		public:
			///
			void View_Value(void)const
			{
				INHERIT::View_Value();	//	Call function of INHERIT with protected members.
				return;
			}
			
			void Change_Value(void)
			{
				INHERIT::Change_Value();	//	Call function of INHERIT with protected members.
				return;
			}
			

		//	Here is define some interface to access the protected members of INHERIT.
		//	Because the protected members of INHERIT can be access by this third heir.That is from INHERIT'protected,and from BASE'public.
		//	But third heir isn't access the protected members of INHERIT by the subject of itself directly.
	};

	/*
 *			BASE
 *			|-------------- protected
 *			INHERIT
 *			|--------------	public
 *			INHERIT_SEC
  	*/


BASE::BASE()			//	Default build function of BASE.
{
	cout<<"Hint,BASE subject has been created..."<<endl;
	value=33;
}

BASE::~BASE()			//	Clear function of BASE.
{
	cout<<"Hint,BASE subject has been cleaned..."<<endl;
}

void BASE::View_Value(void)const
{
	cout<<"The value = "<<value<<endl;
	return;
}

void BASE::Change_Value(void)
{
	cout<<"Change Value - "<<endl;
	cout<<"Please input value : ";
	cin>>value;
	cout<<"Input over..."<<endl;
	return;
}

}

//	Define a namespace.

int main(void)
{
	using namespace CLASS;			//	Import items from CLASS.
	
	INHERIT_SEC temp;			//	Statement a subject of INHERIT_SEC.

	//	Third heir can using protected function of Second heir directly.
	
	cout<<"Using INHERIT_SEC subject to call functions - "<<endl;
	
	cout<<"First,show default value - "<<endl;
	temp.View_Value();	

	cout<<"Second,change value - "<<endl;
	temp.Change_Value();

	cout<<"Third,show value again - "<<endl;
	temp.View_Value();

	cout<<"Over...Exitting..."<<endl;

	return 0;
}
