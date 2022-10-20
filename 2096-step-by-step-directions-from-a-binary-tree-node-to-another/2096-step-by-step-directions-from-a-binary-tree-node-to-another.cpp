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
    
    TreeNode* lca(TreeNode* root,int p,int q){
        
        if(!root||root->val==p||root->val==q){
            return root;
        }
        
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
        
    }
    void distance(TreeNode* root,int p,int k,int &dis){
        
        if(!root){
            return ;
        }
        
        if(root->val==p){
            dis=k;
        }
        
        distance(root->left,p,k+1,dis);
        distance(root->right,p,k+1,dis);
        
    }
    void find(TreeNode* root,int q,string &temp,string& pass){
        
        if(!root){
            return ;
        }
        
        if(root->val==q){
            temp=pass;
        }
        pass+="L";
        
        find(root->left,q,temp,pass);
        
        pass.pop_back();
        pass+="R";
        
        find(root->right,q,temp,pass);
        
        pass.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* LCA=lca(root,startValue,destValue);
        
        string temp="";
        
        int dis=0,k=0;
        
        distance(LCA,startValue,k,dis);
        string temp1="",pass="";
        
        find(LCA,destValue,temp1,pass);
        string ans="";
        
        for(int i=0;i<dis;i++){
            ans+='U';
        }
        
        return ans+temp1;
    }
};