#include<iostream>
using namespace std;

//	Process will use throw,try mechanisim to catch error and begining stack return.

short int Error_code=0;				//	Global variable as error_code.

void Test_Func(int &arg) throw(const char*);	//	Function : Test_Func change value of argument,after the error was be detected by it,change Error_code.
						//	throw(const char*) is specifing the typr for aberrant.If it is throw(),
						//	specifing could not trigger a error by this Function.


int main(void)
{
	int arg(0);
	do
	{

		Error_code=0;

		cout<<"Please input a value for variable arg (1024-quit) : ";cin>>arg;	//	Get input from input-stream.cin is saving \n in input-stream.
		try{
			Test_Func(arg);							//	Danger zone,Test_Func() will be calling at here.
		}
		catch(const char* error_string)						//	Catch error from try,and processing it.
		{
			cout<<error_string<<endl<<"Error_code = "<<Error_code<<endl;	//	error_string when error was be caught,it will be assignment to
											//	a string by throw return.
			cout<<"In catch modelue,arg = "<<arg<<endl;
			continue;							//	Back to head of cycle.
		}
		cout<<"Normal arg = "<<arg<<endl;

	} while(Error_code != 1);

	cout<<"Exitting..."<<endl;
	return 0;
}

void Test_Func(int &arg) throw(const char*)	//	arg is input from cin and it must is greater than 10,if not then throw error.
{
	if (arg < 10)
	{
		Error_code=-1;			//	Change error_code.
		throw "The argument'value is less than 10.";	//	Go back to main.
	}
	else if (arg == 1024)
	{
		Error_code=1;			//	When the Error_code is equal 1024,cycle do{}while in main to exitting.
		return;
	}
	else
		arg*=2;				//	Change arg.

	//	The modelue if-else could be overwirte to switch(){} .

	return;
}

