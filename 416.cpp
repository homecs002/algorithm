#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dp[10000 + 5] = {0};
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum % 2 != 0) return false;
        sum /= 2;
        dp[0]=1;
        int len = nums.size();
        for(int i = 1; i < len; i++){
            for(int j = sum; j >=1;j --){
                if(j < nums[i]) continue;
                dp[j] = dp[j] | dp[j - nums[i]];  // dp[j] ：是否能使背包容量恰好为j
            }
        }
        if(!dp[sum]) return false;
        else return true;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {1,2,5};
    Solution solu;
    cout << solu.canPartition(inp);
    return 0;
}