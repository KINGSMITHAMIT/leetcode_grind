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
    int level(TreeNode * root){
        if(root==NULL) return 0;
        return 1+max(level(root->left), level(root->right));
    }
    void zigzagLevelDisplay(TreeNode* root, int level, int curr, vector<int>& current){
        if(root==NULL) return;
        if(level == curr) {
            current.push_back(root->val);
            return;
        }
        if(level&1){
            zigzagLevelDisplay(root->right, level, curr+1, current);
            zigzagLevelDisplay(root->left, level, curr+1, current);
        }
        else {
            zigzagLevelDisplay(root->left, level, curr+1, current);
            zigzagLevelDisplay(root->right, level, curr+1, current);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = level(root);
        vector<vector<int>> ans;
        for(int i =0; i<n ;i++){
            vector<int>current;
            zigzagLevelDisplay(root, i, 0, current);
            ans.push_back(current);
        }
        return ans;
    }
};