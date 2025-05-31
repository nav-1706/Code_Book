/*
https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> maxInVector(vector<int>&arr){

    int maxi = INT_MIN;
    int maxiIdx = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            maxiIdx = i;
        }
    }

    return {maxi,maxiIdx};
}


int happyPoint(int n, vector<vector<int>>&days, int i){ // i = 0

    if(i==n-1) return maxInVector(days[n-1])[0];

    vector<int>presentDayMax = maxInVector(days[i]);
    int maxHappyPoint = presentDayMax[0];
    int maxHappyPointIdx = presentDayMax[1];
    days[i+1][maxHappyPointIdx] = INT_MIN;

    return (maxHappyPoint + happyPoint(n,days,i+1));
}

int main(){

    vector<vector<int>>days = {
    {6, 7, 8},
    {8, 8, 3},
    {2, 5, 2},
    {7, 8, 6},
    {4, 6, 8},
    {2, 3, 4},
    {7, 5, 1}
};
    int n = days.size();
    cout<<happyPoint(n,days,0);
    return 0;
}