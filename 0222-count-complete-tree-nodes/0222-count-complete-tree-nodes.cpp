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
    
    int leftHeight(TreeNode *root){
        
        int cnt=0;
        
        while(root){
            root = root->left;
            cnt++;
        }
        
        return cnt;
        
    }
    
     int rightHeight(TreeNode *root){
        
        int cnt=0;
        
        while(root){
            root = root->right;
            cnt++;
        }
        
        return cnt;
        
    }
    
    
    int countNodes(TreeNode* root) {
         
        if(!root) return 0;
        
        int left = leftHeight(root);
        int right = rightHeight(root);

        if(left == right) return pow(2, left) -1;
        
        return 1 + countNodes(root->left) +countNodes(root->right);
        
    }
};