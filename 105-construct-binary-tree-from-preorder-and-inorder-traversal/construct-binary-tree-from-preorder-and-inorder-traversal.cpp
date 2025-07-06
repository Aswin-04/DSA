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
    TreeNode* helper(vector<int>& preorder, 
                    vector<int>& inorder, 
                    unordered_map<int, int>& hashIn,  
                    int preStart, 
                    int preEnd, 
                    int inStart, 
                    int inEnd) {
        
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIn = hashIn[root->val];
        int size = rootIn-inStart;
        root->left = helper(preorder, inorder, hashIn, preStart+1, preStart+size, inStart, rootIn-1);
        root->right = helper(preorder, inorder, hashIn, preStart+size+1, preEnd, rootIn+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hashIn;
        for(int i=0; i < inorder.size(); i++) {
            hashIn[inorder[i]] = i;
        }

        TreeNode* root = helper(preorder, inorder, hashIn, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};