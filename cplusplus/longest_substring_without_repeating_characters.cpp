// Given string s, find the length of longest substring without 
// repeating characters
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;
class Solution {
private:
    set<char> set0;
    set<char> set1;
    int current_set = 0;
public:
    int lengthOfLongestSubstring(string s) {
        for (auto character: s){
            if (current_set == 0){
                if (set0.find(character) != set0.end()){
                    if (size(set0) > size(set1)){
                        current_set = 1;
                        set1.clear();
                    }
                    else{
                        set0.clear();
                    }
                }
                else{
                    set0.emplace(character);
                }
            }
            if (current_set == 1){
                if (set1.find(character) != set1.end()){
                    if (size(set1) > size(set0)){
                        current_set = 0;
                        set0.clear();
                    }
                    else{
                        set1.clear();
                    }        
                }
                else{
                    set1.emplace(character);
                }
            }
        }
        return max(size(set0), size(set1));
    }
};

int main(){
    Solution* obj = new Solution();
    cout << obj->lengthOfLongestSubstring("abcabcbb");
}