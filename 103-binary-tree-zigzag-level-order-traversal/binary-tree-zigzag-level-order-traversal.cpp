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
        int f=0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);

            for(int i=0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                int index = f ? size-i-1 : i;
                row[index] = cur->val;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            f = !f;
            res.push_back(row);
        }

        return res;
    }
};