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

// LENGTH OF LIS: RECURSION AND MEMO 

class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, int prev, vector<int>&nums, int n){

        if(i >= n) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int not_taken = solve(i+1, prev, nums, n);
        int taken = INT_MIN;

        if(prev == -1 || nums[i] > nums[prev]){

            taken = 1 + solve(i+1, i, nums, n);
        }

        return dp[i][prev+1] = max(taken, not_taken);
    }
    
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        dp.resize(n+2, vector<int>(n+2, -1));

        return solve(0, -1, nums, n);
    }
};  