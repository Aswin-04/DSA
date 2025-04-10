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

        TreeNode* cur = root;
        stack<TreeNode*> st;
        vector<int> res;

        while(cur != nullptr || !st.empty()) {
            if(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            else {
                TreeNode* temp = st.top()->right;
                if(temp == nullptr) {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                    while(!st.empty() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();
                        res.push_back(temp->val);
                    }
                }
                else cur = temp;
            }
        }
        return res;
    }
};