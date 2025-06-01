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

    // Approach 1: Find longest common subsequence in s and revrse of s

    // Approach 2: Recursion and Memoization

    vector<vector<int>>dp;

    int helper(int i, int j, string &s){

        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = 2+helper(i+1, j-1, s);

        return dp[i][j] = max(helper(i+1, j, s), helper(i, j-1, s));
    }

    int longestPalindromeSubseq(string s) {

        int n = s.length();
        dp.resize(n+1, vector<int>(n+1, -1));

        return helper(0, n-1, s);
    }
};