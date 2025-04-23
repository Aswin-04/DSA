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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root) {
            if(key < root->val) {
                if(root->left && root->left->val == key) {
                    TreeNode* temp = root->left;
                    root->left = helper(temp);
                    delete temp;
                    break;
                }
                else root = root->left;
            }

            else {
                if(root->right && root->right->val == key) {
                    TreeNode* temp = root->right;
                    root->right = helper(temp);
                    delete temp;
                    break;
                }
                else root = root->right;
            }
        }

        return dummy;
    }
private: 
    TreeNode* helper(TreeNode* node) {
        if(!node->left && !node->right) return nullptr;
        else if(!node->left && node->right) return node->right;
        else if(node->left && !node->right) return node->left;

        else {
            TreeNode* lastRight = findLastRight(node->left);
            lastRight->right = node->right; 
        }
        return node->left;  
    }

    TreeNode* findLastRight(TreeNode* node) {
        while(node->right) node = node->right;
        return node;
    }
};