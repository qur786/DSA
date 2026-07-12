class SnapshotArray {
public:
    int snapID;
    vector<vector<pair<int, int>>> arr;
    SnapshotArray(int length) {
        snapID = 0;
        arr.assign(length, vector<pair<int, int>>(1, make_pair(snapID, 0)));
    }

    void set(int index, int val) {
        if (arr[index].back().first == snapID)
            arr[index].back().second = val;
        else
            arr[index].push_back({snapID, val});
    }

    int snap() { return snapID++; }

    int get(int index, int snap_id) {
        pair<int, int> temp(snap_id, INT_MAX);
        auto it = upper_bound(arr[index].begin(), arr[index].end(), temp);
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */