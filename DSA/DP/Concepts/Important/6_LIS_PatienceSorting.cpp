// Lower bound --> find element just greater or equal to nums[i]
// https://youtu.be/dWmh3O8uX8A?si=h9US7hLinv2LyPQ0
// TC = O(n*log(n))

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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>lis;

        for(int i=0; i<n; i++){

            auto it = lower_bound(lis.begin(), lis.end(), nums[i]); // find element just greater or equal to nums[i]

            if(it == lis.end()){ // koi bada nahi mila
 
                lis.push_back(nums[i]);
            }

            else{

                *it = nums[i]; // bade ko chote se replace
            }
        }

        return lis.size();
    }
};