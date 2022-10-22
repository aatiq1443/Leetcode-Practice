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
    
    void dfs(TreeNode *root , string &str , string&ans , string &temp){
        if(!root) return ;
        
        if(!root->left && !root->right){
            
            temp.push_back(str[root->val]);
            
            string str1 = temp;
            
            reverse(str1.begin() , str1.end());
            
            if(ans == "") ans = str1;
            
           else if(ans>str1) ans = str1;
                    
            temp.pop_back();
            return ;
                
           
            
        }
        
        temp.push_back(str[root->val]);
        
        dfs(root->left , str , ans , temp);
        dfs(root->right , str , ans , temp);
        
        temp.pop_back();
        
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        string str = "abcdefghijklmnopqrstuvwxyz";
        string ans = "";
        string temp = "";
        
        dfs(root , str , ans , temp);
        return ans;
        
        
    }
};
