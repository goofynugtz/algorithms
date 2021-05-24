#include <bits/stdc++.h>
using namespace std;

struct Optimizer{
    Optimizer(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
};

Optimizer opt;

int arr[1000001];

void sieve(){
    int maxN = 1000000;
    for (int i = 1; i <= maxN; i++) arr[i] = -1;

    for (int i = 2; i <= maxN; i++){
        if (arr[i] == -1){
            for (int j = i; j <= maxN; j += i){
                if (arr[j] == -1) arr[j] = i;
            }
        }
    }
}

int main(){

    

    return 0;
}