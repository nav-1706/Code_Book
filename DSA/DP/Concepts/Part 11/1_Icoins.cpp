/*
https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

double dp[3005][3005];

double proba(vector<double>&p, int i, int x){

    if(x==0) return 1;
    if(i==-1) return 0;

    if(dp[i][x] > -0.9) return dp[i][x]; // kykoi int and double ke equality check me issue aaega

    return dp[i][x] = proba(p, i-1, x-1)*p[i] + proba(p,i-1,x)*(1-p[i]);
}

int main(){
    
    int n = 3;
    vector<double>prob = {0.30, 0.60, 0.80};

    if(prob.size() == 1) cout<<prob[0]<<endl;

    memset(dp, -1 ,sizeof dp);

    cout<<proba(prob, n-1, (n+1)/2);
}