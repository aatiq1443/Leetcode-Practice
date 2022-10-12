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
    TreeNode* deleteNode(TreeNode* root, int key) {
         
        if(!root)   return NULL;
        
        if(root->val == key){
            
            if(root->left == NULL) return root->right;
            if(root->right == NULL) return root->left;
            
            TreeNode * temp = root->left;
            TreeNode * ans = root->right;
            
            root = root->right ;
            
            
            
            while(root->left != NULL) root = root->left;
            root->left = temp;
            
            return ans;
            
            
        }
        
        
        
        
        if(key < root->val) root->left = deleteNode(root->left, key);
        
        if(key > root->val) root->right = deleteNode(root->right, key);
        
        return root;
    }
};