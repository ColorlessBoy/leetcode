/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */
/*
 * 1. 修改数据结构: 
 * unordered_set<int> 查询、插入和删除操作的平均时间复杂度 O(1)
 * 2. 注意点：val值就是数组最后的值。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> dict;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int rst = false;
        if(dict.find(val) == dict.end()) {
            rst = true;
        }
        dict[val].insert(nums.size());
        nums.push_back(val);
        return rst;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto map_iter = dict.find(val);
        if(map_iter == dict.end()) {
            return false;
        }
        auto &set1 = map_iter->second;

        int n = nums.size();
        int end_val = nums[n-1];
        if(end_val == val) {
            set1.erase(set1.find(n-1));
        }
        else {
            int val_idx = *(set1.begin());
            nums[val_idx] = end_val;
            auto &set2 = dict.find(end_val)->second;
            set2.erase(set2.find(n-1));
            set2.insert(val_idx);
            set1.erase(set1.begin());
        }

        // 需要判断这个数是不是已经被删完了。
        if(set1.empty()) {
            dict.erase(map_iter);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

int main(int argc, char **argv) {
    // Solution s();
    RandomizedCollection r;
    r.insert(4);
    r.insert(3);
    r.insert(4);
    r.insert(2);
    r.insert(4);
    r.remove(4);
    r.remove(3);
    r.remove(4);
    r.remove(4);
    return 0;
}

