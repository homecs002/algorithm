#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dp[105] = {0};
    int rob(vector<int>& nums) {
        dp[1] = nums[0];
        int len = nums.size();
        for(int i = 2; i <= len; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[len];
    }
};
int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {2,7,9,3,1};
    Solution solu;
    cout << solu.rob(inp);
    return 0;
}