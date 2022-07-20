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
        map<int,map<int,multiset<int> >> nodes;    //(vertical distance , (level order , vector))
        queue<pair<TreeNode* , pair<int,int> >>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<TreeNode* , pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* front=temp.first;
            
            int vertical_distance=temp.second.first;
            int level_order=temp.second.second;
            
            nodes[vertical_distance][level_order].insert(front->val);
            
            if(front->left){
                q.push({front->left,{vertical_distance-1,level_order+1}});
            }
            if(front->right){
                q.push({front->right,{vertical_distance+1,level_order+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto i:nodes){
            vector<int>vec;
            for(auto j:i.second){
               for(auto k:j.second){
                   vec.push_back(k);
                   //sort(vec.begin(),vec.end());
               }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};