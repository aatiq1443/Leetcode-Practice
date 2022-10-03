class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int len = colors.size();
        
        int mintime = 0;
        
        priority_queue<int,vector<int>,greater<int>>min_heap;
    
        for(int i = 0 ; i < len ; i++){
            
            min_heap.push(neededTime[i]);
            
            int j=i+1;

            for( ; j < len ; j++){
                
                if(colors[j] == colors[i]){
                    
                    min_heap.push(neededTime[j]);
                    
                    if(min_heap.size()>1){
                        mintime += min_heap.top();
                        min_heap.pop();
                    }
                    
                }
                else{
                    
                    break;
                    
                }
            }
            
            min_heap.pop();
            i=j-1;
            
        }

        return mintime;
    }
};