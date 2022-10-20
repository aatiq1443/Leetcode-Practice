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
    
    int getHeight(TreeNode *root){
        if(!root) return 0;
        
        return max(getHeight(root->left) , getHeight(root->right))+1;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int height = getHeight(root);
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        int lvl = 1;
        int sum=0;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            if(temp==NULL){
                
                if(!q.empty()){
                    lvl++;
                    q.push(NULL);
                }
            }
                else{
                    if(lvl == height){
                       sum+=temp->val;
                    }
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
            }
        
        return sum;
    }
};