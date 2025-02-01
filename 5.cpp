#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dp[1005][1005];

    string longestPalindrome(string s) {
        int len = s.size();

        for (int i = 0 ; i < 1005; i ++) for(int j = 0; j < 1005; j ++) {  // 预处理长度为1的串
            if(i == j) dp[i][j] = true;
            else dp[i][j] = false;
        }
        for (int i = 0 ; i < len - 1; i++){  // 预处理长度为2的串
            if(s[i] == s[i + 1]) dp[i][i+1] = true;
        }

        // 我们这里要注意枚举顺序，我们要先找出所有 长度较小 的回文串，才能继续找长度更长的回文串
        // 因此我们外层循环是回文串的长度，内层循环是回文串的起始位置。
        for(int k = 3; k <= len ; k++){  // 找出所有长度为k的回文串
            for(int i = 0 ; i < len - k + 1;i ++){
                int j = i + k - 1;
                if(dp[i + 1][j - 1] && (s[i] == s[j]))
                    dp[i][j] = true;
            }
        }

        int maxn = 0;
        int l, r;
        l = r = 0;
        // 输出最长的回文串
        for(int i = 0 ; i < len ; i++){
            for(int j = i ; j < len ; j++){
                if(dp[i][j] == true){
                    if(j - i + 1 > maxn){
                        maxn = j - i + 1;
                        l = i , r = j;
                    }
                }
            }
        }
        string ans = "";
        for(int i = l; i <= r; i++){
            ans += s[i];
        }
        // cout << maxn;
        return ans;

    }
};

int main(){
    // 定义好函数中的测试数据
    // vector<int> inp = {2, 3, 4};
    string s = "aaaaa";
    Solution solu;
    cout << solu.longestPalindrome(s);
    return 0;
}