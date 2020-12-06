#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
using namespace std;

vector<int> v;

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

    BST(){
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
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
        v.push_back(node->data);
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
    bst->inOrder(bst->root);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[1] << endl;
        break;
    }
    return 0;
}