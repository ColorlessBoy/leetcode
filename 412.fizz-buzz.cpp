/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

/*
 * Notes:
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rst;
        for(int i = 1; i <= n; ++i) {
            if(i % 3 == 0 && i % 5 == 0){
                rst.push_back("FizzBuzz");
            }
            else if(i % 3 == 0){
                rst.push_back("Fizz");
            }
            else if(i % 5 == 0){
                rst.push_back("Buzz");
            }
            else{
                rst.push_back(to_string(i));
            }
        }
        return rst;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

