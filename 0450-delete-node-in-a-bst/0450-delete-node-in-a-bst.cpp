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
        
        if(!root) return NULL;
        
        if(root->val == key){
            
            if(root->left == NULL) return root->right;
            if(root->right == NULL) return root->left;
            
            TreeNode *right = root->right;
            TreeNode *left = root->left;
            
            root = root->left;
            
            while(root->right != NULL){
                root = root->right;
            }
            
            root->right = right;
            return left;
            
        }
        
        if(key > root->val){
            root->right = deleteNode(root->right , key);
            
        }
        
        if(key < root->val){
            root->left = deleteNode(root->left , key);
        }
        
        return root;
    }
};