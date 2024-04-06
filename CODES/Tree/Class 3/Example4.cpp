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

void printBottomView(Node* root) {
    map<int, int> hdToNodemap;
    queue<pair<Node* , int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // over write answers so that the deeper nodes can be stored
        hdToNodemap[hd] = frontNode->data;

        // child ko dekhna hai
        if(frontNode->left != NULL) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "printing top view: " << endl;
    for(auto i: hdToNodemap) {
        cout << i.second << " ";
    }
}

int main() {

    Node* root = createTree();
    levelOrderTraversal(root);

    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    printBottomView(root);

    return 0;
}