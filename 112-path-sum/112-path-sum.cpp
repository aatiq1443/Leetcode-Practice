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
    
    bool dfs(TreeNode *root ,  int target){
        
        if(!root) return 0;
        
        if(!root->left && !root->right){
            if(target == root->val){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        bool left = dfs(root->left , target - root->val);
        bool right = dfs(root->right , target - root->val);
        
        return left || right;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) return false;
        
        
        return dfs(root , targetSum );
        
    }
};