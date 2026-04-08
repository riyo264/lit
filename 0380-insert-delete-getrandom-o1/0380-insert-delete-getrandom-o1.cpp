class RandomizedSet {
private:
    vector<int> out;
    unordered_map<int, int> mpp;
    mt19937 gen{random_device{}()};
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mpp.count(val)) {
            return false;
        }
        else {
            mpp[val] = out.size();
            out.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mpp.count(val)) {
            int last = out.back();
            int idxToRemove = mpp[val];
            out[idxToRemove] = last;
            mpp[last] = idxToRemove;
            out.pop_back();
            mpp.erase(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        uniform_int_distribution<> dis(0, out.size() - 1);
        return out[dis(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */