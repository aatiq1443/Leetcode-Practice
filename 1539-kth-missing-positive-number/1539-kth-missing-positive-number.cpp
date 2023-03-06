class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
              int l = 0, h = arr.size();
        
        while (l < h) {
            int m = (l + h)/2;
			int b = arr[m] - m - 1;
            if (b < k) {
                l = m + 1;
            }
            else {
                h = m;
            }
        }
        return l+k;
    }
};