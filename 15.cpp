#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < size; i ++){
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int k = size - 1;
            for(int j = i + 1; j < size ; j++){
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
                while(nums[k] + nums[i] + nums[j] >= 0){
                    if( k <= j) break;
                    if(nums[k] + nums[i] + nums[j] == 0) {ans.push_back({nums[i], nums[j], nums[k]}); break;}
                    k --;
                }
            }
        }
        return ans;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {0,0,0,0};
    Solution solu;
    vector<vector<int>> ans  = solu.threeSum(inp);
    // for(int i = 0 ; i < ans.size(); i++) {for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j]; cout << "\n";}
    return 0;
}