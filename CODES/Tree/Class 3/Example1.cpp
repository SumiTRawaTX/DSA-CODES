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

void preOrder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void inOrder(Node* root) {
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);   
}

void postOrder(Node* root) {
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);   
    cout << root->data << " ";
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

void printLeftView(Node* root, int level, vector<int>& leftView) {
    if(root == NULL) return;    

    if(level == leftView.size()) {
        // iska matlab left view ki node milgyi h, store karlo
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);

}

int main() {

    Node* root = createTree();
    levelOrderTraversal(root);

    // 10 20 140 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    vector<int> leftView;
    printLeftView(root, 0, leftView);

    cout << "Printing left view: " << endl;
    for(int i=0; i<leftView.size(); i++) {
        cout << leftView[i] << " ";
    }

    return 0;
}