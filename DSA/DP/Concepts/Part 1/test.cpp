#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int>h = {10, 30, 40, 50, 20};
int n = h.size();
int K = 3;
vector<int>dp;

int mini(int i){

    if(i == n-1) return 0;
    if(i >= n) return 100000; // bahut badi value, but not INT_MAX as we are adding it with abs(h[i]-h[i+k])

    if(dp[i] != -1) return dp[i];

    int minimumHeight = INT_MAX;
    for(int k=1; k<=K; k++){

        if(i+k < n) minimumHeight = min(minimumHeight, abs(h[i]-h[i+k]) + mini(i+k));
    }

    return dp[i] = minimumHeight;
}

int main(){

    dp.clear();
    dp.resize(n, -1);
    cout<<mini(0);
    return 0;
}