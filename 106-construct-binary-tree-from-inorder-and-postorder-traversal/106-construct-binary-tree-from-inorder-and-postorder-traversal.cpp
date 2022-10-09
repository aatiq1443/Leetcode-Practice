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
    

    
    TreeNode *solve(vector<int>& inorder, vector<int>& postorder , int &index , int n , int inSt , int inEnd , map<int,int> &mp){
        
        if(index <0 || inSt > inEnd) return NULL;
        
        int element = postorder[index--];
        
        TreeNode *root = new TreeNode(element);
        
        int pos = mp[element];
        
        
        root->right = solve(inorder , postorder , index , n , pos+1 , inEnd , mp);
        root->left = solve(inorder , postorder , index , n , inSt , pos-1 , mp);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n  = postorder.size();
        
        int postInd = n-1;
        
        map<int , int> mp;
        
        for(int i=0 ; i<n ;i++){
            mp[inorder[i]] = i;
        }
       
        return solve(inorder , postorder , postInd , n , 0 , n-1 , mp);
        
    }
};