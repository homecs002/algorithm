#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[205] = {0};
        int m = grid.size();  // 行
        int n = grid[0].size();  // 列
        
        dp[0] = grid[0][0];   // 第0行第0列
        // for(int j = 1; j < n; j++) dp[j] = dp[j-1] + grid[0][j];  // 对第0行进行转移
        for(int i = 0; i < m; i++){
            dp[0]+=grid[i][0];
            for(int j = 1; j < n;j++){
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];   
    }
};

int main(){
    // 定义好函数中的测试数据
    // vector<int> inp = {2, 3, 4};
    vector<vector<int>> inp = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution solu;
    cout << solu.minPathSum(inp);
    return 0;
}