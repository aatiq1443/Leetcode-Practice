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
  
     
       void solve(TreeNode* root, vector<TreeNode*>&v){
        
        if(root==NULL) return;
        
        v.push_back(root);
        solve(root->left,v);
        solve(root->right,v);
        
    }
    
    void flatten(TreeNode* root) {
        
        vector<TreeNode*>v;
        solve(root,v);
        
        TreeNode* temp = new TreeNode(-1);
         TreeNode* newHead=temp;
        for(auto it:v){
            
           temp->right=it;
           temp->left=NULL;
           temp=temp->right;
        }
        
        temp->left=NULL;
        temp->right=NULL;
        
        root = newHead->right;
    }
};