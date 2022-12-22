// Write a program to find the height of a tree.

#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
        data = 0;
    }
};

class tree
{
private:
public:
    Node *root;
    tree()
    {
        root = NULL;
    }

    Node *createNode()
    {
        Node *ptr = new Node();
        return ptr;
    }

    void insertNode(int value)
    {
        Node *ptr = createNode();
        ptr->data = value;

        if (root == NULL)
        {
            root = ptr;
        }
        else
        {
            Node *temp = root;
            while (1)
            {
                if (temp->data < value)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = ptr;
                        return;
                    }
                    temp = temp->right;
                }
                else
                {
                    if (temp->left == NULL)
                    {
                        temp->left = ptr;
                        return;
                    }
                    temp = temp->left;
                }
            }
        }
    }

    void preorder(Node *r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    int heightOfTree(Node *r)
    {
        if (r == NULL)
            return 0;
        int left = heightOfTree(r->left);
        int right = heightOfTree(r->right);
        int max = left > right ? left : right;
        return max + 1;
    }
};

int main()
{

    tree t;
    t.insertNode(30);
    t.insertNode(50);
    t.insertNode(5);
    t.insertNode(8);
    t.insertNode(35);
    t.insertNode(4);
    t.insertNode(60);
    t.preorder(t.root);
    cout << endl
         << "Height of tree is " << t.heightOfTree(t.root) << endl;
    return 0;
}