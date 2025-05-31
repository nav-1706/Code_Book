/*
Given a number 'n', you can perform any of the following opeartions on it some number of times,
    - reduce n to (n-1)
    - if n is divisble by 2, make it n/2
    - if n is divisble by 3, make it n/3

Find out the minimum steps to reduce n to 1
*/ 

#include<iostream>
#include<vector>
using namespace std;

int solve(int i){

    if(i == 1) return 0;

    if(i%2 == 0 && i%3 == 0){
        return 1 + min(solve(i-1), min(solve(i/2), solve(i/3)));
    }

    if(i%2 == 0 && i%3 != 0){

        return 1 + min(solve(i-1), solve(i/2));
    }

    if(i%2 != 0 && i%3 == 0){

        return 1 + min(solve(i-1), solve(i/3));
    }

    if(i%2 != 0 && i%3 != 0){

        return 1 + solve(i-1);
    }
}

int main(){

    int n = 5;
    cout<<solve(n);
}