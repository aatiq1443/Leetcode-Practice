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
    
   void inprepost(TreeNode* root,vector<int>&pre ,vector<int>&in ,vector<int>&post){
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            if(it.second==1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left!=NULL){
                    st.push({it.first->left,1});
                }
            }
           else if(it.second==2){
                    in.push_back(it.first->val);
                    it.second++;
                    st.push(it);
                    if(it.first->right!=NULL){
                        st.push({it.first->right,1});
                    }
              }
            else{
                post.push_back(it.first->val);
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>pre;
        vector<int>in;
        vector<int>post;
        if(root==NULL) return post;
        inprepost(root,pre,in,post);
        return post;
    }
};