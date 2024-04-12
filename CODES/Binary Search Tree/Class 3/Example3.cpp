#include<iostream>
#include<queue>
#include<limits.h>
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

class NodeData {
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData() {

    }
    NodeData(int size, int min, int max, bool valid) {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

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
 
NodeData findLargestBST(Node* root, int& ans) {
    // base case
    if(root == NULL) {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left, ans);
    NodeData rightAns = findLargestBST(root->right, ans);

    // checking starts here
    NodeData currNodeAns;

    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.maxVal = max(root->data, rightAns.maxVal);
    currNodeAns.minVal = min(root->data, leftAns.minVal);

    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)) {
        currNodeAns.validBST = true;
    }
    else {
        currNodeAns.validBST = false;
    }

    if(currNodeAns.validBST) {
        ans = max(ans, currNodeAns.size);
    }
    return currNodeAns;
}

int main() {


    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third= new Node(1);
    Node* fourth = new Node(3);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    cout << "printing the tree" << endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);
    cout << "largest bst size: " << ans << endl;

}
