#include <bits/stdc++.h>
using namespace std;

void deques() {

    //Deque is a combo of stack and queue.
    //Deque is also a dynamic array like vectors with,
    //push_front() and pop_front() functions which is not available in vectors
    
    //SLOWER THAN VECTORS

    deque<int> deq;
    deq.push_back(5);
    deq.push_back(3);
    deq.push_back(3);
    deq.push_front(7);
    deq.push_front(6);
    deq.push_front(10);
    for (auto x : deq) cout << x << " ";
    cout << "\n";

    deq.pop_back();
    deq.pop_front();

    for (auto x : deq) cout << x << " ";

}

int main() {

    deques();
    
    return 0;
}