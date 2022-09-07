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
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        bool leftToRight= true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int>vec(size);
            
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                
                int index=leftToRight ? i : size-i-1;
                vec[index]=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            leftToRight=!leftToRight;
            ans.push_back(vec);
        }
        return ans;
        
    }
};