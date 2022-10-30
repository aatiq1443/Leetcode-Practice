class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        vector<int> bucket(citations.size() +1);
            
        for(int i=0; i< citations.size(); i++){
            
           if(citations[i]>citations.size())
               bucket[citations.size()]++;
            
           else
               bucket[citations[i]]++;               
           }

          int count=0;
        
          for(int i=bucket.size()-1; i>=0; i--){
              
             count+=bucket[i];
              
             if(count>=i)
                return i;
              
           }

        return 0;
        
    }
};