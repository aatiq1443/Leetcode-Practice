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
    
    bool solve(TreeNode* left, TreeNode* right){
        
        if(!left || !right) return left==right;
        
        if(left->val != right->val) return false;
        
        bool leftN = solve(left->left , right->right);
        bool rightN = solve(left->right , right ->left);
        
        return leftN && rightN;
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};