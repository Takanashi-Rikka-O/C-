#include<iostream>
#include<cstdlib>
using namespace std;

void View_string(const int &nums,char** string_set);			//	Function : View string from command-line.
									//	Compile error when use const char** as argument.
									//	Invalid conver from char** to const char** .
int main(int argc,char* argv[])
{
	if (argc < 2)
	{
		cerr<<"Command-line arguments < 2."<<endl;
		abort();						//	abort(),after exited put error format.
	}								//	When the argc is less with 2,process exitting.
	else;

	cout<<"Call View_string - "<<endl;				//	Hint.
	View_string(argc,argv);						//	Send parameter argv to View_string.
	cout<<"Exitting..."<<endl;
}

void View_string(const int &nums,char** string_set)
{
	for (int count=0; count < nums; ++count)
		cout<<"String from command-line : "<<count+1<<" = "<<string_set[count]<<endl;	//	string_set is a array of char-pointes.
	return;
}
