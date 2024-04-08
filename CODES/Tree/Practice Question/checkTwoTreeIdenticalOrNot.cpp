class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are identical
        if (p == NULL && q == NULL)
            return true;
        // If one of the trees is empty but the other is not, they are not identical
        if (p == NULL || q == NULL)
            return false;
        
        // Check if current node values are equal
        if (p->val != q->val)
            return false;
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};