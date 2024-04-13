void fun(Node* root, unordered_map<int, bool>& visited, bool & ans) {
    if(root == 0) return;

    // visit the node
    if(root->left == 0 && root->right == 0) {
        // left node
        int xp1 = root->data + 1;
        int xn1 = root->data - 1 == 0 ? root->data : 1;
        if(visited.find(xp1) != visited.end() && visited.find(xn1) != visited.end()) {
            ans = true;
            return;
        }
    }
    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

bool isDeadEnd(Node* root) {
    bool ans = false;
    unordered_map<int, bool>visited;
    fun(root, visited, ans);
    return ans;
}