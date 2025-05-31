// LEETCODE 1048

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

    static bool comp(string &s1, string &s2){

        return s1.size() < s2.size();
    }

    bool isPred(string &pred, string &succ){

        int count = 0;
        if(succ.size()-pred.size() != 1) return false;

        int i = 0; // traverse pred
        int j = 0; // traverse succ

        while(i < pred.size() && j < succ.size()){

            if(count > 1) return false;

            if(pred[i] == succ[j]){
                i++;
                j++;
            }

            else{

                j++;
                count++;
            }
        } 

        if(count > 1) return false;
        
        return true;
    }

    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), comp);

        int n = words.size();
        vector<int>dp(n, 1);
        int max_len = 1;

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){

                if(isPred(words[j], words[i])){

                    dp[i] = max(dp[i], dp[j]+1);
                }
            }

            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};