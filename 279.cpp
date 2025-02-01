#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for(int i = 0; i <= n;i++) dp[i] = 0;  // 初始化
        for(int i = 1; i <= n; i++){
            int temp = INT_MAX;
            int upBound = sqrt(i);
            for(int j = 1; j <= upBound; j++) temp = min(temp, dp[i - j * j]);
            dp[i] = temp + 1;
        }
        return dp[n];
    }
};

int main(){
    // 定义好函数中的测试数据
    // vector<int> inp = {2, 3, 4};
    int n = 13;
    Solution solu;
    cout << solu.numSquares(n);
    return 0;
}