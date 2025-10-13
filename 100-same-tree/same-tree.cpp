//APPROACH 2
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case 
        if(p==NULL && q==NULL) return 1;
        if(p==NULL|| q== NULL) return 0;
        //LET'S go with checking wether or not the values of each tree are same or not 
        if(p->val!=q->val)return false;
        else {
            // let's check for my left sub tree
        bool lst= isSameTree(p->left, q->left);
        if(!lst) return 0;
        bool rst = isSameTree(p->right , q->right);
        if(!rst) return 0;
        }
        //if by now we havent return 0 then 
        return 1;
    }
};