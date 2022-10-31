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
    
    TreeNode *solve(vector<int> &pre , int &i , int bound){
        
        if(i == pre.size() || pre[i] > bound) return NULL;
        
        TreeNode *root = new TreeNode (pre[i++]);
        
        root->left = solve(pre , i , root->val);
        root->right = solve(pre , i , bound);
        
        return root;
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        int bound = INT_MAX;
        
        return solve(preorder , i , bound);
        
    }
};