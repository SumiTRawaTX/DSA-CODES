Node* findPredecessor(Node* root, Node* p) {
    Node* pred = 0;
    node* curr = root;
    while(curr) {
        if(curr->data < p->data) {
           pred = curr;
           curr = curr->right;
        }
        else {
            curr = curr->left;
        } 
    }
    return pred;
}