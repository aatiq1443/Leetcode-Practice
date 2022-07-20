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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
    
    int solve(TreeNode* root, int&dia){
        if(!root) return 0;
        
        int left=solve(root->left,dia);
        int right=solve(root->right,dia);
        
        dia=max(dia,left+right);
        
        return 1+ max(left,right);
    }
};