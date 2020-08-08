/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

/*
 * Note:
 * 首先，肯定要排序。
 * 把数组分为两种:基础单词与连接词。
 * 如果它是连接词，那么肯定不是基础单词,
 * 逆反命题：如果它是基础单词，那么它肯定不是连接词。
 * 连接词只能够由比它短的单词组成。
 * 
 * 如果组成基础单词库呢？ 用tire+dfs。
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), 
            [&](string a, string b){
                if(a.size() == b.size())
                    return a < b;
                return a.size() < b.size();
            });
        Tire tire;
        vector<string> rst;
        for(auto &word: words) {
            if(word.empty()) continue;
            if(tire.isInTire(word)) {
                rst.push_back(word);
            }
            else {
                tire.insert(word);
            }
        }
        return rst;
    }
private:
    struct Node{
        Node* next[26];
        bool isWord;
        Node() {
            memset(next, 0, sizeof(next));
            isWord = false;
        }
    };
    struct Tire{
        Node* root;
        Tire() {
            root = new Node();
        }
        void insert(string &word) {
            Node* node = root;
            for(auto &ch: word) {
                if(node->next[ch-'a'] == 0) {
                    node->next[ch-'a'] = new Node();
                }
                node = node->next[ch-'a'];
            }
            node->isWord = true;
        }
        bool isInTire(string &word) {
            return dfs(root, word, 0);
        }
        bool dfs(Node* node, string &word, int idx) {
            if(node == NULL) return false;
            if(idx == word.size()) 
                return node->isWord;
            bool rst = false;
            if(node->isWord) {
                rst = dfs(root, word, idx);
            }
            if(node->next[word[idx]-'a'] != NULL) {
                rst |= dfs(node->next[word[idx]-'a'], word, idx+1);
            }
            return rst;
        }
    };
};
// @lc code=end

int main(int argc, char **argv) {
    Solution s;
    vector<string> words = {
        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
    };
    auto rst = s.findAllConcatenatedWordsInADict(words);
    return 0;
}

