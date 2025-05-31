/*
https://www.spoj.com/problems/GNYR09F/a
*/

#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
// #include<climits> 
#include<string.h> // ye memeset ki header file hai
using namespace std;

int dp[105][105][2];

int AdjBC(string str){

    vector<int>strVec;
    int ABC = 0;
    for(int i=0; i<str.length(); i++){

        if(str[i] == '0') strVec.push_back(0);
        if(str[i] == '1') strVec.push_back(1);
    }

    for(int i=0; i<strVec.size()-1; i++){
        ABC = ABC + (strVec[i]*strVec[i+1]);
    }

    return ABC;
}

void fun(int n , int k, string ans, vector<string>&finalAns){

    if(ans.length() == n && AdjBC(ans) == k){
        finalAns.push_back(ans);
        return;
    }

    if(ans.length()<n){
        fun(n,k,ans+"0",finalAns);
        fun(n,k,ans+"1",finalAns);
    }
}

int fun2(int n , int k, string ans){

    if(ans.length() == n && AdjBC(ans) == k){
        return 1;
    }

    if(ans.length()<n){

        return (fun2(n,k,ans+"0") + fun2(n,k,ans+"1") );
        
    }
}

int fun3(int n, int k, int last){

    if(n==0) return 0;
    if(n==1){
        if(k==0) return 1; // its 1, not 2 remember
        else return 0;
    }

    if(dp[n][k][last] != -1) return dp[n][k][last];

    if(last == 1){
        return dp[n][k][last] = fun3(n-1,k,0) + fun3(n-1,k-1,1);

        // agar last me '1' hai, to 2nd last me ya to '1' hoga ya to '0', agar '1' hua to ek bit kam ho jaaegi(n-1) and k-1 ho jaaeha kyoki ek AdjBC mil gaya, also last ab '1' ho jaaega, par agar 2nd last bit '0' hui to n-1 hoga but 'k' hi raghegam and last bit '1' ho jaaega

    }

    else{
        return dp[n][k][last] = fun3(n-1,k,0) + fun3(n-1,k,1);
    }
}


int main(){

    string ans = "";
    // vector<string>finalAns;
    int n = 20;
    int k = 8;

    // fun(n,k,ans,finalAns);

    /*
    for(int i=0; i<finalAns.size(); i++){

        cout<<finalAns[i]<<endl;
    }
    */
    
    // cout<<finalAns.size()<<endl;
    //cout<<fun2(5,2,ans)<<endl;

    memset(dp,-1,sizeof(dp) );
    cout<<( fun3(n,k,0) + fun3(n,k,1) )<<endl;


    return 0;
}