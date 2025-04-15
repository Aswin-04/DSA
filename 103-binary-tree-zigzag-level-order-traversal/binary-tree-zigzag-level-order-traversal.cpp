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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        int size = q.size();
        int f=0;
        while(!q.empty()) {
            vector<int> level;
            for(int i=0; i < size; i++) {
                TreeNode* cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                level.push_back(cur->val);
                q.pop();
            }
            size = q.size();
            if(f) {
                reverse(level.begin(), level.end());
                f=0;
            }
            else f=1;
            res.push_back(level);
        }

        return res;
    }
};