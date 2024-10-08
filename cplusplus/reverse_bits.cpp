#include <stdint.h>
#include <unordered_map>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint8_t pow = 31;
        while(n){
            ret += (n&1) << pow;
            n = n >> 1;
            pow -= 1;
        }
        return ret;
    }
};


class Solution_ByteWise {
private:
    unordered_map<uint32_t, uint32_t> map;
public:
    uint32_t reverseByte(uint32_t byte){
        if (map.find(byte) != map.end()){
            return map[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        return map[byte] = value;
    }
    uint32_t reverseBits(uint32_t n){
        uint32_t ret = 0;
        uint8_t pow = 24;
        while(n){
            ret += reverseByte(n&0xff) << pow;
            n = n >> 8;
            pow -= 8;
        }
        return ret;
    }
};

class Solution_NO_loop {
    uint32_t reverseBits(uint32_t n){
        n = (n >> 16) | (n << 16);
        n = ((n&0xff00ff00) >> 8) | ((n&0x00ff00ff) << 8);
        n = ((n&0xf0f0f0f0) >> 4) | ((n&0x0f0f0f0f) << 4);
        n = ((n&0xcccccccc) >> 2) | ((n&0x33333333) << 2);
        n = ((n&0xaaaaaaaa) >> 1) | ((n&0x55555555) << 1);
        return n;
    }
};