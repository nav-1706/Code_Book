/*
f(n) --> nth fibonnachi, 0 is 0th fibo, 1 is 1st fibo, 1 is 2nd fibo, 2 is 3rd fibo, and so on
*/

#include<iostream>
using namespace std;

int fibo(int n){

    if(n == 1 || n == 0 ) return n;
    return (fibo(n-1) + fibo(n-2));
}

int main(){

    cout<<endl;
    cout<<fibo(5)<<endl;
}