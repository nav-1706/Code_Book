// LEETCODE 368

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

// The largest subset must be sorted --> if b is divisible by a and c is divisible by b, then c is by default divisible by a (if a < b < c)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int>prev(n, -1);
        int max_len = 1;
        vector<int>dp(n, 1);
        int last_lis_index = 0;

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){

                if(nums[i] >= nums[j] && nums[i]%nums[j] == 0){

                    if(dp[j]+1 > dp[i]){

                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                }

                if(dp[i] > max_len){

                    max_len = dp[i];
                    last_lis_index = i;
                }
            }
        }

        vector<int>ans;
        for(int i = last_lis_index; i != -1; i = prev[i]){

            ans.push_back(nums[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};