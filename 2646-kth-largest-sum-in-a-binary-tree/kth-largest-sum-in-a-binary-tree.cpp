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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root==nullptr)
      return ans;

    queue<TreeNode*> q{{root}};
    while (!q.empty()) {
      vector<int> currLevel;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
    }
    return ans;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<int>>Tree=levelOrder(root);
        if(Tree.size()<k) return -1;
        vector<long long>sum;
        for(int i=0;i<Tree.size();i++){
            long long temp=0;
            for(int j=0;j<Tree[i].size();j++){
                temp+=Tree[i][j];
            }
            sum.push_back(temp);
        }
        sort(sum.rbegin(),sum.rend());
        return sum[k-1];
    }
};