class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        
        vector<int>vec1(n, 1);
        vector<int>vec2(n, 1);
        
        for (int i = 0; i < n - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                vec1[i + 1] = vec1[i] + 1;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                vec2[i] = vec2[i + 1] + 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans += max(vec1[i], vec2[i]);
        }
        
        return ans;
    }
};