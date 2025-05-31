/*
https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<long long int>>dp;

long long int maxProfit(int n,int w, vector<int>&weights, vector<long long int>&values,int i){

    if(i>=n) return 0;
    if(w<=0) return 0;

    if(dp[w][i] != -1) return dp[w][i];

    long long int taken  = 0;

    long long int notTaken = maxProfit(n,w, weights, values, i+1);
    
    if(w >= weights[i]){
        taken = values[i] + maxProfit(n,w-weights[i], weights, values, i+1);
    }

    return dp[w][i] = max(taken,notTaken);
}

int main(){

    int n = 5;
    int w = 5;

    vector<int>weights = {1,1,1,1,1};
    vector<long long int>values = {1000000000, 1000000000,1000000000,1000000000,1000000000};

    dp.clear();
    dp.resize(w+5, vector<long long int>(n+5, -1));

    long long int result = maxProfit(n,w,weights,values,0);

    cout<<result;
    return 0;
}