class Solution {
public:

//Approach 2-
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;

            if(!q.empty()) {
                count ++;
                q.push(NULL);
            }
        }
        else {
            // cout  << front->data << " ";

            if(front->left != NULL) {
                q.push(front->left);
            }

            if(front->right != NULL) {
                q.push(front->right);
            }
        }
    }

    return count;

        //APPROACH 1- 
        // base case
        // if(root == NULL) return 0;

        // int leftHeight = maxDepth(root->left);
        // int rightHeight = maxDepth(root->right);
        // int height = max(leftHeight, rightHeight) + 1;
        // return  height;
    }
};