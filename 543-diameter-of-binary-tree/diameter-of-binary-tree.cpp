class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        
        // Helper function to calculate depth and diameter simultaneously
        function<int(TreeNode*)> helper = [&](TreeNode* node) -> int {
            if (node == NULL) return 0;
            int leftDepth = helper(node->left);
            int rightDepth = helper(node->right);
            maxDia = max(maxDia, leftDepth + rightDepth);
            return 1 + max(leftDepth, rightDepth);
        };
        
        helper(root);
        return maxDia;
    }
};
