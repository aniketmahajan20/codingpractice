#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> anagram_map;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++){
            string hash_key = get_anagram_key(strs[i]);
            if (anagram_map.find(hash_key) != anagram_map.end()){
                anagram_map[hash_key].push_back(strs[i]);
            }
            else{
                anagram_map[hash_key] = {strs[i]};
            }
        }
        for (auto element: anagram_map){
            result.push_back(element.second);
        }
        return result;
    }

    string get_anagram_key(string s){
        sort(s.begin(), s.end());
        return s;
    }
};