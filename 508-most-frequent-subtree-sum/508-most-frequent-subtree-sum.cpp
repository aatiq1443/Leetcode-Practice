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
    
    int solve(TreeNode *root , vector<int> &ans){
        if(!root) return 0;
        
        int temp= solve(root->left , ans) + solve(root->right , ans) + root->val;
        ans.push_back(temp);
        
        return temp;
        
        
    }
    
//     void dfs(TreeNode * root , vector<int> &ans){
//         if(!root) return ;
        
//         solve(root , ans);
//         dfs(root->left , ans);
//         dfs(root->right , ans);
//     }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        
        if(root->left==NULL && root->right!=NULL && root->val!=root->right->val && root->right->right==NULL &&  root->right->left==NULL){
            
            ans.push_back(root->right->val);
            cout<<root->right->val;
            return ans;
        }
        if(root->left!=NULL && root->right==NULL  && root->val!=root->left->val && root->left->left==NULL && root->left->right==NULL){
            
            ans.push_back(root->left->val);
            cout<<root->left->val;
            return ans;
        }
        
        solve(root , ans);
        int maxi=INT_MIN;
        map<int,int> mp;
        
        for(auto i:ans){
            mp[i]++;
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:mp){
            if(maxi<i.second){
                maxi=i.second;
            }
        }
        cout<<maxi;
        if(maxi==1){
            return ans;
        }
        else{
            vector<int>ds;
             for(auto i:mp){
                if(maxi==i.second){
                    ds.push_back(i.first);
                }
            }
            return ds;
        }
        
    }
};