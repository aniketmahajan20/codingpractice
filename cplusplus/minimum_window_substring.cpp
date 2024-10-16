#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
private:
    unordered_map<char, int> map;
    queue<int> index_queue; 
public:
    string minWindow(string s, string t) {
        if (s == t){
            return s;
        }
        for (auto c: t){
            if (map.find(c) != map.end()){
                map[c]++;
            }
            else{
                map[c] = 1;
            }
        }
        int required_total = t.size();
        int max_length =INT_MAX;
        string result = "";
        int final_first = 0, final_second = 0;
        //declaring two pointers for the sliding window
        int first = 0, second = 0;
        int cur_total = 0;
        while(second < s.size()){
            if (map.find(s[second]) != map.end()){
                if (cur_total != required_total){
                    if (first != second){
                        index_queue.push(second); 
                    }
                    map[s[second]]--;
                    if (map[s[second]]>=0){
                        cur_total++;
                    }
                }
                if (cur_total == required_total){
                    if (max_length>(second-first + 1)){
                        max_length = second-first + 1;
                        final_first = first;
                        final_second = second;
                    }
                    while(cur_total == required_total && index_queue.size() >0){
                        map[s[first]]++;
                        if (map[s[first]] >0){  
                            cur_total--;
                        }
                        first = index_queue.front();
                        index_queue.pop();
                        if (cur_total == required_total){
                            if (max_length>(second-first + 1)){
                                max_length = second-first + 1;
                                final_first = first;
                                final_second = second;
                            }
                        }
                    }
                    
                }
            }
            if (cur_total == 0){
                first++;
            }
            second++;
        }
        if (max_length == INT_MAX){
            return "";
        }
        for(int i = final_first; i<= final_second; i++){
            result.push_back(s[i]);
        }
        return result;
    }
};