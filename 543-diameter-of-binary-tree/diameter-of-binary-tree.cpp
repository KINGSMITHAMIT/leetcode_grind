class Solution {
public:
    int max_diameter = 0;
    int height(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left_height = height(root->left);
        int right_height = height(root->right);
        max_diameter = max(max_diameter,left_height + right_height);
        return 1+max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = height(root);
        return max_diameter;
    }
};
