class Solution {
private:
    int solve(vector<int> &nums,string &visited,int k){
     
        if(k == 0){
            return 0;
        }

        if(dp[visited] != 0){
            return dp[visited];
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(visited[i] == '0'){
                visited[i] = '1';
                int temp = 0;
                for(int j=i+1;j<nums.size();j++){
                    if(visited[j] == '0'){
                        visited[j] = '1';
                        temp = max(k * gcd(nums[i],nums[j]) + solve(nums,visited,k-1),temp);
                        visited[j] = '0';
                    }
                }
                
                visited[i] = '0';
                ans = max(ans,temp);
            }
        }

        return dp[visited] = ans;
    }
public:
    unordered_map<string,int> dp;
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        string visited(n,'0');

        return solve(nums,visited,n/2);
    }
};
