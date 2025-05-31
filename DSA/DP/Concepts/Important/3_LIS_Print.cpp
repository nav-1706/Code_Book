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

// PRINTING LIS: BOTTOM UP

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int max_len = 1;
        int lis_last_idx = 0;
        vector<int>prev_idx(n, -1);

        vector<int>dp(n, 1);

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){

                if(nums[i] > nums[j]){

                    if(dp[j]+1 > dp[i]){
                        
                        dp[i] = dp[j]+1;
                        prev_idx[i] = j;
                    }
                }
            }

            if(dp[i] > max_len){

                max_len = dp[i];
                lis_last_idx = i;
            }
        }

        vector<int>lis;
    
        for(int i = lis_last_idx; i != -1; i = prev_idx[i]){
            lis.push_back(nums[i]);
        }

        reverse(lis.begin(), lis.end());

        for(auto ele: lis) cout<<ele<<" ";
        return max_len;
    }

};