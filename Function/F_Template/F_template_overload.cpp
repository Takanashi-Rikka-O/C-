#include<iostream>
//					#include<cstring>	clib function sprintf() is not in string.h,it is in stdio.h.
#include<cstdio>
using namespace std;

//	Reference template overload.

template<class Any>
void Swap(Any **a,Any **b);		//	This Swap to swap string.

//	Method 1

template<class Any>
void Swap(Any &a,Any &b);		//	This Swap to swap value.

//	Method 2

int main(void)
{
	char* str1;char* str2;		//	Char point for method 1
	char a('A'),b('B');		//	Var for method 2.Initialztion A and B.

	str1=new char[11];
	str2=new char[11];		
					//	Get memory for str1 and str2.
	if (str1 == NULL || str2 == NULL)
	{
		cout<<"Can not get memory for str1 and str2.\nexitting..."<<endl;
		return -1;
	}
	else;

	cout<<"Method 1 swap strings : "<<endl;
	cout<<"Write string=KKSK to str1.Write string=ZA,WORLD to str2. str1 and str2 max-len=11."<<endl;
	sprintf(str1,"KKSK");		//	len=4+1
	sprintf(str2,"ZA,WORLD");	//	len=8+1
	cout<<"str1= "<<str1<<" Address= "<<static_cast<const void*>(str1)
		<<" str2= "<<str2<<" Address= "<<static_cast<const void*>(str2)<<endl;	//	View string and address.
	Swap(&str1,&str2);		//	Swap str1 and str2.Call Swap() method 1.
	cout<<"str1= "<<str1<<" Address= "<<static_cast<const void*>(str1)
		<<" str2= "<<str2<<" Address= "<<static_cast<const void*>(str2)<<endl;	//	View string and address.

	cout<<"\nMethod 2 swap value by var'quote : "<<endl;
	cout<<"a= "<<a<<" Address= "<<&a<<" b= "<<b<<" Address= "<<&b<<endl;
	Swap(a,b);			//	Swap a and b.Call Swap() method 2.
	cout<<"a= "<<a<<" Address= "<<&a<<" b= "<<b<<" Address= "<<&b<<endl;

	cout<<"\nReference over...exitting..."<<endl;

	delete[] str1;
	delete[] str2;
					//	Recycle memory from new.

	return 0;
}

template<class Any>
void Swap(Any **a,Any **b)		//	Definition method 1.Swap memory point.
{

/*
 *	This method 1 must be use the address point of *a and *b.
 *	If var list use 'Any *a,Any *b',the value of point is be sent,
 *	only using point'value cannot swap address for str1 and str2.
*/ 



#ifdef DEBUG
	cout<<"DEBUG : a'add= "<<a<<" b'add= "<<b<<endl;
	cout<<"DEBUG : *a= "<<static_cast<const void*>(*a)<<" *b= "<<static_cast<const void*>(*b)<<endl;
#endif

	Any* temp;			//	Statement a point the type is Any.
//
	temp=*b;
#ifdef DEBUG
	cout<<"DEBUG : temp= "<<static_cast<const void*>(temp)<<endl;
#endif			
	*b=*a;
	*a=temp;
//					Swap point.

#ifdef DEBUG
	cout<<"DEBUG : *a= "<<static_cast<const void*>(*a)<<" *b= "<<static_cast<const void*>(*b)<<endl;
#endif

	return;
}

template<class Any>
void Swap(Any &a,Any &b)		//	Definition method 2.Swap value by variable'quote.
{
	Any temp;			//	Statement a variable the type is Any.
//
	temp=b;
	b=a;
	a=temp;
//					Swap value.
	return;
}
