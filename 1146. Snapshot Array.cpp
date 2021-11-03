class SnapshotArray {
public:
    
    vector <map <int, int>> map_vec;
    int snapshot;
    
    SnapshotArray(int length) : map_vec(length) {
        snapshot = 0;
        for(auto& mp : map_vec ) {
            mp[0] = 0;
        }
    }
    
    void set(int index, int val) {
        auto it = prev(map_vec[index].end());
        if( it->first == snapshot) {
            it->second = val;
        }
        else {
            map_vec[index].insert(map_vec[index].end(), make_pair(snapshot, val));
        }
    }
    
    int snap() {
        snapshot++;
        
        return snapshot - 1;
    }
    
    int get(int index, int snap_id) {
        return prev(map_vec[index].upper_bound(snap_id))->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */