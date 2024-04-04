class Solution {
public:

    bool solve(TreeNode* root, int targetSum, int sum) {
        // base case
        if(root == NULL) {
            return false;
        }
        sum = sum + root->val;
        if(root->left == NULL && root->right == NULL) {
            // i m currently standing on a leaf node
            //verify
            if(sum == targetSum) {
                return true;
            }
            else return false;
        }

        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};