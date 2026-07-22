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
    void findSum(TreeNode* root,int sum,vector<int> &record){
        if(root==NULL) return;
        sum=sum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            record.push_back(sum);
            return;
        }
        findSum(root->left,sum,record);
        findSum(root->right,sum,record);
        return;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> record;
        findSum(root,0,record);
        int res=accumulate(record.begin(),record.end(),0);
        return res;

    }
};