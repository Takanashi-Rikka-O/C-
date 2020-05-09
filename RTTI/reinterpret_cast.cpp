#include<iostream>

using namespace std;


namespace {

	struct test{

		short a;
	};


}

int main(void)
{

	struct test t1={1024};	//	Initialize at declare.

	cout<<"Member - a "<<t1.a<<" Address "<<&t1<<endl;

	struct test* p1(&t1);	//	A struct pointer.


	long int PV=(long int)p1;	//	Explicit convert pointer to long int.

	cout<<"Use explicit convertion,convert p1 - "<<p1<<" to a long int value - "<<PV<<endl;
	
	struct test* p2(NULL);

	if (p2=reinterpret_cast<struct test*>(PV))	//	Use reinterpret_cast to convert PV to a pointer and then assignment for p2 with that value.
	{
		cout<<"long int variable PV could convert to a struct test* !!\n";
		cout<<"Member - a "<<p2->a<<" Address "<<p2<<endl;
	}
	else
		cout<<"long int variable PV could not convert t oa struct test* !!\n";

	


	return 0;
}

