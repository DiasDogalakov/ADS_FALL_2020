#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cmath>
 
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

    void sheet(Node *node)
    {
        if(node == NULL)
            return;
        if(node->left == NULL && node->right == NULL)
            v.push_back(node->data);
            //cout << node->data << endl;
        if(node->right != NULL)
            sheet(node->right);
        if(node->left != NULL)
            sheet(node->left);
    }

    void razvilky(Node *node)
    {
        if(node == NULL)
            return;
        razvilky(node->right);
        if(node->left && node->right)
            v.push_back(node->data);
        razvilky(node->left);
    }

    void vetky(Node *node)
    {
        if(node == NULL)
            return;
        vetky(node->left);
        if((node->left && !node->right) || (node->right && !node->left))
            v.push_back(node->data);
        vetky(node->right);
    }

    int height(Node *node)
    {
        if(node == NULL)
            return 0;
        else
        {
            int l = height(node->left);
            int r = height(node->right);
            if(l <= r)
                return r+1;
            else
                return l+1;
        }
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
    int lefthead = bst->height(bst->root->left);
    int righthead = bst->height(bst->root->right);
    if(righthead == 0 || lefthead == 0){
        cout<<"NO";
    }
    if(abs(lefthead - righthead) > 1){
        cout << "NO" << endl;
    }
    else{
        int my_bst = ( lefthead + righthead + 1 ) / 2 + 1;
        if(my_bst!=0){
            cout << "YES" << endl;
        }
    }
    return 0;
}