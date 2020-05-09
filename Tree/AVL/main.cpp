#include"avl.h"

int main(void)
{
	using namespace AVL_TREE;

	AVL tree;

	int test[8]={12,7,9,3,17,13,21,26};
	
	for (int i=0; i < 8; ++i)
		tree.Insert(test[i]);

	//	The first traversal
	tree.Traversal();

	//	Delete '9'.
	tree.Delete(9);

	//	The second traversal
	tree.Traversal();

	

	return 0;
}
