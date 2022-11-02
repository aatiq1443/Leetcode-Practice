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
    
    int solve(TreeNode *root , int &ans){
        if(!root) return 0;
        
        int left = solve(root->left , ans);
        int right = solve(root->right , ans);
        
        if(!root->left || root->val != root->left ->val) left = 0;
        if(!root->right || root->val != root->right->val) right = 0;
        
        ans = max(ans , (left + right));
        
        return 1 + max(left , right);
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};