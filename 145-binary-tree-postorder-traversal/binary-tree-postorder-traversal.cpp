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
class Solution { // left right root 
public:
    // left right root ->in order to do that we will try to basically have it in my ans vector we will try to stare the elements in my ans vector in a reverse manner that is
// we will try to push the root then left then right by that means when we try to reverse the ans array we will have our postorder array
void postOrderTraversalIterative(TreeNode*root, vector<int>&ans){  
    stack<TreeNode*>st;
    if(root!=NULL)st.push(root); 
    while(!st.empty()){
            TreeNode* node = st.top(); 
            st.pop();   
            ans.push_back(node->val);   
            if(node->left!=NULL)st.push(node->left);
            if(node->right!=NULL)st.push(node->right);
    }
    reverse(ans.begin(), ans.end());
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrderTraversalIterative(root, ans);
        return ans;
    }
};