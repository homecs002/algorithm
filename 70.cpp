#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dp[50] = {0};
    int climbStairs(int n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n ; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    // 定义好函数中的测试数据
    // vector<int> inp = {2, 3, 4};
    int n = 3;
    Solution solu;
    cout << solu.climbStairs(n);
    return 0;
}