class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans,vector<int> temp, int sum ) {
        // base case
        if(root == NULL) return;

        // one case solve
        sum += root->val;
        // store temp path in final Ans
        temp.push_back(root->val);

        //extra case
        if(root->left == NULL && root->right == NULL) {
            //verify
            if(sum == targetSum) {
                ans.push_back(temp);
            }
            else {
                return;
            }
        }
        // recursion will handle it
        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};