//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
   pair<int, pair<int, int>> findLargestBST(Node* root, int& answer)
{
    //Edge and base case
    if(root == NULL)
        //Note that this can easily be defeated; and counted into a BST, even in further recursive calls
        return {0, {INT_MAX, INT_MIN}};

    //Recursively move into the subtrees
    auto leftSubtree = findLargestBST(root->left, answer);
    auto rightSubtree = findLargestBST(root->right, answer);  

    //If the current node (aka root) satisfies the property of a BST...
    if(leftSubtree.second.second < root->data and rightSubtree.second.first > root->data)
    {
        //...recompute the new BST size
        int bstSize = leftSubtree.first + rightSubtree.first + 1;

        //and update the final answer 
        answer = max(answer, bstSize);

        //return the current BST size, min of the entire BST and max of the entire BST 
        return {bstSize, {min(root->data, leftSubtree.second.first), max(root->data, rightSubtree.second.second)}};
    }

    //If the current node can't satisfy BST property, return.
    //Can't be defeated; Hence it'll not to be counted into a BST in further recursion calls too.
    return {0, {INT_MIN, INT_MAX}}; 
}
   int largestBst(Node *root)
   {
        int answer = 0;
        findLargestBST(root, answer);
        return answer;
   }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends