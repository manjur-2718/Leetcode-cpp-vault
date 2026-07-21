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
    bool res=false;

    void check(TreeNode* root, int targetSum,int sum){
        if(root==NULL) return;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                res=true;
                return;
            }
        }

        check(root->left,targetSum,sum);
        check(root->right,targetSum,sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int sum=0;
        check(root,targetSum,sum);
        return res;
        
    }
};