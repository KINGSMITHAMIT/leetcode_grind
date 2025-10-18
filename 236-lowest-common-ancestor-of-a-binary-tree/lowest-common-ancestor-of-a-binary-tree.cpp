/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // let's write the bool case for checking wether or not the values are present or not 
    // the basic idea is simple to return wether or not the value is present or not 
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL) return 0;
        if(root==target) return 1;
        return exists(root->left, target) || exists(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root== q) return root; 
        if(exists(root->right, p)&&exists(root->left, q)) return root;
        if(exists(root->left, p)&&exists(root->right, q)) return root;
        else if(exists(root->left, p)&&exists(root->left, q)) return lowestCommonAncestor(root->left, p , q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};