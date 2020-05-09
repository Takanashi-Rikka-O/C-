#include<iostream>
#include<cstdlib>
#include<cstring>

namespace CLASS{

using namespace std;

const short int Len=128;

	class BASE						//	A base class.
	{
		private:					//	private members.
			short int State;			//	0 - Using default build.
								//	1 - Using overload build.
			char* str1_a;
			char* str2_a;
		public:						//	public members.
			BASE();					//	Default build.
			BASE(char* tmp1,char* tmp2);		//	Overload build.
			virtual void View_string(void)const;	//	Show strings.		BASE
			virtual ~BASE();			//	Clear method.Because the class BASE is as base class.

			virtual void operator = (char* temp);	//	Overload = to copy string from outside of class.
	};

	class INHERIT:public BASE				//	Inherit from class-BASE,the modus is public.
	{
		private:					//	private members
			short int State;			//	0 - Using default build.
								//	1 - Using overload build.
//			Inherit from BASE;

			char* str1_b;	
			char* str2_b;		
		public:						//	public members
			INHERIT();				//	Default build.			
			INHERIT(char* tmp1,char* tmp2);		//	Overload build.
			virtual void View_string(void)const;	//	Show strings.	Will be writting this method.
			~INHERIT();				//	Clear method.

			//	The operator function will be inherited from BASE.
			//	But here is must overwritting with it.

			virtual void operator = (char* temp);	
	};

								//	public inherit,inheit-class can get data-members of base-class.
								//	But the memberes of base-class with private,must be using the methods of base-class to
								//	access.

	//	Clear method call order : 1.Inherit-class ; 2.Base-class.
	//	Build method call order : 1.Base-class ; 2.Inherit-class.

///////////////////////////////////////		Definition of BASE.

BASE::BASE()
{
	cout<<"Hint,BASE() default function was called..."<<endl;
	State=0;
	str1_a=new char[Len];
	str2_a=new char[Len];
	if (str1_a != NULL && str2_a != NULL)
		cout<<"Object create succseccly."<<endl;
	else
	{
		cerr<<"Can not get memory for BASE."<<endl;
		exit(-1);
	}
}

BASE::BASE(char* tmp1,char* tmp2)
{
	cout<<"Hint,BASE() overload function was called..."<<endl;
	State=1;
	str1_a=tmp1;
	str2_a=tmp2;
}

BASE::~BASE()
{
	cout<<"Hint,~BASE() was called..."<<endl;
	switch (State)
	{
		case 0:	//	Default build.
			if (str1_a != NULL && str2_a != NULL)
			{
				cout<<"Using mode 1 - default build - clear..."<<endl;
				delete[] str1_a;
				delete[] str2_a;
			}
			else
			{
				cerr<<"Error,pointer1 or pointer2 is NULL..."<<endl;
				exit(-1);
			}
			break;
		case 1: //	Overload build.
			cout<<"Using mode 2 - overload build - clear..."<<endl;
			str1_a=NULL;
			str2_a=NULL;
			break;
		default:
			cerr<<"State = "<<State<<" is not be defined..."<<endl;
			exit(-1);
	}
}

void BASE::View_string(void)const		//	virtual method of BASE.
{
	cout<<"BASE function - View_string "<<endl;
	cout<<"String 1 : "<<str1_a<<endl
		<<"String 2 : "<<str2_a<<endl;
	return;
}

void BASE::operator = (char* temp)
{
	cout<<"Hint,call operator..."<<endl;
	if (temp == NULL)
	{
		cerr<<"temp is NULL..."<<endl;
		return;
	}
	else;
	switch (State)
	{
		case 0:
			memset(str1_a,'\0',sizeof(char)*Len);
			memset(str2_a,'\0',sizeof(char)*Len);
			strncpy(str1_a,temp,Len);
			strncpy(str2_a,temp,Len);
			break;
				
		case 1:
			str1_a=str2_a=temp;
			break;		
		default:
			cerr<<"State = "<<State<<" is not be defined..."<<endl;
			exit(-1);
	}
	return;
}


///////////////////////////////////////		Definition of INHERIT.

INHERIT::INHERIT():BASE()
{
	cout<<"Hint,INHERIT() default function was called..."<<endl;
	State=0;
	str1_b=new char[Len];
	str2_b=new char[Len];
	if (str1_b != NULL && str2_b != NULL)
		cout<<"Object create succseccly."<<endl;
	else
	{
		cerr<<"Can not get memory for INHERIT."<<endl;
		exit(-1);
	}
}

INHERIT::INHERIT(char* tmp1,char* tmp2):BASE(tmp1,tmp2)
{
	cout<<"Hint,BASE() overload function was called..."<<endl;
	State=1;
	str1_b=tmp1;
	str2_b=tmp2;
}

INHERIT::~INHERIT()
{
	cout<<"Hint,~INHERIT() was called..."<<endl;
	switch (State)
	{
		case 0:	//	Default build.
			if (str1_b != NULL && str2_b != NULL)
			{
				cout<<"Using mode 1 - default build - clear..."<<endl;
				delete[] str1_b;
				delete[] str2_b;
			}
			else
			{
				cerr<<"Error,pointer1 or pointer2 is NULL..."<<endl;
				exit(-1);
			}
			break;
		case 1: //	Overload build.
			cout<<"Using mode 2 - overload build - clear..."<<endl;
			str1_b=NULL;
			str2_b=NULL;
			break;
		default:
			cerr<<"State = "<<State<<" is not be defined..."<<endl;
			exit(-1);
	}
}

void INHERIT::View_string(void)const		//	virtual method of BASE.
{
	BASE::View_string();
	cout<<"INHERIT function - View_string "<<endl;
	cout<<"String 1 - INHERIT : "<<str1_b<<endl
		<<"String 2 - INHERIT : "<<str2_b<<endl;
	return;
}

void INHERIT::operator = (char* temp)
{
	cout<<"Hint,call operator..."<<endl;
	if (temp == NULL)
	{
		cerr<<"temp is NULL..."<<endl;
		return;
	}
	else;
	switch (State)
	{
		case 0:
			BASE::operator = (temp);

			memset(str1_b,'\0',sizeof(char)*Len);
			memset(str2_b,'\0',sizeof(char)*Len);
			strncpy(str1_b,temp,Len);
			strncpy(str2_b,temp,Len);
			break;
				
		case 1:
			str1_b=str2_b=temp;
			break;		
		default:
			cerr<<"State = "<<State<<" is not be defined..."<<endl;
			exit(-1);
	}
	return;
}


///////////////////////////////////////


	//	The virtual method : 
	//				virtual-method is called by the pointer or the cite or the object.
	//				The pointer and the cite : 
	//					If they are directe to Inherit-class,so called method is of the Inherit-class;
	//					If they are directe to Base-class,so called method is of the Base-class;
	//
	//				You can overwrite with the virtual method in Inherit-method,then using the pointer or the cite of Inherit-class to call
	//				it.
	//				
	//				Remember : The actual method will be palling the virtual,at that time,either the pointer or the cite are call the ---
	//				actual method.
	//				
	//				The private members of Base-class can not be accessed by Inherit-class,must be using method of Base-class to access.
	//
	//				Inherit-class can succeed the methods of Base-class as public member.
	//
	//				If you want to call method of Base-class at the scope of Inherit-class,using Base_name::Method_name to call function.

}

//	A namespace CLASS;



int main(void)
{
	using namespace CLASS;					//	Import names.
	cout<<"Start..."<<endl;

	const char* EX="I sometimes think that all of this is too good to be true.";	//	const char pointer.
	char* example_string=new char[64];
	if (example_string == NULL)
	{
		cerr<<"Can not get memory for example_string..."<<endl;
		exit(-3);
	}
	else
		strncpy(example_string,EX,64);


	BASE base;						//	Statement a BASE class object.
	BASE & bc=base;						//	Statement and initialize a  BASE cite.
	BASE* bp=&base;						//	Statement and initialize a  BASE pointer.

	INHERIT inherit;					//	Statement a INHERIT class object.
	INHERIT & ic=inherit;					//	Statement and initialize a INHERIT cite.
	INHERIT* ip=&inherit;					//	Statement and initialize a INHERIT pointer.	



	cout<<"Call operator function - "<<endl<<endl;		//	Hint
	base=example_string;					//	Call operator = by object.
	inherit=example_string;					//	Call operator = by object.
	
	cout<<"Call View_string - "<<endl<<endl;		//	Hint

	cout<<"Cite - BASE : "<<endl;
	bc.View_string();					//	Call function by cite.
	cout<<"Pointer - BASE : "<<endl;
	bp->View_string();					//	Call function by pointer.

	cout<<endl;

	cout<<"Cite - INHERIT : "<<endl;
	ic.View_string();					//	Call function by cite.
	cout<<"Pointer - INHERIT : "<<endl;
	ip->View_string();					//	Call function by pointer.

	cout<<"\nOver...Exitting..."<<endl;
	return 0;
}
