/*
https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/?purpose=login&source=problem-page&update=google
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<vector<int>>>dp3D;

int kOrderLCS(vector<int>&v1, vector<int>&v2, int k, int i, int j){

    if(i >= v1.size() || j >= v2.size()) return 0;

    if(dp3D[k][i][j] != -1) return dp3D[k][i][j];

    if(v1[i] == v2[j]) return dp3D[k][i][j] = 1 + kOrderLCS(v1,v2,k,i+1,j+1);

    else if (v1[i] != v2[j] && k>0){

        return dp3D[k][i][j] = max( 1+kOrderLCS(v1,v2,k-1,i+1,j+1), max( kOrderLCS(v1,v2,k,i+1,j), kOrderLCS(v1,v2,k,i,j+1) ) ); // only change
    }

    else if (v1[i] != v2[j] && k<=0){
        return dp3D[k][i][j] = max( kOrderLCS(v1,v2,k,i+1,j), kOrderLCS(v1,v2,k,i,j+1) );
    }
}

int main(){

    vector<int>v1 = {1, 1, 2, 3, 3, 4, 4};
    vector<int>v2 = {1, 2, 3, 4, 5};
    int k = 2;
    int n = v1.size();
    int m = v2.size();

    dp3D.clear();
    dp3D.resize(k+5, vector<vector<int>>(n+5, vector<int>(m+5, -1)));

    // very important syntax;

    cout<<kOrderLCS(v1,v2,k,0,0)<<endl;

    return 0;
}