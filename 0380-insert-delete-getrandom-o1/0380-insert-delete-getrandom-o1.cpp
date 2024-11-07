class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end())
        {
            nums.push_back(val);
            mp[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it!= mp.end())
        {
            nums[it->second] = nums.back(); // It gives the value of last element without changing or removing it.
            nums.pop_back(); // Remove last element of the array.
            mp[nums[it->second]] = it->second; // updating the Element's index after the swapping.

            mp.erase(val); // Erase the element->index 
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */