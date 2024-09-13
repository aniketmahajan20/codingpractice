#include <unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<int, int> map;
public:
    int fib(int n) {
        if (map.count(n) > 0){
            return map[n];
        }
        if (n < 2) {
            return n;
        }
        return (map[n] = fib(n-1) + fib(n-2));
    }
};