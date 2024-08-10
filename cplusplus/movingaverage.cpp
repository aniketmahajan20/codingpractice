

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class MovingAverage {
private:
    queue<int> q;
    int window_size;
    int running_sum;
public:
    MovingAverage(int size) {
        window_size = size;
        running_sum = 0;
    }

    double next(int val) {
        q.push(val);
        int first = 0;
        if(q.size() > window_size){
            first = q.front();
            q.pop();
        }
        else{
            first = 0;
        }
        float average = 1.0 * (running_sum + val - first)/q.size();
        cout<<q.size();
        return average;
    }
};

int main(){
    MovingAverage* obj = new MovingAverage(3);
    double param_1 = obj->next(1);
    param_1 = obj->next(10);
    param_1 = obj->next(3);
    return 0;
}