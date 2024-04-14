void in(node* root, Node* &prev) {
    if(root == NULL) return;
    in(root->left, prev);
    prev->left  =0;
    prev->right = root;
    prev = root;
    in(root->right, prev);
}

Node* Flatten(node* root) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    in(root, prev);
    prev->left = prev->right = 0;
    root = dummy->right;

    return root;
}