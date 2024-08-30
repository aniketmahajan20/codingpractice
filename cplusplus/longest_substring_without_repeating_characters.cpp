// Given string s, find the length of longest substring without 
// repeating characters

// Note: This solution needs minor modifications to adhere to the fact that,
// the next longest substring starts from i + 1, where i is the index]
// of the character that is already present but is repeated.
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
private:
    unordered_set<char> set0;
    unordered_set<char> set1;
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

// Slider window solution
class SolutionSliderWindow {
private:
    unordered_map<char, int> map;
public:
    int result = 0;
    int lengthOfLongestSubstring(string s) {
        for (int i = 0, j = 0; j < int(size(s)); j++) {
            if (map[s[j]] > 0){
                i = max(i, map[s[j]]);
            }
            result = max(result, j - i +1);
            map[s[j]] = j +1;
        }
        return result;
    }
};

int main(){
    Solution* obj = new Solution();
    cout << obj->lengthOfLongestSubstring("abcabcbb");
}