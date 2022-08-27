class Solution {
public:
   int getSum(vector<int>& arr,int k){
        int maxi=INT_MIN;
        int n=arr.size();
        int sum=0;
        set<int> s;
        s.insert(0);
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            auto it=s.lower_bound(sum-k);
            if(it!=s.end()){
                maxi=max(maxi,sum-*it);
            }
            
            s.insert(sum);
        }
        return maxi;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> arr(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    arr[k]+=matrix[j][k];
                }
                int maxSum=getSum(arr,k);
                maxi=max(maxi,maxSum);
            }
        }
        return maxi;
    }
};