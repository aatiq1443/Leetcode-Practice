}
};
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
//  TreeNode* solve(TreeNode* root, int v, int d){
//          if(root==NULL) return NULL;
//          if(d==2){
//              TreeNode* curr_left = new TreeNode(v);
//              TreeNode* curr_right = new TreeNode(v);
//              curr_left->left=root->left;
//              curr_right->right=root->right;
//              root->left=curr_left;
//              root->right=curr_right;
//              return root;
//          }
//          root->left=solve(root->left,v,d-1);
//          root->right=solve(root->right,v,d-1);
//          return root;
//      }
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//            if(depth==1){
//             TreeNode* curr_left=new TreeNode(val);
//             curr_left->left=root;
//             return curr_left;
//         }
//        return solve(root,val,depth);
//     }