//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
       Node* constructBinaryTree(vector<int> pre, vector<int> preMirror, int size){
        if(size <= 3){
            if(size == 1){
                Node *n = new Node(pre[0]);
                return n;
            }
            Node *n = new Node(pre[0]);
            Node *n1 = new Node(pre[1]);
            Node *n2 = new Node(pre[2]);
            n->left = n1;
            n->right = n2;
            return n;
        }
        
        vector<int>::iterator left = pre.begin()+1;
        vector<int>::iterator right;
        vector<int>::iterator rightM = preMirror.begin() + 1;
        vector<int>::iterator leftM;
        int count = 1;
        
        for(int x = 2; x < size; x++){
            if(pre[x] == preMirror[1]){
                break;
            }
            count++;
        }
        
        right = left + count;
        leftM = rightM + count;
        
        vector<int> leftV(left, left + count);
        vector<int> rightV(right, pre.end());
        vector<int> leftVM(leftM, preMirror.end());
        vector<int> rightVM(rightM, rightM + count);
        
        Node *n = new Node(pre[0]);
        n->left = constructBinaryTree(leftV, leftVM, count);
        n->right = constructBinaryTree(rightV, rightVM, size - 1 - count);
        return n;
    }
    
    Node* constructBinaryTree(int pre[], int preMirror[], int size){
        vector<int> preV = {pre, pre + size}, preMV = {preMirror, preMirror + size};
        return constructBinaryTree(preV, preMV, size);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends