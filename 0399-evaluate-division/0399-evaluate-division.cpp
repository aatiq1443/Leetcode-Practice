class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> map;
    
    double solve(string &s, string &d, double cur, set<string> &vis){
        if(map.find(s) == map.end()) return -1.0;
        if(s==d) return cur;
        
        vis.insert(s);
        for(auto &e : map[s]){
           if(vis.find(e.first) == vis.end()){
               double ans = solve(e.first, d, cur*e.second, vis);
               if(ans!=-1) return ans;
           }
        }
        return -1.0;
    }
        
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map.clear();
        int n = equations.size();
        for(int i=0; i<n; ++i){
            map[equations[i][0]].push_back({equations[i][1], values[i]});
            map[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        vector<double> res;
        for(auto &q : queries){
            string s = q[0], d = q[1];
            if(map.find(s)== map.end() || map.find(d)==map.end()){
                res.push_back(-1.0);
            }else{
                set<string> vis;
                res.push_back(solve(s,d,1.0,vis));
            }
        }
        return res;
    }
};