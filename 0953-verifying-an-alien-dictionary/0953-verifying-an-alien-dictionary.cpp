class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       
    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; words[i][j] != '\0' || words[i-1][j] != '\0'; j++) {
            if (words[i][j] != words[i - 1][j]) {
                int cur;
                int prev;
                for (int k = 0; order[k] != '\0'; k++) {
                    if (order[k] == words[i][j])
                        cur = k;
                    if (order[k] == words[i-1][j])
                        prev = k;
                }
                if (cur < prev)
                    return false;
                else
                    break;
            } else {
                if (words[i][j+1] == '\0' && words[i-1][j+1] != '\0')
                    return false;
                else if (words[i-1][j+1] == '\0' && words[i][j+1] != '\0')
                    return true;
            }
        }
    }
    return true;

    }
};