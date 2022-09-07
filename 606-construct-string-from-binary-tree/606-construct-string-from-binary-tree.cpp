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
     void preorder(TreeNode* root , string & result)
    {
        if(root==NULL)
            return ;
        result += to_string(root->val);
        if(root->left)
        {
          result += '(' ;
             preorder(root->left,result);
            result += ')' ;
        }
        else
        {
            if(root->right)
                result +="()";
        }
        if(root->right){
            result += '(' ;
            preorder(root->right, result);
            result += ')' ;      
        }
    }
    string tree2str(TreeNode* root) {
        string result ="";
        preorder(root,result);
        return result;
    }
};