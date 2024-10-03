#include <string>
using namespace std;
#define BASE 7
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0){
            return "0";
        }
        string result = "";
        int remainder = 0;
        string neg = "";
        if (num<0){
            neg = "-";
        }
        while(num){
            remainder = num%BASE;
            if (remainder < 0){
                remainder *= -1;
            }
            result += to_string(remainder);
            num = num/BASE;
        }
        result += neg;
        reverse(result.begin(), result.end());
        return result;
    }
};