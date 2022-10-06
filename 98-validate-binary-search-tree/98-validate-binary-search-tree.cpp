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
    
    bool isvalid(TreeNode *root , long minn , long maxi){
        
        if(!root) return true;
        
        if(root->val >minn && root->val<maxi){
            bool left = isvalid(root->left , minn , root->val);
            bool right = isvalid(root->right , root->val  , maxi);
            
            return left && right;
        }
        else{
            return false;
        }
        
    }
    
    
    bool isValidBST(TreeNode* root) {
        return isvalid(root , LONG_MIN , LONG_MAX);
    }
};