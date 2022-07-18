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
    int solve(TreeNode*root,int tarSum){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            if(tarSum==root->val){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int left=solve(root->left,tarSum-root->val);
        
        int right=solve(root->right,tarSum-root->val);
        
        return (left || right);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum);
    }
};