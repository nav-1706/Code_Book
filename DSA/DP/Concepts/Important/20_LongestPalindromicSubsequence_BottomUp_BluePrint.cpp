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

    // METHOD: 3 --> Blue Print *********** BOTTOM UP**********

    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n));

        // dp[i][j] --> LPS from index [i : j]

        for(int i=0; i<n; i++) dp[i][i] = 1;

        for(int L = 2; L<=n; L++){

            for(int i=0; i < n-L+1; i++){

                int j = i+L-1;

                if(s[i] == s[j]){

                    dp[i][j] = 2 + dp[i+1][j-1];
                }

                else {

                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};