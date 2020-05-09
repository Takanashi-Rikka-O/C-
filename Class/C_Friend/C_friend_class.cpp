#include<iostream>
#include<cstdlib>					//	abort()'prototype.

namespace CLASS{
//	Defined a namespace

	using namespace std;

	class Friend_Class;				//	Statement at front of the Base_Class.
							//	Because the code:'friend class Friend_Class;' has been writed in the class Base_Class.

	class Base_Class
	{	
		private:				//	private members.
			char* str1;
			char* str2;
			const short int Long;		//	Long is a const value,it can not has be initialized at class definition,so it couldn't has be
							//	assignment.
							//
							//	How do intialize to the const member?
							//	Using members-initialization-list to initialize the cosnt member.
							
							/*
 							*	Base_Class():Long(value)
 							*	{
 							*		...
 							*	}
 							*	
 							*	You must use this code to initialize the const member,also,using enum type.
 							*
 							* 	enum {Long=value};
 							*
 							*/
							
							
		public:					//	public members.
			friend class Friend_Class;	//	Friend class for Base_Class.

			Base_Class();			//	Default build method.
			~Base_Class();			//	Clear method.

			//	Here doesn't to define more method for Base_Class.
			//	Operation for Base_Class object is transfer to friend class Friend_Class.
	};

	class Friend_Class
	{
		private:				//	Here doesn't to define any members of private for Friend_Class.
		public:					//	Define method and to operate the private members of Base_Class.
		
		//	The methods of friend class could access to normal-class,but it must be statemented in the normal-class.

		void View_String(const Base_Class &temp);	//	Show strings of Base_Class.
		void Resive_String(Base_Class &temp);		//	Resive the strings of Base_Class.
		
		//	End.
	};

////////////////////////////////////////////

	Base_Class::Base_Class():Long(21)			//	Defined a build method with default of Base_Class.
	{
		cout<<"Hint,the build method of Base_Class has been called!"<<endl;
		str1=new char[Long];
		str2=new char[Long];
		//	Get memory.
		if (str1 == NULL || str2 == NULL)
		{
			cerr<<"Can not get memorys for char pointer..."<<endl;
			abort();
		}
		else
			cout<<"Initialized,the lenght of array with char is "<<Long<<endl;
	}

	Base_Class::~Base_Class()			//	Defined a clear method of Base_Class.
	{
		cout<<"Hint,the clear method of Base_Class has been called!"<<endl;
		if (str1 != NULL && str2 != NULL)
		{
			delete[] str1;
			delete[] str2;
		}
		else
		{
			cerr<<"The memeorys of char-array hadn't be recycle..."<<endl;
			abort();
		}

	}

////////////////////////////////////////////

//	The default build method of Friend_Class will be using the method is from system.

	void Friend_Class::View_String(const Base_Class &temp)
	{
		cout<<"The string of Base_Class : "<<endl
			<<"String 1 : "<<temp.str1<<endl
			<<"String 2 : "<<temp.str2<<endl;
		return;
	}
	void Friend_Class::Resive_String(Base_Class &temp)
	{
		cout<<"Please input for string 1 : ";cin.getline(temp.str1,temp.Long);
		cout<<"Please input for string 2 : ";cin.getline(temp.str2,temp.Long);
		cout<<"Inpution over..."<<endl;
		return;
	}

////////////////////////////////////////////

}

//	Start

int main(void)
{
	using namespace CLASS;
	Base_Class base1;			//	Create a object of Base_Class.
	Friend_Class friend1;			//	Create a object of Friend_Class.

	cout<<"Please input somethings for the private members of Base_Class - "<<endl;
	friend1.Resive_String(base1);
	cout<<"Show the contents of Base_Class object - "<<endl;
	friend1.View_String(base1);

	cout<<"Over...Exitting..."<<endl;
	return 0;
}
