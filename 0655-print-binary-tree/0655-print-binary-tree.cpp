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
    int height(TreeNode* root){
        if(root == NULL) return 0;
       
        return max(height(root->left) , height(root->right))+1;
    }

   
    void solve(TreeNode* root, vector<vector<string>>&ans,int h,int l,int r){
        if(root == NULL) return;
        
        int mid = (l+r)/2;
        ans[h][mid] = to_string(root->val);
        
        solve(root->left, ans, h+1, l, mid-1);
        solve(root->right, ans, h+1, mid+1, r);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        
        int m = height(root);
        int n = (1<<m) -1;
       
        vector<vector<string>>ans(m,vector<string>(n));
        
        solve(root,ans,0,0,n-1);   
        return ans;     
    }
};