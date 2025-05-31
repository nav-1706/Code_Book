// LONGEST COMMON SUBSEQUENCE

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

    vector<vector<int>>dp;

    int solve(int i, string &s1, int j, string &s2){

        if(i >= s1.length() || j >= s2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return 1 + solve(i+1, s1, j+1, s2);
        return dp[i][j] = max(solve(i+1, s1, j, s2), solve(i, s1, j+1, s2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));
        return solve(0, text1, 0, text2);
    }
};