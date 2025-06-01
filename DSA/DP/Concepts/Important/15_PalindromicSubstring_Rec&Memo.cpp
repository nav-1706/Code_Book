// TC = O(n^2)

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

    bool isPalin(string &s, int i, int j){ // checks if string is palindrome from i-th incex to j-th index

        if(i > j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){

            return dp[i][j] = isPalin(s, i+1, j-1);
        }

        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        
        dp.resize(s.length()+1, vector<int>(s.length()+1, -1));

        int n = s.length();
        int count = 0;

        for(int i=0; i<n; i++){

            for(int j=i; j<n; j++){

                if(isPalin(s, i, j)){

                    count++;
                }
            }
        }

        return count;
    }
};