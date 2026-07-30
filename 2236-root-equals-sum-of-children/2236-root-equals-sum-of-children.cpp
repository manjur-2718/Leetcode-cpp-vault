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
    bool ans=true;
    void check(TreeNode* root){
        if(!root->left && !root->right) return;
        int sum=0;
        if(root->left) sum+=root->left->val;
        if(root->right) sum+=root->right->val;

        if(sum!=root->val){
            ans=false;
            return;
        }
        if(root->left) check(root->left);
        if(root->right) check(root->right);
    }
    bool checkTree(TreeNode* root) {
        check(root);
        return ans;
    }
};