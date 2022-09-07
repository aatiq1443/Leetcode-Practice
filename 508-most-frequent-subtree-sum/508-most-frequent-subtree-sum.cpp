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
    
    int solve(TreeNode *root , vector<int> &ans){
        if(!root) return 0;
        
        int left= solve(root->left , ans);
        int right= solve(root->right , ans);
        int temp=left + right + root->val;
        ans.push_back(temp);
        
        return temp; 
        
    }
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
    
        vector<int> ans;
        solve(root , ans);
        int maxi=INT_MIN;
        map<int,int> mp;
        
        for(auto i:ans){
            mp[i]++;
        }
       
        for(auto i:mp){
            if(maxi<i.second){
                maxi=i.second;
            }
        }
        
        if(maxi==1){
            return ans;
        }
        
        else{
            vector<int>ds;
             for(auto i:mp){
                if(maxi==i.second){
                    ds.push_back(i.first);
                }
            }
            return ds;
        }
        
    }
};