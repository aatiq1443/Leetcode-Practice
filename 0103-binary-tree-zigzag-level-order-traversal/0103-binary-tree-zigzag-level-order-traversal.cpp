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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> vec;
        if(!root) return vec;
        queue<TreeNode*>q;
        
        q.push(root);
        
        bool leftToright = true;
        
        while(!q.empty()){
            int size = q.size();
            
            vector<int> ans (size);
            
            for(int i=0 ;i < size ;i++){
                auto temp = q.front();
                q.pop();
                
                int ind = leftToright ? i : size -i -1;
                
                ans[ind] = temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            vec.push_back(ans);
            leftToright = !leftToright;
        }
        return vec;
    }
};