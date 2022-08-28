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
    
   int height(TreeNode *root){
       if(root==NULL) return 0;
       
       int left=height(root->left);
       int right =height(root->right);
       
       return max(left, right)+1;
   }
    
    void dfs(TreeNode *root , int count , int level , int &ans){
        if(root==NULL) return ;
        
        if(level == count){
            ans+=root->val;
        }
        // cout<<level<<" ";
        dfs(root->left , count , level+1 , ans);
        dfs(root->right , count , level+1 ,ans);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
       
       int count=height(root );
        // cout<<count;
        int ans=0;
        dfs(root , count , 1 , ans);
        return ans;
    }
};