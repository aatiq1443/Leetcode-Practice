class Solution {
public:

    
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool flag=true;
                for(int f=0,k=0;f<n;f++,k++)
                {
                    if (grid[f][j]==grid[i][k])
                    {
                        continue;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

 