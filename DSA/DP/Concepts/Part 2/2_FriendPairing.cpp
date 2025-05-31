/*

QUESTION:

Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired up only once. Find the total number of ways in which friends can remain single or can be paired up.

ANSWER:

Suppose 4 friends hai , A,B,C,D and lets suppose ki D ne bol diya ki vo party me sigle jaaega then, party me jaane ke tarike sirf A,B,C par depend karenge and D un tariko me chala jaaega 

so ways will be : (3C2)
    A, B, C, D
    (A,B), C, D
    (A,C), B, D
    (B,C), A, D

4 ways

f(n) = f(n-1) + somthing { as nth friend will go single}

par agar D decide karta hai ki vo pair me jaaega then uske paas (n-1) choises hai as 1 to vo khud hi pair ka part hai
and then party me jaane ka tarika bache hue (n-2) friends par decide karega hence , (n-1)f(n-2) ways

so f(n) = f(n-1) + (n-1)*f(n-2) where f(1) = 1 and f(2) = 2

*/

#include <iostream>
using namespace std;

int f(int n){

    if(n==1 || n==2) return n;
    return ( f(n-1) + (n-1)*f(n-2) );
}

int main(){

    cout<<"Total Number of ways: "<<f(4)<<endl;
    return 0;
}