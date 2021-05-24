#include <bits/stdc++.h>
using namespace std;

void maps() {

    //Maps are generalized array consisting key-value pairs.

    map<string, int> m;
    m["iPhone"] = 2;
    m["Dustbin"] = 7;
    m["RandomString"] = 5;

    cout << m["Dustbin"] << "\n";
    cout << m["AnotherRandomString"] << "\n";

    for (auto x : m) cout << x.first << " " << x.second << "\n";

}

int main() {

    maps();

    return 0;
}