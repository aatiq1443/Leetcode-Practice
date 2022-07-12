class Solution {
public:
    int lim;
    
    bool pos(vector<int>& matchsticks , int i , vector<int>& a){
         
        if(i==matchsticks.size()) return 1;
        
        for(int j=0;j<4;j++){
            
            if(a[j]+matchsticks[i]<=lim){
                a[j]+=matchsticks[i];
                if(pos(matchsticks,i+1,a)) return 1;
                a[j]=a[j]-matchsticks[i];
            }
            
        }
        return 0;        
    } 
   
    bool makesquare(vector<int>& matchsticks) {

        int total=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total%4!=0) return 0;
        lim=total/4;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        vector<int> a(4,0);
        return pos(matchsticks,0,a);
    }
};