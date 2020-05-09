//	AVL Tree head file.

#ifndef _AVL_H_
#define _AVL_H_


#include<iostream>


namespace AVL_TREE{

using std::cout;
using std::cin;
using std::endl;


/*	Define structure for node.	*/
typedef int Element;
typedef struct Tree_Node{

	Element value;			//	Element in node
	struct Tree_Node* Left;		//	Left child node
	struct Tree_Node* Right;	//	Right child node
	int Height_Value;		//	Height of node

}node;
/*					*/


/*	Classic AVL-Tree		*/
/*	There define some interfaces for features of AVL-Tree.		*/
/*	In outside of class,user can use these interfaces to execute some operations.	*/
//
//	Insert
//	Find
//	Delete
//	Traversal
//	Clear
//
//	Inside of this class,does not support for copy this AVL-Tree to make other AVL-Tree!!!

class AVL{

	private:
		
	/*			Data			*/
		node* Head;		//	ROOT pointer
		int Numbers;		//	Numbers of nodes in this tree

	/*		Location interfaces		*/

		int Height(node* NODE);	//	Return height of NODE
		

		/*		Balance Adjustment	*/
		node* RotateLeft(node* No_Balance);
		node* RotateRight(node* No_Balance);
		//////////////////////////////////////////
		node* DoubleRotateLeft(node* No_Balance);
		node* DoubleRotateRight(node* No_Balance);

	/*		Follow function			*/

		node* Follow(node* FROM,node* MAIN);

	/*		Clear function,when object of this classic was expired		*/

		void Clear(node* head);

	/*		Insert Overload			*/

		node* Insert(Element X,node* TEMP);

	/*		MAX				*/

		int Max(int a,int b);
	
	/*		Overload			*/
		node* Find(Element X,node* head);
		void Traversal(const node* head)const;
		node* Delete(Element X,node* tmp);

		
	public:

	/*			Class build functions	*/
		AVL();
		~AVL();
		AVL(class AVL& TEMP);
	//////////////////////////////////////////////////
	
		void Insert(Element X);	//	Insert a element into tree.
		node* Find(Element X);	//	Find element in this tree.
		void Delete(Element X);		
		void Traversal(void)const;	//	Traversal all elements in this tree.
		
};

}

#endif
