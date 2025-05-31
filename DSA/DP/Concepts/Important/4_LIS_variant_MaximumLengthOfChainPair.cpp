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

    static bool comp(vector<int>&p1, vector<int>&p2){

        return p2[1] > p1[1]; // accending on the basis of 2nd element 
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), comp);

        int n = pairs.size();
        vector<int>dp(n, 1);
        int max_len = 1;

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){

                if(pairs[i][0] > pairs[j][1]){

                    dp[i] = max(dp[i], dp[j]+1);
                }
            }

            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};