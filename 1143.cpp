#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[1005][1005];   // 分别表示考虑text1[i] 和 text2[j] 前这么多字符，的最长公共子序列的长度。
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // vector<vector<int>>dp(1005, 1005);
        for(int i = 0; i < 1005; i ++) for(int j = 0; j < 1005; j++) dp[i][j] = 0;
        int len1 = text1.size();
        int len2 = text2.size();

        // if(text1[0] == text2[0]) dp[0][0] = 1;

        for(int i = 1; i <= len1; i ++){
            for (int j = 1; j <= len2; j++){
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1][len2];
    }

};

int main(){
    // 定义好函数中的测试数据
    // vector<int> inp = {2, 3, 4};
    string text1 = "abcde";
    string text2 = "ace";
    Solution solu;
    cout << solu.longestCommonSubsequence(text1, text2);
    return 0;
}