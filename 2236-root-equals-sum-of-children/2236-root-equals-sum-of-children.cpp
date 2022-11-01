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
    bool checkTree(TreeNode* root) {
        
        if(!root || !root->left && !root->right) return true;
        
        int lsum  , rsum;
        
        if(root->left) lsum = root->left ->val;
        if(root->right) rsum = root->right ->val;
        
        // return ( root->val == (lsum + rsum) && checkTree(root->left) && checkTree(root->right) );
        
        if(root->val != (lsum + rsum)) return false;
        
        checkTree(root->left);
        checkTree(root->right);
        
        return true;
        
        
        
    }
};