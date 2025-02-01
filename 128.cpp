#include <iostream>
#include <bits/stdc++.h>
// #include <unordered_map>
// #include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for (auto num : nums)
            uset.insert(num);
        int max_len = 0;

        for(auto num : uset){
            // 对于num，先查看其是否有前缀，有的话，以他为起点的数组长度一定
            // 小于以 num - 1 为起点的数组长度。因此直接跳过
            if (uset.count(num - 1)) continue;

            // 找不到
            int cur = num;
            int cur_len = 1;
            while(uset.count(cur + 1)){
                cur += 1;
                cur_len += 1;
            }
            max_len = max(cur_len, max_len);
        }
        return max_len;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {100,4,200,1,3,2};
    Solution solu;
    int ans = solu.longestConsecutive(inp);
    return 0;
}