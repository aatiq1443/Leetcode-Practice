class Solution {
public:
double dp[30][30][105];
        int dx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
        int dy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };

        double dfs(int i,int j,int k, int n){
            if(i < 0 || j < 0 ||i >= n || j >= n) return 0;
            if(k == 0) return 1;
            if(dp[i][j][k] != 0) return dp[i][j][k];

            double temp = 0;

            for(int l = 0;l < 8; l++){
              int x = i + dx[l];
              int y = j + dy[l];
              temp += dfs(x,y,k-1,n);
            }
            return dp[i][j][k] += (temp/8.0);
        }

        double knightProbability(int n, int k, int row, int column) {
            memset(dp,0,sizeof(dp));
            return dfs(row,column,k,n); 
        }
};