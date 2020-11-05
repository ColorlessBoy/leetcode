/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
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
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) 
            return 0;
        int cnt = 0, m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'X' 
                &&(i == 0 || board[i-1][j] == '.')
                &&(j == 0 || board[i][j-1] == '.'))
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    
    return 0;
}

