#include <iostream>
#include <limits.h>
using namespace std;

class node
{
public:
    int val;
    node *left, *right;
    node(int val) : val(val)
    {
        left = right = nullptr;
    }
} *root = nullptr;
// To jest to co w AVL, ale bez równoważenia!
void LL(node *&p)
{
    node *x = p->left;
    p->left = x->right;
    x->right = p;
    p = x;
}
void RR(node *&p)
{
    node *x = p->right;
    p->right = x->left;
    x->left = p;
    p = x;
}
void LR(node *&p)
{
    node *x = p->left;
    node *y = x->right;
    x->right = y->left;
    p->left = y->right;
    y->left = x;
    y->right = p;
    p = y;
}
void RL(node *&p)
{
    node *x = p->right;
    node *y = x->left;
    x->left = y->right;
    p->right = y->left;
    y->left = p;
    y->right = x;
    p = y;
}

// Lewe przeksztąłcanie drzewa!
void LZigZig(node *&p)
{
    LL(p);
    LL(p);
}
void LZigZag(node *&p)
{
    LR(p);
}
void LZig(node *&p)
{
    LL(p);
}
// Prawe przekształacanie drzewa!
void RZigZig(node *&p)
{
    RR(p);
    RR(p);
}
void RZigZag(node *&p)
{
    RL(p);
}
void RZig(node *&p)
{
    RR(p);
}
void Splay(int v, node *&root1)
{
    if (v < root1->val)
    {
        if (root1->left)
        {
            if (root1->left->val > v)
            {
                if (root1->left->left)
                {
                    Splay(v, root1->left->left);
                    LZigZig(root1);
                }
                else
                    LZig(root1);
            }
            else if (root1->left->val < v)
            {
                if (root1->left->right)
                {
                    Splay(v, root1->left->right);
                    LZigZag(root1);
                }
                else
                    LZig(root1);
            }
            else
                LZig(root1); // Element szukany znajduje się tuż pod rootem, v - jest korzeniem lewego poddrzewa roota!
        }
    }
    else if (v > root1->val)
    {
        if (root1->right)
        {
            if (root1->right->val < v)
            {
                if (root1->right->right)
                {
                    Splay(v, root1->right->right);
                    RZigZig(root1);
                }
                else
                {
                    RZig(root1);
                }
            }
            else if (root1->right->val > v)
            {
                if (root1->right->left)
                {
                    Splay(v, root1->right->left);
                    RZigZag(root1);
                }
                else
                    RZig(root1);
            }
            else
                RZig(root1);
        }
    }
}
void wypisz(node *p)
{
    if (!p)
        return;
    cout << p->val << " ";
    wypisz(p->left);
    wypisz(p->right);
}
node *Search(int v)
{
    // funkcja search orzysta ze Splay!!
    // element szukany zawsze trafia do roota!
    if (!root)
        return nullptr;
    Splay(v, root);
    if (root->val == v)
        return root;
    else
        return nullptr;
}
void Insert(int v)
{
    // funkcja Insert dla drzewa SPLAY, rowniez korzysta z funkcji Splay.
    if (!root)
    {
        root = new node(v);
        return;
    }
    node *nowy_element = new node(v);
    Splay(v, root);
    if (root->val == v)
        return;
    node *left = root->left;
    node *right = root->right;
    node *root2 = new node(v);
    // Poprawne wstawienie v do korzenia i ze wzgl na moduł v i v' odpowiednie zrownowazenie drzewa.
    if (v > root->val)
    {
        root2->left = root;
        root->right = nullptr;
        root2->right = right;
    }
    else
    {
        root2->right = root;
        root->left = nullptr;
        root2->left = left;
    }
    root = root2;
}
void Delete(int v)
{
    if (!root)
        return;
    Splay(v, root);
    if (root->val != v)
        return;
    if (!left)
    {
        root = root->right;
        return;
    }
    Splay(INT_MAX, root->left); // szukamy dla niewyobrażalnie dużej wartości zeby prawe poddrzewo nie istniało!!
                                // można dać też samo v, wtedy jak np INT_MAX jest elementem drzewa nie wywali "błędu"!

    root->left->right = root->right;
    root = root->left;
}
int main(int argc, char **argv)
{
    for (int i = 1; i <= 8; i++)
    {
        Insert(i * 2);
    }
    // Insert(13);
    Search(3);
    wypisz(root);
    return EXIT_SUCCESS;
}