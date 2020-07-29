/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */
/*
 * 一个哈希表，一个动态数组实现插入与查找是 O(1);
 * 要删除的元素与最后的元素交换，再删除最后的元素;
 * C++ 生成随机正整数的函数 rand(). 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> record;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(record.find(val) == record.end()) {
            record[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = record.find(val);
        if(iter == record.end()) {
            return false;
        }

        int n = nums.size();
        record[nums[n-1]] = record[val];
        nums[record[val]] = nums[n-1];

        record.erase(record.find(val));
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(nums.empty())
            return 0;
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
// @lc code=end

int main(int argc, char **argv) {
    // Solution s();

    return 0;
}

