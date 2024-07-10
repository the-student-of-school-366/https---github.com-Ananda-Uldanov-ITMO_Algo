#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
    string data;
};
struct BST
{
    Node *root = NULL;

    Node *exists(string x)
    {
        Node *element = root;
        while (element != NULL and element->data != x)
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

    void insert(string x)
    {
        if (exists(x) != NULL)
        {
            return;
        }
        Node *leaf = new Node;
        leaf->data = x;
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
};
int main()
{
    BST f;
    BST s;
    BST t;
    vector<string> f1;
    vector<string> s2;
    vector<string> t3;
    int n;
    cin >> n;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        f.insert(tmp);
        f1.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
        s2.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        t.insert(tmp);
        t3.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.exists(f1[i]) == NULL and t.exists(f1[i]) == NULL)
        {
            result1 += 3;
        }
        if ((s.exists(f1[i]) == NULL and t.exists(f1[i]) != NULL) or (s.exists(f1[i]) != NULL and t.exists(f1[i]) == NULL))
        {
            result1 += 1;
        }
        if (s.exists(f1[i]) != NULL and t.exists(f1[i]) != NULL)
        {
            result1 += 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (f.exists(s2[i]) == NULL and t.exists(s2[i]) == NULL)
        {
            result2 += 3;
        }
        if ((f.exists(s2[i]) == NULL and t.exists(s2[i]) != NULL) or (f.exists(s2[i]) != NULL and t.exists(s2[i]) == NULL))
        {
            result2 += 1;
        }
        if (f.exists(s2[i]) != NULL and t.exists(s2[i]) != NULL)
        {
            result2 += 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s.exists(t3[i]) == NULL and f.exists(t3[i]) == NULL)
        {
            result3 += 3;
        }
        if ((s.exists(t3[i]) == NULL and f.exists(t3[i]) != NULL) or (s.exists(t3[i]) != NULL and f.exists(t3[i]) == NULL))
        {
            result3 += 1;
        }
        if (s.exists(t3[i]) != NULL and f.exists(t3[i]) != NULL)
        {
            result3 += 0;
        }
    }
    cout << result1 << " " << result2 << " " << result3 << " ";
}