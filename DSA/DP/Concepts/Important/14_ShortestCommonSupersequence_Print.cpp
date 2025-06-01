// Print: Shortest Common Supersequernce;
// LEETCODE 1092

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
    string shortestCommonSupersequence(string s1, string s2) {
        
        // state defination: dp[i][j] --> shortest common supersequence between s1 of length i and s2 of length j, final Ans: dp[m][n]
        
        int m = s1.length(); // horizontal in table
        int n = s2.length(); // verticle in table

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;
        
        for(int i=1; i<=m; i++){
            
            for(int j=1; j<=n; j++){
                
                if(s1[i-1] == s2[j-1]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1];
                } 
                
                else{
                    
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // return dp[m][n]; 

        string scs = "";

        int i = m;
        int j = n;

        while(i > 0 && j > 0){ // dont confuse i and j with cordinates, it is length of s1 and s2, not geometrical coordinates of the dp table

            if(s1[i-1] == s2[j-1]){

                scs.push_back(s1[i-1]);
                i--;
                j--;
            }

            else{

                if(dp[i][j-1] < dp[i-1][j]){ // moving up

                    scs.push_back(s2[j-1]);
                    j--;
                }

                else{ // moving left

                    scs.push_back(s1[i-1]);
                    i--;
                }
            }
        }

        while(i > 0){

            scs.push_back(s1[i-1]);
            i--;
        }

        while(j > 0){

            scs.push_back(s2[j-1]);
            j--;
        }

        reverse(scs.begin(), scs.end());

        return scs;
    }
};