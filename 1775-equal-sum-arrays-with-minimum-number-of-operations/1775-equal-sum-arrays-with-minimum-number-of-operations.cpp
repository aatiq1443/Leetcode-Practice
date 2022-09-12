class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
       int s1 = 0, s2 = 0, ans = 0;
        
        for(int i : nums1) s1 += i;
        
        for(int i : nums2) s2 += i;
        
        int val = s1 - s2;
        if(!val) return 0;
        
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        
        if(val > 0) {
            for(int i : nums1) pq1.push(i);
            for(int i : nums2) pq2.push(i);
        }
        
        else {  
            for(int i : nums2) pq1.push(i);
            for(int i : nums1) pq2.push(i);
        }
        
        val = abs(val);
        
        while(val > 0) {
            
            if(pq1.top() == 1 && pq2.top() == 6) return -1;
            
            if(pq1.top() - 1 > 6 - pq2.top()) {
                int i, h = pq1.top(); pq1.pop();
                for(i=1; i<h; i++) if(val - h + i >= 0) break;
                val -= h - i;
                if(i != h) ans++;
                pq1.push(i);
            }
            
            else {
                int j, l = pq2.top(); pq2.pop();
                for(j=6; j>l; j--) if(val - j + l >= 0) break;
                val -= j - l;
                if(j != l) ans++;
                pq2.push(j);
            }
            
        }
        return ans;
        
    }
};