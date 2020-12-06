#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node * right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class BST
{
    public:
        Node *root;
        int size;

    BST(){
        root = NULL;
        size = 0;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            size++;
            return node;
        }
        else if (data < node->data) 
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        //cout << node->data << " ";
        inOrder(node->right);
    }
};







int main()
{
    bool check = true;
    BST *bst = new BST();
    while(check)
    {
        int n;
        cin >> n;
        if(n != 0)
            bst->root = bst->insert(bst->root, n);
        else
            check = false;
    }
    cout << bst->size;
    return 0;
}