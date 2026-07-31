/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> parent_map;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                parent_map[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent_map[node->right]=node;
            }
        }

        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int curr_dist=0;

        while(!q.empty()){
            if(curr_dist==k) break;

            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && visited.find(node->left)==visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && visited.find(node->right)==visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if(parent_map.find(node)!=parent_map.end() && visited.find(parent_map[node])==visited.end()){
                    visited.insert(parent_map[node]);
                    q.push(parent_map[node]);
                }
            }
            curr_dist++;
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
        
    }
};