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


Node* bstUsingInorder(int inorder[], int s, int e) {
    // base case
    if(s>e) return NULL;

    int mid = (s+e)/2;
    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = bstUsingInorder(inorder, s, mid-1);
    root->right = bstUsingInorder(inorder, mid+1, e);

    return root;
}
int main() {

    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;

    Node* root = bstUsingInorder(inorder, s, e);
    levelOrderTraversal(root);

}
