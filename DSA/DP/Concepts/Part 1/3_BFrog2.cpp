//https://atcoder.jp/contests/dp/tasks/dp_b

#include<iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int>h; // heights
vector<int>dp;
int k;

int f(int i){

    if(i>=h.size()){
        return INT_MAX;
    }

    if(i == h.size()-1){
        //last stone
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int ans = INT_MAX;

    for(int j=1; j<=k; j++){
        if(i+j >= h.size()) break;

        ans = min(ans,abs(h[i]-h[i+j])+f(i+j)); // recursion call
    }

    dp[i] =  ans;

    return ans;
}

int main(){
    int n;
    cin>>n>>k;
    h.resize(n);
    dp.resize(n,-1); // dp[i] == -1, ith state not yet completed

    for(int i=0; i<n; i++){
        cin>>h[i];
    } 

    cout<<f(0)<<endl;
}