#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int len = s.size();
        int r = -1, ans = 0;
        for(int l = 0; l < len; l++){  // 枚举左指针
            if(l != 0){
                hash.erase(s[l - 1]);
            }
            while(r + 1 < len && !hash.count(s[r + 1])){
                hash.insert(s[r + 1]);
                ++r;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {2, 3, 4};
    Solution solu;
    
    return 0;
}