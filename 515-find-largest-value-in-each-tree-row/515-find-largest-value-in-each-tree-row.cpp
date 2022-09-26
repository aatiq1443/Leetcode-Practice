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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        vector<int> ans;
        if(!root) return ans;
        int maxi = INT_MIN;
        
        while(!q.empty()){
            
            auto temp = q.front();
            q.pop();
            
            if(temp==NULL){
                ans.push_back(maxi);
                if(!q.empty()){
                    maxi=INT_MIN;
                    q.push(NULL);
                }
            }
            else{
                maxi = max(maxi , temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
        }
        return ans;
        
    }
};