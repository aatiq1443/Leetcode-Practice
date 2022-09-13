class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int prev = 0,m;
        for(auto& d:data){
            if((d&128)==0){
                if(prev)
                    return false;
                prev=0;
            }
            else{
                if((d&64)==0)
                    prev--;
                else{
                    if(prev) return false;
                    prev=1;m=5;
                    while(d&(1<<(m--))){
                        prev++;
                        if(prev>3) return false;
                    }
                }
            }
        }
        return prev==0;
    }
};