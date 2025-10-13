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
    void visit(TreeNode* node, string &st){
        if(node==NULL) {
            st+=" ";
            return;
            }
        st+=node->val+'0';
        visit(node->right, st);
        visit(node->left,st);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string st1="";
        string st2="";
        visit(p, st1);
        visit(q, st2);
        return st1==st2;
    }
};