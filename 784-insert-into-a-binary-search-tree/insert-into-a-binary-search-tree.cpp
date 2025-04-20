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

        TreeNode* newNode = new TreeNode(val);
        if(!root) return newNode;

        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while(true) {
            if(val < cur->val) {
                if(cur->left == nullptr) {
                    cur->left = newNode;
                    return root;
                }
                else cur = cur->left; 
            }
            else {
                if(cur->right == nullptr) {
                    cur->right = newNode;
                    return root;
                }
                else cur = cur->right;
            }
        }
    }
};