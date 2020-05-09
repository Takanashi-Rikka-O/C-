#include<iostream>
#include<cstring>
#include<cstdlib>

/*
 *	Template is for the members of class.Use 'Any' to resives them.
 *
 *	Definition : 
 *			template<class Type>
 *			class EX
 *			{
 *				private:
 *					Any mem1;
 *					Any mem2;
 *				public:
 *					EX();
 *					~EX();
 *					Any & Func(vars-list);
 *					...
 *			};
 *
 *	For example,it's as same as template with function.
 *	Of coures it have that the instantiation and the specialization,too.Modus have implicit and explicit.
 *
 *	Specialization : 
 *			implicit-instantiation : 
 *						It's happend in that statement a subject.
 *						E.g.	EX<int> subject;
 *						This will make a template instantiation.
 *			explicit-instantiation : 
 *						It's must use this code to make instantiation.
 *						E.g.	template class EX<int>;
 *						This situation will make a template instantiation.
 *			explicit-specialization : 
 *						It's must special some type to specialization.If you changed the hevior of class with special type,use that
 *						can make a sepcialy instantiation.
 *
 *						<In some translater,'template<>' and 'prototype' must in same line.>
 *						E.g.	template<> prototype ...
 *
 *						E.g.	
 *							template<> 
 *							class EX<char*>
 *							{
 *								...
 *							};
 *
 *							The definition is same as template with function.If you want using 'char*' as type for class,g++ doesn't
 *							using normal definition of class template,it will be using this definition to make a instantiation.
 *
 *							Use this mechanism,you can change the hevior of class.
 *
 *	And also,you can use template class in the scope of template class.	-	Recursive
 *	And also,you can use more general type as the Type of templalte class.	-	EX<EX<int>> subject;	
 *										<Buildition of class is begin inside end outside.>
 *
 *	And also,you can provide the default type to the general type of template class.	-	template <class Any,class Any=int>...
 *	And also,you can partial specialization for template.
 *								E.g.
 *									template<class Any> class EX<Any,typename>{...};
 *								
 *								This partial specialization will saving Any,but using typename as another type.
 *
 *	And also,you can use the template class as members.
 *								E.g.
 *									template<class Any>
 *									class EX
 *									{
 *										template<class Another>		//	Nested.
 *										class EX1
 *										{
 *											...
 *										};
 *
 * 										...
 *									};
 *
 *								This is basic attribues with STL.
 *
 *	And also,you can use template class as the Type of template.
 *								E.g.
 *									template<template<class Any> class EX>>
 *									class EX1
 *									{
 *										...
 *									};
 *
 *								So if you want instantiation this template,must send a template class as argument for template.
 *
 *	And also,you can use friend function in template class.
 *	-
 *		friend function with template class have three for classic.
 *
 *		One : Is not template friend.
 *		Two : Bound template friend,that is the type of friend to decide by the type from instantiation.
 *		Three : Unbound template friend,that is friend for all types.Specialization of friend,them are friend with specialization of class with anytype
 *
 *		Attention : When you use template friend function in classic,in prototype must use generic convertion. <...>
 *			
 *		E.g.
 *
 *			one : 
 *				template<class Any>
 *				class EX
 *				{
 *					friend type Func(vars-list);
 *					...
 *				};
 *				
 *				This friend function could access to all instantiation of class EX.It will become to all instantiation'friend.
 *
 *
 *			two : 
 *				
 *				//	Declare outside of class.
 *
 *				template<class Type>
 *				type Func(var-list);
 *
 *				template<class Any>
 *				class EX
 *				{
 *					
 *					//	Declare again and make it as a friend function of this class.
 *
 *					friend type Func<Any>(vars-list);
 *					...
 *				};
 *
 *				Its type had limit by class EX,and this friend function'type is as same as instantiation of class EX.
 *				<This bound template friend,must declare prototype as a template of the friend function and outside of clas.>
 *				<Instantiate type parameter must as same with class.>
 *
 *			three : 
 *				template<class Any>
 *				class EX
 *				{
 *					template<Typename Class> friend type Func(vars-list);
 *					...
 *				};
 *
 *				All instantiations of friend function,they could access to all instantiations of class EX.
 *
 *
 *
 *	Template class is the basic of STL.STL is basic for Generic programming.
 *
*/ 

namespace CLASS{

	using namespace std;

	template<class Any=int>
	class BASE				//	A template of class.Type is normal-type 'Any'.
	{
		private:			//	private members.
			Any value1;
			Any value2;	
		public:				//	public members.
			BASE();			//	Default build function.
			~BASE();		//	Clear function.

			void View_Value1(void)const;
			void View_Value2(void)const;
	};

//	Here deine a template class with specialization.

	template<>
	class BASE<const char*>				//	explicit speialization with 'char*'
	{
		private:				//	private members.
			char* value1;
			char* value2;
		public:					//	public members.
			BASE();				//	Because the default argument can not be using in explicit-specialization.
			BASE(const char* tmp1,const char* tmp2);
			~BASE();

			void View_Value1(void)const;
			void View_Value2(void)const;
	};		

/////////////////////////////////////////////////


//	Deinition of template<class Any> class BASE{ ... };
//	Style : template<class Type>Class_NAME<Type>::Func_NAME(vars-list)
//		{
//			....
//		}


template<class Any>		//	At here,if you want set default type for template 'class Any=int' or another TYPE,here does not need that 'Any=int'.
BASE<Any>::BASE()
{
	cout<<"Hint,created a template class!"<<endl;
	value1=value2=1024;
}

template<class Any>
BASE<Any>::~BASE()
{
	cout<<"Hint,cleaned a template class!"<<endl;
	value1=value2=0;
}

template<class Any>
void BASE<Any>::View_Value1(void)const
{
	cout<<"Value one = "<<value1<<endl;
	return;
}
template<class Any>
void BASE<Any>::View_Value2(void)const
{
	cout<<"Value two = "<<value2<<endl;
	return;
}


/////////////////////////////////////////////////
//
//	Definition of template<> class BASE<char*>{ ... };

//	Attention : At the time of you are defining function of explicit-specialization template class,remember that 'template<>' is can not has be 
//	writting in the front of function'definition.
//	|
//	|
//template<>			//	Here is a error,if you wrote it,will be throwing 'does not match any template declaration' away.

BASE<const char*>::BASE()
{
	value1=new char[64];
	value2=new char[64];
	if (value1 == NULL || value2 == NULL)
	{
		cerr<<"Can not get memory for private members."<<endl;
		exit(-1);
	}
	else;

	strncpy(value1,"NULL",64);
	strncpy(value2,"NULL",64);

	cout<<"Hint,created a template class with const char*!"<<endl;

}

//template<>
BASE<const char*>::BASE(const char* tmp1,const char* tmp2)		//	Here,you do not use default arguments in template class explicit-specialization
{
	value1=new char[64];
	value2=new char[64];
	if (value1 == NULL || value2 == NULL)
	{
		cerr<<"Can not get memory for private members."<<endl;
		exit(-1);
	}
	else;

	strncpy(value1,tmp1,64);
	strncpy(value2,tmp2,64);

	cout<<"Hint,created a template class with const char*!"<<endl;
}

//template<>
BASE<const char*>::~BASE()
{
	if (value1 != NULL && value2 != NULL)
	{
		delete[] value1;
		delete[] value2;
		cout<<"Hint,cleaned a template class with char*!"<<endl;
	}
	else
	{
		cerr<<"Can not recycle memory for private members."<<endl;
		exit(-1);
	}
}

//template<>
void BASE<const char*>::View_Value1(void)const
{
	cout<<"Value one = "<<value1<<endl;
	return;
}

//template<>
void BASE<const char*>::View_Value2(void)const
{
	cout<<"Value two = "<<value2<<endl;
	return;
}




}

//	Define a namespace.

int main(void)
{
	using namespace CLASS;
	
	//	First statement a template class with 'int'.
	
	BASE<> subject1;				//	Because Any=int,so here will be using default type.Could save null in center of <>,but '<>" is 
							//	must.

	//	Second statement a template class with 'char*'.

	BASE<const char*> subject2("KKSK","FUBUKI");	

	cout<<"First,view value from template class with 'int' - "<<endl;
	subject1.View_Value1();
	subject1.View_Value2();

	cout<<"Second,view value from template class with 'char*' - "<<endl;
	subject2.View_Value1();
	subject2.View_Value2();


	cout<<"\nOver...Exitting..."<<endl;
	return 0;
}




