// LEETCODE 198

/*
Mostly in recurrsion question containing array/string we pass array/string,index and n(length)
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int>dp;

// ******************************** METHOD: 1 ***************************************

class Solution {
public:

    vector<int>dp;

    int robbing(int i, vector<int>&nums){

        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i]; // dp[i] --> maxium amount that can be robbed from ith index house till last (from i-th index) 

        return dp[i] = max( (nums[i] + robbing(i+2, nums)), robbing(i+1, nums));
    }

    int rob(vector<int>& nums) {
        
        dp.resize(nums.size()+1, -1);
        return robbing(0, nums);
    }
};

// ***************************** METHOD: 2 ***************************************

/*

class Solution {
public:

    vector<int>dp;

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp.resize(n, -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){

            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }

        return dp[n-1];
    }
};

*/

// ************************ METHOD: 3 ***************************************

int bottomUp(vector<int>&nums){

    int n = nums.size();
    if(n==1) return nums[0];

    dp.clear();
    dp.resize(n,-1);

    // base case
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-2], nums[n-1]);

    for(int i = n-3; i>=0; i--){

        dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
    }

    return dp[0];
}
