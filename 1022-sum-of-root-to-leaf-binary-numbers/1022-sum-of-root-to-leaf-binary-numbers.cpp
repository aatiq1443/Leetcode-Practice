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
    
    void dfs(TreeNode * root , int  &sum , int ans){
    
        ans = ans*2 + root->val;
        
        if(!root->left && !root->right){
            
            sum = sum + ans;
            return ;
            
        }

        
        if(root->left) dfs(root->left , sum , ans);
        if(root->right) dfs(root->right , sum , ans);
        
        
           
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        
        int sum = 0;
        int val = 0;
        dfs(root , sum , val);
        
        return sum;
        
    }
};