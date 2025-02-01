#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        int m = coins.size();
        vector<int>dp(n + 3);
        for(int i = 0 ; i < n+3; i++) dp[i] = -1;
        dp[0] = 0;

        for(int i = 1 ; i <= n;i++){
            int temp = INT_MAX;
            bool flag = false;  // 记录temp是否被更新
            for(auto j : coins){
                if(j <= i && dp[i - j] != -1){
                    flag = true;
                    temp = min(temp, dp[i - j]);
                }
            }
            if(flag){
                dp[i] = temp + 1;
            }
        }

        return dp[amount];
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> coins = {2};
    int amount = 3;
    Solution solu;
    cout << solu.coinChange(coins, amount);
    return 0;
}