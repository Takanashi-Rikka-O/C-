#include"avl.h"

//	Interfaces definition.

namespace AVL_TREE{


//	Part of private.

inline int AVL::Max(int a,int b)
{
	return (a>b)?a:b;
}

inline int AVL::Height(node* NODE)
{
	if (NODE)
		return NODE->Height_Value;
	else
		return -1;
}

//	Rotate

node* AVL::RotateLeft(node* No_Balance)
{
	node* NODE1;	//	Use to save the left child node of No_Balance
	
	
	NODE1=No_Balance->Left;	//	Set NODE1 as child node in left of No_Balance.
	No_Balance->Left=NODE1->Right;	//	Set the left is right child node of NODE1.
	NODE1->Right=No_Balance;	//	Set No_Balance as right child node of NODE1.
	
	//	Update height.
	
	No_Balance->Height_Value=Max(Height(No_Balance->Left),Height(No_Balance->Right))+1;	//	Update height of No_Balance
	NODE1->Height_Value=Max(Height(NODE1->Left),No_Balance->Height_Value)+1;//	Update height of NODE1

	return NODE1;
}

node* AVL::RotateRight(node* No_Balance)
{

	node* NODE1;	//	Use to save the right child node of No_Balance.

	NODE1=No_Balance->Right;	//	Set NODE1 as right child node of No_Balance
	No_Balance->Right=NODE1->Left;	//	Set right child node of No_Balance to the left child node of NODE1
	NODE1->Left=No_Balance;		//	Set No_Balance as left child node of NODE1
	
	//	Update height
	No_Balance->Height_Value=Max(Height(No_Balance->Left),Height(No_Balance->Right))+1;	//	Update height of No_Balance
	NODE1->Height_Value=Max(Height(NODE1->Right),No_Balance->Height_Value)+1;	//	Update height of NODE1

	return NODE1;

}

node* AVL::DoubleRotateLeft(node* No_Balance)
{
	No_Balance->Right=RotateLeft(No_Balance->Right);	//	First,left
	return RotateRight(No_Balance);			//	Second,right
}

node* AVL::DoubleRotateRight(node* No_Balance)
{
	No_Balance->Left=RotateRight(No_Balance->Left);		//	First,left
	return RotateLeft(No_Balance);		//	Second,right
}

//	Interfaces of Insert and Delete

node* AVL::Insert(Element X,node* TEMP)
{
	if (TEMP == NULL)
	{
		TEMP=new node;	//	Get memory.
		if (TEMP)
		{
			//	Initialize
			TEMP->Height_Value=0;
			TEMP->Left=TEMP->Right=NULL;
			TEMP->value=X;

			//	Update number of nodes
			Numbers++;
		}
		else
		{
			cout<<"Can not get memory for new node....\n";
			return TEMP;
		}
	}
	else if (X < TEMP->value)	//	Part fro left
	{
		TEMP->Left=Insert(X,TEMP->Left);	//	Recursive.

		//	Check balance
		if (Height(TEMP->Left)-Height(TEMP->Right) == 2)
			if (X < TEMP->value)
				TEMP=RotateLeft(TEMP);	//	Outside
			else
				TEMP=DoubleRotateRight(TEMP);//	Inside
		else;
	}
	else if (X > TEMP->value)	//	Part for right
	{
		TEMP->Right=Insert(X,TEMP->Right);//	Recursive.

		//	Check balance
		if (Height(TEMP->Right)-Height(TEMP->Left) == 2)
			if (X > TEMP->value)
				TEMP=RotateRight(TEMP);	//	Outside
			else
				TEMP=DoubleRotateLeft(TEMP);//	Inside
		else;
	}
	else
	{
		cout<<"Element has been existed!!!\n";
		return TEMP;

	}

	//	Update height.
	TEMP->Height_Value=Max(Height(TEMP->Left),Height(TEMP->Right))+1;

	return TEMP;
	
}

node* AVL::Follow(node* FROM,node* MAIN)
{
	if (MAIN)
	{
		MAIN->Right=Follow(FROM,MAIN->Right);	//	Reach bottom.
		int hl,hr;
		hl=Height(MAIN->Left);		//	H Left
		hr=Height(MAIN->Right);		//	H Right
		MAIN->Height_Value=Max(hl,hr)+1;	//	Update H
		if (hr-hl == 2)		//	Check balance
			MAIN=RotateRight(MAIN->Right);
		else
			return MAIN;
	}
	else
		return FROM;	//	In bottom
}


//	Clear 
void AVL::Clear(node* head)
{
	if (head)
	{
		Clear(head->Left);	
		Clear(head->Right);
		//	Go to bottom,then begining delete nodes.
		delete head;
	}
	else;
}



//	Part of public.
AVL::AVL()
{
	//	Initialize.
	Head=NULL;
	Numbers=0;
}

AVL::~AVL()
{
	
	Clear(Head);
	cout<<"AVL-Tree has been deleted..\n";
}

AVL::AVL(class AVL& TEMP)
{
	cout<<"AVL-Tree does not support for copy..\n";	
}

void AVL::Insert(Element X)
{
	Head=Insert(X,Head);	//	Insert
	return;
}

node* AVL::Find(Element X)
{
	return Find(X,Head);	//	Call overload
}

node* AVL::Find(Element X,node* head)
{
	if (head)
		if (head->value == X)			//	Match
			return head;
		else if (head->value < X)
			return Find(X,head->Right);	//	Greater than
		else	
			return Find(X,head->Left);	//	Less than
	else
		return NULL;
}

void AVL::Delete(Element X)
{
	Head=Delete(X,Head);	//	Call overload
}

node* AVL::Delete(Element X, node* tmp)
{
//	Delete node,and return its right child node.
//	If that node have left child node,then follow the left to right.

	if (tmp)
	{
		if (X == tmp->value)
		{
			node* left=tmp->Left;	//	Left node
			node* right=tmp->Right;	//	Right node
			delete tmp;		//	Deleted

			//	Update Number of nodes
			Numbers--;
		
			if (left)	//	Check if have left child node
			{
				return Follow(left,right);	//	Follow
			}
			else
				return right;		//	Right 
		}
		else if (X > tmp->value)
		{
			tmp->Right=Delete(X,tmp->Right);	//	Next
			int hl,hr;
			hl=Height(tmp->Left);			//	H Left
			hr=Height(tmp->Right);			//	H Right
			tmp->Height_Value=Max(hl,hr)+1;		//	Update

			if (hl-hr == 2)		//	Check balance
				tmp=RotateLeft(tmp);
			else;

		}
		else
		{
			tmp->Left=Delete(X,tmp->Left);		//	Next
			int hl,hr;		
			hl=Height(tmp->Left);			//	H Left
			hr=Height(tmp->Right);			//	H Right
			tmp->Height_Value=Max(hl,hr)+1;		//	Update
			if (hr-hl == 2)		//	Check balance
				tmp=RotateRight(tmp);
			else;
		}
	}
	else;
	
	return tmp;

}

void AVL::Traversal(void)const
{
	cout<<"Numbers of all nodes : "<<Numbers<<endl;	//	Show nodes number
	Traversal(Head);	//	Overload version.
	return;
}

void AVL::Traversal(const node* head)const
{
	if (head)
	{
		//	The Follow-up-traversal.
		Traversal(head->Left);	
		Traversal(head->Right);
		cout<<"Element : "<<head->value<<endl;
	}
	else;
}
















}
