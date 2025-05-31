#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

// LENGTH OF LIS: BOTTOM-UP

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // state defination, dp[i] --> exactly i-th index par khatam hone wale LIS ki length kya hai;     

        int n = nums.size();
        int max_len = 1;
        vector<int>dp(n, 1);

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){

                if(nums[i] > nums[j]){

                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            if(dp[i] > max_len) max_len = dp[i];
        }

        return max_len;
    }
};