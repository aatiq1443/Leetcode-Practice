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
    
    // #0 => not monitored
    // #1 => monitored no camera
    // #2 => monitored and having camera itself
    
    // by: Aatiq Afzal
    
    
    int solve(TreeNode *root , int &camera){
        
        if(!root) return 1;           // no camera
        
        int left = solve(root->left , camera);
        int right = solve(root->right , camera);
        
        if(left == 0 || right == 0){             // not monitored and should be monitored Hence, increase camera
            camera++;
            return 2;
        }
        if(left == 1 && right == 1){             // already monitored but not having camera
            return 0;
        }
        
        if(left == 2 || right == 2){             // this node is near the camera node
            return 1;
        }
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(!root) return 0;
        
        int camera = 0;
        
        if(solve(root , camera) == 0)  camera++;     // if root node is not monitored we need to monitored at last
        
        return camera;
        
    }
};