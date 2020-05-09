#include<iostream>
using namespace std;

void simple1(int x,int y=3);	//	Default pramement is be defined in function

int main(void)
{
	int x(2),y(1);

	cout<<"First x="<<x<<" y="<<y<<endl;
	simple1(x,y);	//	pramement 2
	cout<<"Second x="<<x<<" y=void"<<endl;
	simple1(x);	//	pramement 1

	return 0;
}

void simple1(int x,int y)	//	Function' define code,none default deine in here
{
	cout<<"x * y ="<<x*y<<endl;
	return;
}
