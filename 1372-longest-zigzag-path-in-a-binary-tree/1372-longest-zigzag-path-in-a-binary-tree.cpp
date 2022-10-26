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
    
    pair<int , int> solve(TreeNode *root , int &ans){
        
        if(!root) return {-1 , -1};
        
        pair<int , int> left = solve(root->left , ans);
        pair<int , int> right = solve(root->right , ans);
        
        ans = max(ans , max(left.second , right.first)+1);
        
        return {left.second+1 , right.first+1};
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = -1;
        solve(root , ans);
        
        return ans;
    }
};