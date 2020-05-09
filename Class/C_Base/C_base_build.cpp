#include<iostream>

using namespace std;


namespace {

	class Base{		//	Class have three for types classic member.All have limits for type.

			//	'this' is a pointer and it point to a call object.
			//	If a object of class called member function,and in that function have a 'this' pointer,it point to call object.

		private:

		/*
 		*		If members have be defined in here,they could be accessed by other members of classic.
 		*	Could define data-object or function in there.And they all have limit is that only could be accessed by classic member.
 		*	And also could define class'definition in there.
  		*/

		(type) Name;	//	Object
		type func(...);	//	Function

		struct What{	//	A struct.And is a nested structure.
			...
		};
				//	Its scope is supported by definition scope.
				//	If definition scope in private zone,only that zone know them;if in protect zone,only that zone know them;if in
				//	public zone,also only that zone know tem.


		class What{	//	A class.And is not has-a,it is nested class.
			...
		};

		/*
 		* 		If you want use const object in class,have two for methods.
		*	One : const type name;	And then initialize in build function with 'members-list-initialization'.
		*	Two : enum {...};
		*
		*	Attention : If you use static variable in class,then all objects are instantiated will shared ones static object.
		*		So,ones changed that static object,all class objects will have be affected.
		*
		*/ 

		protect:

		/*
 		* 		There is also could define some data-object or function.And only could be accessed by classic member.But in inherit class,
 		* 	its public member could access to them straight,need not to use basic'member to call them.
 		*/ 

		public:

		/*
 		*		Also in there could define some data-object or function.But members in there could be accessed by outside of classic.
 		*/ 

		Base();		//	This is class'default build function.Does not return and receive nothing argument.
				//	If you did not define default build function,translater will auto to make it.

		Base(var-list);	//	This is a class build function,but it is not default.If you define it,and did not define default build function,
				//	translater would throw a error.You can use default argument to make it become a default build function.

		Base(class-name &);	//	This is a copy-build function,it except a cite of a class'.And the copy build function have models 
					//	'implicit' and 'explicit'.If you not defined copy build function,translater will auto to make it,but only 
					//	copy value.
		//	Use 'explicit' speciliter could set off to its implicit call.
		//	Default behavior,translater would use a build function which receive one a parameter as convert-function.But this feature is need not 
		//	in normal.So use 'explicit' could set down this feature for bulid function.


		~Base();	//	Class'clear function,when class object had been expire it will be calling with auto.But if it is own of a basic-class,
				//	must set it as virtual function as well.
		
		operator type-name();	//	Convert operator overload.It receive nothing argument,and must have return.On prototype is have not return,
					//	but must to return a value realy.

		type operator operate-symbolic(var-list);	//	Operator overload,all of operator overload,they must is members of class.

	};




}





