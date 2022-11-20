class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int n = sentences.size();
        int ans = 0;
        
        for(int i=0 ; i< n ; i++){
            int cnt = 0;
            string temp = sentences[i];
            
            for(int j=0 ; j<temp.size() ; j++){
                if(temp[j] == ' '){
                    cnt++;
                }
            }
            
            ans = max( ans , cnt+1);
        }
        return ans;
        
    }
};