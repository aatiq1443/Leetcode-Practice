class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
         vector<vector<int>> al(n);
    vector<int> prereq(n), lead(n);
    for (auto &r : relations) {
        al[r[0] - 1].push_back(r[1] - 1);
        ++prereq[r[1] - 1];
    }
    vector<int> q;
    for (int i = 0; i < n; ++i)
        if (prereq[i] == 0)
            q.push_back(i);
    while(!q.empty()) {
        vector<int> q1;
        for (int i : q) {
            lead[i] += time[i];
            for (int j : al[i]) {
                lead[j] = max(lead[j], lead[i]);
                if (--prereq[j] == 0)
                    q1.push_back(j);
            }
        }
        swap(q, q1);
    }
    return *max_element(begin(lead), end(lead));
    }
};