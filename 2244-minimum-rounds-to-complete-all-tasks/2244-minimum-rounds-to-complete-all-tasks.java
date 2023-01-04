class Solution {
    public int minimumRounds(int[] tasks) {
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i:tasks){
            hm.put(i, 1 + hm.getOrDefault(i,0));
        }
        int ans=0;
        for(int k:hm.keySet()){
            int x=hm.get(k);
            if(x==1)return -1;
            if(x==2) ans++;
            if(x==3) ans++;
            if(x>=4){
                int u=x/3;
                int rem = x- 3*u;
                if (rem ==0){
                    ans+=u;
                }
                if (rem ==1){
                    ans+=(u-1+2);
                }
                 if (rem ==2){
                    ans+=(u+1);
                }
            }
        }
        return ans;
    }
};