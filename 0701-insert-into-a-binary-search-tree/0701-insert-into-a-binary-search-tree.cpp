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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root) {
            TreeNode *newnode = new TreeNode(val);
            return newnode;
        }
        
        if(val > root->val){
            root->right = insertIntoBST(root->right , val);
        }
        else if(val < root->val){
            root->left = insertIntoBST(root->left , val);
        }
        
        return root;
        
    }
};