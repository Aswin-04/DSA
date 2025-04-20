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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // find the largest smallest element lesser than val
        TreeNode* newNode = new TreeNode(val);
        if(!root) return newNode;

        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while(cur) {
            prev = cur;
            if(val > cur->val) cur = cur->right;
            else cur = cur->left;
        }

        if(val < prev->val) prev->left = newNode;
        else prev->right = newNode;

        return root;

    }
};