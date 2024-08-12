/*Given an mxn grid.
*/

#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;
vector<int> directions = {-1,0,1,0,-1};

class Solution {
    int rows, columns, count;
public:
    int numIslands(vector<vector<char>>& grid) {
        count = 0;
        rows = grid.size();
        columns = grid[0].size();
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i , j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int column){
        for (int i = 0; i < 4; i++){
            int new_row = row + directions[i];
            int new_column = column + directions[i+1];
            if (new_row >= 0 && new_column >= 0 && new_row < rows && new_column < columns && grid[new_row][new_column] == '1'){
                grid[new_row][new_column] = '0';
                dfs(grid, new_row, new_column);
            }
        }
    }
};