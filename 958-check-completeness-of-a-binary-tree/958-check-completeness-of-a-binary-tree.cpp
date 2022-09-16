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
    
    int totalNode(TreeNode *root){
        
        if(!root) return 0;
        
        int ans =1 + totalNode(root->left) + totalNode(root->right);
        
        return ans;
        
    }
    
    bool isCBT(TreeNode *root , int index  , int cnt){
        
        if(!root) return true;
        
        if(index>=cnt) return false;
        
        else{
            
            bool left = isCBT(root->left , 2*index+1 , cnt);
            bool right = isCBT(root->right , 2*index+2 , cnt);
            
            return left && right;
            
        }
        
    }
    
    bool isCompleteTree(TreeNode* root) {
        int index =0;
        
        int cnt = totalNode(root);
        
        if(isCBT(root , index  , cnt)){
            return true;
        }
        else
            return false;
        
    }
};