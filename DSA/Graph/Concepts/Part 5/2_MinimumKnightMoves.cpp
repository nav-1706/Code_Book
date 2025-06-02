// LEETCODE 1197

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<pair<int,int>>dir = { // moves in clockwise dirextion
    {2,1}, 
    {1,2},
    {-1,2},
    {-2,1},
    {-2,-1},
    {-1,-2},
    {1,-2},
    {2,-1}

};

int bfs(int x, int y, queue<pair<int,int>>& qu){

    int count = 0;
    vector<vector<bool>>visited(610, vector<bool>(610,false));
    visited[305][305] = true;  // 305 ka offset set kiya hai kyoki, chess board negative me bhi jaa sakta hai 

    while(!qu.empty()){
        
        int size = qu.size(); // this is the main loop for level-order traversal/bfs traversal, many question can be solved without this loop by just takig the first element out of the queue, but not all questions can be solved(like this one) so always use this outer loop
        for(int i = 0; i < size; i++){ 
            auto cell = qu.front();
            qu.pop();
            int currX = cell.first;
            int currY = cell.second;
            if(currX == x && currY == y) return count;

            for(int d = 0; d < 8; d++) { // this is the loop of possible movement 
                int newRow = currX+dir[d].first;
                int newCol = currY+dir[d].second;

                if(newRow == x && newCol == y){
                    return count+1;
                }

                //
                
                if(visited[newRow+305][newCol+305]) continue; // if already visited
                visited[newRow+305][newCol+305] = true; 
                //cout<<"("<<newRow<<" "<<newCol<<")"<<"-->";
                
                qu.push({newRow, newCol});
            }

        }
        
        
        count++;
    }

}

int main(){

    int x, y;
    cin >> x >> y;
    queue<pair<int,int>> qu;
    qu.push({0,0});
    
    //for(int i=0; i<8; i++){
      //  qu.push(dir[i]);
    //}

    cout<<bfs(x,y,qu);

    return 0;
}