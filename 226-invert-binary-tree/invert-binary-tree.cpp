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
    void exchange(TreeNode* node){
        if(node==NULL) return;
        swap(node->right, node->left);
        exchange(node->right);
        exchange(node->left);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
         exchange(root);
        return root;
    }
};