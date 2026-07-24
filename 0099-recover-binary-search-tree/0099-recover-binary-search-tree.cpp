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
    int wrong = 0;
    TreeNode* wrong1first=NULL;
    TreeNode* wrong1second=NULL;
    TreeNode* wrong2first=NULL;
    TreeNode* wrong2second=NULL;
    TreeNode* prev=NULL;
    void fun(TreeNode* root){
        if(root==NULL) return;
        fun(root->left);
        if(prev==NULL) prev=root;
        else{
            if(prev->val > root->val){
                if(wrong==0){
                    wrong1first=prev;
                    wrong1second=root;
                    wrong++;
                }
                else{
                    wrong2first=prev;
                    wrong2second=root;
                    wrong++;
                }
            }
            prev=root;
        }
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        if(wrong==1){
            swap(wrong1first->val,wrong1second->val);
        }
        else{
            swap(wrong1first->val,wrong2second->val);
        }
    }
};