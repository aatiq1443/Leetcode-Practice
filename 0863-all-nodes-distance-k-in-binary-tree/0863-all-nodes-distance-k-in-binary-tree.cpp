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
        
        map<int , list<int>> g;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            int v = node->val;
            q.pop();
            
            if(node->left){
                
                int u = node ->left->val;
                g[v].push_back(u);
                g[u].push_back(v);
                q.push(node->left);
                
            }
            
            if(node->right){
                
                int u = node ->right->val;
                g[v].push_back(u);
                g[u].push_back(v);
                q.push(node->right);
                
            }
            
        }
        
        // for(int i=0 ;i <9 ;i++){
        //     for(auto it: g[i]){
        //         cout<<it<<" ";
        //     }
        // }
        
        vector<int>dis(501 , INT_MAX);
        queue<int> qu;
        
        dis[target->val] = 0;
        
        qu.push(target->val);
        
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();
            
            for(auto child : g[node]){
                if(dis[child] == INT_MAX){
                    
                    dis[child] = 1+ dis[node];
                    qu.push(child);
                    
                }
            }
        }
        
        vector<int>ans;
        
        for(int i=0 ;i<501 ;i++){
            if(dis[i] == k){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};








