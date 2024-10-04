#include <string>
#include <iostream>
using namespace std;
#define BASE 16
class Solution {
public:
    string toHex(int num) {
        unsigned int number = num;
        if (number == 0){
            return "0";
        }
        string result = "";
        int remainder = 0;
        if (number<0){
            unsigned int temp = ((1 << 31) - 1);
            cout << temp;
            number = number^ temp;
            number= number + 1;
            number |= 1<<32;
            cout << number << endl;
        }
        while(number){
            remainder = number%BASE;
            if (remainder < 0){
                remainder *= -1;
            }
            if(remainder < 10){
                result += to_string(remainder);
            }
            else{
                result += char(remainder+87);
            }
            number= number/BASE;
        }
        reverse(result.begin(), result.end());
        cout << result;
        return result;
    }
};


class Solution_Direct_Conversion {
public:
    string toHex(int num) {
        unsigned int number = num;
        if (number == 0){
            return "0";
        }
        if (number<0){
            unsigned int temp = ((1 << 31) - 1);
            number = number^ temp;
            number= number + 1;
            number |= 1<<32;
            cout << number << endl;
        }
        string result = "";
        int hex_number;
        for (int i = 0; i < 8; i++){
            hex_number = number & 0xf;
            if (number > 0){
                if(hex_number < 10){
                    result += to_string(hex_number);
                }
                else{
                    result += char(hex_number+87);
                }
            }
            number = number >> 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main(){
    Solution* obj = new Solution();
    obj->toHex(-1);
}