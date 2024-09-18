#include <iostream>
using namespace std;

class Solution {
private:
    double product = 1;
public:
    double myPow(double x, int n) {
        if (x == 0){
            return 0;
        }
        if (n == 0){
            return 1;
        }
        if (n < 0){
            double variable  = my_Pow(x, -n);
            return 1/product;
        }        
        else{
            double variable = my_Pow(x, n);
            return product;
        }
    }
    double my_Pow(double x, int n){
        if (n==1) {
            return (product = product * x);
        }
        product = product * x;
        return myPow(x, n-1);
    }
};