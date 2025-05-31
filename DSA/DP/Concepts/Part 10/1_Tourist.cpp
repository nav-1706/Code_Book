/*
https://www.spoj.com/problems/TOURIST/

Don't consider it 2 different journey, instead consider 2 tourists, one from "top left --> bottom right" and another from "bottom right --> top left"

Consider both tourists T1 and T2 are initially at (0,0)

x+y = i+j (coordinates of two tourists), with the help of any 3 variable we can find 4th variable and the state of DP changes from 4 to 3
y = i+j-x

// LEETCODE 741 
*/

#include<iostream>
#include<vector>
#include<climits>
#include <cstring>
#define ll long long int
using namespace std;

ll n, m; // dimension of input matrix
char mat[105][105]; // input matrix
ll dp[105][105][105]; // dp state

ll f(ll i, ll j, ll x, ll y){

    if(i>n || j>n || x>n || y>n || mat[i][j] == '#' || mat[x][y] == '#'){
        return 0;
    }

    if(i==n && j==m){
        if(mat[i][j] == '*') return 1;
        else return 0;
    }

    if(dp[i][j][x] = -1) return dp[i][j][x];

    ll result = INT_MIN;

    result = max(result,f(i+1, j, x+1, y));
    result = max(result,f(i+1, j, x, y+1));
    result = max(result,f(i, j+1, x, y+1));
    result = max(result,f(i, j+1, x+1, y));

    result += (mat[i][j] == '*'); // agat T1 intresting par hai
    result += (mat[x][y] == '*'); // agar T2 intresting par hai

    // remove repitition

    if(i==x && j==y && mat[i][j] == '*' ) result--; // dono same cell par hai jo ki intresting hai

    return dp[i][j][x] = result;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        cin>>n>>m;
        memset(dp,-1, sizeof dp);
        for(int i=1; i<=n; i++){ // 1 based indexing
            for(int j=1; j<=m; j++){

                cin>>mat[i][j];
            }
        }

        cout<<f(1,1,1,1)<<endl;
    }
    return 0;
}