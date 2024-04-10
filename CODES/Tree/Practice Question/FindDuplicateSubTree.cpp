class solution {
    public:

    bool solve(TreeNode* root, unordered_map<string, int> &mp, string &res) {
        string postorder(TreeNode* root, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& duplicates) {
        if (!root) return "#";
        string leftSerialized = postorder(root->left, subtreeCount, duplicates);
        string rightSerialized = postorder(root->right, subtreeCount, duplicates);

        string subtreeSerialized = to_string(root->val) + "," + leftSerialized + "," + rightSerialized;

        subtreeCount[subtreeSerialized]++;

        if (subtreeCount[subtreeSerialized] == 2)
            duplicates.push_back(root);

        return subtreeSerialized;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        unordered_map<string, int> subtreeCount; // Map to store subtree serialization and its count

        postorder(root, subtreeCount, duplicates);

        return duplicates;
    }
};

