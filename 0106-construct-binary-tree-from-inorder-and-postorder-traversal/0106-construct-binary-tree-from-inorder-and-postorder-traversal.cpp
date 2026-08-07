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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root = constructTree(postorder,0,postorder.size()-1,
        inorder,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode* constructTree(vector<int>& postorder, int postStart, int postEnd,
    vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& mpp){
        if(postStart>postEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[postorder[postEnd]];
        int leftTree = inRoot-inStart;

        root->left = constructTree(postorder,postStart,postStart+leftTree-1,
        inorder,inStart,inRoot-1,mpp);
        root->right = constructTree(postorder,postStart+leftTree,postEnd-1,
        inorder,inRoot+1,inEnd,mpp);

        return root;
    }
};