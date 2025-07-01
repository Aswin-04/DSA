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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        
        while(!stk.empty() || tmp) {
            if(tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            }

            else {
                tmp = stk.top();
                stk.pop();
                res.push_back(tmp->val);
                tmp = tmp->right;
            }
        }

        return res;
    }
};