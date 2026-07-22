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
    void find(TreeNode* root, int depth, int &ans){
        if(root==NULL) return;
        depth++;
        if(root->left==NULL && root->right==NULL){
            ans=min(ans,depth);
            return;
        }
        find(root->left,depth,ans);
        find(root->right,depth,ans);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MAX;
        find(root,0,ans);
        return ans;
    }
};