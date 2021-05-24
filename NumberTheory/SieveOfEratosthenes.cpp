#include <bits/stdc++.h>
using namespace std;



int is_prime[1000001];

void sieve() {
    int maxN = pow(10, 6);

    //1 denotes prime, 0 denotes composite
    for (int i = 1; i <= maxN; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i*i <= maxN; i++){
        if (is_prime[i]) {
            for (int j = i*i; j <= maxN; j+= i){
                is_prime[j] = 0;
            }
        }
    }
}


int main(){

    sieve(); //IMPORTANT TO CALL IT ONCE
    /* for (int i = 0; i < 50; i++){
        cout << i << " is: " << is_prime[i] <<"\n";
    } */
    
    return 0;
}