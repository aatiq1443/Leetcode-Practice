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
public:
    void printSubtree(TreeNode *root , int k ,vector<int>&ans){
        
        if(!root || k<0) return ;
        
        if(k==0) 
        {
            ans.push_back(root->val);
            return ;
        }
        
        printSubtree(root->left , k-1 , ans);
        printSubtree(root->right , k-1 , ans);
        
    }
    
    int printNode(TreeNode *root , TreeNode *target , int k , vector<int>&ans){
        
        if(!root) return -1;
        
        if(root == target){
            printSubtree(root , k , ans);
            return 0;
        }
        
        int left = printNode(root->left , target , k ,ans);
        
        if(left!=-1){
            if(left+1 ==k){
                ans.push_back(root->val);
            }
            else{
                printSubtree(root->right , k-left-2 ,ans);
            }
            return 1+left;
        }
        
        
        int right = printNode(root->right , target , k ,ans);
        
        if(right!=-1){
            if(right+1 ==k){
                ans.push_back(root->val);
            }
            else{
                printSubtree(root->left , k-right-2 , ans);
            }
            return 1+right;
        }
        return -1;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        printNode(root , target , k , ans);
        return ans;
    }
};