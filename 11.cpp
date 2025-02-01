#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int i = 0, j = size - 1;
        int max_area = 0;
        while(j >= i){
            int area = (j - i) * min(height[i], height[j]);
            max_area = max(max_area, area);
            if(height[i] < height[j]){
                i ++ ;
            }else j --;
        }
        return max_area;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {1,8,6,2,5,4,8,3,7};
    Solution solu;
    cout << solu.maxArea(inp);
    return 0;
}