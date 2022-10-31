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
    
    void solve(TreeNode *root , unordered_map<int , int> &mp , bool &ans , int k){
        
        if(!root) return ;
        
        if(mp[k - root->val]){
            ans  = true;
            return;
        }
        
        mp[root->val] = 1;
        solve(root->left , mp , ans , k);
        solve(root->right , mp , ans , k);
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int , int> mp;
        
        bool ans = false;
        
        solve(root , mp , ans , k);
        
        return ans;
        
    }
};