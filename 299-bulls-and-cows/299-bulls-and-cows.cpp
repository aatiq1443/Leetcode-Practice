class Solution {
public:
    string getHint(string secret, string guess) {
        int count = 0;
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                count ++;
            }
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        string str=to_string(count);
        str+="A";
        
        count=0;
        for(auto i:mp1){
            count+=min(i.second,mp2[i.first]);
        }
        str+=to_string(count);
        str+="B";
     return str;
        
    }
};