/*
1. DP unhi par lagti hai jin par "repetition of sub-problems hoti hai" mostly brute force solution me

2. If we have optimal answer of smaller problem and using this we can find optimal answer of smaller problem --> Optimal Sub-structure 

3. Jaruri nahi ki har recurrssion problem me DP lagegi

This is Top-Down solution, 1 big problem divided in smaller problems

Bottom-Up Solution --> We have to figure out ordder of computation --> we have to think, kis proble ko pahle solve kare taaki uski parent problem solve kar paaye
*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> dp;

int fibo(int n){
    
    if(n==0 || n==1) return n;

    // dp check, to identify if problem was already solved or not
    if(dp[n] != -1) return dp[n];

    return dp[n] = (fibo(n-1) + fibo(n-2));

}

int main(){
    
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    dp.clear(); // to clear the garbage value
    dp.resize(n+1, -1); // size set kiya (n+1) kyoki n+1 unknowns hai,   i.e if n = 5 ,{ fibo(5),fibo(4),fibo(3),fibo(2),fibo(1),fibo(0) }

    cout<<fibo(n)<<endl;

    /*
    It is :"bottom up approach"

    if we do --
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }


    */
}