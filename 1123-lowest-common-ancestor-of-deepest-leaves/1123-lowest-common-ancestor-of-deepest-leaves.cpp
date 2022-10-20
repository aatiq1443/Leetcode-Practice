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
    
    int getHeight(TreeNode *root){
        
       if(!root) return 0;
        
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    
    
    void bfs(vector<int> &ans , int height , TreeNode *root , int &lvl){
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            auto temp = q.front();
            q.pop();
           
            if(temp == NULL){
                lvl++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(lvl == height) ans.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
        }
        
    }
    
    
    TreeNode *lca(int p , int q , TreeNode *root){
        if(!root) return NULL;
        
        if(root->val == p || root->val == q) return root;
        
        TreeNode *left = lca(p , q , root->left);
        TreeNode *right = lca(p , q , root->right);
        
        if(left && right) return root;
        if(!left && right) return right;
        if(left && !right) return left;
        else
            return NULL;
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        int height = getHeight(root);
        
        vector<int> ans;
        int lvl = 1;
        
        bfs(ans , height , root , lvl);
        
        if(ans.size() == 1){
            TreeNode *newnode = new TreeNode(ans[0]);
            return newnode;
        }
        
        return lca(ans[0] , ans[ans.size()-1] , root);
        
    }
};