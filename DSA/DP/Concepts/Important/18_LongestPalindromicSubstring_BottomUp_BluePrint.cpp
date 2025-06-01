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

/*
dp[i][j] --> True/False --> is s[i-th idx : j-th idx] palindrome

1 length --> dp[i][i] --> always true(only one length);
2 length --> is(s[i] == s[j]) where j = i+1

general: dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
*/

class Solution {
public:

    vector<vector<int>>dp;

    string longestPalindrome(string s) {
        
        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int startIdx  = 0; 

        for(int L = 1; L <= n; L++){

            for(int i=0; i+L-1 < n; i++){

                int j = i+L-1;

                if( L == 1){
                    dp[i][j] = true;
                }

                else if(L == 2){

                    dp[i][j] = (s[i] == s[j]);
                }

                else{

                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }

                if(dp[i][j] && L > maxLen){

                    maxLen = L;
                    startIdx = i;
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};  