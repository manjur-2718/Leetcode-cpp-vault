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
    void check(TreeNode* root, int targetSum, int sum, vector<int> &sub, vector<vector<int>> &res){
        if(root==NULL) return;
        sum+=root->val;
        sub.push_back(root->val);
        if(root->left == NULL && root->right==NULL){
            if(sum==targetSum){
                res.push_back(sub);
            }
        }
        else{
            check(root->left,targetSum,sum,sub,res);
            check(root->right,targetSum,sum,sub,res);
        }
        sub.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> sub;
        check(root,targetSum,0,sub,res);
        return res;
    }
};