/*

https://cses.fi/problemsetassembly/task/1633
// LEETCODE 1155

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input

The only input line has an integer n.
Output

Print the number of ways modulo 10^9+7.

*/

#include<iostream>
#include<vector>
using namespace std;

vector<int>dp;

int countWays(int n){

    if(n==0) return 1; // this is the catch
    // if(n==1) return 1;
    // if(n==2) return 2;

    if(dp[n]!=-1) return dp[n];

    int ways = 0;
    for(int i=1; i<=min(n,6); i++){
        ways = (ways + countWays(n-i));
    }

    return dp[n] = ways;
}

int main(){

    dp.clear();
    int n = 9;
    dp.resize(n+1,-1);
    cout<<countWays(n)<<endl;
    return 0;
}