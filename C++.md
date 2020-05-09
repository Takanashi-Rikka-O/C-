#	C++	NOTE

---

##	Operator priority and Combine Nature

	High

	1-------|	::			
	2-------|	(Expression),func(),type(expr),[]		(L-R)
		|	->,'.','++,-- (suffix)'
		|	const_cast,dynamic_cast
		|	reinterpret_cast,static_cast
		|	typeid
	3-------|	!,~,'+,- (symbolic)','++,-- (prefix)'		(R-L)
		|	&,*,()expr,sizeof,new,new[]
		|	delete,delete[]
	4-------|	'.*','->*'					(L-R)
	5-------|	*,/,%						(L-R)
	6-------|	+,-						(L-R)
	7-------|	<<,>>						(L-R)
	8-------|	<,<=,>=,>					(L-R)
	9-------|	==,!=						(L-R)
	10------|	&	(and)					(L-R)
	11------|	^	(xor)					(L-R)
	12------|	|	(or)					(L-R)
	13------|	&&						(L-R)
	14------|	||						(L-R)
	15------|	:? 'x=(a <,.. b)?v1:v2;'			(R-L)
	16------|	=,*=,/=,%=,+=,-=,&=,^=,|=,<<=,>>=		(R-L)
	17------|	throw err					(L-R)
	18------|	,						(L-R)

	Low

##	Storage-Class-Specifier and CV-Qualifier	

	Specifier : 
		auto			Auto attrbute,auto create and auto delete.
		register		Request save variable into register.
		static			Static,not auto delete,and in memory only have one a object.
		extern			Extern,is not a declare with definition,only declare in somewhere have that object.
		mutable			Mutable,change const tag and then could change for the const variable.
	Qualifier :
		const			Const,can not change to variable.
		volatile		Volatile,tell translater do not optimization for the object.


---


##	Operator overload :

&emsp Could be overloaded : 

	|:-:|:-:|:-:|:-:|:-:|:-:|
	|+|-|*|/|%|^|
	|&|\||~=|\!|=|<|

	|>|+=|-=|*=|/=|%=|
	|^=|&=|\|=|<<|>>|>>=|
	|<<=|==|!=|<=|>=|&&|
	|\|\||++|--|,|->*|->|
	|()|[]|new|delete|new[]|delete[]|

&emsp Could not to be overloaded : 

	|:-:|:-:|:-:|:-:|:-:|
	|sizeof|\.|\.*|::|?:|
	|typeid|const_cast|dynamic_cast|reinterpret_cast|static_cast|

&emsp Attention : These operator must be operation in class_function.

*
    + =
    + ()
    + []
    + ->
*

&emsp **Operation can not change attributes of operator.**

---

##	Function


###	Function overload

&emsp Example :  
&emsp&emsp void Func(prameter1,prameter2);  
&emsp&emsp void Func(prameter1);

&emsp&emsp **Vars list is not as same,but Function_name as same.** 
$emsp$emsp **Type could is not as same,but name is must as same as others.**   

---


###	Default value of function arguments

&emsp Example :  
&emsp&emsp void Func(parmeter1,prameter2=value);

&emsp&emsp **If setting default_value to function variable,the assignment order must be right to left.**  

---


###	Function template  

&emsp Example :  
&emsp&emsp template<class Any>void Func(Any var);&emsp&emsp normal.  
&emsp&emsp template<>void Func<type>(type var);&emsp&emsp explicit-specialization for template,its definition is not the same as tempate-normal.  
&emsp&emsp template void Func<type>(type var);&emsp&emsp explicit-instantiation for template,g++ will make a template-instantiation for template with type.  
&emsp&emsp template<> and template ,they are not as same as one a type in code.

---

##	Standard I/O

###	cin istream class

####	cin.get and cin.getline

&emsp **cin.get() is saving enter in the input-stream,cin.getline() is not save enter in the input-stream.**  

###	cout ostream class

####	Prototype : ostram & operator << (type);
####	Other method of ostream class : 

&emsp&emsp	ostream & put(character);	//	Recevie a value and show it on the screen.
&emsp&emsp	basic_ostream<char T,traits> & write(const char_type* s,streamsize n);	//	Receive a address with char type and a size of it.

####	ostream class operator : 

&emsp&emsp	endl	//	Output a '\n'.
&emsp&emsp	flush	//	Flush buffer of cout.

####	cout format : (operator)

&emsp&emsp	ostream & hex(cout); cout<<hex;	//	Set output format as hex for cout.	Not temporary attribute.
&emsp&emsp	ostream & oct(cout); cout<<ocx;	//	Set output format as ocx for cout.	Not temporary attribute.
&emsp&emsp	ostream & dec(cout); cout<<dec;	//	Set output format as dec for cout.	Not temporary attribute.

&emsp&emsp	int width();	//	Return the field width is currently.
&emsp&emsp	int width(int i);	//	Change the field width to value i.	Temporary attribute.

&emsp&emsp	fill(character);	//	Set character to full null space.	Not temporary attribute.

&emsp&emsp	precision(int w);	//	Set precisely to show for the bits of float data.	Not temporary attribute.

&emsp&emsp	fmtflags setf(fmtflags);	//	Return old attribute.
&emsp&emsp		Attribute of setf could is : 		Not temporary setting.

							ios_base::showpoint		//	Show decimal places.
							ios_base::boolalpha		//	Bool value use 'true' or 'false' to put.
							ios_base::showbase		//	Add prefix for cardinal number.
							ios_base::uppercase		//	Hex output use 'E' method to put it.
							ios_base::showpos		//	Show symbol of number. + || -

&emsp&emsp	fmtflags setf(fmtflags,fmtflags);	//	Multi-control-attributes.	Return old attribute.	First use '0' to off that attribute.
			Attributes of setf could are : 		Not temporary setting.
								
							Second				First

							ios_base::basefield		ios_base::dec		//	Dec cardinal number.
											ios_base::oct		//	Oct cardinal number.
											ios_base::hex		//	Hex cardinal number.

							ios_base::floatfield		ios_base::fixed		//	Field point countion.
											ios_base::scientific	//	Scientific countion.
											
							ios_base::adjustfield		ios_base::left		//	Left align.
											ios_base::right		//	Right align.
											ios_base::internal	//	Prefix left align,value right align.

&emsp&emsp	cout.unsetf(Attribute);		//	Close a attribute.

&emsp&emsp	Standard controlor : 		//	cout<<Standard_Operator;

		Operator		Call					Operator		Call
	
		boolalpha		setf(ios_base::boolalpha)		nouppercase		unsetf(ios_base::uppercase)
		noboolalpha		unsetf(ios_base::boolalpha)		iternal			setf(ios_base::internal,ios_base::adjustfield)
		showbase		setf(ios_base::showbase)		left			setf(ios_base::left,ios_base::adjustfield)
		noshowbase		unsetf(ios_base::showbase)		right			setf(ios_base::right,ios_base::adjustfield)
		showpoint		setf(ios_base::showpoint)		dec			setf(ios_base::dec,ios_base::basefield)
		noshowpoint		unsetf(ios_base::showpoint)		hex			setf(ios_base::hex,ios_base::LIbasefield)
		showpos			setf(ios_base::showpos)			oct			setf(ios_base::oct,ios_base::LIbasefield)
		unshowpos		unsetf(ios_base::showpos)		fixed			setf(ios_base::fixed,ios_base::floatfield)
		uppercase		setf(ios_base::uppercase)		scientific		setf(ios_base::scientific,ios_base::floatfield)

---


##	Aberrant Exception Handler

&emsp In the program language C++,you can use by throw-try-catch module to deal with error.  
&emsp&emsp Example :  
		try{
		...
		}
		catch(void arg)
		{
		...
		}

		...

		throw void-arg;  

&emsp&emsp When code-unit in try{} was trigger a error,process will be going back to try{} and dealing the error with has catch.
&emsp&emsp In catch(void arg),the arg is from throw.(void-arg),error info would be coping to the 'void arg'.
&emsp&emsp Specify aberrant for function :  
&emsp&emsp Example :  
		void Test_Func(void) throw(type);
&emsp&emsp type will be specifing error for function,so throw could return aberrant for type to catch().If type is equal null that is throw(),so specify  
&emsp&emsp the Function could not to trigger a error.Whether that function triggers exception and other with type,process will be interrupted.(Default)

&emsp&emsp You can use function-'terminate()' to change default behavior when catch a 'unexpected exception',that function is contained in 'exception'.
&emsp&emsp terminate() default call abort(),but could use set_terminate() to change that behavior.
&emsp&emsp	typedef void ('*'terminate_handler)();
		terminate_handler set_terminate(terminate_handler f)thorw();

&emsp&emsp 'std::bad_exception',this is a classic.If exception had been trigger and not match exception type,and in that exception type have not contain 
&emsp&emsp 'std::bad_exception',program will call terminate().If contained that classic,then not match exception will be insteading by 'std::bad_exception'.

&emsp&emsp If Func1 called Func2,but Func2 was triggered a aberrant.At this time,process will be starting unwinding the stack.Go back to function it called  
&emsp&emsp Func1 and dealing error with catch().

---


##	Class

###	Basic

&emsp&emsp Statement and definition :  
		class Name
		{
			private:
				...
			protected:
				...
			public:
				...
		};

&emsp&emsp private members could be accessed by public-method only.
&emsp&emsp protected members could be accessed by public-method of Inherit-class from base-class only.
&emsp&emsp public members could be accessed by object of class and Inherit-class from base-class.

&emsp&emsp In a class,only have a clear-method and a default build method.But normal build-method could be overloaded.
&emsp&emsp And have a implicit convertion of build method.If build method receive a paramter only,it would be using to as type convert function.
&emsp&emsp 'explicit' could set down for that attrbute.
&emsp&emsp Example : 

			Name(){ }		//	Default-build-method style 1.
			Name(type var){ }	//	Overload for build-method.

			Name(type var=value){ }	//	Default-build-method style 2.

			**But in a class can not have two for default builds.**

			//	style 1 and style 2 can not coexist.

			Name(type var=value)member_name(var){ }	
			//	Initialization method with members-list.If using at Inherit-class,must be use default-build-method of base-class to instead the
			//	private_member_name; build_base_method(var).However,Inherit-class can using members-list to initialize the private_member_name
			//	with own it.


			~Name(){ }		//	Clear-method only one.
						//	At the time of expired with class-object,this method will be auto executing.But you can executing by  
						//	manual.

&emsp&emsp In class,it can be have one a copy function.
&emsp&emsp Example : 

			Class-Name(const Class-Name & );	//	Prototype.
			Class-Name::Class-Name(const Class-Name & tmp)	//	Definition
			{
				...
			}

&emsp&emsp It is as same as you saw,copy method is not return anything.Use 'const' could protect for real paramter.
&emsp&emsp You could do not define copy function,translater can auto define it.But if you used pointer in class,auto defined copy function only do that  
		copy as same values to the other class-object.So pointer is only a value,does not get new memory and copy real datas.
&emsp&emsp Define a copy function,and change its behavior to do more works at the time of copy class and class.You can get new memory with 'new' and copy
		real datas to new memory.


			type P_Method(vars-list){ }	//	Method of class member.It is could access to private-members.
			type P_Method(vars-list)const{ }	//	Method of class member.It does not revising private-members.

&emsp&emsp this pointer.this pointer in the method of class,this pointer is direction to a object it called this method.
&emsp&emsp *this is object,this is address of current object.

&emsp&emsp array of class-object : 

		Name array[num]={Name(),Name(var),Name(var1,var2)};

		If you does not specify that build-method for class elements of class array,that is will auto creat object with default-build-method.
		Using array[0] to access with first of impcilit-object ...


###	Operation symbolics overload

&emsp&emsp operator : 
	
		class Name
		{
			private:
				...
			public:
				...
			type operator '+|-|..' (vars-list);		//	Statement a operator function for class.
		};

		Remember that the operator function of class,can not change the attribues of operations.
		
		After,you can using Name.operator '+|-|...' (parameter) or Object 'operator' prameter.

####	Convert operator overload

&emsp&emsp Example : 

		class Name
		{
			private:
				...
			public:

			operator type-name();
		}

		That prototype as same as you saw,it receive nothing paramter,and it could return a value for type convertion.
		If you defined E.g. 'operator int()',then you can use 'int var=class-object;' or 'int var=int(class-object);' to convert type.

###	Friend function

&emsp&emsp friend function for class,keyword 'friend' is wrote at front of prototype only.
&emsp&emsp Example : 
		class Name
		{
			private:
				...
			public:
				...
				friend type Function(vars-list);//	Statemented a friend function for Name.
								//	friend function can access to private with direction.
		};

		Function(vars-list)				//	Definition of friend function for class-Name.
		{
			...
			'example : have object of Name in vars-list,Temp1'
			'Allow using Temp1.private_member_name to access the members of class-Name private.'

		}

		You could use ' friend type operator '+|-|...' (vars-list); ' to defined a friend function for operator.




&emsp&emsp The methods of friend class,they are could to access the members of base class.
&emsp&emsp Example : 
			class B;			//	Statement for class B is before the class A.
							//	Because the definiton of class A,that have code: friend class B;
							//	g++ must have be know that the statement of class B is before the class A.

			class A
			{
				...
				friend class B;		//	The methods of class B could access to the members of class A.
							//	So these will become the friend method for class A.
			}

			class B
			{
				...
			}


###	Const member in classic

&emsp&emsp If you want to using the const member in class,you have two of modus to statement and initialize.
&emsp&emsp Example : 
		One : 
			class A
			{
				const type name;

				A():name(value) { }
			}

		Two : 
			class A
			{
				enum {name=value};
			}

&emsp&emsp Modus one is must to initialize the const member at the build method with members-initialize-list.enum modus does not need that.

###	Class Inherition

		Draw : 
					Inherit class
						|
						|
						|
						|
					Basic class

			Convert Basic class to Inherit class is 'Upwards force classic convertion'.This is allowed in 'is-a' inherit.Inherit class is a Basic
			class,this is right.Because Inherit class inherited from Basic class.
			Convert Inherit class to Basic class is 'Downwards force classic convertion'.This is not allowed in 'is-a' inherit.Inherit class is a 
			Basic class,because it inherited from Basic class.But Basic class is not a Inherit class.

&emsp&emsp Inherit : 
&emsp&emsp Example :  
			class A
			{
				...
			};
			class B : public A
			{
				...
			};

&emsp 		class B is Inherit from A,it can succeed public members of class A as public members of itself.But it did not succeed the private members of 
		class A.

&emsp&emsp	private inherit : All members of basic class will become to private members of inherit class.But private members of basic class would not be
	changed.If inherit class want to access them,must use protect members or public members of basic class.
&emsp&emsp	public inherit : All members of basic class will become to public members.But private members would not be changed.
&emsp&emsp	protect inherit : All members of basic class will become to protect members.But private members would not be changed.

&emsp&emsp	Protect members of basic class could be accessed by inherit class with straight.But outside of class can not access them with straight.

###	Nested class

E.g.
		class A{
			private:
			class B{
				...
			};
			protect:
	//		class B{
	//			...
	//		};
			public:
	//		class B{
	//			...
	//		};
		};

		You can define a class inside of a class.But feature scope is identificated by 'private / protect / public' zone.

	private zone : 
			That class definition only be saw in that class.
	protect zone : 
			That class definition could be saw in that class and its inherit class.
	public zone : 
			That class definition could be saw in that class and out space.But use at out space,must use '::' to access.So style is 
			'class A::class B object;'.

		Nested class in a template class.All instandtiation will contain that class.
E.g.
		template<class Any>
		class A{
			class B{
				...
			};
		};

###	Virtual function

&emsp		Call method of class A at the scope of class B,using - Base_name::Method_name;
&emsp&emsp virtual keyword : 
&emsp&emsp Example :  
			class A
			{
				...
				virtual type funcNAME(vars-list);
			};
			class B : public A
			{
				...
				virtual type funcNAME(vars-list);
			};

&emsp&emsp keyword 'virtual' is only write in the front of prototype.virtual method of class A is auto become virtual method in class B.
&emsp&emsp virtual method could be wrote in the class B.

&emsp&emsp virtual method call : 

&emsp&emsp	If use object to call it,so that is by the type of object.
&emsp&emsp	If use cite to call it,so that is by the type of the cite to.
&emsp&emsp	If use pointer to call it,so that is by the type of the pointer to.

&emsp&emsp	If has not the keyword virtual,call by the type of the pointer or the cite.

&emsp&emsp	Remember : 
			
			Must keep for virtual functions prototype in Basic class and in Inherit class.But have a exception,if the virtual function return a 
			Basic class pointer or cite,could be changed to a Inherit class pointer or cite.

			Actual method will be palling the virtual method.	//	virtual Type Func() 'Actual' ; Type Func() 'Virtual' ;

			Redefinition for virtual method must keep the prototype as same,if changed the prototype of method,new prototype of virtual method 
			will palling the virtual method of Base-class.

			If virtual method is overload in Base-class,so them would have to be defined at Inherit-class,Inherit-class must defining all version 
			of the them.Ohterwise one a defined version will be palling all others virtual methods version.If you defined a function and name as
			same as virtual function but not use keyword 'virtual',then this realy function will pall all virtual functions with as same name.

			The clear method of Base-class must is virtual,when class as a Basic class.
			
			The pointer or cite if is type of Base-class,they could directe to a Inherit-class,but can not do reverse transformat.

&emsp&emsp '=0' addend to a virtual function,will make this virtual function become to a 'pure virtual function'.
&emsp&emsp	virtual Type Func()=0;	//	This is a prototype of pure virtual function.
&emsp&emsp	Remeber : 
		
			If have a pure virtual function in one a class,then this class can not creat object.
			This class will become to a abstract classic.And this pure virtual function could not have a definition.
			All pure virtual function must have be overrided in Inherit class as a virtual function.

			Override : 
				virtual Type Func(){...}


&emsp&emsp Member function attribues :  

|Func|Could Inherit?|Friend or member|Could default build?|Could is virtual?|Has return value?|
|:-:|:-:|:-:|:-:|:-:|:-:|
|Build|NO|M|YES|No|NO|
|Clear|NO|M|YES|YES|NO|
|=|NO|M|YES|YES|YES|
|&|YES|ARBITRARY|YES|YES|YES|
|Conversion|YES|M|NO|YES|NO|
|()|YES|M|NO|YES|YES|
|[]|YES|M|NO|YES|YES|
|->|YES|M|NO|YES|YES|
|op=|YES|ARBITRARY|NO|YES|YES|
|new|YES|STATIC-M|NO|NO|void*|
|delete|YES|STATIC-M|NO|NO|void|
|other operator|YES|ARBITRARY|NO|YES|YES|
|other member|YES|M|NO|YES|YES|
|friend|NO|F|NO|NO|YES


&emsp&emsp Class members attribues : 
&emsp				public:		public members could be accessed at outside of class,for expample,the subject of class.Call function by - 
						subject.
&emsp				protected:	protected members as same as private for outside of class,but heir class can access it directly.(have not use
						function of Base class.)
&emsp				private:	private members could be accessed by public method of class,heir class have to use public method to access - 
						these.

&emsp&emsp Inherit-attribues : 
&emsp				public:		heir class can succeed the public members of base as public members of itself.
&emsp				protected:	heir class will succe the public and the protected members of base as protected members of itself,and inside - 
						of third heir could access these directly.
&emsp				private:	heir class will succe the public and the protected members of base as private members of itself,heir class must
						have to using the public method of itself to access these private members(protected and public of base).

&emsp&emsp Remember : Only the public members could be accessed at outside of class,protected members and private members could be accessed at inside of class 
			- only.


###	Abstract base classic	Multi-inherit(MI)

&emsp&emsp Virtual BASE class : 
&emsp&emsp Example : 

		class BASE{};
		class HEIR1:virtual public BASE
		{
			///
		};
		class HEIR2:virtual public BASE
		{
			///
		};
		class HEIR3:public HEIR1,public HEIR2
		{
			///
		};


###	MI-Multiple Inherition

&emps&emsp MI : Multiple Inheritance.

&emsp&emsp At the situation from over,'virtual public' keyword will be the HEIR1 and HEIR3 are shared one BASE class.So HEIR3 is only have one BASE class in the
		scope of itself.If do not write 'virtual public',at that situation,the HEIR3 will be having two for BASE class.That will make error.

&emsp&emsp Keyword is not only 'virtual public',allow use 'virtual private' and 'virtual protected'.

&emsp&emsp At the situation that usage 'virtual public' keyword,HEIR3 can not use build method of itself to send info to BASE class.
&emsp&emsp Example : 
		
		BASE(int x=0)
		{
			...
		}
		^
		|
		HEIR1(int x=0,int y=0):BASE(Y)
		{
			...
		}
		^
		|
		HEIR2(int x=0,int y=0):BASE(y)
		{
			...
		}
		^
		|
		HEIR3(int temp1=0,int temp2=0,int temp3=0):HEIR1(temp2,temp3),HEIR2(temp2,temp3)
		{
			...
		}
	
&emsp&emsp **In MI,that is error.MI is not allow to send info to BASE by Middle Class.But in normal situation,that is right.**

&emsp&emsp So,overwrite HER3();
&emsp&emsp : 
		HEIR3(int temp1=0,int temp2=0,int temp3=0):HEIR1(temp2,temp3),HEIR2(temp2,temp3),BASE(temp3)
		{
			...
		}

&emsp&emsp HEIR1() and HEIR2() is as same as front,but the temp3 have not send to BASE().


###	Template class

&emsp&emsp template class : 

&emsp&emsp Note : 

 	Template is for the members of class.Use 'Any' to resives them.
 
	Definition : 
 			template<class Type>
 			class EX
 			{
 				private:
 					Any mem1;
 					Any mem2;
 				public:
 					EX();
 					~EX();
 					Any & Func(vars-list);
 					...
 			};
 
 	For example,it is as same as template with function.
 	Of coures it have that the instantiation and the specialization,too.Modus have implicit and explicit.
 
 	Specialization : 
 			implicit-instantiation : 
 						It is happend in that statement a subject.
 						E.g.	EX<int> subject;		//	Generic.
 						This will make a template instantiation.
 			explicit-instantiation : 
 						It is must use this code to make instantiation.
 						E.g.	template class EX<int>;
 						This situation will make a template instantiation.
 			explicit-specialization : 
 						It is must special some type to specialization.If you changed the hevior of class with special type,use that
 						can make a sepcialy instantiation.
 						E.g.	
 							template<> 
 							class EX<char*>
 							{
 								...
 							};

							Attention : At the time of you are defining function from explicit-specialization,do not write that 
							'template<>' in front of definition of Function.
							//	template<> type EX<char*>::Func(vars-list);	this is a error.
							Attention : Do not using default argument in explicit-specialization.
 
 							The definition is same as template with function.If you want using 'char*' as type for class,g++ does
							not using normal definition of class template,it will be using this definition to make a instantiation.
 							Use this mechanism,you can change the hevior of class.

	Attribues : 
			1. Recursive use template class.			(Using template in the scope of itself.)
										**EX< EX<Type,Type>,Type> object;**
			2. Using more type-args for template class.		(template<class A,class,B,class C...>)
			3. Set default type for template class.			(template<class A=int/float/char/...> do not write A=int in definition of Func)
										E.g. template<class A=int> type EX<Any>::Func(){...} This is a error.
										Correct : template<class A> type EX<Any>::Func(){...}
										Use in main : EX<> subject;
											In center of <> could not have type,but '<>' is must.
			4. Partial specialization.
										E.g.
										->	template<class A,class B> class EX{...}
										->	template<class A> class EX<A,type>{...}
			5. Template class as member.
										E.g.
											template<...>
											class EX
											{
												template<...>class EX1{...};
												...
											}
			6. Using template as argument.
										E.g.
											template< template<typename Any> class EX>
											class EX1
											{
												EX<type> s1;		//	Template type.
												EX<type> s2;
												...
											};

											In code,if you use 'class EX1<string> ob;' to make a object,and then
											'EX<type> s1' will be insteaded by 'string<type> s1;' and 'EX<type> s2'
											will be insteaded by 'string<type> s2;'.Because you defined this class
											template receive a template as generic-type,so you must send a template
											type to class when you create a object.


			7. Using friend function in template class.
				-	Rule : 
						1. Is not template friend.	friend Type Func(vars-list);
						2. Bound template friend.	friend Type Func<Any>(vars-list);
						3. Unbound template friend.	template<typename Any> friend type Func(Any,Any);

				E.g.

						1> Not a template friend.

						template<class T>
						class EX{

							friend type Func(var-list);
						};
						This friend function will become to friedn for all instandtiation of this template class.

						2> Bound template friend.

						template<class X>
						type Func(var-list);

						template<class Any>
						class EX{
							friend type Func<Any>(var-list);
						};
						Declare a template function outside of class,and then redeclare at once with that template function as friend 
						of template class inside.But prototype must specify generic.
						Type of this friend function is as same as the type of template class object.Types as same,so friend function
						could access to template class object with same type.

						3> Unbound template friend.
					
						template<class Any>
						class EX{

							template<class A,class B>type Func(var-list);
						};
						Declare template friend function.Ones of all instandtiation of friend functions could access to all 
						instandtiation of template class object.

	
	Inherition : 
			If you want inherit a template classic,you must generic conversion for it.
		E.g. : 

			template<class T>
			class A{
				...
			};
		
			class B:public A{};	//	This is a error.When class inherit it,must generic conversion it.

			class B:'inherition method' A<Type>
			{
				...
			};						

			And a template class could inherition from other template class.

			template<class T>
			class A{
				...
			};

			template<class Any>
			class B:'inherition method' A<Any>
			{
				...
			};

	Split definition : 
			If translater support for keyword 'export',you can write 'export' in front of class declare at ones header file.
		And then could defined class definition in other code file.But use this method,must have supported by translater,and once class definition must
		write 'export' in front of it.


&emsp&emsp **Template class is basic for 'STL(Standard template library)'...And STL is basic for 'Generic Programming'.**



##	RTTI(Runtime Type Identification)

&emsp&esmp RTTI is a technology that identification for object at runtime.It could ask type is own object,and test type convertion whether secury.
&emsp Attention : RTTI is only support to classic which contain virtual function.

&emsp&emsp RTTI elements : 
&emsp&emsp&emsp 1> dynamic_cast 'operator'  
&emsp&emsp&emsp&emsp dynamic_cast could ask that can or cannot for assignment with object address to a specilit type pointer.
&emsp&emsp&emsp&emsp dynamic_cast<Type>(pointer); If could not secury with assignment for the pointer,dynamic_cast will return 'NULL'.

&emsp&emsp You could not use a inherit classic pointer point to a basic classic.So use 'dynamic_cast<Type>()' could to check secury for this convertion.

&emsp&emsp&emsp 2> typeid 'operator' and type_info 'classic'  
&emsp&emsp&emsp&emsp typeid(),parameter only have two classic,'class name' or 'expression and the result is a object'.And it return a cite of type_info  
&emsp&emsp&emsp classic,in header 'typeinfo.h'.
&emsp&emsp&emsp&emsp EX: typeid(Classic) == typeid (Expression),if classic == expression,that is 'true' otherwise is 'false'.

##	Classic convertion operator
&emsp&emsp For classic convert in C++ is very strictly.
&emsp&emsp EX:
&emsp&emsp&emsp struct Data{...};
&emsp&emsp&emsp Data d={...};
&emsp&emsp&emsp char* pch=(char*)(&d);
&emsp&emsp&emsp char ch=char (&d);
&emsp&emsp&emsp&emsp Two type convertions in the over,all are have not 'significance',but all are allowed in C.C++ is not allow that.

&emsp&emsp&emsp C++ classic convertion : 
&emsp&emsp&emsp&emsp 1> dynamic_cast;
&emsp&emsp&emsp&emsp 2> const_cast;
&emsp&emsp&emsp&emsp 3> static_cast;
&emsp&emsp&emsp&emsp 4> reinterpret_cast;

&emsp&emsp&emsp 1> dynamic_cast is RTTI element,and it is usually used in class at normal.
&emsp&emsp&emsp 2> const_cast only support one a classic convertion,'const or volatile'.const_cast<type-name>(expression).Buf is not realy to changed type,
&emsp&emsp because 'const',translater is not allow to change it,only make a copy for the variable with temp.
&emsp&emsp&emsp 3> static_cast<type-name>(expression);only type-name could be converted to expression with implicit,convertion is legal.
&emsp&emsp&emsp 4> reinterpret_cast<type-name>(expression);it is not allow to delete 'const',usually used in bottom programming.

