//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
         struct Trie{
      unordered_map<char,Trie*>m;
      bool flag;
    };
    
    Trie* gen(){
        Trie* temp=new Trie;
        temp->flag=false;
        return temp;
    }
    
    void insert(Trie** root,string s){
        if(*root==NULL){
            *root=gen();
        }
        Trie* temp=*root;
        for(auto i:s){
            if(temp->m.find(i)==temp->m.end()){
                temp->m[i]=gen();
            }
            temp=temp->m[i];
        }
        temp->flag=true;
        temp=*root;
        for(int i=s.length()-1;i>=0;i--){
            if(temp->m.find(s[i])==temp->m.end()){
                temp->m[s[i]]=gen();
            }
            temp=temp->m[s[i]];
        }
        temp->flag=true;
    }
    
    int search(Trie* root,string s){
        for(auto i:s){
            if(root->m.find(i)!=root->m.end()){
                root=root->m[i];
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Trie* root=NULL;
        for(auto i:s1){
            insert(&root,i);
        }
        int c=0;
        for(auto i:s2){
            string s=i;
            reverse(s.begin(),s.end());
            c+=(search(root,i)||search(root,s));
        }
        return c;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends