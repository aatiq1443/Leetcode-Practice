#define p pair<int, int>
unordered_map<int, int> um;

bool compare(int x, int y) {
    if (um[x] == um[y])
        return x < y;
    return um[x] < um[y];
}

class Solution {
    vector<int> ans;
    
public:
    int countSoldiers(vector<int>& nums, int n) {
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == 1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        int m = nums[0].size();
        
        int curr = INT_MIN;
        for (int i = n-1; i >= 0; i--) {
            int cnt = countSoldiers(nums[i], m);
            um[i] = cnt;
            ans.push_back(i);
            curr = max(cnt, curr);
        }
        
        sort(ans.begin(), ans.end(), compare);
        
        return vector<int>(ans.begin(), ans.begin() + k);
        
    }
};