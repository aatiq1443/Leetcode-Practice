class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
          
        sort(stones.begin(), stones.end(), greater());
        for(auto i:stones){
            cout<<i<<" ";
        }
while(stones.size()!=1){
stones[0]=stones[0]-stones[1];
stones.erase(stones.begin()+1);
sort(stones.begin(), stones.end(), greater());
}
return stones[0];
    }
};