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
    
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root)!=-1;
    }
    int dfsHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left=dfsHeight(root->left);
        if(left==-1) return -1;
        int right=dfsHeight(root->right);
        if(right==-1) return -1;
       
        if(abs(left-right)>1) return -1;
        return max(left,right)+1;
    }
};