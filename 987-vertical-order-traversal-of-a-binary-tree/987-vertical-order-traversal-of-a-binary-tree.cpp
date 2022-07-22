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
        map<int,map<int , multiset<int> >> nodes;
        queue<pair<TreeNode*,pair<int,int> >>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* front=temp.first;
            int vd=temp.second.first;
            int lvl=temp.second.second;
            
            nodes[vd][lvl].insert(front->val);
            
            if(front->left){
                q.push({front->left,{vd-1,lvl+1}});
            }
            if(front->right){
                q.push({front->right,{vd+1,lvl+1}});
            }
            
        }
        vector<vector<int>>ans;
        for(auto i:nodes){
            vector<int>vec;
            for(auto j:i.second){
                for(auto k:j.second){
                    vec.push_back(k);
                }
            }
            ans.push_back(vec);
        }
        return ans;
        
    }
};