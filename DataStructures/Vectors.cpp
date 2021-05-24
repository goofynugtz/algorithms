#include <bits/stdc++.h>
using namespace std;

int main() {

    //Dynamic Arrays or Vectors are flexible size

    vector<int> v;
    int n; cin >> n;
    for (int i = 1; i <= 10; i++){
        v.push_back(i * n);
    }

    cout << v.size() << "\n";

    for (auto x : v){
        cout << x << " ";
    }

    return 0;
}