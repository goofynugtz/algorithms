#include <bits/stdc++.h>
using namespace std;

void ranges() {

    vector<int> v1 = { 3, 4, 6, 7, 3, 24 ,34, 22, 5 };
    cout << "Vector: ";
    for (auto x : v1) cout << x << " ";
    cout << "\n";

    cout << "Sorting Vector\n";
    sort(v1.begin(), v1.end());
    for (auto x : v1) cout << x << " ";
    cout << "\n";

    cout << "Reversing Vector\n";
    reverse(v1.begin(), v1.end());
    for (auto x : v1) cout << x << " ";
    cout << "\n";

    cout << "Shuffling Vector\n";
    random_shuffle(v1.begin(), v1.end());
    for (auto x : v1) cout << x << " ";
    cout << "\n";
}

void iterators() {

    //Used to access elements of a set;

    set<int> s;
    //Example Set
    s.insert(7);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    for (auto x : s) cout << x << " ";
    cout << "\n";

    //Following creates an iterator itr that points to the smallest element in a set;

    /* set<int>::iterator itr = s.begin(); */
    //Above code is equivalent to:
    auto itr = s.begin();  

    cout << *itr << "\n";  //Points towards smallest element ie 2.

    cout << "Printing Set with iterator: ";
    for (auto itr = s.begin(); itr != s.end(); itr++) cout << *itr << " ";
    cout << "\n";

    //For geting largest in set:
    auto itr2 = s.end(); itr2--;
    cout << *itr2;

}

int main() {

    // ranges();
    iterators();

    return 0;
}