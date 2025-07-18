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
    pair<bool, int> maxDepth(TreeNode* root) {
        if(root == nullptr) return {true, 0};
        pair<bool, int> left = maxDepth(root->left);
        pair<bool, int> right = maxDepth(root->right);
        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1; 
        return {balanced, 1 + max(left.second, right.second)};
    }
    bool isBalanced(TreeNode* root) {
        return maxDepth(root).first;
    }
};