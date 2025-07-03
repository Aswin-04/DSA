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
    int maxDepth(TreeNode* root, bool& isBalanced) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left, isBalanced);
        int right = maxDepth(root->right, isBalanced);
        if(isBalanced) {
            isBalanced = abs(left-right) > 1? false : true;
        } 
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        maxDepth(root, isBalanced);
        return isBalanced;
    }
};