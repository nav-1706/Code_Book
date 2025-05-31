/*

https://cses.fi/problemset/task/1634

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,....c_n: the value of each coin.

Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

*/

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>dp;

int minimumCoin(int x, vector<int> &coins){

    if(x==0) return 0;

    if(dp[x] != -1) return dp[x];

    // from line 31 to 41 is most important part of the code, and is mostly used in maximizing and minimizing problem

    int minCoins = INT_MAX;
    for(int i=0; i<coins.size(); i++){

       if(x >= coins[i]){
        minCoins = min( minCoins, 1 + minimumCoin(x-coins[i], coins) );
       }
    }

    if(minCoins == INT_MAX){ // for loop me gaya hi nahi (ex: x = 2, coins = {4,6,9})

        return dp[x] = 1e9;
    }
    return dp[x] = minCoins;
    
}

int solve(int i, vector<int>coins){

    if(i == 0) return 0;
    if( i < 0) return INT_MAX;

    if(dp[i] != -1) return dp[i];
    int mini = INT_MAX;
    for(int k = 0; k<coins.size(); k++){

        mini = min(mini, solve(i-coins[k], coins));
    }

    if(mini != INT_MAX) return dp[i] = 1 + mini;
    else return dp[i] = INT_MAX;
}

int main(){

    dp.clear();

    int x = 1000000;
    vector<int>coins = {2390,24239, 49476, 189008, 194217, 270814, 448939, 503669, 699752, 715805};

    dp.resize(1000006,-1);

    int ans = minimumCoin(x,coins);
    if(ans >= 1e9) cout<<-1<<endl;
    else cout<<ans<<endl;

    dp.clear();
    dp.resize(1000006,-1);

    int ans2 = solve(x,coins);
    if(ans2 == INT_MAX) cout<<-1<<endl;
    else cout<<ans2<<endl;

    return 0;
}