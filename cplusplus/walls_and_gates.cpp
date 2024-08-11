#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

#define INF     (pow(2,31) - 1)

#define TARGET  0

vector<int> directions = {-1,0,1,0,-1};

class Solution {
    int rows;
    int columns;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        rows = rooms.size();
        columns = rooms[0].size();
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (rooms[i][j] == 0){
                    q.emplace(i,j);
                }
            }
        }
        int step = 0;
        while(!q.empty()){
            ++step;
            int size = q.size();
            for (int i =0; i<size; i++){
                pair<int,int> cur = q.front();

                for (int k = 0; k < 4; k++){
                    int row = cur.first + directions[k];
                    int column = cur.second + directions[k+1];

                    if (row >= 0 && column >=0 && row < rows && column < columns && rooms[row][column] == INF){
                        rooms[row][column] = step;
                        q.emplace(row,column);
                    }
                }
                q.pop();
            }
        }
    }
};

// int main(){
//     cout << INT_MAX << "   " << INF;
//     return 0;
// }