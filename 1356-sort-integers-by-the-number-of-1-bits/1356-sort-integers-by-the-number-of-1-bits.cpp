class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
               sort(arr.begin(), arr.end());
        vector<vector<int>> freq(14);
        for (int i = 0; i < arr.size(); i++)
        {
            freq[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        int i = 0;
        for (int j = 0; j < 14; j++)
        {
            for (int k = 0; k < freq[j].size(); k++)
            {
                arr[i++] = freq[j][k];
            }
        }
        return arr;
    }
};