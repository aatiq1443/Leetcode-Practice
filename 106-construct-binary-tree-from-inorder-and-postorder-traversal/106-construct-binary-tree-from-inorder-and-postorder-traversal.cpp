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
    
    int findPosition(vector<int> &inorder , int element , int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode *solve(vector<int>& inorder, vector<int>& postorder , int &index , int inStart , int inEnd , int n){
        
        if(index < 0 || inStart > inEnd){
            return NULL;
        }
        
        int element = postorder[index--];
        TreeNode * root= new TreeNode(element);
        int pos = findPosition(inorder , element , n);
        
        root-> right = solve(inorder , postorder , index , pos+1 , inEnd , n);
        root-> left = solve(inorder , postorder , index , inStart , pos-1 , n);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=postorder.size();
        int postOrIndex=n-1;
        
        TreeNode * ans=solve(inorder , postorder , postOrIndex , 0 , n-1 , n);
        return ans;
    }
};