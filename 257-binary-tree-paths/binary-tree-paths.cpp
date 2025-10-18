class Solution {
public:
    void help(TreeNode* node, string path, vector<string> &ans) {
        if (node == NULL)
            return;
            if(!path.empty()) path+="->";
            path+=to_string(node->val);
        if (node->right == NULL && node->left == NULL) {
            ans.push_back(path);
            return;
        }
            help(node->left, path, ans);
            help(node->right, path, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) { 
       vector<string>ans; 
        help(root, "", ans);
        return ans;
    }
};