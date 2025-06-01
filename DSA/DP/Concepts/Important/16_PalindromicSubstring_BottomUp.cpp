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

// https://youtu.be/jCK_y0h8VVE?si=F7LHqngpYuOO1srv

/*
************************ BOTTOM-UP --> BLUE PRINT ********************

dp[i][j] --> True/False --> is s[i-th idx : j-th idx] palindrome

1 length --> dp[i][i] --> always true(only one length);
2 length --> is(s[i] == s[j]) where j = i+1

general: dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
*/

class Solution {
public:

    int countSubstrings(string s) {

        // *********** Blue-Print **************

        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        int count = 0;

        for(int L = 1; L <= n; L++){

            for(int i=0; i+L-1 < n; i++){ // as for any 'i' j will go till j < n and L = j-i+1

                int j = i+L-1;

                if(i == j){ // 1 length
                    dp[i][j] = true; 
                }
                
                else if(j == i+1){ // 2 length
                    dp[i][j] = (s[i] == s[j]);
                }

                else{
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }

                if(dp[i][j] == true) count++;
            }
        }

        return count;
    }
};