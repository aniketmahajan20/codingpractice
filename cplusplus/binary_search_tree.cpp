/* Implementing a Binary search Tree in C++
Will Contain the Follwoing functions:
- void insert(int data);
- bool contains(int data);
- void printInOrder();
- void printPreOrder();
- void printPostOrder(); */
#include <iostream>
#include <queue>

using namespace std;
class Node{
private:
    Node* left;
    Node* right;
    int data;
public:
    Node(int data){
        this->data = data;
        left = right = NULL;
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

    void printPostOrder(){
        if (left != nullptr){
            left->printPreOrder();
        }
        cout << data << endl;
        if (right != nullptr){
            right->printPreOrder();
        }
    }

    void printBFSOrder(){
        queue<Node*> bfs_queue;
        bfs_queue.push(this);
        while(!bfs_queue.empty()){
            Node* node = bfs_queue.front();
            cout << node->data << endl;
            bfs_queue.pop();

            if (left != nullptr){
                bfs_queue.push(node->left);
            }
            if (right != nullptr){
                bfs_queue.push(node->right);
            }
        }
    }
};


int main(){
    Node* obj = new Node(55);
    obj->insert(46);
    obj->insert(77);
    obj->insert(22);
    obj->insert(47);
    obj->insert(99);
    obj->insert(32);
    obj->printBFSOrder();
    return 1;
}