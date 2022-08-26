class Solution {
public:
    string minWindow(string s, string t) {
         if(s.size()<t.size())
            return s.substr(0,0);
      unordered_map<char,int> m; unordered_map<int,int> l;
        for(int i=0;i<t.size();i++)
            m[t[i]]++;
        int i=0; int j=0; int count=m.size(); int mini=s.size();
        while(j<s.size() )
        {
           if(count!=0) 
           {
              if(m.count(s[j]))
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }  
           }
            if(count>0)
                j++;
            else if(count==0)
            {
                l[j-i+1]=i;
                mini=min(mini, j-i+1);
                if(m.count(s[i]))
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count++;
                    m[s[j]]++;
                    if(m[s[j]]==1)
                        count++;
                }
                i++;
            }
        }
        if(l.size()==0)
            return s.substr(0,0);
        return s.substr(l[mini],mini);
    }
};