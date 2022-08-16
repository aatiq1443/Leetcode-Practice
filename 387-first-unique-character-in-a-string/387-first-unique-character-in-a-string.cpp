class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int temp=-1;
        for( int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                temp=i;
                break;
            }
        }
        if(temp==-1){
            return -1;
        }
        return temp;
    }
};