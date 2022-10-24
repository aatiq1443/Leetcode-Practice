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
    
     bool flipTree(TreeNode* root , vector<int> &v, vector<int> &res , int &i){
         
        if(!root) return true;
         
        if(root->val != v[i++]) return false;
         
        if(root->left != NULL && root->left->val != v[i]){   
            
            res.push_back(root->val);
            swap(root->left , root->right);
            
        }
         
        return flipTree(root->left , v, res , i) && flipTree(root->right ,v , res , i);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        
        int i=0;
        
        vector<int>ans;
        
        if(flipTree(root , v, ans , i))
            return ans;
        
        return {-1};
        
    }
   
};