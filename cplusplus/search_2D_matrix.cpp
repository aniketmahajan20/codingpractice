#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        while(col < matrix[0].size() && (row > -1)){
            if (matrix[row][col] == target){
                return true;
            }
            if (matrix[row][col] < target){
                col++;
            }
            else{
                row--;
            }
        }
        return false;
    }
};