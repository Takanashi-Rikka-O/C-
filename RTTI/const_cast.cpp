#include<iostream>

using namespace std;

int main(void)
{

	const int Test(1024);		//	Test variable.		Test use 'const' or not use 'const',have two stuations.
					//	If use const,use volatilep can not change Test'value.
					//	But not use const,volatilep could change Test'value.
					//	But all stuations the addresses are as same.

	//	Pointer.
	const int* tmp1(&Test);

	cout<<"Now test const_cast<>()!"<<endl;

	cout<<"Test - "<<Test<<" - Address - "<<&Test<<endl;
	cout<<"tmp1 -> Test "<<*tmp1<<" - Address -"<<tmp1<<endl;

	cout<<endl<<"Use int* volatilep=const_cas<int*>(tmp1)"<<endl<<endl;
	int* volatilep=const_cast<int*>(tmp1);	//	Delete 'const' for tmp1;

	//	Change value.
	*volatilep=2048;

	cout<<"*volatile - "<<*volatilep<<" - Address - "<<volatilep<<endl;
	cout<<"Test - "<<Test<<" - Address - "<<&Test<<endl;
	cout<<"tmp1 -> Test "<<*tmp1<<" - Address -"<<tmp1<<endl;





	return 0;
}
