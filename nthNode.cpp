// Write a program to find out the n-th node of inorder traversal.

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

    void inOrder(Node *r)
    {
        if (r != NULL)
        {
            inOrder(r->left);
            cout << r->data << " ";
            inOrder(r->right);
        }
    }

    void nthNode(Node *r,int nodeNumber){
      int static count = 0;    
      if(r != NULL)
        {
            nthNode(r->left,nodeNumber);
            count+=1;
            if(count == nodeNumber)
            {
               cout<<endl<<"Nth node is "<<r->data;
            }
            nthNode(r->right,nodeNumber);
        }
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
    t.inOrder(t.root);
    t.nthNode(t.root,8);
    return 0;
}