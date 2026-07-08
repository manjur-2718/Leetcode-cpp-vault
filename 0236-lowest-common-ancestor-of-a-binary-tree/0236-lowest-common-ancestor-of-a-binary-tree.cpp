/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans=nullptr;
    int helper(TreeNode* node,TreeNode* p,TreeNode* q){
        if(node==NULL) return 0;
        int left=helper(node->left,p,q);
        int right=helper(node->right,p,q);
        int self=0;
        if(node==p || node==q) self=1;
        int total=left+right+self;
        if(total==2 && ans==NULL) ans=node;
        return total;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=NULL;
        int total=helper(root,p,q);
        return ans;
    }
};