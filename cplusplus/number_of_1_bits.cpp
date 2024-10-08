class Solution {
public:
    int hammingWeight(int n) {
        short total_set_bits = 0;
        while (n){
            total_set_bits += n & 0x1;
            n = n >> 1;
        }
        return total_set_bits;
    }
};