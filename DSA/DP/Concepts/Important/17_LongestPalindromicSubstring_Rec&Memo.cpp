// LEETCODE 005

// ********** METHOD 1 (RECURSION + MEMO) *****************

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

    bool isPalin(int i, int j, string &s){

        if(i > j) return true;

        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (s[i] == s[j] && isPalin(i+1, j-1, s));
    }

    string longestPalindrome(string s) {

        dp.resize(s.length()+1, vector<int>(s.length(), -1));

        int maxLen = 0;
        int startIdx = -1;

        for(int i=0; i<s.length(); i++){

            for(int j=i; j<s.length(); j++){

                if(isPalin(i, j, s)){
                    int len = j-i+1;

                    if(len > maxLen){
                        startIdx = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
}; 