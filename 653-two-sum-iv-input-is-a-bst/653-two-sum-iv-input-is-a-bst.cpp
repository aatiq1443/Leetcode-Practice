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
private:
    
    void dfs(TreeNode* root, vector<int>& arr){
        arr.push_back(root->val);
        
        if(root->left != nullptr){
            dfs(root->left, arr);
        }
        
        if(root->right != nullptr){
            dfs(root->right, arr);
        }
    }
    
public:

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        
        dfs(root, arr);
        
        for(int start = 0; start < arr.size() - 1; start++){
            for(int next = start + 1; next < arr.size(); next++){
                if(arr[start] + arr[next] == k){
                    return true;
                }
            }
        }
            
        return false;
    }
};