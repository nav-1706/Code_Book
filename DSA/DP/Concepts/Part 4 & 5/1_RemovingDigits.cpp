/*
https://cses.fi/problemsetassembly/task/1637

You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.

*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int>dp;

int minimumStepsGreedy(int n){

    if(n==0) return 0;
    if(n>0 && n<=9) return 1;

    int maxi = INT_MIN;
    int num = n;

    while(num>0){
        int digit = num%10;
        if(digit > maxi) maxi = digit;
        num = num/10;
    }

    return 1 + minimumStepsGreedy(n-maxi);
}

int minimumStepsDp(int n){

    if(n==0) return 0;
    if(n>0 && n<=9) return 1;

    if(dp[n]!=-1) return dp[n];

    vector<int>digits;
    int num = n;

    while(num>0){
        int digit = num%10;
        if(digit!=0) digits.push_back(digit);
        num = num/10;
    }

    int minimunRes = INT_MAX;
    for(int i=0; i<digits.size(); i++){

        minimunRes = 1 + min(minimunRes, minimumStepsDp(n-digits[i]));
    }

    return dp[n] = minimunRes;

}

int main(){

    dp.clear();
    int n = 850;
    dp.resize(n+5, -1);
    cout<<minimumStepsGreedy(n)<<endl;
    cout<<minimumStepsDp(n)<<endl;

    return 0;
}