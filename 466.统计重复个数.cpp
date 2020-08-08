/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

/*
 * Note:
 * 查找循环节。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, pair<int, int>> record;
        //record[i << 8 + j] = [epoch, cnt]
        int j = 0, cnt = 0, size1 = s1.size(), size2 = s2.size();
        for(int epoch = 0; epoch < n1; ++epoch) {
            for(int i = 0; i < size1; ++i) {
                if(s1[i] == s2[j]) {
                    int code = (i << 8) + j;
                    if(j + 1 == size2) {
                        cnt++;
                        if(record.find(code) != record.end()) {
                            //快速更新epoch
                            int d_epoch = epoch - record[code].first;
                            if(d_epoch > 0) {
                                int d_cnt = cnt - record[code].second;
                                int t = (n1 - 1 - epoch) / d_epoch;
                                epoch += t * d_epoch;
                                cnt += t * d_cnt;
                            }
                        }
                    }
                    record[code] = make_pair(epoch, cnt);
                    j = (j + 1) % size2;
                }
            }
        }
        return cnt / n2;
    }
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    auto rst = s.getMaxRepetitions("aaa", 20, "aaaaa", 1);
    return 0;
}

