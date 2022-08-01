class Solution {
public:
    vector<string> findAndReplacePattern( vector<string>& words, string p ) 
    {
        vector<string> ans;
        
        p = Reformat(p);
        
        for( auto word : words )
        {
            if( !Reformat(word).compare(p) )
            {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
    
    string Reformat( string word )
    {
        vector<int> charTable(26, -1);
        string ans;
        int indx = 0;
        
        for( auto c : word )
        {
            int pos = c - 'a';
            
            if( charTable[pos] == -1 )
            {
                charTable[pos] = indx;
                ans.push_back(indx++);
            }
            else
            {
                ans.push_back(charTable[pos]);
            }
        }
        return ans;
    }
};