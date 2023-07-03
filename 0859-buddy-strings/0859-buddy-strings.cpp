class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if (s.size() != goal.size()) return false;
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        int diffs = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) diffs++;
            count1[s[i] - 'a']++;
            count2[goal[i] - 'a']++;
        }

        int allUniqueChars = true;
        for (int i = 0; i < count1.size(); i++) {
            if (count1[i] != count2[i]) return false;
            if (count1[i] > 1) allUniqueChars = false;
        }

        return diffs == 2 || (diffs == 0 && !allUniqueChars);
    }
};