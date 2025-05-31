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

// PRINTING LCS

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){

            for(int j=1; j<=n; j++){

                if(text1[i-1] == text2[j-1]){

                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string lcs = "";
        int i = m; // i and j are lengths
        int j = n;

        while(i > 0 && j > 0){

            if(text1[i-1] == text2[j-1]){

                lcs.push_back(text1[i-1]);
                i--;
                j--;
            }

            else{

                if(dp[i-1] >= dp[j]) i--;
                else j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        cout<<lcs<<endl;

        return dp[m][n];
    }
};