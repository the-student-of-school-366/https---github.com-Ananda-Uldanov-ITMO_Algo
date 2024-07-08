#include <iostream>
using namespace std;
struct Leaf
{
    int data = 0;
    int height = 1;
    int left = 1;
    int right = 1;
    Leaf *parent = NULL;
};
int main()
{
    int n;
    cin >> n;
    int l, r;
    Leaf wood[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wood[i].data >> l >> r;
        wood[l - 1].parent = &wood[i];
        wood[r - 1].parent = &wood[i];
        if (wood[i].parent != NULL)
        {
            wood[i].height = wood[i].parent->height + 1;
        }
        wood[i].right = wood[i].height;
        wood[i].left = wood[i].height;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (wood[i].data > wood[i].parent->data)
        {
            wood[i].parent->right = wood[i].height;
        }
        else
        {
            wood[i].parent->left = wood[i].height;
        }
        if (wood[i].height > wood[i].parent->height)
        {
            wood[i].parent->height = wood[i].height;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << wood[i].right - wood[i].left << "\n";
    }
}