#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;
        bool flag = true;
        for (char c: s){
            if (c == '(' || c == '[' || c == '{'){
                parentheses_stack.push(c);
                flag = false;
            }
            else{
                if (parentheses_stack.empty()){
                    return false;
                }
                if (c == ')'){
                    if (parentheses_stack.top() != '('){
                        return false;
                    }
                    flag = true;
                    parentheses_stack.pop();
                }
                if (c == '}'){
                    if (parentheses_stack.top() != '{'){
                        return false;
                    }
                    flag = true;
                    parentheses_stack.pop();
                }
                if (c == ']'){
                    if (parentheses_stack.top() != '['){
                        return false;
                    }
                    flag = true;
                    parentheses_stack.pop();
                }

            }
        }
        if (!parentheses_stack.empty()){
            return false;
        }
        return flag;
    }
};

int main(){
    Solution* obj = new Solution();
    cout << obj->isValid("[][][]");
    return 0;

}