#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct Node
{
    Node *left = NULL;
    Node *right = NULL;
    string data;
    int height = 1;
    Node(const string &x)
    {
        data = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
int tree_height(Node *x)
{
    if (x == nullptr)
    {
        return -1;
    }
    if (x->height == -1)
    {
        x->height = max(tree_height(x->left), tree_height(x->right)) + 1;
    }
    return x->height;
}
Node *turn_right(Node *x)
{
    Node *tmp = x->left;
    x->left = tmp->right;
    tmp->right = x;
    x->height = max(tree_height(x->left), tree_height(x->right)) + 1;
    tmp->height = max(tree_height(tmp->left), tree_height(tmp->right)) + 1;
    return tmp;
}
Node *turn_left(Node *x)
{
    Node *tmp = x->right;
    x->right = tmp->left;
    tmp->left = x;
    x->height = max(tree_height(x->left), tree_height(x->right)) + 1;
    tmp->height = max(tree_height(tmp->left), tree_height(tmp->right)) + 1;

    return tmp;
}

int bal(Node *x)
{
    if (x == NULL)
    {
        return 0;
    }
    return tree_height(x->right) - tree_height(x->left);
}

Node *balancing(Node *x)
{
    if (x == NULL)
    {
        return NULL;
    }
    x->height = max(tree_height(x->left), tree_height(x->right)) + 1;
    if (bal(x) == 2)
    {
        if (bal(x) < 0)
        {
            x->right = turn_right(x->right);
        }
        return turn_left(x);
    }
    if (bal(x) == -2)
    {
        if (bal(x) > 0)
        {
            x->left = turn_left(x->left);
        }
        return turn_right(x);
    }
    x->height = max(tree_height(x->left), tree_height(x->right)) + 1;
    return x;
}
Node *insert(Node *tmp, const string &x)
{
    if (!tmp)
        return new Node(x);
    if (x < tmp->data)
    {
        tmp->left = insert(tmp->left, x);
    }
    else
    {
        tmp->right = insert(tmp->right, x);
    }
    return balancing(tmp);
}

Node *exists(Node *parent, const string &x)
{
    if (parent == NULL)
        return NULL;
    if (parent->data == x)
        return parent;
    if (x < parent->data)
        return exists(parent->left, x);
    else
        return exists(parent->right, x);
}

int main()
{
    int n;
    int final = 0;
    cin >> n;
    string x;
    Node *fir = NULL;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (exists(fir, x) != 0)
        {
            Node *list = NULL;
            for (char j : x)
            {
                if (exists(list, to_string(j)) == 0)
                {
                    list = insert(list, to_string(j));
                    final++;
                }
            }
        }
        else
        {
            fir = insert(fir, x);
        }
    }
    cout << final;
}