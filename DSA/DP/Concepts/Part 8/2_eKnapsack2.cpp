/*
https://atcoder.jp/contests/dp/tasks/dp_e

the main deifference between this ans previous problem is that the constraints of 'w' is increased to 10^9, which mean we can't create 'dp' vector with 'w' as its dimenssion

*/

// Approach: Agar hamare paas ek target value hai, to hum kam se kam kitne weights pick kar sakte hai, target value acheive karne ke liye

/*
Target value ki maximum value (n*10^3) ho sakti hai, so hum 0 se lekar maximum target value ka ek loop chalaenge hai har target value ke liye minimum weigth find karenge, then vo wali target value pick kar lenge jisme weigth, knapsack capacity se kam hai, then use pick kari hui target value me se maximum target value return kar denge
*/

#include<iostream>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;

vector<vector<ll>>dp(105,vector<ll>(100005,-1));

ll f(vector<ll>&weigth,vector<ll>&val, int idx, int tv){

    if(idx == weigth.size()) return INT_MAX;
    if(tv == 0) return 0;

    if(dp[idx][tv] != -1) return dp[idx][tv];

    ll ans = INT_MAX;

    ans = min(ans,f(weigth,val,idx+1,tv)); // not pick

    if(val[idx] <= tv){
        ans = min( ans,weigth[idx] + f(weigth,val,idx+1,tv-val[idx]) ); // pick
    }

    return dp[idx][tv] = ans;
}

int main(){
 
    vector<ll>weigth = {3,4,5};
    vector<ll>values = {30,50,60};

    int n = 3;
    int w = 8; 

    int result = -1;
    for(int i=0; i<=n*1000; i++){
        if(f(weigth,values,0,i) <= w){
            result = i; // maximum target value(tv) for which acheived weight is <= w(capacity)
        }
    }

    cout<<result<<endl;
    return 0;
}