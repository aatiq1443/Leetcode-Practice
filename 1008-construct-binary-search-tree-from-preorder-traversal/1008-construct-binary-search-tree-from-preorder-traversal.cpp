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
    
    TreeNode *solve(vector<int>&pre , vector<int> &in , int n , int &index , map<int , int> &mp , int inSt , int inEnd){
        
        if(index > n || inSt > inEnd) return NULL;
        
        int element = pre[index++];
        TreeNode *root = new TreeNode(element);
        
        int pos = mp[element];
        
        root->left  = solve(pre , in , n , index , mp , inSt , pos-1);
        root->right = solve(pre , in , n , index , mp , pos+1 , inEnd);
        
        return root;
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> in=preorder;
        sort(in.begin() , in.end());
        
        int n = preorder.size();
        int preIND = 0;
        
        map<int , int> mp;
        for(int i=0 ; i<in.size() ; i++){
            mp[in[i]] = i;
        }
        
        return solve(preorder , in , n , preIND , mp , 0 , n-1);
        
    }
};