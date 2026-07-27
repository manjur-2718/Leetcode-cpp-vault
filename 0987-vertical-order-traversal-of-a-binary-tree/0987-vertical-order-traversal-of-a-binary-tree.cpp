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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> vertical;  // {vertical,column,value} all sorted in order
        queue<pair<TreeNode*,pair<int,int>>> q; // {node,(vertical/col),(level/row)}
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;
            vertical[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{col-1,row+1}});
            }
            if(node->right){
                q.push({node->right,{col+1,row+1}});
            }
        }

        for(auto col_pair : vertical){
            vector<int> temp;
            for(auto row_pair : col_pair.second){
                for(auto val : row_pair.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};