class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
         int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int i = 0;
        int j = n - 1;
		
        bool flag = false;
        int score = 0;
        
        while (i <= j) {
			
            while (i <= j && power >= tokens[i]) {
                power -= tokens[i];
                score += 1;
                flag = false;
                i++;
            }
            
            if (score > 0 && i < j){
                power += tokens[j];
                score -= 1;
                j--;
                flag = true;
            }
            
            else {
                break;
            }
            
        }
        
        if (flag) return score + 1;
        return score;
        
    }
};