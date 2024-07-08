#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int dat)
  {
    data=dat;
    left=nullptr;
    right=nullptr;
  }
};

void insert(Node *&root, int dat)
{
  if (root == NULL)
  {
    root = new Node(dat);
  }
  else if (dat <= root->data)
  {
    insert(root->left, dat);
  }
  else
  {
    insert(root->right, dat);
  }
}

void theRight(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  queue<Node *> que;
  que.push(root);

  while (!que.empty())
  {
    int level = que.size();
    int mostright = 0;

    for (int i = 0; i < level; ++i)
    {
      Node *cur = que.front();
      que.pop();
      mostright = cur->data;

      if (cur->left != NULL)
      {
        que.push(cur->left);
      }

      if (cur->right != NULL)
      {
        que.push(cur->right);
      }
    }

    cout << mostright << " ";
  }
}

int main()
{
  int n;
  cin >> n;

  Node *fir = NULL;

  for (int i = 0; i < n; ++i)
  {
    int dat;
    cin >> dat;
    insert(fir, dat);
  }

  theRight(fir);

}
