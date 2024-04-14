class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insert(Node* root, int val, int&succ) {
    if(!root) return new Node(val);
    if(val > root->data) {
        root->right = insert(root->right, val, succ);
    } else {
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }
    return root;
}

class Solution {
    public:
        vector<int> findLeastGreater(vector<int>& arr, int n) {
            vector<int> ans(arr.size(), -1);
            Node* root = 0;
            for(int i = arr.size() - 1; i >= 0; i--) {
                int succ = -1;
                root = insert(root, arr[i], succ);
                ans[i] = succ;
            }
            return ans;
        }
};