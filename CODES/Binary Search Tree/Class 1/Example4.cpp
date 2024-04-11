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

void preOrderTraversal(Node* root) {
    // nlr
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    // lnr
    if(root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    // lrn
    if(root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int maxVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) return -1;
    
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

Node* findNodeInBST(Node* root, int target) {
    // base case
    if(root == NULL) return NULL;

    if(root->data == target) return root;

    if(target > root->data) {
        return findNodeInBST(root->right, target);
    }

    else {
        return findNodeInBST(root->left, target);
    }
}

Node* deleteNodeInBST(Node* root, int target) {
    // base case
    if(root == NULL) return root;

    if(root->data == target) {
        // isi ko delete kerna hai
        // 4 cases
        if(root->left == NULL && root->right == NULL) {
            // leaf node
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL) {
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right == NULL) {
            Node* child = root->left;
            delete root;
            return child;
        }
        else {
            // both child
            int inOrderPre = maxVal(root->left);
            // replace roor->data value inOrder pre
            root->data = inOrderPre;
            // delete inorderd  predecessor from left 
            root->left = deleteNodeInBST(root->left, inOrderPre);
            return root;
        }
    }

    else if(target > root->data) {
        // right jana chahiye
        root->right = deleteNodeInBST(root->right, target);
    }

    else if(target < root->data) {
        // left jana chahiye
        root->left = deleteNodeInBST(root->left, target);
    }

    return root;
}

int main() {

    Node* root = NULL;
    cout << "enter the value for Node: " << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelOrderTraversal(root);

    // cout << "printing inOrder - " << endl;
    // inOrderTraversal(root);
    // cout << endl;

    // cout << "printing preOrder - " << endl;
    // preOrderTraversal(root);
    // cout << endl;

    // cout << "printing postOreder -  " << endl;
    // postOrderTraversal(root);
    // cout << endl;

    deleteNodeInBST(root, 100);
    levelOrderTraversal(root);
    
    // 100 50 150 40 60 175 110 -1
}
