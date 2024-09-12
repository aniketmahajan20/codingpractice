#include <vector>
#include <unordered_map>
using namespace std;

class Solution_BruteForce_TLE {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal_row;
        for (int i = 0; i <= rowIndex; i++){
            pascal_row.push_back(get_number(rowIndex, i));
        }
        return pascal_row;
    }

    int get_number(int i, int j){
        if (j == 0 || i == j) {
            return 1;
        }
        return get_number(i-1, j-1) + get_number(i-1, j);
    }
};

class Solution_Dynamic_Programming {
private:
    unordered_map<int, int> map;
    int max_rows = 0;
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal_row;
        max_rows = rowIndex;
        for (int i = 0; i <= rowIndex; i++){
            pascal_row.push_back(get_number(rowIndex, i));
        }
        return pascal_row;
    }

    int get_number(int i, int j){
        int rowCol = i * max_rows + j;
        if (map.count(rowCol) > 0){
            return map[rowCol];
        }
        if (j == 0 || i == j) {
            return (map[rowCol] = 1);
        }
        return (map[rowCol] = get_number(i-1, j-1) + get_number(i-1, j));
    }
};

class Solution_Memory_Efficient_DP {
private:
public:
    vector<int> getRpw(int rowIndex) {
        vector<int> pascal_row(rowIndex+1, 0);
        for (int i = 0; i <= rowIndex; i++){
            for (int j = i; j>=0; j--){
                if (j == i || j == 0){
                    pascal_row[j] = 1;
                }
                else{
                    pascal_row[j] = pascal_row[j] + pascal_row[j-1];
                }
            }
        }
        return pascal_row;
    }
};