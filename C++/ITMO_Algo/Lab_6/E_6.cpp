#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct Node
{
    Node *left = NULL;
    Node *right = NULL;
    string data;
    int height = -1;
};
struct TreeAVL
{
    Node *root = NULL;
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
    Node *balancing(Node *x)
    {
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
    Node *inser(Node *x, string tmp)
    {
        if (x == NULL)
        {
            x = new Node;
            x->data = tmp;
            x->height = 0;
            x->left = NULL;
            x->right = NULL;
            return x;
        }
        if (tmp < x->data)
        {
            x->left = inser(x->left, tmp);
        }
        else
        {
            x->right = inser(x->right, tmp);
        }
        return balancing(x);
    }
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
        root = inser(root, x);
    }
    int bal(Node *x)
    {
        return tree_height(x->right) - tree_height(x->left);
    }
};
int main()
{
    TreeAVL f;
    TreeAVL s;
    TreeAVL t;
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
