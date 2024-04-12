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

void convertIntoSortedDDL(Node* root, Node*& head) {
    // base case
    if(root == NULL) return;

    // right subtree into DDL 
    convertIntoSortedDDL(root->right, head);

    // attach root to node
    root->right = head;

    if(head != NULL) {
        head->left = root;
    }

    // update head
    head = root;

    // left subtree into DDL
    convertIntoSortedDDL(root->left, head);
}
 

void printLinkedList(Node* head) {
    Node* temp = head;
    cout << endl;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

Node* sortedLinkedListToBST(Node*& head, int n) {
    // base case
    if(n == 0 || head == NULL) return NULL;

    Node* leftSubtree = sortedLinkedListToBST(head, (n-1)/2);

    Node* root = head;
    root->left = leftSubtree;

    head = head->right; // Move head pointer to the next node
    // Construct right subtree with remaining nodes
    root->right = sortedLinkedListToBST(head, n - 1 - (n-1)/2);
    return root;
}


int main() {

    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;

    Node* root = bstUsingInorder(inorder, s, e);
    levelOrderTraversal(root);

    cout << "printing sorted DDL: " << endl;
    Node* head = NULL;
    convertIntoSortedDDL(root, head);
    printLinkedList(head);

    Node* root1 = NULL;
    root1 = sortedLinkedListToBST(head, 9);
    cout << "Doping level order traversal for root 1 " << endl;
    levelOrderTraversal(root1);

}
