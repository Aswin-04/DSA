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
    int result = 0;

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int l1 = maxDepth(root->left);
        int l2 = maxDepth(root->right);
        result = max(result, l1+l2);
        return 1 + max(l1, l2);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return result;
    }
};