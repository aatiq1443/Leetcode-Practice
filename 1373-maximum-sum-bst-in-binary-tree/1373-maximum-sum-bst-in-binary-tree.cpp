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

class Nodevalue{  
public: 
    int maxNode , minNode , maxSum ;
    
     Nodevalue(int minNode , int maxNode , int maxSum){
         
         this-> minNode = minNode ; 
         this->maxNode = maxNode ;
         this->maxSum = maxSum ;
   
     }  
};



class Solution {
    
        
public:
    
    
    Nodevalue solve ( TreeNode* root , int &ans ){
        
        if( !root) 
            return Nodevalue (INT_MAX ,INT_MIN , 0  ) ;
 
        auto left = solve (root->left , ans) ;        
        auto right = solve (root->right , ans) ;
 
        if( left.maxNode < root->val && right.minNode > root->val){
            
            
            ans = max (ans , left.maxSum + right.maxSum + root->val) ;
            
           
            return Nodevalue (min (root->val , left.minNode) ,
                              max (root->val , right.maxNode), left.maxSum + right.maxSum + root->val) ;
             }
        
        return Nodevalue (INT_MIN, INT_MAX , max (left.maxSum , right.maxSum )) ;
  
    }
    
     int maxSumBST(TreeNode* root) {
        
        int ans = 0  ;
        int sum = solve (root ,ans).maxSum ;
        
        return max(ans,max(sum , 0)) ;
        
        
    }
};
