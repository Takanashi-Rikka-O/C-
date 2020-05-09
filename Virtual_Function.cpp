#include<iostream>

using namespace std;

namespace{

	class A{
	
		public:
			A()
			{
				cout<<"Classic Object - A had been created!\n";
			}
			virtual ~A()
			{
				cout<<"Classic Object - A had been deleted!\n";
			}
			virtual class A* Show(int* Var)
			{
				cout<<"A Received int "<<*Var<<" - ";
				return this;
			}
			virtual const char* Show(const char* Str)
			{
				cout<<"A Received str "<<Str<<" - ";
				return Str;
			}
			virtual float* Show(float* Val)
			{
				cout<<"A Received float "<<*Val<<" - ";
				return Val;
			}

			virtual void Show(void)
			{
				cout<<"This A!\n";
			}
	};

	class B:public A{

			public:
				B()
				{
					cout<<"Classic Object - B had been created!\n";
				}
				~B()
				{
					cout<<"Classic Object - B had been deleted!\n";
				}

				virtual class B* Show(int Var)
				{
					cout<<"B Received int "<<Var<<" - ";
					return this;
				}

				virtual void Show(void)
				{
					cout<<"This B!\n";
				}
	};
}

int main(void)
{
	class A* Aobj=new class A;
	if (Aobj)
		;
	else
	{
		cerr<<"Can not create A object!\n";
		return 1;
	}

	class B* Bobj=new class B;
	if (Bobj)
		;
	else
	{
		cerr<<"Can not create B object!\n";
		delete Aobj;
		return 1;
	}

	class A* Basic=Bobj;		//	Use a basic class pointer point to a inherit class.
					//	Then can use this pointer to call functions of basic in inherit class.
		//	If would be calling function is a virtual function,so if Basic point to A,then call this function in A,if point to B,then call function
		//	in B.

	Basic->Show();		//	Call virtual function Show() by pointer.


	//	Now use object to call functions.
	(*Aobj).Show();
	(*Bobj).Show();


	class B* BTO=dynamic_cast<class B*>(Aobj);			//	Forcibly type-conversion Basic Pointer to Inherit Pointer.
				//	If Aobj could be converted to class B*,return a pointer it is not Null,otherwise return NULL.
	if (BTO)
		BTO->Show();
	else
		cout<<"Convert basic pointer to inherit pointer failed!\n";


	int VALUE(15);
	const char* STR="KKSK";
	float FLO(33.3);

	cout<<static_cast<void*>(Aobj->Show(&VALUE))<<endl;		//	A show int *

	cout<<static_cast<const void*>(Aobj->Show(STR))<<endl;		//	A show str *

	cout<<static_cast<void*>(Aobj->Show(&FLO))<<endl;		//	A show float *

	cout<<static_cast<void*>(Bobj->Show(VALUE))<<endl;		//	B show int

//	cout<<static_cast<void*>(Bobj->Show(&VALUE))<<endl;		//	B show int *

//	cout<<static_cast<void*>(Bobj->Show(&FLO))<<endl;		//	B show float	Had been Hided.
	



	delete Aobj;
	delete Bobj;

	return 0;
}
