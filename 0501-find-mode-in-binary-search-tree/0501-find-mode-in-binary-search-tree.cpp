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
    void traverse(TreeNode *root, unordered_map<int,int> &mp)
    {
        if(root == NULL)
            return;
        
        mp[root->val]++;
        
        traverse(root->left,mp);
        traverse(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> mp;
        traverse(root,mp);
        vector<int> ans;
        int mode = 0;
        for(auto it:mp)
        {
            mode = max(mode,it.second);
        }
        
        for(auto it:mp)
        {
            if(it.second == mode)
            ans.push_back(it.first);
        }
        return ans;
    }
};