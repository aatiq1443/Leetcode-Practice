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
    
    void solve(TreeNode *root , int sum , vector<vector<int>> &ans , vector<int> ds){
        if(!root) return ;
        
        if(!root->left && !root->right) {
            
            if(sum==root->val){
                ds.push_back(root->val);
                ans.push_back(ds);
                return;
            }
        }
        
        ds.push_back(root->val);
        
        solve(root->left , sum-root->val , ans , ds);
        solve(root->right , sum-root->val , ans , ds);
        
       
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>ds;
        
        solve(root , targetSum , ans , ds);
        return ans;
    }
};