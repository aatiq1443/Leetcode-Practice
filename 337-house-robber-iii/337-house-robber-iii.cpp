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
    
//     int houseRob(vector<int>&vec , int n){
        
//         if(n==0) return vec[n];
        
//         if(n<0) return 0;
        
//         int left = vec[n] + houseRob(vec ,  n-2);
//         int right = 0 + houseRob(vec , n-1);
        
//         return max(left , right);
        
//     }
    
    
//     void solve(TreeNode *root , vector<int> &vec){
        
//         if(!root) return ;
//         vec.push_back(root->val);
        
//         solve(root->left , vec);
//         solve(root->right , vec);
        
//     }
    
    
    


   int sum = 0;
    
    int rob(TreeNode* root) {
        
        if(!root){
            sum = 0;
            return 0;
        }
        
        int left = rob(root->left);
        int preSum = sum;
        
        int right = rob(root->right);
        preSum += sum;
        
        sum = left + right;
            
        return max(root->val + preSum, sum);
    }
};