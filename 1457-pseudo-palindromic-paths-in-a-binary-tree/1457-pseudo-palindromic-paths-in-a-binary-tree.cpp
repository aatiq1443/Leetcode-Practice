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
    
    void dfs(TreeNode* root , vector<int> &ans , int &count){
        
        if(!root) return ;
        
        ans[root->val]++;
        
        dfs(root->left , ans , count);
        dfs(root->right , ans , count);
        
        if(!root->left && !root->right){
            int element_cnt  = 0;
            
            for(int i=0 ;i<10 ;i++){
                if(ans[i]%2!=0) element_cnt++;
            }
            
            if(element_cnt == 1 || element_cnt == 0) count++; 
            
        }
        
        ans[root->val]--;
        
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> ans(10 , 0);
        int count = 0;
        
        dfs(root , ans , count);
        
        return count;
    }
};