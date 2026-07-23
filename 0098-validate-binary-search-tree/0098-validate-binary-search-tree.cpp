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
    TreeNode* prev=nullptr;
    bool ans=true;
    void fun(TreeNode* root){
        if(root==NULL) return;
        fun(root->left);
        if(prev==NULL){
            prev=root;
        }
        else{
            if(prev->val >= root->val){
                ans=false;
                return;
            }
            prev=root;
        }

        fun(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        
        fun(root);
        return ans;
    }
};