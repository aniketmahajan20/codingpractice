#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define INF     (2^31 - 1)

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        int columns = rooms[0].size();
        cout << rows << columns;
    }
};


int main(){
    Solution* obj = new Solution();
    vector<vector<int>> twoD_array{
        {1,2},
        {3,4}
    };
    for(int i=0; i<5; i++){

    }
    obj->wallsAndGates(twoD_array);
    return 0;
}