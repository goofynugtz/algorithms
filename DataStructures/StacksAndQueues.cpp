#include <bits/stdc++.h>
using namespace std;

void stacks() {

    //Only provides two operations of O(1) time: push() or pop() element from the top.
    //First In : First Out
    cout << "Stack: \n";
    stack<int> s;
    s.push(7);
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(1);

    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";

}

void queues() {

    //Similar to stack but adds element to end and removes the first element.
    //First In : Last Out

    cout << "Queue: \n";
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(5);
    q.push(7);
    q.push(10);

    cout << q.front() << "\n";
    q.pop();
    cout << q.front() << "\n";

}

int main() {

    stacks();
    queues();

    return 0;
}