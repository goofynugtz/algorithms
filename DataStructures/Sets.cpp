#include <bits/stdc++.h>
using namespace std;

void sets(){

    cout << "Sets\n";

    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    for (auto x : s) cout << x << " ";
    cout << "\n";

    //Sets don't show up duplicate items [FOR DUPLICATE ELEMENTS: See multiset]

    s.erase(2);
    for (auto x : s) cout << x << " ";
    cout << "\n";
}

void unorderedset() {

    cout << "Unordered Sets\n";

    //Unordered Sets are more efficient and does exactly what is mentioned in the name but in a limited functionality.

    //WARN: lower_bound(x) or upper_bound(x) functions are not supported by unordered sets.

    unordered_set<int> s;
    
    s.insert(1);
    s.insert(4);
    s.insert(4);
    s.insert(2);
    s.insert(0);
    s.insert(5);

    for (auto x : s) cout << x << " ";
    cout << "\n";
}

void multisets(){

    cout << "Multisets\n";

    multiset<int> s;
    s.insert(9);
    s.insert(8);
    s.insert(7);
    s.insert(7);
    s.insert(7);
    s.insert(4);
    s.insert(4);

    for (auto x : s) cout << x << " ";
    cout << "\n";

    s.erase(7);
    for (auto x : s) cout << x << " ";
    cout << "\n";

    //set.erase(n) will erase all instances of n;
    //for erasing a single instance, DO:
    s.erase(s.find(4));
    for (auto x : s) cout << x << " ";
    cout << "\n";

}

int main() {

    sets();
    unorderedset();
    multisets();

    return 0;
}