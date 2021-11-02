class SnapshotArray {
public:
    
    int sshot;
    int v[50009];
    
    struct INFO{
        map <int, int> mp;  
    }sinfo[50009];
    
    SnapshotArray(int length) {
        sshot = 0;
        for(int i=0 ; i<length ; i++ ) {
            v[i] = 0;
            sinfo[i].mp.clear();
        }
    }
    
    void set(int index, int val) {
        v[index] = val + 1;
        sinfo[sshot].mp[index] = val + 1;
    }
    
    int snap() {
        sshot++;
        return sshot-1;
    }
    
    int get(int index, int snap_id) {
        if( sinfo[snap_id].mp[index] != 0 )
            return sinfo[snap_id].mp[index] == 0 ? 0 : sinfo[snap_id].mp[index] - 1;
        
        while(snap_id > 0 && sinfo[snap_id].mp[index] == 0) {
            snap_id--;
        }
        
        return sinfo[snap_id].mp[index] == 0 ? 0 : sinfo[snap_id].mp[index] - 1;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */