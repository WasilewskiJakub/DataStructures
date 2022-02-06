#include <iostream>
using namespace std;

// Leaftist Heap
// binary tree with heap properties
// child.priority <= father.priority
// for every node, npl of left sub-tree is >= than npl of right sub-tree.
// npl - null path length, length of th shortest way to null subtree.

class node
{
public:
	char key;
	node *left, *right;
	int npl; // null path length
	node(char key) : key(key), left(nullptr), right(nullptr), npl(0) {}
} *root = nullptr;

node *Union(node *p1, node *p2) // O(log(n)) all operation done on right subtree whose legth is <= log(n)
{
	if (!p1 && !p2)
		return nullptr;
	if (!p1)
		return p2;
	if (!p2)
		return p1;
	node *p;
	if (p1->key >= p2->key)
	{
		p = p1;
		p1->right = Union(p1->right, p2);
	}
	else
	{
		p = p2;
		p2->right = Union(p2->right, p1);
	}

	if (!p->left || p->left->npl < p->right->npl) // swap left and right side. left->npl must be biger than right->npl !!!!
		swap(p->right, p->left);
	if (!p->right)
		p->npl = 0;
	else
	{
		// In this etap structure of our Lheap is correct, due to properies we know that right sub-tree is lower than left one.
		// it means that path to null is equal right side + (1) - connection beetween node p and right subtree.
		p->npl = p->right->npl + 1;
	}
	return p;
}
void Insert(int v) // Union existing Heap with new element
{
	if (!root)
	{
		root = new node(v);
		return;
	}
	root = Union(root, new node(v));
}
node *DeleteMax() // max is in root, Union root->left with root->right !
{
	node *p = root;
	root = Union(root->left, root->right);
	p->left = p->right = nullptr; // remove connction with other nodes, to avoid spoil the structer of heap!
	return p;
}
void print(node *x)
{
	if (!x)
	{
		//cout << "22 "; // helper to read structure.
		return;
	}
	cout << x->key << " ";
	print(x->left);
	print(x->right);
}
int main(int argc, char **argv)
{
	srand(1);
	char tab[] = {'w', 'a', 's', 'i', 'l', 'e', 'w', 's'};
	for (int i = 0; i < 8; i++)
	{
		Insert(tab[i]);
	}
	cout << "Leftist heap:\n";
	print(root);
	DeleteMax();
	cout << endl;
	cout << "Leftist heap, DeleteMax():\n";
	print(root);
	return EXIT_SUCCESS;
}