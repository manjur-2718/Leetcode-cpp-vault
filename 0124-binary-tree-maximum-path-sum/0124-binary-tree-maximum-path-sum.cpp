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
    int maxSum=INT_MIN;
    int findPathSum(TreeNode* root){
        if(root==NULL) return 0;

        int left = max(0,findPathSum(root->left));
        int right = max(0,findPathSum(root->right));

        maxSum = max(maxSum,left+right+root->val);

        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        findPathSum(root);
        return maxSum;
    }
};