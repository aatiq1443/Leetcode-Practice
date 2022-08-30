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
    
    void solve(TreeNode *root , int &ans , long long int sum , map<TreeNode * , int>&mp){
        
        if(!root) return;
        
        if(sum == root->val && mp[root]<1) ans++;
        
        mp[root]=1;
        
        solve(root->left , ans , sum-root->val , mp);
        solve(root->right , ans , sum-root->val ,mp);
        
    }
    
    void dfs(TreeNode *root , int &ans , long long int sum){
        
        if(!root) return;
        
        map<TreeNode *, int>mp;
        
        solve(root , ans , sum ,mp);
        
        dfs(root->left , ans , sum);
        dfs(root->right , ans , sum);
        
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        
        long long int sum=targetSum;
        
        dfs(root , ans , sum);
        
        return ans;
    }
};