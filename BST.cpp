#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
    node(int key) : key(key) { left = right = nullptr; }
} *root = nullptr;

node *Search(int v, node *&last)
{

    if (!root)
        return nullptr;
    node *ptr = root;
    last = nullptr;
    while (ptr && ptr->key != v)
    {
        last = ptr;
        if (v < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}
node **Search1(int v)
{
    node **tmp = &root;
    while ((*tmp) && (*tmp)->key != v)
    {
        if (v < (*tmp)->key)
            tmp = &((*tmp)->left);
        else if (v > (*tmp)->key)
            tmp = &((*tmp)->right);
    }
    return tmp;
}
void Insert(int v)
{
    if (!root)
    {
        root = new node(v);
        return;
    }
    node **tmp = Search1(v);
    if (*tmp)
        return;
    *tmp = new node(v);
}
void print(node *tmp)
{
    if (!tmp)
    {
        return;
    }
    cout << tmp->key << " ";
    print(tmp->left);
    print(tmp->right);
}
int main()
{
    srand(1);
    int tab[9] = {10, 8, 7, 6, 14, 12, 15, 11, 9};
    for (int i = 0; i < 9; i++)
        Insert(tab[i]);
    print(root);
    return EXIT_SUCCESS;
}