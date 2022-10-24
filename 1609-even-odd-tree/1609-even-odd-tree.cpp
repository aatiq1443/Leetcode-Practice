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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        
        
        int lvl = 0;
        
        int res = 0;
        
        vector<int> ans;
        
        while(!q.empty()){
           
            int size = q.size();
            
            
            for(int i=0 ;i<size ;i++){
                auto temp = q.front();
                q.pop();
                
                ans.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
           
           
            if(lvl%2==0){
                
                if(ans[0] %2 == 0 ) return false;
               
                for(int i=1 ;i<ans.size();i++){
                    if(ans[i]%2 == 0) return false;
                    if(ans[i-1] >= ans[i]) return false;
                }
               
            }
            
            else{
                
                if(ans[0] %2 !=0 ) return false;
                
                for(int i=1 ;i<ans.size();i++){
                    if(ans[i]%2 !=0 ) return false;
                    if(ans[i-1] <= ans[i]) return false;
                }
            }
            
            
            ans.clear();
            
            lvl++;
        }
       return true;
    }
};