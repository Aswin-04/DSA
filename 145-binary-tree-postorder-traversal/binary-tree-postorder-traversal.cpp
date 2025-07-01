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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(!stk.empty() || curr) {
            if(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* tmp = stk.top()->right;
                if(tmp == nullptr) {
                    tmp = stk.top();
                    stk.pop();
                    res.push_back(tmp->val);
                    while(!stk.empty() && stk.top()->right == tmp) {
                        tmp = stk.top();
                        stk.pop();
                        res.push_back(tmp->val);
                    }
                }
                else {
                    curr = tmp;
                }
            }
        }
        return res;
        
    }
};