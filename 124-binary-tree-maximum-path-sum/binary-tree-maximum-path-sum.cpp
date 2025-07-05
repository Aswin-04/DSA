/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dfs(TreeNode* root, int& max_sum) {
        if(root == nullptr) return 0;
        int leftPathSum = dfs(root->left, max_sum);
        int rightPathSum = dfs(root->right, max_sum);
        int crnt_sum = root->val + leftPathSum + rightPathSum;
        max_sum = max(max_sum, crnt_sum);
        return max(0, max(root->val+leftPathSum, root->val+rightPathSum));
    }
    
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
};