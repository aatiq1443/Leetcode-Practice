//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
                int n  = s.length();

 

        int count = 0;

 

       for(int i = 0; i < n;i++){

 

           //unordered_map<char,int> mp;

           int cnt[26] = {};

 

           for(int j = i;j<n;j++)

 

           {

                

               cnt[s[j]-'a']++;

 

               int max = 0;

 

               int min = 600;

 

            

                   for(int k = 0;k<26;k++){

 

                       if(cnt[k] > max )  max = cnt[k];

 

                        if(cnt[k] < min && cnt[k] != 0)  min = cnt[k];

 

                   }

                   

                if(min != 600  )    

                  count += (max - min);

 

           }

 

       }

      

       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends