/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

/*
 * Notes:
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        m = matrix.size();
        n = matrix[0].size();
        table = vector<vector<int>>(m, vector<int>(n, 0));

        //查看太平洋能流到的地方
        for(int i = 0; i < m; ++i) {
            dfs(i, 0, 1, matrix);
        }
        for(int j = 0; j < n; ++j) {
            dfs(0, j, 1, matrix);
        }
        //查看大西洋能流到的地方
        for(int i = 0; i < m; ++i) {
            dfs(i, n-1, 10, matrix);
        }
        for(int j = 0; j < n; ++j) {
            dfs(m-1, j, 10, matrix);
        }

        //统计
        vector<vector<int>> rst;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(table[i][j] == 11)
                    rst.push_back({i, j});
            }
        }
        return rst;
    }
private:
    int m, n, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    vector<vector<int>> table;
    void dfs(int r, int c, int bound, vector<vector<int>>& matrix){
        if(table[r][c] >= bound)
            return;
        table[r][c] += bound;
        for(int i = 0; i < 4; ++i) {
            if(r + dr[i] >= 0 && r + dr[i] < m 
            && c + dc[i] >= 0 && c + dc[i] < n
            && matrix[r][c] <= matrix[r+dr[i]][c+dc[i]])
            dfs(r + dr[i], c + dc[i], bound, matrix);
        }
    }
    
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto rst = s.pacificAtlantic(matrix);
    return 0;
}

