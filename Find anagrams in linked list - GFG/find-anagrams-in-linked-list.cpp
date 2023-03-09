//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
     vector<Node*> findAnagrams(struct Node* head, string s) {

        // code here

        vector<Node*> v;

        map<char,int> mp;

        for(auto it:s)

            mp[it]++;

        Node *temp = head;

        //cout<<"head = "<<&head<<" temp = "<<temp<<endl;

        while(temp){

            Node* itr = temp;

            Node* toStore = NULL;

            Node *itrToStore = NULL;

            Node* prev = NULL;

            int valid = 0;

            map<char,int> mTemp = mp;

            while(valid < s.size() && itr){

                if(mTemp[itr->data]){

                    mTemp[itr->data]--;

                    valid++;

                    prev = itr;

                    if(toStore == NULL){

                        toStore = new Node(itr->data);

                        itrToStore = toStore ;

                    }

                    else{

                        itrToStore -> next = new Node(itr -> data);

                        itrToStore = itrToStore -> next ;

                    }

                    itr = itr -> next;

                }

                else

                    break;

            }

            if(valid == s.size()){

                v.push_back(toStore);

                temp = prev -> next;

            }

            else

                temp = temp -> next ;

        }

        //cout<<"size of the vector = "<<v.size()<<" and element is "<<v[0] -> data<<endl;

        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends