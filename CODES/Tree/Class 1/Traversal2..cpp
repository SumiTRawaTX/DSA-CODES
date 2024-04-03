#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }

};

 //it returns root node of the created tree
Node* createTree() {
    cout << "enter the value: " << endl;
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }   

    // step1- create a Node
    Node* root = new Node(data);

    // step2 - create left subtree  
    root->left = createTree();

    // step3 - create right subtree
    root->right = createTree();
}

void inOrderTraversal(Node* root) {
    //base caes
    if(root == NULL) {
        return;
    }

    // L N R
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

int main() {

Node* root = createTree();

cout << "printing PreOrder: " ;
inOrderTraversal(root);
cout << endl; 

return 0;

}