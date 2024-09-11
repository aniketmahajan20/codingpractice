#include <vector>

using namespace std;

class Solution {
private:
    int i = 0;
    char temp;
public:
    void reverseString(vector<char>& s) {
        if (i >= (s.size()+1)/2){
            return;
        }
        temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
        i += 1;
        reverseString(s);
    }
};