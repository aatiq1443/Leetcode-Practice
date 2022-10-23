/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ans = "";
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0 ;i<n ;i++){
                auto temp = q.front();
                q.pop();
                
                if(temp) ans.append(to_string(temp->val) + ',');
                
                if(temp) {
                    q.push(temp->left);
                    q.push(temp->right);
                }
                
                if(!temp){
                    ans.append("N,");
                }
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream ss(data);
        
        string str;
        getline(ss , str , ',');
        
        TreeNode *root = new TreeNode(stoi(str));
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            auto temp = q.front();
            q.pop();
            
            getline(ss , str , ',');
            
            if(str == "N") temp->left = NULL;
            
            else{
                TreeNode *newnode = new TreeNode (stoi(str));
                temp->left = newnode;
                
                q.push(newnode);
            }
            
            getline(ss , str , ',');
            
            if(str == "N") temp->right = NULL;
            
            else{
                TreeNode *newnode = new TreeNode (stoi(str));
                temp->right = newnode;
                
                q.push(newnode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;