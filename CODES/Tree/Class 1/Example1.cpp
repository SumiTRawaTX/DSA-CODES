#include<iostream>
#include<queue>
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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;

            if(!q.empty()) 
                q.push(NULL);
        }
        else {
            cout  << front->data << " ";

            if(front->left != NULL) {
                q.push(front->left);
            }

            if(front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

int main() {

    Node* root = createTree();

    cout << "lever  order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}