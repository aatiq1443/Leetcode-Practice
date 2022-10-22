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
    
    void solve(TreeNode *root , vector<string>&ans , vector<string> &temp){
        
        if(!root) return;
        
        if(!root->left && !root->right){
            
            temp.push_back(to_string(root->val));
            string str = "";
            for(auto i:temp){
                str+=i;
            }
            
            ans.push_back(str);
            
            temp.pop_back();
            return;
            
        }
        
        temp.push_back(to_string(root->val) + "->");
        
        solve(root->left , ans , temp);
        solve(root->right , ans , temp);
        
        temp.pop_back();
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        
        vector<string>temp;
        
        solve(root , ans , temp);
        return ans;
        
    }
};