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
    int maxLevelSum(TreeNode* root) {
        
        vector<pair<int , int>> vec;
        int lvl=1;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        int sum = 0;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            if(temp==NULL){
                
                
                vec.push_back({sum , lvl});
                lvl=lvl+1;
                if(!q.empty()){
                    sum=0;
                    q.push(NULL);
                }
            }
            else{
                
                sum = sum+temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            
        }
        int maxi = INT_MIN;
        int temp;
        for(auto i:vec){
           if(maxi<i.first){
               maxi = i.first;
               temp = i.second;
           }
        }
        return temp;
        
    }
};