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

    void levelOrder(TreeNode* root, map<int, map<int, multiset<int>>> &mp) {
        queue< pair<TreeNode*, pair<int, int>> > q;
        if(!root) return;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int c = p.second.first;
            int r = p.second.second;

            mp[c][r].insert(node->val);

            if(node->left) q.push({node->left, {c-1, r+1}});
            if(node->right) q.push({node->right, {c+1, r+1}});
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        levelOrder(root, mp);
        vector<vector<int>> res;

        for(auto outer: mp) {
            vector<int> col;
            for(auto inner: outer.second) {
                for(auto val: inner.second) {
                    col.push_back(val);
                }
            }
            res.push_back(col);
        }

        return res;
    }
};