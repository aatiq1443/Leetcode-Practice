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
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        if(root->left == NULL){
            int right = minDepth(root->right);
            return right+1;
        }
        else if(root->right==NULL){
            int left = minDepth(root->left);
            return left+1;
        }
        else{
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        return min(left, right)+1;
        }
        
    }
};