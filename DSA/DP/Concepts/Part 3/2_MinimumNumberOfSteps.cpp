/*
Given a number 'n', you can perform any of the following opeartions on it some number of times,
    - reduce n to (n-1)
    - if n is divisble by 2, make it n/2
    - if n is divisble by 3, make it n/3

Find out the minimum steps to reduce n to 1
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<int>dp;

int miniRec(int n){

    if(n==1) return 0;
    if(n==2 || n==3) return 1;


    if(dp[n]!=-1) return dp[n];

    if(n%3 == 0 && n%2 == 0){

        return dp[n] = 1+ min( miniRec(n/3), min( miniRec(n/2), miniRec(n-1) ) );
    }

    else if(n%3 == 0 && n%2 != 0){

        return dp[n] = 1+ min(miniRec(n/3), miniRec(n-1));
    }

    else if(n%2 == 0 && n%3 != 0){

        return dp[n] = 1+ min(miniRec(n/2), miniRec(n-1));
    }
    
    else if(n%2 != 0 && n%3 != 0){
        
        return dp[n] = 1+ miniRec(n-1);
    }
}

int main(){

    int n = 7;
    dp.clear();
    dp.resize(n+5,-1);

    cout<<"By recursion"<<endl;
    cout<<miniRec(n)<<endl;
    
    
    return 0;
}