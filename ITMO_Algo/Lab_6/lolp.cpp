#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    int height = -1;
    int left = -1;
    int right = -1;
    Node(int data, int left, int right): data(data), left(left), right(right), height(-1) {}
};
struct TreeAVL{
    vector<Node> wood;
    int root;
    explicit TreeAVL(int n) : wood{vector<Node>(n)}, root{0} {}

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
        if(kid==-1)
        {
            return 0;
        }
        if(kid<=parent)
        {
            return kid +2;
        }
        else
        {
            return kid+1;
        }
    }
    void print_tree()
    {
        Node* ro=&wood[root];
        cout<<ro->data<<" "<<children(ro->left,root)<<" "<<children(ro->right, root)<<"\n";
        for(int i=0;i<wood.size();i++)
        {
            if(i!=root)
            {
                Node* element=&wood[i];
                if(i<root)
                {
                    cout<<element->data<<" "<<children(element->left,root);
                    cout<<" "<<children(element->right, root)<<"\n";
                }
                else
                {
                    cout<<element->data<<" "<<children(element->left,root)<<" "<<element->right+1<<"\n";

                }
            }   
        }
    }
    void TheTurn()
    {
        if(balanc(wood[0].right)==-1)
        {
            big_turn_left(0);
        }
        else
        {
            turn_left(0);
        }
    }
};
int main()
{
    int n;
    cin>>n;
    TreeAVL *fin=new TreeAVL(n);
    int x;
    int l;
    int r;
    for(int i=0;i<n;i++)
    {
        cin>>x>>l>>r;
        fin->wood[i]=Node(x,l-1,r-1);
    }
    fin->TheTurn();
    cout<<n<<"\n";
    fin->print_tree();

}