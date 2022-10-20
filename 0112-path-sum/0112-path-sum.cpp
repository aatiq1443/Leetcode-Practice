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
    
    bool solve(TreeNode *root , int sum){
        
        if(!root) return false;
        
        if(!root->left && !root->right){
            if(root->val == sum){
                return true;
            }
            return false;
        }
        
        bool left = solve(root->left , sum - root->val);
        bool right = solve(root->right , sum - root->val);
        
        return left || right;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root , targetSum);
    }
};