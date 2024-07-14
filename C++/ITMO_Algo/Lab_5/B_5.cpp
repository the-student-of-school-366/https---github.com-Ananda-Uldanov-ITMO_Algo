#include <iostream>
#include <string>
using namespace std;
struct Node
{
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
    int data;
};
struct BST
{
    Node *root = NULL;

    void insert(int x)
    {
        if (exists(x) != NULL)
        {
            return;
        }
        Node *leaf = new Node;
        leaf->data = x;
        leaf->left = NULL;
        leaf->right = NULL;
        Node *element = root;
        while (element != NULL)
        {
            leaf->parent = element;
            if (leaf->data < element->data)
            {
                element = element->left;
            }
            else
            {
                element = element->right;
            }
        }
        if (leaf->parent == NULL)
        {
            root = leaf;
        }
        else
        {
            if (leaf->data < leaf->parent->data)
            {
                leaf->parent->left = leaf;
            }
            else
            {
                leaf->parent->right = leaf;
            }
        }
    }

    Node *exists(int x)
    {
        Node *element = root;
        while ((element != NULL) and (x != element->data))
        {
            if (element->data > x)
            {
                element = element->left;
            }
            else
            {
                element = element->right;
            }
        }
        return element;
    }
    Node *next(int x)
    {
        Node *element = root;
        Node *bigger = NULL;
        while (element != NULL)
        {
            if (element->data > x)
            {
                bigger = element;
                element = element->left;
            }
            else
            {
                element = element->right;
            }
        }
        return bigger;
    }
    void Delete(int x)
    {
        Node *flag = exists(x);
        if (flag == NULL)
        {
            return;
        }
        Node *prev;
        Node *element;
        if (flag->left == NULL or flag->right == NULL)
        {
            prev = flag;
        }
        else
        {
            prev = next(x);
        }
        if (prev->left != NULL)
        {
            element = prev->left;
        }
        else
        {
            element = prev->right;
        }
        if (element != NULL)
        {
            element->parent = prev->parent;
        }
        if (prev->parent == NULL)
        {
            root = element;
        }
        else
        {
            if (prev == prev->parent->left)
            {
                prev->parent->left = element;
            }
            else
            {
                prev->parent->right = element;
            }
        }
        if (prev != flag)
        {
            flag->data = prev->data;
        }
        delete prev;
    }
    Node *prev(int x)
    {
        Node *element = root;
        Node *prev = NULL;
        while (element != NULL)
        {
            if (element->data < x)
            {
                prev = element;
                element = element->right;
            }
            else
            {
                element = element->left;
            }
        }
        return prev;
    }
};
int main()
{
    int x;
    BST Tree;
    string command;
    while (cin >> command)
    {
        if (command == "insert")
        {
            cin >> x;
            Tree.insert(x);
        }
        else if (command == "delete")
        {
            cin >> x;
            Tree.Delete(x);
        }
        else if (command == "exists")
        {
            cin >> x;
            if (Tree.exists(x) != NULL)
            {
                cout << "true" << "\n";
            }
            else
            {
                cout << "false" << "\n";
            }
        }
        else if (command == "next")
        {
            cin >> x;
            Node *nex = Tree.next(x);
            if (nex != NULL)
            {
                cout << nex->data << "\n";
            }
            else
            {
                cout << "none" << "\n";
            }
        }
        else if (command == "prev")
        {
            cin >> x;
            Node *pre = Tree.prev(x);
            if (pre != NULL)
            {
                cout << pre->data << "\n";
            }
            else
            {
                cout << "none" << "\n";
            }
        }
    }
}
