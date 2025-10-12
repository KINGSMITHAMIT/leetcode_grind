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
 int maxDia=0;
    int maxPath(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(maxPath(root->left),maxPath(root->right));
    }
    int helper(TreeNode* root ){
        if(root==NULL) return 0;
        // int maxDia=0;
        int dia = maxPath(root->right)+maxPath(root->left);
        maxDia= max(dia, maxDia);
        helper(root->left);
        helper(root->right);
        return maxDia;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia=0;// reinitialize
        return helper(root);
    }
};