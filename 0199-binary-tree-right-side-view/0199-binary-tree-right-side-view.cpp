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
    
    void solve(TreeNode *root , vector<int> &ans , int lvl , int &maxi){
        
        if(root == NULL) return ;
        
        if(maxi < lvl){
            ans.push_back(root->val);
            maxi = lvl;
        }
        
        solve(root->right , ans , lvl+1  , maxi);
        solve(root->left , ans , lvl+1 , maxi);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxi = 0;
        
        if(!root) return ans;
        
        solve(root , ans , 1 , maxi);
        return ans;
    }
};