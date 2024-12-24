class Solution {
public:
    void reverse(TreeNode *root){
        if( root== NULL ) return;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        reverse(root->left);
        reverse(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
};