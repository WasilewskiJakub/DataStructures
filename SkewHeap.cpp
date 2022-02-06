#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
    int npl; // null path length
    node(int key) : key(key), left(nullptr), right(nullptr), npl(0) {}
} *root = nullptr;

// Skew Heap
// binary tree with heap properties
// child.priority <= father.priority
// similar to leftist heap, but does not have npl property.
// but in Union every time we swap left and right sub-trees
// npl - null path length, length of th shortest way to null subtree.

node *Union(node *p1, node *p2)
{
    // Union in the worst case O(n).
    // Can prove that n * Union() = O(nlog(n)),
    // it means that in pesimistic case it has O(log(n)).
    // zamortyzowana = O(log(n)) na każdą operacje!
    if (!p1 && !p2)
        return nullptr;
    if (!p1)
        return p2;
    if (!p2)
        return p1;
    node *p;
    if (p1->key > p2->key)
    {
        p = p1;
        p->right = Union(p1->right, p2);
    }
    else
    {
        p = p2;
        p->right = Union(p2->right, p1);
    }
    swap(p->right, p->left); // swap left and right sub-trees.
    return p;
}
void Insert(int v)
{
    if (!root)
    {
        root = new node(v);
        return;
    }
    root = Union(root, new node(v));
}
void print(node *x)
{
    if (!x)
    {
        //cout << "s "; // helper to read structure.
        return;
    }
    cout << x->key << " ";
    print(x->left);
    print(x->right);
}

int main(int argc, char **argv)
{
    srand(1);
    for (int i = 0; i < 10; i++)
    {
        Insert(rand() % 15);
    }
    cout << "Skew heap:\n";
    print(root);
    cout << endl;
    return EXIT_SUCCESS;
}