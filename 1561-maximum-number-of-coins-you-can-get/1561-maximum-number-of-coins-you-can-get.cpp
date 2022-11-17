class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end(),greater<int>());
        
        int x=piles.size()/3;
        int sum=0;
        
        for(int i=1;i<x*2;i+=2){
            
            sum+=piles[i];
        }
        
        return sum;
        
    }
};