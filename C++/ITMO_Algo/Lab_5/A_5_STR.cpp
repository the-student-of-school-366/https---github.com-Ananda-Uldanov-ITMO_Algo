#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int dat)
    {
        data = dat;
        left = NULL;
        right = NULL;
    }
};
Node *BST(vector<int> &vec, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }
    int middle = (left + right) / 2;
    Node *parent = new Node(vec[middle]);
    parent->left = BST(vec, left, middle - 1);
    parent->right = BST(vec, middle + 1, right);
    return parent;
}
void preorder(Node *parent)
{
    if (parent == NULL)
    {
        return;
    }
    cout << parent->data << " ";
    preorder(parent->left);
    preorder(parent->right);
}
int main()
{
    int n;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    Node *tree = BST(vec, 0, n - 1);
    preorder(tree);
}
