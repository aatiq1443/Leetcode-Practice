/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void post_order(Node *root, vector<int> &ans){

            if (!root) return ;

            for (auto x: root->children){
                post_order(x, ans);
            }

            ans.push_back(root->val);
        }
    
    vector<int> postorder(Node *root){

        vector<int> ans;

        post_order(root, ans);

        return ans;
    }
};