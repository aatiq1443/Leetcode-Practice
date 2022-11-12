/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    void dfs(TreeNode* main, TreeNode* local, TreeNode* target, TreeNode*& ans) {
        
        if(!main) return;
        
        if(main == target) ans = local;
        
        dfs(main -> left, local -> left , target , ans);
        dfs(main -> right, local -> right , target , ans);
        
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* ans = NULL;
        
        dfs(original, cloned, target, ans);
        
        return ans;
    }
};