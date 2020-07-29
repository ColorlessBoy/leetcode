/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= n) {
            int mid = l + (r - l) / 2;
            int state = guess(mid);
            if(state == 0) {
                return mid;
            }
            else if(state == 1) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return 0;
    }
};
// @lc code=end

