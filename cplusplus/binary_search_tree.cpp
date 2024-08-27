/* Implementing a Binary search Tree in C++
Will Contain the Follwoing functions:
- void insert(int data);
- bool contains(int data);
- void printInOrder();
- void printPreOrder();
- void printPostOrder(); */
#include <iostream>
using namespace std;
class Node{
private:
    Node* left;
    Node* right;
    int data;
public:
    Node(int data){
        this->data = data;
    }
    void insert(int value){
        if (value <= data){
            if(left == nullptr){
                left = new Node(value);
            }
            else{
                left->insert(value);
            }
        }
        if (value >= data) {
            if(right == nullptr){
                right = new Node(value);
            }
            else{
                right->insert(value);
            }
        }   
    }

    bool contains(int value){
        if (value == data) {
            return true;
        }
        else if (value < data){
            if (left == nullptr){
                return false;
            }
            else {
                left->contains(value);
            }
        }
        else {
            if (right == nullptr){
                return false;
            }
            else {
                right->contains(value);
            }
        }
    }

    void printInOrder(){
        if (left != nullptr){
            left->printInOrder();
        }
        cout << data  << endl;
        if (right != nullptr){
            right->printInOrder();
        }
    }

    void printPreOrder(){
        cout << data << endl;
        if (left != nullptr){
            left->printPreOrder();
        }
        if (right != nullptr){
            right->printPreOrder();
        }
    }

};


int main(){
    Node* obj = new Node(55);
    obj->insert(46);
    obj->insert(77);
    obj->insert(99);
    obj->printPreOrder();
    return 1;
}