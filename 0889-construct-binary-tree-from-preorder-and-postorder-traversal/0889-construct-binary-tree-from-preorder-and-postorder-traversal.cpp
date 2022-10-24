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
    
     TreeNode* buildTree(vector<int>& pre,unordered_map<int,int>& mp,int& preorderIndex){
         
        int curr=pre[preorderIndex++];
         
        TreeNode* newnode = new TreeNode(curr);
         
        if(preorderIndex<pre.size()  && mp[pre[preorderIndex]] < mp[curr]){
            newnode->left=buildTree(pre,mp,preorderIndex);
        }
         
        else 
            return newnode;
         
        if(preorderIndex < pre.size() && mp[pre[preorderIndex]] < mp[curr]){
            newnode->right=buildTree(pre,mp,preorderIndex);
        }
         
        return newnode;
        
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
     
        int n = pre.size();
        
        unordered_map<int,int> mp;
        for(int i=0;i<post.size();i++)
            mp[post[i]]=i;
        
        int preorderIndex=0;
        return buildTree(pre,mp,preorderIndex);
        
    }
   
};