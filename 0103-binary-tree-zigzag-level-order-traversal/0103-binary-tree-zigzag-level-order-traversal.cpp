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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool leftToRight = true;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvsize = q.size();
            int first = 0;
            int last = lvsize-1;
            vector<int> temp(lvsize,0);
            while(lvsize--){
                TreeNode* t = q.front();
                q.pop();
                if(leftToRight==true){
                    temp[first++] = t->val;
                }
                else{
                    temp[last--] = t->val;
                }
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
            
        }
        return res;
        
    }
};