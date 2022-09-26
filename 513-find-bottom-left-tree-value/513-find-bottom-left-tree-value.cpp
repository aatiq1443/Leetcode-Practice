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
    
    int height(TreeNode *root){
        if(!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left , right) + 1;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        
        int size= height(root);
        
        if(!root->left && !root->right) return root->val;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        int lvl=1;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            if(temp==NULL){
                lvl = lvl+1;
                if(!q.empty()){
                    q.push(NULL);
                }   
            }
            else{
                
                
                if(temp->left) {
                    if(lvl+1 == size){
                        return temp->left->val;
                    }
                    q.push(temp->left);
                }
                if(temp->right) {
                    if(lvl+1 == size){
                        return temp->right->val;
                    }
                    q.push(temp->right);
                }
            }
            
        }
        return 0 ;
    }
};







