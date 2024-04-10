class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // Find the rightmost node in the left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right)
                    rightmost = rightmost->right;

                // Reassign the pointers to flatten the subtree
                rightmost->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the right child
            curr = curr->right;
        }
    }
};