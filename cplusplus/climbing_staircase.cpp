#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<int, int> map;
public:
    int climbStairs(int n) {
        if (map.count(n) > 0){
            return map[n];
        }
        if (n == 0 || n == 1 || n == 2 || n ==3){
            return (map[n] = n);
        }
        return (map[n] = climbStairs(n-2) + climbStairs(n-1));
    }
};

class Solution_DP {
private:
public:
    int climbStairs(int n) {
        vector<int> step_count(n+1,0);
        if (n >0){
            step_count[1] = 1;
        }
        if (n>1){
            step_count[2] = 2;
        }
        for (int i = 3; i < step_count.size(); i++){
            step_count[i] = step_count[i-1] + step_count[i-2];
        }
        return step_count[n];
    }
};