#include<iostream>

using namespace std;


namespace {

	class BASE{
		public:
		
			virtual void View(int* Para)
			{
				size_t SI(sizeof(Para));			//	Get size of parameter.
				cout<<"In base classic.Get parameter - size is "<<SI<<endl;
				cout<<"Value - "<<*Para<<"Address - "<<Para<<endl;			//	View value
			}
	};

	class INHERIT:public BASE{
		public:
			virtual void View(int* Para)
			{
				cout<<"In inherit classic,value - "<<*Para<<" Address - "<<Para<<endl;
			}
	};
}




int main(void)
{

	int Test(1024);

	//	Make object 
	class BASE base;
	class INHERIT inherit;
	//	Classic pointers.
	class BASE* baseP(&base);
	class INHERIT* inheritP(&inherit);

	//	Use dynamic_cast.
	
	if (inheritP=dynamic_cast<class INHERIT*>(baseP))	//	If could not convert for it,return NULL.
	{
		cout<<"Convert classic 'class BASE*' to 'class INHERIT*' - "<<endl;
		inheritP->View(&Test);				//	Call
	}
	else
	{
		cout<<"Can not convert 'class BASE*' to 'class INHERIT*' - "<<endl;
		if (inheritP)
			;
		else
			inheritP=&inherit;
		inheritP->View(&Test);				//	Call method which is virtual and in class INHERIT.
		baseP->View(&Test);				//	Call method which is virtual and in class BASE.
	}



	return 0;
}
