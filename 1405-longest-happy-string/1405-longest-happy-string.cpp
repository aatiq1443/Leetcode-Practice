class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
         priority_queue<pair<int,char>> pq; 
        
        if(a!=0) pq.push({a,'a'});
        if(b!=0) pq.push({b,'b'});
        if(c!=0) pq.push({c,'c'});
        
        string s="";
        pair<int,char> prev={0,'#'};
        
        while(!pq.empty()){
            
            auto [val,ch]=pq.top();
            pq.pop();
            if(prev.first>0) pq.push(prev);
            
            if(val<prev.first){
               
                s.push_back(ch);
                prev={val-1,ch};
            }
            else{
              
                s.push_back(ch);
                
               if(val>1) s.push_back(ch);
                prev={val-2,ch};
                
            }
        }
        
        return s;
        
    }
};