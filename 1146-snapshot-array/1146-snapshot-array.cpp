class SnapshotArray {
public:
     SnapshotArray(int length) : len(length) {
        
    }
    
    void set(int index, int val) {
        if (index >= len) {
            return;
        }
                
        snapArray[index][snapCount] = val;
    }
    
    int snap() {
        ++snapCount;
        return snapCount - 1;
    }
    
    int get(int index, int snap_id) {
        if (index >= len || snap_id > snapCount) {
            return -1;
        }
        if (snapArray[index].empty()) {
            return 0;
        }
        auto pos = snapArray[index].lower_bound(snap_id);
        if (pos == snapArray[index].end()) {
            return 0;
        }

        return pos->second;
    }
    private:
    using SMap = std::map<int, int, greater<int>>;
    std::unordered_map<int, SMap> snapArray;
    int snapCount = 0;
    int len = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */