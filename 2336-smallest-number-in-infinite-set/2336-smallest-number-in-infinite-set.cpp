class SmallestInfiniteSet {
public:
    set<int> set1;
    SmallestInfiniteSet() {
        set1.clear();
        for(int i=1;i<=1000;i++){
            set1.insert(i);
        }
    }
    
    int popSmallest() {
        
        int temp=*set1.begin();
        
        set1.erase(set1.begin());
        return temp;
    }
    
    void addBack(int num) {
        set1.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */