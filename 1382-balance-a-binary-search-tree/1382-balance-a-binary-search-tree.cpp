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
    void inorder(TreeNode* node, vector<int>&v){
        if(!node)
            return;
        
        inorder(node->left, v);
        
        v.push_back(node->val);
        
        inorder(node->right, v);
    }
    
    TreeNode* makeTree(vector<int>& v, int left, int right){
        
        if(left>right)
            return NULL;
        
        int mid=(left+right)/2;
        
        TreeNode* node = new TreeNode(v[mid]);
        
        node->left=makeTree(v, left, mid-1);
        node->right=makeTree(v, mid+1, right); 
        
        return node;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> v;
        inorder(root, v);
        
        return makeTree(v, 0, v.size()-1);
        
    }
};