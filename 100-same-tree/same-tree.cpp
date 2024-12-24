class Solution {
public:
    void visit(TreeNode* root, string &x){
        if(root ==NULL) {
            x+="null";
            return;
            }
        x += root->val;
        visit(root->left,x);
        visit(root->right,x);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string a ="", b = "";
        visit(p,a);
        visit(q,b);
        if(a==b) return true;
        return false;
    }
};