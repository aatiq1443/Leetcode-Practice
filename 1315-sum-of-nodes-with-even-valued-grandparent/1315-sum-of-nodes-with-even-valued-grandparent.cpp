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
    
    void dfs(TreeNode *curr , TreeNode *parent , TreeNode *grandparent , int &sum){
        
        if(!curr) return ;
        
        if(grandparent && grandparent->val%2==0){
            sum+= curr->val;
        }
        
        dfs(curr->left , curr , parent , sum);
        dfs(curr->right , curr , parent , sum);
        
        
    }
    
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        
        dfs(root , NULL , NULL , sum);
        
        return sum;
    }
};