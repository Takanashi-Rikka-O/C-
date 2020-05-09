#include<iostream>

//	MI	--	Multiple Inheritance
/*
 *	--------BASE-----
 *	|		|
 *	HEIR1		HEIR2
 *	--------|--------
 *		HEIR3
 *
 *	HEIR1 and HEIR2 are succeed from BASE,the HEIR3 is succeed from HEIR1 adn HEIR2.If not statement virtual inherition,the HEIR3 will have two for BASE.
 *
 *	MI:
 *
 *		class BASE{};
 *
 *		class HEIR1:virtual public BASE
 *		{
 *			...
 *		};
 *
 *		class HEIR2:virtual public BASE
 *		{
 *			...
 *		};
 *
 *		class HEIR3:public HEIR1,public HEIR2
 *		{
 *			...
 *		};
 *
 *	Use virutal inherition to avoid that have two for BASE,otherwise can not use Multipele State to process .
*/ 


namespace CLASS{

	using namespace std;

	class BASE
	{
		//	BASE is provides that Calculation function.

		public:

		//	Define build function and clear function as hinter.

		BASE();
		~BASE();

		int Adding(const int & temp1,const int & temp2)const;
		int Subtraction(const int & temp1,const int & temp2)const;
		int Multiplication(const int & temp,const int & temp2)const;
		int Division(const int & temp1,const int & temp2)const;

		//	Operating.
	};

		//	For the int BASE::Adding() and int BASE::Adding_HEIR3()const,you can not use 'this' as argument send to not have 'const' function.
		//	Error: "dicards qualifiers.

	class HEIR1:virtual public BASE
	{
		//	HEIR1 is provides that the value of left.
		
		private:		//	private members.
			int L_value;		
		public:			//	public members.
		
		//	HEIR1 is have the data members,so must have build function.And HEIR3 can not to access the private members of HEIR1 directly,have to 
		//	statement some function to get datas.

			HEIR1();
			~HEIR1();

			int Get_Value_HEIR1(void)const;
			void Change_Value_HEIR1(const int temp);
		
		//	Read data from HEIR1 or write data to HEIR1.
	};

	class HEIR2:virtual public BASE
	{
		//	HEIR2 is provides that the value of right.
		
		private:		//	private members.
			int R_value;
		public:			//	public members.

		//	HEIR2 is have the data members,so must have build function.And HEIR3 can not to access the private members of HEIR1 directly,have to 
		//	statement some function to get datas.

			HEIR2();
			~HEIR2();
		
			int Get_Value_HEIR2(void)const;
			void Change_Value_HEIR2(const int temp);

		//	Read data from HEIR2 or write data to HEIR2.
	};

	class HEIR3:public HEIR1,public HEIR2
	{
		//	HEIR3 is provides the process function.

		private:		//	private members.
			///
		public:			//	public members.
		
		//	HEIR3 is responsible for process functions.So it have to statement some function to call method from the BASE class of itself.

		HEIR3()
		{
			cout<<"Hint,HEIR3() has been finished...!"<<endl;
		}

		~HEIR3()
		{
			cout<<"Hint,~HEIR3() has been finished...!"<<endl;
		}

		//	First define two for functions to update Left value and Right value.

		void Update_L(const int temp);
		void Update_R(const int temp);

		//	Second define four for functions to call method from virtual BASE.Because HEIR1 and HEIR2 is virtual public succeed from BASE,so HEIR3 -
		//	is only one for BASE.

		int Adding_HEIR3(void)const;
		int Subtraction_HEIR3(void)const;
		int Multiplication_HEIR3(void)const;
		int Division_HEIR3(void)const;

			

	};

//////////////////////////		MI	Multiple Inheritance.




//////////////////////////	Define BASE

BASE::BASE()
{
	cout<<"Hint,BASE() has been finished...!"<<endl;
}

BASE::~BASE()
{
	cout<<"Hint,~BASE() has been finished...!"<<endl;
}

int BASE::Adding(const int & temp1,const int & temp2)const
{
	return temp1+temp2;
}

int BASE::Subtraction(const int & temp1,const int & temp2)const
{
	return temp1-temp2;
}

int BASE::Multiplication(const int & temp1,const int & temp2)const
{
	return temp1*temp2;
}

int BASE::Division(const int & temp1,const int & temp2)const
{
	return temp1/temp2;
}

//////////////////////////	Define HEIR1

HEIR1::HEIR1()
{
	cout<<"Hint,HEIR1() has been finished...! Value has be initialized to 1."<<endl;
	L_value=1;	//	Assignment.
}

HEIR1::~HEIR1()
{
	cout<<"Hint,~HEIR1() has been finished...!."<<endl;
}

int HEIR1::Get_Value_HEIR1(void)const
{
	return L_value;
}

void HEIR1::Change_Value_HEIR1(const int temp)
{
	L_value=temp;
	return;
}

//////////////////////////	Define HEIR2

HEIR2::HEIR2()
{
	cout<<"Hint,HEIR2() has been finished...! Value has be initialized to 1."<<endl;
	R_value=1;	//	Assignment.
}

HEIR2::~HEIR2()
{
	cout<<"Hint,~HEIR2() has been finished...!"<<endl;
}

int HEIR2::Get_Value_HEIR2(void)const
{	
	return R_value;
}

void HEIR2::Change_Value_HEIR2(const int temp)
{
	R_value=temp;
	return;
}

//////////////////////////	Define HEIR3

//	First.

void HEIR3::Update_L(const int temp)
{
	HEIR1::Change_Value_HEIR1(temp);
	return;
}

void HEIR3::Update_R(const int temp)
{
	HEIR2::Change_Value_HEIR2(temp);
	return;
}

//	Second.
int HEIR3::Adding_HEIR3(void)const
{
	int tmpL,tmpR;
	tmpL=tmpR=0;
	
	tmpL=HEIR1::Get_Value_HEIR1();
	tmpR=HEIR2::Get_Value_HEIR2();
	//	Get data.

	return BASE::Adding(tmpL,tmpR);		//	Call function Adding() of BASE.

}

int HEIR3::Subtraction_HEIR3(void)const
{
	int tmpL,tmpR;
	tmpL=tmpR=0;
	
	tmpL=HEIR1::Get_Value_HEIR1();
	tmpR=HEIR2::Get_Value_HEIR2();
	//	Get data.

	return BASE::Subtraction(tmpL,tmpR);	//	Call function Subtraction() of BASE.

}

int HEIR3::Multiplication_HEIR3(void)const
{
	int tmpL,tmpR;
	tmpL=tmpR=0;
	
	tmpL=HEIR1::Get_Value_HEIR1();
	tmpR=HEIR2::Get_Value_HEIR2();
	//	Get data.

	return BASE::Multiplication(tmpL,tmpR);	//	Call function Multiplication() of BASE.

}

int HEIR3::Division_HEIR3(void)const
{
	int tmpL,tmpR;
	tmpL=tmpR=0;
	
	tmpL=HEIR1::Get_Value_HEIR1();
	tmpR=HEIR2::Get_Value_HEIR2();
	//	Get data.
	
	if (tmpR == 0)
	{
		cerr<<"The Right_Value is zero at the Division."<<endl;
		return -1;
	}
	else
		return BASE::Division(tmpL,tmpR);	//	Call function Division() of BASE.

}

//////////////////////////

}

//	Define a namespace.


int main(void)
{
	using namespace CLASS;

	HEIR3 sub;			//	Build a subject of HEIR3.Using default build function.
	

	//				First.
	cout<<"\nFirst - \n";

	cout<<"Adding - "<<sub.Adding_HEIR3()<<endl;
	cout<<"Subtraction - "<<sub.Subtraction_HEIR3()<<endl;
	cout<<"Multiplication - "<<sub.Multiplication_HEIR3()<<endl;
	cout<<"Division - "<<sub.Division_HEIR3()<<endl;	
	
	//				Second.
	
	cout<<"\nSecond - \n";

	int tmpL,tmpR;

	cout<<"Please input value for Left : ";	cin>>tmpL;
	cout<<"Please input value for Right : ";cin>>tmpR;

	sub.Update_L(tmpL);sub.Update_R(tmpR);			//	Update date-members.

	cout<<"Calculation again - "<<endl;

	cout<<"Adding - "<<sub.Adding_HEIR3()<<endl;
	cout<<"Subtraction - "<<sub.Subtraction_HEIR3()<<endl;
	cout<<"Multiplication - "<<sub.Multiplication_HEIR3()<<endl;
	cout<<"Division - "<<sub.Division_HEIR3()<<endl;	

	cout<<endl<<"Over...Exitting...\n"<<endl;

	return 0;
}

