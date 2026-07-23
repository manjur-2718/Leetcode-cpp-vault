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
    void findDepth(TreeNode* root, int depth, int &ans){
        if(root==NULL) return;
        depth++;
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,depth);
            return;
        }
        findDepth(root->left,depth,ans);
        findDepth(root->right,depth,ans);
        return;
    }

    int find(TreeNode* root){
        int ans = 0;
        findDepth(root,0,ans);
        return ans;

    }

    void findDiameter(TreeNode* root,int &max_diameter){
        if(root==NULL) return;
        
        int left_depth = find(root->left);
        int right_depth = find(root->right);

        max_diameter = max(max_diameter,left_depth+right_depth);

        findDiameter(root->left,max_diameter);
        findDiameter(root->right,max_diameter);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int max_diameter=0;
        findDiameter(root,max_diameter);
        return max_diameter;
    }
};