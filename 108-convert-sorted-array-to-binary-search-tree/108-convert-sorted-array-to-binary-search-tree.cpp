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
    
    
    TreeNode *solve(vector<int>&ans , int st  , int end){
        if(st> end) return NULL;
        
        int mid = st + (end-st)/2;
        
        TreeNode *curr= new TreeNode(ans[mid]);
        
        curr->left=solve( ans , st , mid-1);
        curr->right = solve(ans , mid+1 , end);
        
        return curr;
        
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        
        return solve(nums ,0, nums.size()-1);
    }
};