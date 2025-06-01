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
        
        if(i == s1.length() && j == s2.length()) return 0;
        else if(i == s1.length() && j != s2.length()) return s2.length()-j;
        else if(i != s1.length() && j == s2.length()) return s1.length()-i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(i+1, s1, j+1, s2);
        return dp[i][j] = 1 + min(solve(i+1, s1, j, s2), solve(i, s1, j+1, s2));
    }
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        
        dp.resize(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(0, s1, 0, s2);
    }
};

