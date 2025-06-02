/*

You are given a grid of n*m size. Every cell of the grid is marked as 'L', 'R', 'U', 'D'. Character on the cell denotes if you are standing on that cell, what direction you can move to, Check if we start from (0,0), can we reach (n-1,m-1). Solve in O(1) space time complexity

Answer:

Solution _1: We will get cycle if we revisit a cell twice, we can use BFS/DFS (but it takes space), if we revisits a cell it means there is loop and hence we can never get to the destination.

Solution_2: In worst case, we have to tarverse m*n cells(all), if after m*n steps we didn't get to destination, it means we can never as we are stuck in loop.(TC = O(m*n))

Solution_3: We will use same technique as we do to detect cycle in linked list, we will keep two pointers, one fast and one slow, slow will move 1 step and fast will move 2 steps, if they collid then there is cycle, if the fast one reached the destination(then slow will also) then there is no cycle.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){

    return 0;
}