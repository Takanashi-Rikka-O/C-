#include<iostream>

namespace CLASS{

	using std::cout;
	using std::cin;
	using std::endl;

	//	Nested namespace.

	class Calculation;			//	Statement at fornt.

	//	C++ using OOP-idea to carry attribues of things up,build a Class for the things.

}	

//	Namespace CLASS,in the file,have a global namespace and more than one of namespace are local-scope.

//	Outside of main{},there is global-scope,inside of main{},there is local-scope.
	
//	Using symbol '::' to parsing scope for namespace.Example : using namespace CLASS; The command will be importting elements of namespace to local
//	scope.
//	C++ is not recommend that using static to create a static-variable.


namespace CLASS{

	class Calculation
	{
		private:				//	Private members,access by class-members-method only.
			int l_value;
			int r_value;
		public:					//	Public members,could be accessed by Object of this class.
			
		//	Calculation();			//	Default build method for class-Calculation.Build func haven't the type.
		//	Let we using style 2 on here.	//	Style 1.
			Calculation(int tmp1,int tmp2);	//	Build method for class-Calculation with overload.
							//	Style 2.
							//	You can assignmented for build-func,so it as default build-method.
							//	Default value to assignment is could defined at definition of func only.
							//	But Calculation() and Calculation(type=value) can not coexist at a class.
			~Calculation();			//	Clear-function for class-Calculation.This type of func is could have one only.

							//	Public member method,it's could access to private-members.
			int Adding(void);		//	Adding.
			int Subtraction(void);		//	Subtraction.
			int Multiplication(void);	//	Multiplication.
			int Division(void);		//	Division.	Division will be throwing accuracy away.
			void Change_value(void);	//	Change value for private.
	};	

	//	This definition is a little as same as definition of struct.
					

	Calculation::Calculation(int tmp1=1,int tmp2=1):l_value(tmp1),r_value(tmp2)	//	Initialize at list-type.Style 2,created a default build-func.
	{
		cout<<"Hint,the class Calculation'object was be created!"<<endl;
		cout<<"Left value= "<<l_value<<" Right value= "<<r_value<<endl;
	}
											//	Using list-type at base-class must use by name of private mems.
											//	But in the inherit-class,must using build func to initialize for
											//	implicit-base-class.
	Calculation::~Calculation()							//	At the time of expired for class-Calculation,auto exec.
	{
		l_value=-1;
		r_value=-1;
		cout<<"Hint,the class Calculation'object was expired!"<<endl;
	}
	//	Member-method could access to private members.

///////////////////////////////////////////////////////			Definition of public functions.
//	Type : 		Type Scope::F_name(vars-list){ }		If defined at class-scope,don't use Scope:: .
//	Type :		Type Scope::F_name(vars-list)const { }		'const' is specify that the function doesn't revise private-members.
	int Calculation::Adding(void)
	{
		return l_value+r_value;
	}

	int Calculation::Subtraction(void)
	{
		return l_value-r_value;
	}	
	
	int Calculation::Multiplication(void)
	{
		return l_value*r_value;
	}

	int Calculation::Division(void)
	{	
		return l_value/r_value;				//	Here will be throwing accuracy away. float/double-type -> int-type.
	}

	void Calculation::Change_value(void)
	{
		cout<<"Please enter left value : ";cin>>l_value;
		cout<<"Please enter right value : ";cin>>r_value;
		cout<<"Input over!"<<endl;
		return;
	}

///////////////////////////////////////////////////////

//	If you want to define for elements of namespace,you must use this style to definition.Append definition for elements of namespace.

}

//	Using a class must after of defintion.


int main(void)
{
	using namespace CLASS;				//	Import namespace to local scope for main{} .
	Calculation kksk;				//	Creat a object of class-Calculation.Method using implicit-build.
//	Calculation kksk2(11,11);			//	Creat a object of class-Calculation.Method using explicit-build.

	int Condition(1024);				//	Condition for executive.
	
	do
	{
		cout<<"CHA-0 ; ADD-1 ; SUB-2 ; MUL-3 ; DIV-4 ; EXIT-1024"<<endl;
		cout<<"Please enter selection : ";cin>>Condition;
		
		switch (Condition)			//	Use switch instead with if-else to put effectiveness up for process.
		{
			case 0:
				cout<<"Changing..."<<endl;
				kksk.Change_value();
				break;
			case 1:
				cout<<"Adding..."<<endl;
				cout<<"Result= "<<kksk.Adding()<<endl;
				break;
			case 2:
				cout<<"Subtraction..."<<endl;
				cout<<"Result= "<<kksk.Subtraction()<<endl;
				break;
			case 3:
				cout<<"Multiplication..."<<endl;
				cout<<"Result= "<<kksk.Multiplication()<<endl;
				break;
			case 4:
				cout<<"Division..."<<endl;
				cout<<"Result= "<<kksk.Division()<<endl;
				break;
			case 1024:
				cout<<"Executiving exition..."<<endl;
				break;
			default:
				cout<<"Behavior doesn't be defined..."<<endl;
		}


	} while (Condition != 1024);

	cout<<"Exitting..."<<endl;


	return 0;
}



