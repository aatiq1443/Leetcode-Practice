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
    int sum = 0;
    
    void inorder(TreeNode* root, int L, int R){
        
        if(root->left) inorder(root->left, L, R);
        
        if(root->val >= L && root->val <= R) sum += root->val;
        
        if(root->right) inorder(root->right, L, R);
        
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        inorder(root, L, R);
        
        return sum;
    }
};