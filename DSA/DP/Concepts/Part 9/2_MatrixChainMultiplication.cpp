/*
Matrix Chain Multiplication
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>>dp;

int f(int i, int j, vector<int>&arr){

    if(i==j || i+1 == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i+1; k<j; k++){

        ans = min(ans, f(i,k,arr) + f(k,j,arr)+arr[i]*arr[j]* arr[k]);
    }

    return dp[i][j] = ans;
}

int main(){

    cout<<"Enter the number of dimmensions: n"<<endl;
    int n;
    cin>>n;

    dp.resize(1005,vector<int>(1005,-1));

    vector<int>v(n);

    cout<<"Enter dimmensions, seperated by <space> : "<<endl;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<f(0,n-1,v)<<endl;
    return 0;
}