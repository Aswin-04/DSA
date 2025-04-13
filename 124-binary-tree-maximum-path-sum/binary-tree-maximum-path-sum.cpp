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
    int maxSum = INT_MIN;
    int helper(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        maxSum = max(maxSum, root->val);
        maxSum = max(maxSum, root->val+leftSum);
        maxSum = max(maxSum, root->val+rightSum);
        maxSum = max(maxSum, leftSum+rightSum+root->val);
        return max(root->val+max(leftSum, rightSum), root->val);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};