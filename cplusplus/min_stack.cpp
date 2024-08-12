#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

class stackNode {
public:
    int value;
    int minValue;
    stackNode(int value, int minValue) {
        value = value;
        minValue = minValue;
    }
};

class MinStack {
private:
    vector<stackNode*> data;
public:
    MinStack() {

    }
    
    void push(int val) {
        int minValue;
        int curr_min_value = top();
        if (val < curr_min_value){
            minValue = val;
        }
        else{
            minValue = curr_min_value;
        }
        stackNode* node = new stackNode(val, minValue);
        data.push_back(node);
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        stackNode* node = data.back();
        return node->value;
    }
    
    int getMin() {
        stackNode* node = data.back();
        return node->minValue;
    }
};
// 
//  Your MinStack object will be instantiated and called as such:
// int main(){
//     MinStack* obj = new MinStack();
//     obj->push(-2);
//     obj->push(0);
//     obj->push(-3);
//     int param_3 = obj->top();
//     int param_4 = obj->getMin();
//     return 0;
// }