/*
https://www.spoj.com/problems/ACODE/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

vector<int>dp;

vector<int> digitArr(int n){
    vector<int> arr;
    while(n>0){
        arr.push_back(n%10);
        n /= 10;
    }

    reverse(arr.begin(), arr.end());

    return arr;
}

int getNum(int a, int b){

    return (a*10 + b);
}

ll decodes(vector<int>&arr, int n, int i){

    if(i == n-1) return 1;
    if(i == n) return 0;
    if(i==n-2){

        ll num = getNum(arr[n-2],arr[n-1]);

        if(num <= 26){
            return 2;
        }
        else{
            return 1;       
        }
    }

    if(dp[i] != -1) return dp[i];

    ll ans = 0; // number of ways

    /*
    Is question me hum do(two) ways consider karenge, 1st is single digit, in that case 'i' will increase to 'i+1' and will return the ways of decode(arr,n,i+1), because hum sirf ek digit consider kar rahe hai, for example 12345, lets suppose ways of 2345 is 'x' then ways of 12345 will also be 'x', jo bhi decode kiya hai usme sabke aage 'A' lag jaaega, par ways wahi rahenge.

    Agar hum 2 digit consider karte hai to bhi ways 'x' hi rahega supppose 12345 me 235 ke 'x' ways hai then 12345 ke bhi 'x' hi ways honge, jo bhi sequence decode kiya hai usme aage 'L' lag jaaega
    */

    if(arr[i] > 0) ans = ans+decodes(arr,n,i+1);

    if(arr[i] > 0 && getNum(arr[i],arr[i+1]) <= 26){
        ans = ans+decodes(arr,n,i+2);
    }

    return dp[i] = ans;
}

int main(){

    dp.clear();
    dp.resize(5005,-1);
    
    ll num = 1111111111;

    vector<int>arr = digitArr(num);
    int n = arr.size();

    cout<<decodes(arr,n,0)<<endl;
    return 0;
}