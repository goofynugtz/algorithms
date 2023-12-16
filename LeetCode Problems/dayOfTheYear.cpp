// https://leetcode.com/problems/day-of-the-year/

#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
using namespace std;

class Solution {
public:
  int dayOfYear(string date) {
    int yyyy = stoi(date.substr(0, 4));
    int mm = stoi(date.substr(5, 7));
    int dd = stoi(date.substr(8, 10));
    if (yyyy % 400 == 0 || (yyyy%100 != 0 && yyyy%4==0) && mm > 2)
      dd++;
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i <= mm; i++){
      dd += months[i-1];
    }
    return dd;
  }
};

int main(void){
  Solution s;
  cout << s.dayOfYear("2002-12-25") << "\n";
  cout << s.dayOfYear("2019-01-09") << "\n";
  return 0;
}