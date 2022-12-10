//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
     stack<char> st;

    for(int i=0; i<num.size(); i++){

        

            while(!st.empty() && st.top() > num[i] && k){

                st.pop();

                k--;

            }

        st.push(num[i]);

        

    }

    while(!st.empty() && k--) st.pop();

 

    string ans = "";

    while(!st.empty()){

        ans += st.top();

        st.pop();

    }

    while(ans[ans.size()-1] == '0') ans.pop_back();

    reverse(ans.begin(), ans.end());

    return ans == "" ? "0" : ans;
}