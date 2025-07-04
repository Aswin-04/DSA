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
    void dfs(TreeNode* root, int& ans, int& ctr, int k) {
        if(root == nullptr) return;
        dfs(root->left, ans, ctr, k);
        if(++ctr == k) {
            ans = root->val;
            return;
        }
        if(ctr < k) dfs(root->right, ans, ctr, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int ctr = 0;
        dfs(root, ans, ctr, k);
        return ans;
    }
};