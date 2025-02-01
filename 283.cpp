#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int i = 0;
        int len = nums.size();
        while(i < len && j < len){
            while(i < len && nums[i] != 0) i++;
            if(i >= len) break;
            j = i;
            while(j < len && nums[j] == 0) j++;
            if(j >= len) break;
            swap(nums[i], nums[j]);
        }
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {0, 0, 1};
    Solution solu;
    solu.moveZeroes(inp);
    return 0;
}