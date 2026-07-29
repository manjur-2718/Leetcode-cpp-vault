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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        long long max_width=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long min_id = q.front().second;
            long long first,last;
            int size = q.size();
            for(int i=0; i<size; i++){
                long long curr_id = q.front().second - min_id;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;
                if(node->left) q.push({node->left,2*curr_id+1});
                if(node->right) q.push({node->right,2*curr_id+2});
            }
            long long curr_width = last-first+1;
            max_width = max(max_width,curr_width);
        }
        return max_width;
    }
};