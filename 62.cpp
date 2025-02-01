#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[105];
        for(int i = 0 ; i < 105; i++) dp[i] = 1;
        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};


int main(){
    // 定义好函数中的测试数据
    // vector<int> inp = {2, 3, 4};
    int m = 3, n = 7;
    Solution solu;
    cout << solu.uniquePaths(m, n);
    return 0;
}