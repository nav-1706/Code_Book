// Best code for flood fill type questions

class Solution {
public:

    void dfs(vector<vector<int>>&image, int currRow, int currCol, int initialColor, int newColor, vector<vector<bool>>& visited){ // newColor == color

        int n = image.size();
        int m = image[0].size();

        if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m || visited[currRow][currCol] == true){

            return;
        }

        if(image[currRow][currCol] != initialColor) return; // condition elimination

        visited[currRow][currCol] = true; // marki visited

        image[currRow][currCol] = newColor; // agar  image[currRow][currCol] ka color initialColor ke equal hai


        // traversal in all 4 directions

        dfs(image, currRow+1, currCol, initialColor, newColor, .visited); // down
        dfs(image, currRow, currCol-1, initialColor, newColor, visited); // left
        dfs(image, currRow-1, currCol, initialColor, newColor, visited); // up
        dfs(image, currRow, currCol+1, initialColor, newColor, visited); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         
        // we will use recurssion, hence DFS

        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        int initialColor = image[sr][sc];

        if(initialColor != color){
            dfs(image, sr, sc, initialColor, color, visited);
        }
    
        return image;
    }
};