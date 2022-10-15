class Solution {
public:
    char findTheDifference(string s, string t) {
        // optimal solution
        int n = s.length();
        int m=t.length();
        int sum = 0;
        for(int i = 0; i< m ;i++) 
           sum=sum+t[i];
        for(int j =0 ;j < n ; j++)  
            sum =sum - s[j];
        
        return char ( sum);
    }
};