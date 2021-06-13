#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class smartQueue {
    private:
        queue<int> inputs;
        queue<int> minSt;
        queue<int> maxSt;

    public: 
        void push(int data) {
            inputs.push(data);
            if (minSt.empty()) {
                minSt.push(data);
            }
            else if (data < minSt.front()) {
                minSt.push(data);
            }

            if (maxSt.empty()) {
                maxSt.push(data);
            }
            else if (data > maxSt.front()) {
                maxSt.push(data);
            }
        }
        bool pop() {
            if (minSt.front() == inputs.front()) {
                inputs.pop();
                minSt.pop();
                return true;
            }
            else if (maxSt.front() == inputs.front()) {
                inputs.pop();
                maxSt.pop();
                return true;
            }
            else {
                inputs.pop();
                return true;
            }
            return false;
        }
        int front() {
            return inputs.front();
        }
        bool empty() {
            return inputs.empty();
        }
        int min() {
            if (minSt.empty()) {
                return inputs.front();
            }
            return minSt.back();
        }
        int max() {
            if (maxSt.empty()) {
                return inputs.front();
            }
            return maxSt.back();
        }
};
int main() {
    smartQueue sQ;
    // push 3, 7, 2, 9, 8, 4
    // pop() 
    sQ.push(3);
    cout<<"Push 3:"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 3, "<<sQ.max()<<endl;
   
    sQ.push(7);
    cout<<"Push 7"<<endl;
     cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 7, "<<sQ.max()<<endl;
    sQ.push(2);
    cout<<"Push 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 7, "<<sQ.max()<<endl;
    sQ.push(9);
    cout<<"Push 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<"front: 3, "<<sQ.front()<<endl;;
    cout<<"  min: 2, "<<sQ.min()<<endl;
    cout<<"  max: 9, "<<sQ.max()<<endl;
    sQ.push(8);
    cout<<"Push 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.push(4);
    cout<<"Push 4"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;

    cout<<endl<<"Start popping"<<endl<<endl;
    // elements in smartQueue: 3, 7, 2, 9, 8, 4
    sQ.pop();
    cout<<"Popped 3"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 7, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 7"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 2, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 9, "<<sQ.front()<<endl;
    cout<<"   min: 4, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 8, "<<sQ.front()<<endl;
    cout<<"   min: 4, "<<sQ.min()<<endl;
    cout<<"   max: 8, "<<sQ.max()<<endl;
    cout<<"Print rest of the queue: ";
    sQ.push(3);
    cout<<"Pushed 3"<<endl;
    // queue has 8, 4, 3
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 8, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 8, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 4, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 4, "<<sQ.max()<<endl;
    cout<<"Print rest of the queue: ";
   // print_queue(sQ);
    return 0;
}
