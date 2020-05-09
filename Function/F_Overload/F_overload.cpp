#include<iostream>
#include<cstring>
using namespace std;

//	Function overload

void Overload(char* str,int str_len);			//	plane 1
			
void Overload(int x,int y);				//	plane 2

void Overload(const char* str1,const char* str2);	//	plane 3

int main()
{
	char* str1;char* str2;	//	Here are two char_pointes,they will be using by overload3 || overload1
	int str_len(0);		//	Here a int_variable,it will be using by overload1
	int x(0),y(0);		//	Here are two int_variables,they will be using by overload2

	int &x1=x,&y1=y;	//	Here are two variables of int_quote,feature is change to values of x1 and y1

	str1=new char[11];
	str2=new char[11];
	if (str1 == NULL || str2 == NULL)
	{
		cout<<"Can't get memories for str1 and str2"<<endl;
		return 0;
	}
	else;

	cout<<"First Overload : "<<endl;
	cout<<"Please enter string for str1 : ";
	cin.getline(str1,11);			//	cin.getline,class method;read a line of string and max_count= value-1;cin.getline can throw '\n' away.
	cout<<"Call to overload - \n";
	str_len=strlen(str1);
	Overload(str1,str_len);

	//	part one
	
	cout<<"Second Overload : "<<endl;

	cout<<"Please input values for x and y \n";
	cout<<"x= ";cin>>x1;
	cout<<"y= ";cin>>y1;
	//	Care : If use 'cin' to reading data from input-stream,'cin' will be staying '\n' in input-stream.

	cout<<"Call to overload - \n";
	Overload(x,y);

	//	part two
	
	cout<<"Third Overload : "<<endl;
	cout<<"Please enter string for str2 : ";
	cin.get();
	//	cin.get,clear to '\n' from input-stream.
	cin.getline(str2,11);
	cout<<"Call to overload - \n";
	Overload(str1,str2);

	//	part three

	//	exit
	delete[] str1;		//	Delete[],use this method to delete the memory from new.
	delete[] str2;		//	Delete[] can delete a part of memory from new.
	
	return 0;
}


void Overload(char* str,int str_len)		//	plane 1
{
	cout<<"In function Overload method one,var list : char* str,int str_len.\n";
	cout<<"Feture : View string and change chars of string.\n";
	cout<<"str= "<<str<<endl;
	cout<<"Now +1 to chars of str str_len= "<<str_len<<" : ";
	for (int i(0); i < str_len; ++i)
		str[i]+=1;
	cout<<"str= "<<str<<endl;
	cout<<"exitting...\n";
	return;
}
			
void Overload(int x,int y)				//	plane 2
{
	cout<<"In function Overload method two,var list : int x,int y.\n";
	cout<<"Feture : Calculation - multiplication x and y.\n";
	cout<"x * y = ";cout<<x*y<<endl;
	cout<<"exitting...\n";
	return;
}

void Overload(const char* str1,const char* str2)	//	plane 3
{
	cout<<"In function Overload method three,var list : const char* str1,const char* str2.\n";
	cout<<"Feture : View strings and their memory address.\n";
	cout<<"str1= "<<str1<<" , str1&= "<<static_cast<const void*>(str1)<<endl;
	cout<<"str2= "<<str2<<" , str2&= "<<static_cast<const void*>(str2)<<endl;
	cout<<"exitting...\n";
}


