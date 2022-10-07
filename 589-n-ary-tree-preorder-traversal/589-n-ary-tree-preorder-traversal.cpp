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
    vector<int> preorder(Node* root) {
           vector<int >answer;
        
        if(root==NULL)
            return answer;
        stack<Node*>s;
        s.push(root);
        
        while(!s.empty()){
            Node* currentNode = s.top();
            s.pop();
            answer.push_back(currentNode->val);
            
            vector<Node*> child= currentNode->children;
            int n = child.size();
            
            for(int i=n-1;i>=0;i--){
                s.push(child[i]);
            }
            
        }
        return answer;
        
    }
};