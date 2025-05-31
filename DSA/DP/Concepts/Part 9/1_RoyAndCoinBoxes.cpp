/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
*/


#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n; // number of boxes
    cin>>n;
    
    int m; // number of queries;
    cin>>m;

    vector<int>f(n+1, 0); // number of coins in each box f[i] --> how many coins does the i-th box contains

    vector<int>l(n+1, 0);
    vector<int>r(n+1, 0);

    for(int i=0; i<m; i++){

        int L, R;
        cin >> L >> R;
        l[L]++;
        r[R]++;

    }

    f[1] = l[1];
    for(int i = 2; i<n+1; i++){

        f[i] = l[i]-r[i-1]+f[i-1];
    }

    vector<int>c(10000005, 0); // c[i] --> how many boxes have 'i'  number of coins
    for(int i=0; i< n+1; i++){

        int coins = f[i];
        c[coins]++;
    }

    // how many boxes have at-least 'i' number of coins --> suffix sum of 'c'

    for(int i = c.size()-2; i>=0; i--){

        c[i] = c[i] + c[i+1];
    }

    int q; // number of question queries
    cin>>q;

    while(q--){

        int num;
        cin>>num;
        cout<<c[num]<<endl;
    }
}