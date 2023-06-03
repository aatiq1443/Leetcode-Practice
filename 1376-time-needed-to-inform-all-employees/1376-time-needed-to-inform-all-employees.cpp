class Solution {
public:
int dfs(int id,vector<int>&vis,vector<int>ad[],vector<int>&it){
        vis[id]=1;
        int ans=it[id];
        int mx=0;
        for(auto k : ad[id]){
            if(!vis[k]){
                mx= max(mx,dfs(k,vis,ad,it));
            }
        }
        return ans+mx;
    }
    int numOfMinutes(int n, int id, vector<int>& manager, vector<int>& it) {
        vector<int>ad[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                ad[manager[i]].push_back(i);
            }
        }
        vector<int>vis(n,0);
        vis[id]=1;
        return dfs(id,vis,ad,it);
    }
};