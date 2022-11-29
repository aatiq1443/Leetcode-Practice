class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> num;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(m.find(val)==m.end()){
            
            m[val]=num.size();
            num.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        
        if(m.find(val)!=m.end()){
            
            int ind=m[val];
            num[ind]=num[num.size()-1];
            m[num[num.size()-1]]=ind;
            
            num.pop_back();
            m.erase(val);
            return true;
            
        }
        
        return false;
    }
    
    int getRandom() {
        
        int p=rand()%num.size();
        return num[p];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */