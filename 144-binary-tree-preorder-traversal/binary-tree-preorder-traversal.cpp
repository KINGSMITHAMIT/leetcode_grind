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
    // let's go for an iteratve traversal
    void preorderIterative(TreeNode*root, vector<int>&ans){
        stack<TreeNode*>st;
        if(root!=NULL)st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorderIterative(root, ans);
        return ans;
    }
};