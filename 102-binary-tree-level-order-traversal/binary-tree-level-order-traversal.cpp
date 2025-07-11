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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> queue;
        vector<vector<int>> res;
        if(root == nullptr) return res;

        queue.push(root);

        while(!queue.empty()) {
            int size = queue.size();
            vector<int> level;

            for(int i=0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                level.push_back(node->val);

                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }

            res.push_back(level);
        }
        
        return res;
    }
};