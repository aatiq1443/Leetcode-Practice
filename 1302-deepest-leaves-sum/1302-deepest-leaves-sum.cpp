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
    
   void LevelOrder(TreeNode* root ,int & cnt){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                // cout<<endl;
                cnt++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }



            else{
                // cout<<temp->data<<" ";
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    
    void dfs(TreeNode *root , int count , int level , int &ans){
        if(root==NULL) return ;
        
        if(level == count){
            ans+=root->val;
        }
        // cout<<level<<" ";
        dfs(root->left , count , level+1 , ans);
        dfs(root->right , count , level+1 ,ans);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int count=0;
        LevelOrder(root , count);
        // cout<<count;
        int ans=0;
        dfs(root , count , 1 , ans);
        return ans;
    }
};