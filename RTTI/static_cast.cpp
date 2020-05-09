#include<iostream>

using namespace std;

int main(void)
{

	int Test(1024);

	int* I1(I1);

//	long int* t1;

//	char* c1;

//	double* d1;

//	int i1;

	void* v1(NULL);

	if (v1=static_cast<void*>(I1))
		cout<<"int* could vonvert to a void* with implicit !!\n";
	else
		cout<<"int* could not convert to a void* with implicit !!\n";


/*	Beginning at there,all are invalid convertions.
 
	if (t1=static_cast<long int*>(I1))
		cout<<"int* could convert to long int* with implicit !!\n";
	else
		cout<<"int* could not convert to long int* with implict !!\n";

	if (c1=static_cast<char*>(I1))
		cout<<"int* could convert to char* with implicit !!\n";
	else
		cout<<"int* could not convert to char* with implicit !!\n";

	if (d1=static_cast<double*>(I1))
			cout<<"int* could not convert to double* with implicit !!\n";
	else
			cout<<"int* could not convert to double* with implicit !!\n";

	if (i1=static_cast<int*>(Test))
			cout<<"int value could convert to int* with implicit !!\n";
	else
			cout<<"int value could not convert to int* with implicit !!\n";
*/

/*	if (i1=static_cast<int>(I1))
		cout<<"int* could convert to a int value with implicit !!\n";
	else
		cout<<"int* could not convert to a int value with implicit !!\n";
*/	



	return 0;
}
