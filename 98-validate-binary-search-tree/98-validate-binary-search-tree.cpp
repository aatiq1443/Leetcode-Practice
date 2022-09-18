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
    bool isBST(TreeNode* root , long minn , long maxi){
        if(root==NULL) return true;
        
        if(root->val > minn && root->val < maxi){
            bool left= isBST(root->left , minn , root->val);

            bool right=isBST(root->right , root->val , maxi);
            
            return left && right;
        }
        
        else return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root , LONG_MIN , LONG_MAX);
    }
};