class Solution {
public:
     int f(int ind, int k, vector<vector<int>> &events, vector<vector<int>> &dp){
         
        if(ind == events.size() || k == 0){
            return 0;
        }
         
        if(dp[ind][k] != -1) return dp[ind][k];
         
        int take = events[ind][2];
         
        for(int i = ind+1; i < events.size(); ++i){
            if(events[ind][1] < events[i][0]){
                take += f(i,k-1,events,dp);
                break;
            }
        }
         
        int notTake = 0;
         
        notTake = f(ind+1, k, events, dp);
         
        return dp[ind][k] = max(take,notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        
        sort(events.begin(),events.end());
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        return f(0,k,events,dp);
    }
};