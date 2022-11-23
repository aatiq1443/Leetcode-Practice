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
    
    void solve(TreeNode *root , int target , int &ans , unordered_map<long ,long> &mp , long sum){
        
        if(!root) return ;
        
        sum = sum + root->val;
        
        ans = ans + mp[sum - target];
        
        mp[sum]++;
        
        solve(root->left , target , ans , mp , sum);
        solve(root->right , target , ans , mp , sum);
        
        mp[sum]--;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        int ans = 0;
        
        unordered_map<long , long> mp;
        
        mp[0] = 1;
        
        solve(root , targetSum , ans , mp , 0);
        
        return ans;
        
        
    }
};