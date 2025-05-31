#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n = 3;
vector<vector<int>>days = { {10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

vector<vector<int>>dp;

int solve(int ith_day, int prev_activity){

    if(ith_day == n) return 0;

    if((prev_activity != -1) && dp[ith_day][prev_activity] != -1) return dp[ith_day][prev_activity];

    int max_enjoy = INT_MIN;
    for(int i=0; i<3; i++){

        if(i == prev_activity) continue;
        max_enjoy = max(max_enjoy, days[ith_day][i]+solve(ith_day+1, i));   
    }

    if(prev_activity != -1) return dp[ith_day][prev_activity] = max_enjoy;
    return max_enjoy;
    
}

int main(){

    dp.resize(n+1, vector<int>(3, -1));
    cout<<solve(0, -1);
}