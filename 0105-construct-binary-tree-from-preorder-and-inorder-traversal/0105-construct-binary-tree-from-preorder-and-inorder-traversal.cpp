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
    
    TreeNode *solve(vector<int> &pre , vector<int> &in , map<int , int> &mp , int n ,int &ind , int inSt , int inEnd){
       
        if(ind ==n || inSt> inEnd) return NULL;
        
        int element = pre[ind++];
        
        TreeNode *root = new TreeNode(element);
        
        int pos = mp[element];
        
        root->left = solve(pre ,in , mp , n , ind , inSt , pos-1);
        root->right = solve(pre , in , mp , n , ind , pos+1 , inEnd);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        int preInd = 0;
        
        map<int , int > mp;
        for(int i=0 ; i< inorder.size() ;i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode *root=solve(preorder , inorder , mp , n , preInd , 0 , n-1);
        
        return root;
    }
};