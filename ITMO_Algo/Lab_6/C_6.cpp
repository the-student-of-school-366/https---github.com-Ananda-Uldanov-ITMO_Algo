#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data=-1;
    int height=-1;
    Node* left=NULL;
    Node* right=NULL;
    Node* parent=NULL;
};
struct TreeAVL
{
    Node* root=NULL;
    vector<Node> wood;
    TreeAVL
    {
        
    }
       int tree_height(int x)
    {
        if (x == -1)
        {
            return 0;
        }
        if (wood[x].height != -1)
        {
            return wood[x].height;
        }
        return wood[x].height = 1 + max(tree_height(wood[x].left), tree_height(wood[x].right));
    }
    int balanc(int x)
    {
        return tree_height(wood[x].right) - tree_height(wood[x].left);
    }

    int turn_left(int x)
    {
        int tmp = wood[x].right;
        wood[x].right = wood[tmp].left;
        wood[tmp].left = x;
        wood[x].height = max(tree_height(wood[x].left), tree_height(wood[x].right)) + 1;
        wood[tmp].height = max(tree_height(wood[tmp].left), tree_height(wood[tmp].right)) + 1;
        if (x == root)
            root = tmp;

        return tmp;
    }

    int big_turn_left(int x)
    {
        wood[x].right = turn_right(wood[x].right);
        return turn_left(x);
    }

    int turn_right(int x)
    {
        int tmp = wood[x].left;
        wood[x].left = wood[tmp].right;
        wood[tmp].right = x;
        wood[x].height = max(tree_height(wood[x].left), tree_height(wood[x].right)) + 1;
        wood[tmp].height = max(tree_height(wood[tmp].left), tree_height(wood[tmp].right)) + 1;
        return tmp;
    }
    int children(int kid, int parent)
    {
        if (kid == -1)
        {
            return 0;
        }
        if (kid <= parent)
        {
            return kid + 2;
        }
        else
        {
            return kid + 1;
        }
    }
}