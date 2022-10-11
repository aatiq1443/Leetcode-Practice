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
     int solve(TreeNode *cur){
         
        if(cur==NULL) return 0;
         
        return 1+max(solve(cur->left),solve(cur->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        if(left==right)return root;
        
        else if(left<right)return lcaDeepestLeaves(root->right);
        
        else return lcaDeepestLeaves(root->left);
    
    }
};