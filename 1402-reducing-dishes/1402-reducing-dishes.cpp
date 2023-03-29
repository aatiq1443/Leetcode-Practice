class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        
        int n=s.size();
        
        sort(s.begin(),s.end());
        int sum=0,temp=0,cnt=0;
        
        for(auto e:s){
            temp+=e*(cnt++);
        }
        
        sum=max(sum,temp);
        for(int i=0;i<n;i++){
            
            cnt=1;
            temp=0;
            
            for(int j=i;j<n;j++){
                temp+=(s[j])*(cnt++);
            }
            
            sum=max(sum,temp);
        }
        
        return sum;
    }
};