// Write a program to print elements of a tree at a given level using recursion.
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

    int HeightOfTree(Node *r)
    {
        if (r == NULL)
            return 0;

        int left = HeightOfTree(r->left);
        int right = HeightOfTree(r->right);
        int maxHeight = left < right ? right + 1 : left + 1;
        return maxHeight;
    }

    void printGivenlevel(Node *r, int level)
    {
        int static height = 0;

        if (r == NULL)
            return;

        if (height == 0)
        {
            height = HeightOfTree(r);
        }

         if (level<=-1 || (height - 1) < level)
        {
            cout<<"Invalid level"<<endl;
            return;
        }

        if (level == 0)
            cout << r->data << " ";

        if (level > 0)
        {
            printGivenlevel(r->left, level - 1);
            printGivenlevel(r->right, level - 1);
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
    t.preorder(t.root);
    cout << endl;
    t.printGivenlevel(t.root, 1);
    return 0;
}