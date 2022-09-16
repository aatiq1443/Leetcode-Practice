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
    int res=0;
    map<int,int>mp;
    
    void solve(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        mp[root->val]++;
        if(!root->left&&!root->right)
        {
            int x=0;
            for(auto i:mp)
            {
                if(i.second%2!=0)
                {
                    x++;
                }
            }
            if(x<=1)
            {
                res++;
            }
        }
        solve(root->left);
        solve(root->right);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        solve(root);
        return res;
    
    }
};