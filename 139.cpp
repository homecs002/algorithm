#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int mem[300 + 5];
    
    bool check(string slice, vector<string>& wordDict){
        // 检查区间slice是否在wordDict里面
        auto it = find(wordDict.begin(), wordDict.end(), slice);
        if(it != wordDict.end()) return true;
        else return false;
    }

    bool dfs(int l, string s,vector<string>& wordDict){
        int len = s.size();
        if(l == len) return true;
        // else return false;
        for(int r = l; r < len; r++){
            string slice = s.substr(l, r - l + 1);
            // 在check前，先检查是否在字典中
            if(check(slice, wordDict)) {
                    bool flag;
                    if(mem[r + 1] != -1) flag = mem[r + 1];
                    else flag = dfs(r + 1, s, wordDict);  // 如果下个dfs传递过来是true，说明成功了，那么这个dfs就要
                    mem[r + 1] = (int)(flag);
                    if (flag){  // 继续把这个知识向上传递。
                        return true;
                    }
                }
        }
        return false;  // 到这里说明失败了，要向上传递false。
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // 对mem进行初始化，全部初始化为-1，代表没有计算过。
        for(int i = 0; i < 305; i++) mem[i] = -1;
        
        return dfs(0, s, wordDict);
    }
};

int main(){
    // 定义好函数中的测试数据
    string s = "aaaaaaa";
    vector<string> wordDirct = {"aaaa","aaa"};
    Solution solu;
    cout << solu.wordBreak(s, wordDirct);
    return 0;
}