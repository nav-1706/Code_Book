// https://www.geeksforgeeks.org/problems/shortest-uncommon-subsequence5746/1 

/*

class Solution {
  public:
  
    int find(char a, string str, int startIdx){
        
        for(int i=startIdx; i<str.length(); i++){
            
            if(str[i] == a) return i;
        }
        
        return -1;
    }
  
    int fun(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        
        if(i==s.length()) return INT_MAX;
        if(j==t.length()) return 1;
        
        if (dp[i][j] != -1) return dp[i][j]; 
        
        
        int k = find(s[i], t, j); 
        if (k == -1) return 1;  
        
        int notTake = fun(s, t, i + 1, j, dp); // from str 's'
        int take = 1 + fun(s, t, i + 1, j +k + 1, dp); // from str 's'
        
        dp[i][j] = min(notTake, take);
        return dp[i][j];

    }
    
    int shortestUnSub(string S, string T) {
        
        int m = S.length();
        int n = T.length();
        vector<vector<int>> dp(m+5, vector<int>(n+5, -1));
        
        int result = fun(S,T,0,0,dp);
        return (result == INT_MAX) ? -1 : result;
        
    }
};

*/