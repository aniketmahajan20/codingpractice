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
private:
    int rows;
    int columns;
    int count;
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        count = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (grid[i][j] == '1'){
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int row, int column){
        queue<pair<int, int>> q;
        q.emplace(row, column);
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++){
                int new_row = curr.first + directions[i];
                int new_column = curr.second + directions[i+1];
                if (new_row >= 0 && new_column >= 0 && new_row < rows && new_column < columns && grid[new_row][new_column] == '1'){
                    grid[new_row][new_column] = '0';
                    q.emplace(new_row, new_column);
                }
            }
        }
    }
};

// int main(){
//     cout << INT_MAX << "   " << INF;
//     return 0;
// }