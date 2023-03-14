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
    void solve(TreeNode *root , int &maxi , vector<int>&ans){
        if(root==NULL) return ;
          ans.push_back(root->val);
        if(!root->left && !root->right){
            int temp=0;
           for(auto i:ans){
               temp=temp*10+i;
           }
            maxi=maxi+temp;
        }
      
        
        solve(root->left , maxi ,ans);
        solve(root->right, maxi , ans);
        ans.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        int maxi=0;
        vector<int>ans;
        solve(root , maxi ,ans);
        return maxi;
    }
};