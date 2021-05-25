#include <bits/stdc++.h>
using namespace std;

//When using arrays as database, Insertion would be of O(1) time and removal would be of O(n) time. Or in case of using sorted arrays, insertion of O(n) and removal is O(1). Thus overall process is of O(n) time.

/* 
    insert  remove-min  net for n operations
1   1       n           n + n^2 
2   n       1           n^2 + n
3   log(n)  log(n)      n*log(n) + n*log(n)     //For Binary Heaps
 */

void PriorityQueue() {

    //Maintains set of elements
    //Supported Operations are: Insertion, Removal of Max or Min element both of O(logn) time and Retrieval of O(1) time;

    priority_queue<int> q;
    //aka Binary Heaps

    q.push(3);
    q.push(5);
    q.push(5);
    q.push(2);
    q.push(10);

    cout << q.top() << "\n";
    q.pop();
    cout << q.top() << "\n";

    //Priority Queue supporting retrieval of smallest element:
    priority_queue<int, vector<int>, greater<int>> q2;

}

int main() {

    PriorityQueue();

    return 0;
}