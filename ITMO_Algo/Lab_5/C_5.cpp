#include <iostream>

using namespace std;

// Структура для представления узла бинарного дерева поиска
struct TreeNode
{
    int data;
    int size; // Размер поддерева с корнем в данном узле
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), size(1), left(nullptr), right(nullptr) {}
};

// Вставка нового элемента в бинарное дерево поиска
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    ++root->size;

    if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Поиск k-го максимума в бинарном дереве поиска
int findKthMax(TreeNode *root, int k)
{
    int rightSize = (root->right != nullptr) ? root->right->size : 0;

    if (k == rightSize + 1)
    {
        return root->data;
    }
    else if (k <= rightSize)
    {
        return findKthMax(root->right, k);
    }
    else
    {
        return findKthMax(root->left, k - rightSize - 1);
    }
}

// Удаление элемента из бинарного дерева поиска
TreeNode *remove(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    --root->size;

    if (value < root->data)
    {
        root->left = remove(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = remove(root->right, value);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *minRight = root->right;
        while (minRight->left != nullptr)
        {
            minRight = minRight->left;
        }

        root->data = minRight->data;
        root->right = remove(root->right, minRight->data);
    }

    return root;
}

int main()
{
    int n;
    cin >> n;

    TreeNode *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        int command, k;
        cin >> command >> k;

        if (command == 1)
        {
            root = insert(root, k);
        }
        else if (command == 0)
        {
            cout << findKthMax(root, k) << endl;
        }
        else if (command == -1)
        {
            root = remove(root, k);
        }
    }

    return 0;
}
