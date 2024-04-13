int findActualMedian(Node* root) {
    int count = 0;
    Node* curr = root;
    while(curr) {
        // left node is NULL then visit it and go right;
        if(curr->left == NULL) {
            count++;
            curr = curr->right;
        }
        else {
            // find inorder predecessor
            Node* pred = curr->left;
            while(pred->right != curr && pred->right) {
                pred = pred->right;
            }
            // if pred right node is NULL, then go left after establishing link from pred to curr
            if(pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                // left is alrready visited
                pred->right = nullptr;
                count ++;
                curr = curr->right;
            }
        }
    }
    return ans;
}

float findMedian(struct Node* root) {
    int n = findNodeCount(root);
    return findActualMedian(root, n);
}