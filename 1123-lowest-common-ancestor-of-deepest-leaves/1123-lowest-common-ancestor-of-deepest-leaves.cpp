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
    
    TreeNode *lca(TreeNode *root , int p , int q){
        
        if(!root) return NULL;
        
        if(root->val == p || root->val == q) return root;
        
        TreeNode * left = lca(root->left , p , q);
        TreeNode * right = lca(root->right , p , q);
        
        if(left && right) return root;
        
        if(!left && right) return right;
        
        if(left && !right) return left;
        
        else return NULL;
        
    }
    
    
    int height(TreeNode *root){
        
        if(!root) return 0;
        
        return max(height(root->left) , height(root->right)) +1;
        
    }
    
    void bfs(TreeNode*root , vector<int> &ans , int &lvl , int len){
        
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
                if(lvl == len){
                    ans.push_back(temp->val);
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        int len = height(root);
        
        int lvl = 1;
        vector<int> ans;
        bfs(root , ans , lvl , len);
        
        if(ans.size() == 1){
            TreeNode *newnode = new TreeNode(ans[0]);
            return newnode;
        }
        
        TreeNode *node = lca(root , ans[0] , ans[ans.size() - 1]);
        
        return node;
        
    }
};