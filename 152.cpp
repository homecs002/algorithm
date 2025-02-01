#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dp(2e4 + 5, 1);  // dp[i]:考虑前i个数，且以a[i]结尾的子串的最大乘积
        int len = nums.size();
        for(int i = 1 ; i <= len; i++) dp[i] = max(dp[i - 1] * nums[i - 1], nums[i - 1]);
        int ans = -INT_MAX;
        for(int i = 1 ; i <=len; i++ ) ans = max(ans, dp[i]);
        return ans;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {-2,0,-1};
    Solution solu;
    cout << solu.maxProduct(inp);
    return 0;
}