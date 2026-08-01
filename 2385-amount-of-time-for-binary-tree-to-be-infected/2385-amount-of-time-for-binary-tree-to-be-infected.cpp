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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target_node=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start) target_node=node;
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        
        
        int ans=0;
        
        if(target_node==NULL) return ans;
        
        unordered_set<TreeNode*> visited;
        visited.insert(target_node);
        q.push(target_node);
        while(!q.empty()){
            int size=q.size();
            int moved=0;
            for(int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && visited.find(node->left)==visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                    moved=1;
                }
                
                if(node->right && visited.find(node->right)==visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);
                    moved=1;
                }
                if(parent.find(node)!=parent.end() && visited.find(parent[node])==visited.end()){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                    moved=1;
                }
            }
            if(moved==1) ans+=moved;
        }
        return ans;
    }
};