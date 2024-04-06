#include<iostream>
#include<queue>
#include<map>
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

Node* createTree() {
    cout << "enter the value for Node: " << endl;
    int value;
    cin >> value;

    if(value == -1) return NULL;

    //create
    Node* root = new Node(value);
    cout << "entering in left of:" << value << endl;
    root->left = createTree();
    cout << "entering in right of:" << value << endl;
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout << endl;

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
}

void printLeftBoundary(Node* root) {
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) return;

    cout << root->data << " ";
    if(root->left != NULL) printLeftBoundary(root->left);
    else {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root) {
    if(root == NULL) return;
    if(root->right == NULL && root->left == NULL) return;

    if(root->right != NULL) printRightBoundary(root->right);
    else {
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    printLeftBoundary(root->left);

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);

    printRightBoundary(root->right);
}

int main() {

    Node* root = createTree();
    levelOrderTraversal(root);

    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    boundaryTraversal(root);

    return 0;
}
