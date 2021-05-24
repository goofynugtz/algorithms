#include <bits/stdc++.h>
using namespace std;

struct Optimizer{
    Optimizer(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
};

Optimizer opt;

bool isPrime(int n){
    if (n==1) return false;

    for (int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }

    return true;
}

int main(){

    int n = 3;
    //cout << isPrime(n);

    return 0;
}