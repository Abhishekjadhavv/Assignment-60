// Write a program to search element in a BST
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

    int serach(Node *r, int value)
    {
        if (r == NULL)
        {
            cout<<endl;
            cout << "Not Found" << endl;
            return 0;
        }
        if (r->data == value){
            cout<<endl<<"Found"<<endl;
            return r->data;
        }
        else if (r->data > value)
            serach(r->left, value);
        else
            serach(r->right, value);
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
    cout<<t.serach(t.root,8);
    return 0;
}