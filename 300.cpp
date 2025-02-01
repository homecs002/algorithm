#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2500 + 5];
        int len = nums.size();
        for (int i = 0 ; i <= len; i++) dp[i] = 0;
        for(int i = 0; i < len;i++){
            dp[i] = 1;
            int temp = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    // dp[i] = max(dp[j] + 1, dp[i]);
                    temp = max(temp, dp[j]);
            }
            dp[i] = temp + 1;
        }
        int ans  = 0;
        for(int i = 0 ; i < len; i++) ans = max(ans, dp[i]);

        return ans;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {10,9,2,5,3,7,101,18};
    Solution solu;
    cout << solu.lengthOfLIS(inp);
    return 0;
}