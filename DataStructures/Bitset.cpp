#include <bits/stdc++.h>
using namespace std;

void bitsets() {

    //Uses only n bits of memory is used
    //Bitset is an array whose value is either (OFF || ON == 0 || 1)
    bitset<10> bit_A;
    bit_A[1] = 1;
    bit_A[3] = 1;
    bit_A[4] = 1;
    bit_A[7] = 1;

    //for (int i = 0; i < 10; i++) cout << bit_A[i] << " ";
    cout << bit_A << "\n";

    bitset<10> bit_B(string("1001010001")); //READS FROM "RIGHT TO LEFT"
    cout << bit_B << "\n";

    cout << bit_B.count() << "\n"; //Returns Number of ONs;

    //Bitwise operations can be used as:
    cout << (bit_A & bit_B) << "\n"; //AND operation
    cout << (bit_A | bit_B) << "\n"; //OR operation
    cout << (bit_A ^ bit_B) << "\n"; //XOR operation

}

int main() {

    bitsets();

    return 0;
}