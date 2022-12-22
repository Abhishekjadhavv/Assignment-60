// Write a program to print 3rd level all node in a tree

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

    void print3rdlevel(Node *r,int level){
       if(r == NULL)
          return;

        if(level == 0)
          cout<<r->data<<" ";

        if(level > 0)
        {
          print3rdlevel(r->left,level-1);
          print3rdlevel(r->right,level-1);
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
    t.insertNode(2);
    t.insertNode(3);
    t.insertNode(7);
    t.insertNode(9);
    t.insertNode(31);
    t.insertNode(36);
    t.insertNode(55);
    t.insertNode(65);
    t.preorder(t.root);
    cout<<endl;
    t.print3rdlevel(t.root,3);
    return 0;
}