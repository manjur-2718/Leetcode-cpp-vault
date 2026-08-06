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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = constructTree(preorder,0,preorder.size()-1,
                                        inorder,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode* constructTree(vector<int> preorder, int preStart, int preEnd,
    vector<int>inorder, int inStart,int inEnd,unordered_map<int,int>& mpp){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[preorder[preStart]];
        int leftTree = inRoot-inStart;

        root->left = constructTree(preorder,preStart+1,preStart+leftTree,
                                inorder,inStart,inRoot-1,mpp);
        root->right = constructTree(preorder,preStart+leftTree+1,preEnd,
                                inorder,inRoot+1,inEnd,mpp);
        
        return root;
    }
};