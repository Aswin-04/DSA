/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root, string& data) {
        if(root == nullptr) {
            data+="N,";
            return;
        }
        data+=to_string(root->val)+",";
        preorder(root->left, data);
        preorder(root->right, data);
    }
    string serialize(TreeNode* root) {
        string data = "";
        preorder(root, data);
        return data.substr(0, data.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* buildTree(vector<string>& data_arr, int& i) {
        if(data_arr[i] == "N") return nullptr;
        TreeNode* root = new TreeNode( stoi(data_arr[i]) );
        root->left = buildTree(data_arr, ++i);
        root->right = buildTree(data_arr, ++i);
        return root;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        vector<string> data_arr;
        stringstream ss(data);
        string token;
        char delimiter = ',';
        while(getline(ss, token, delimiter)) {
            data_arr.push_back(token);
        }
        
        int i=0;
        TreeNode* root = buildTree(data_arr, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));