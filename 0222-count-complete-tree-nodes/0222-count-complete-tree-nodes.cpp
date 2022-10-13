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
    
    int cntleft(TreeNode *node){
        
        if(!node) return 0;
        int cnt=0;
        
        while(node){
            cnt++;
            node = node->left;
        }
        
        return cnt;
    }
    
    int cntRight(TreeNode *node){
        
        if(!node) return 0;
        int cnt=0;
        
        while(node){
            cnt++;
            node = node->right;
        }
        
        return cnt;
    }
    
    
    int countNodes(TreeNode* root) {
        
        if(!root) return 0 ;
        
        int left = cntleft(root);
        int right = cntRight(root);
        
        if(left == right) return (1<<left) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};




