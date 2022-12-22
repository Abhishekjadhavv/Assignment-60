// Write a program to find the maximum element in BST
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

    int maxElement(Node *r)
    {
        if (r == NULL)
        {
            cout<<"Tree is Empty ";
            return -1;
        }

        if (r->right == NULL)
            return r->data;

        maxElement(r->right);
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
    cout<<endl;
    cout<<"Max Element is "<<t.maxElement(t.root);

    return 0;
}