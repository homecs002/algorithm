#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
思路
用一维dp找出最长递增子序列
在这个过程中，额外开一个数组来维护对应长度的个数
*/


class Solution {
public:


    int findNumberOfLIS(vector<int>& nums) {
        int cnt[2005] = {0};
        int dp[2005] = {0};
        for(int i = 0; i < 2005; i++) dp[i] = 1;

        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] > nums[i - 1]){
                
            }
            // else dp[i] = dp[i - 1];
        }
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {2, 3, 4};
    Solution solu;
    
    return 0;
}