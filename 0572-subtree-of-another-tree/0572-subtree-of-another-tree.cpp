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
    bool isSameTree(TreeNode* node,TreeNode* subRoot){
        if(node==NULL && subRoot==NULL) return true;
        if(node==NULL || subRoot==NULL) return false;

        if(node->val!=subRoot->val) return false;
        bool left=isSameTree(node->left,subRoot->left);
        bool right=isSameTree(node->right,subRoot->right);
        return (left && right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val){ //Potential subtree
            if(isSameTree(root,subRoot)) return true;
        }

        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        return (left || right);
    }
};