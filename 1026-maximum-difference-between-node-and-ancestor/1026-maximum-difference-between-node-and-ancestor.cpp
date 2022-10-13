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
    int solve(TreeNode *r , int mn , int mx){
        
          if (r == nullptr) return mx - mn;
        
          mx = max(mx, r->val);
          mn = min(mn, r->val);
        
          return max(solve(r->left, mn, mx), solve(r->right, mn, mx));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int minn = 100000;
        int max = 0;
            
        return solve(root , minn , max);
        
    }
};