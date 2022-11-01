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
    
    void solve(TreeNode *root , int target , vector<vector<int>> &ans , vector<int> ds){
        
        if(!root) return ;
        
        if(!root->left && !root->right){
            if(target == root->val){
                ds.push_back(root->val);
                ans.push_back(ds);    
            }
            ds.pop_back();
            return ;
            
        }
        
        ds.push_back(root->val);
        
        solve(root->left , target-root->val , ans , ds);
        solve(root->right , target - root->val , ans ,ds);
        
        ds.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int>ds;
        
        if(!root) return ans;
        
        if(!root->left && !root->right){
            if(root->val != targetSum){
                return ans;
            }
            else{
                ds.push_back(root->val);
                ans.push_back(ds);
                return ans;
            }
        }
        
        solve(root , targetSum , ans ,ds);
        
        return ans;
        
    }
};