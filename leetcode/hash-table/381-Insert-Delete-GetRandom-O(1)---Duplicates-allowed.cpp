class RandomizedCollection {
public:
    unordered_map<int,set<int>>mp;
    vector<int>nums;
    int curr_pos=0;
    RandomizedCollection() {

    }
    bool insert(int val) {
        if(mp.find(val)==mp.end())
        {
            nums.push_back(val);
            mp[val].insert(nums.size()-1);
            curr_pos++;
            return true;
        }
        else
        {
            nums.push_back(val);
            mp[val].insert(nums.size()-1);
            curr_pos++;
            return false;
        }
    }
    bool remove(int val)
    {
        if(mp.find(val)==mp.end())
        {
            return false;
        }
        int idx=*mp[val].begin();
        int last_idx=nums.size()-1;
        int last_val=nums[last_idx];
        mp[val].erase(idx);
        if(idx!=last_idx)
        {
            nums[idx]=last_val;

            mp[last_val].erase(last_idx);
            mp[last_val].insert(idx);
        }
        nums.pop_back();
        curr_pos--;
        if(mp[val].empty())
        {
            mp.erase(val);
        }
        return true;
    }
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */