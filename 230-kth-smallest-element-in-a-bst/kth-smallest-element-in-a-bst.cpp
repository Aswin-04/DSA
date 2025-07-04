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
    int kthSmallest(TreeNode* root, int k) {
        int ctr = 0;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while(!stk.empty() || curr) {
            if(curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }

            else {
                TreeNode* node = stk.top();
                stk.pop();
                if(++ctr == k) return node->val;
                curr = node->right;
            }
        }

        return -1;
    }
};