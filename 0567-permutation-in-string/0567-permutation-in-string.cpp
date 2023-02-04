class Solution {

public:
    bool checkInclusion(string s1, string s2) {
        
            vector<int> s1hash(26,0);
          vector<int> s2hash(26,0);    

            int left=0, right=0;
            if(s1.size()>s2.size())
                return false;
            while(right<s1.size()){
                s1hash[s1[right]-'a']+=1;
                s2hash[s2[right]-'a']+=1;
                right+=1;  
            }

            right-=1;
            while(right<s2.size()){
                if(s1hash==s2hash)
                  return true;
                  right+=1;
                cout<<endl;
                if(right!=s2.size())
                     s2hash[s2[right]-'a']+=1;
                     s2hash[s2[left]-'a']-=1;
                left+=1;


            }


            return false;


        }
        
    
};