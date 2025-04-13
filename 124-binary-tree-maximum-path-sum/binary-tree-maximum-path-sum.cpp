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
    void updateMax(int& maxSum, int rootVal, int leftSum, int rightSum) {
        maxSum = max(maxSum, rootVal);
        maxSum = max(maxSum, rootVal+leftSum);
        maxSum = max(maxSum, rootVal+rightSum);
        maxSum = max(maxSum, leftSum+rightSum+rootVal);
    }
    int helper(TreeNode* root, int& maxSum) {
        if(root == nullptr) return 0;
        int leftSum = helper(root->left, maxSum);
        int rightSum = helper(root->right, maxSum);
        updateMax(maxSum, root->val, leftSum, rightSum);
        return max(root->val+max(leftSum, rightSum), root->val);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};