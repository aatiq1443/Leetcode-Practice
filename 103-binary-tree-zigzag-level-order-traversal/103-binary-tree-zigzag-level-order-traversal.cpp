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
        
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToright = true;
        
        while(!q.empty()){
            int size = q.size();
            
            vector<int> vec(size);
            for(int i=0 ;i<size ;i++){
                auto temp = q.front();
                q.pop();
                int ind = leftToright ? i : size-i-1;
                vec[ind] = temp->val;
                
                if(temp ->left) q.push(temp->left);
                if(temp ->right) q.push(temp ->right);
            }
            ans.push_back(vec);
            leftToright =!leftToright;
            
        }
        
        return ans;
        
    }
};