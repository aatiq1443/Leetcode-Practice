class Solution {
public:
    string convert(string s, int r) {
        string ans = "";
        int n=s.size();
        int diff = (r-1)*2, up,down;
        if(n<=r || r==1) return s;
        for(int i=0; i<n; i=i+diff){
            ans.push_back(s[i]);
        }
        for(int i=1; i<r-1; i++){
            up = i*2;
            down = (r-i-1)*2;
            bool flag = true;
            for(int j=i; j<n;){
                ans.push_back(s[j]);
                if(flag){
                    j=j+down;
                } 
                else {
                    j=j+up;
                }
                flag = !flag;
            }
        }
        for(int i=r-1; i<n; i=i+diff){
            ans.push_back(s[i]);
        }
        return ans;
    }
};