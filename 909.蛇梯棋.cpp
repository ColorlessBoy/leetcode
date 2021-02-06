/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
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
    int snakesAndLadders(vector<vector<int>>& board) {
        if(board.empty())
            return -1;
        int N = board.size();
        vector<int> array(N * N), steps(N * N, -1);

        // broadcast
        int cnt = 0;
        for(int i = N - 1; i >= 0; --i) {
            if((N - 1 - i) % 2 == 0) {
                for(int j = 0; j < N; ++j) {
                    array[cnt++] = board[i][j] - 1;
                }
            } else {
                for(int j = N - 1; j >= 0; --j) {
                    array[cnt++] = board[i][j] - 1;
                }
            }
        }

        // bfs? circle?
        queue<int> q;
        q.push(0);
        steps[0] = 0;
        while(!q.empty()){
            int current = q.front(); q.pop();
            for(int i = 1; i <= 6; ++i) {
                if(current + i >= N * N) break;
                int next = current + i;
                if(array[next] != -2)
                    next = array[next];
                if(steps[next] == -1) {
                    //unvisited node
                    q.push(next);
                    steps[next] = steps[current] + 1;
                }
            }
        }
        return steps[N * N - 1];
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    int rst = s.snakesAndLadders(board);
    return 0;
}

