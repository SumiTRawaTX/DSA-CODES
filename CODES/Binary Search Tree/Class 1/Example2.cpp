#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // constructor
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    // this is the first node we have to create
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    // no the first node
    if(root->data > data) {
        // insert into left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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

int minVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) return -1;

    while(temp->left != NULL) {
        temp = temp->left;  
    }
    return temp->data;
}

int maxVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) return -1;
    
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int main() {

    Node* root = NULL;
    cout << "enter the value for Node: " << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelOrderTraversal(root);


    cout << "minimum value: " << minVal(root) << endl;
    cout << "maximum value: " << maxVal(root) << endl;
    // 10 20 5 11 17 2 4 8 6 25 15 -1
}
