// https://codeforces.com/problemset/problem/1917/B
// Rahul R, rahulranjan25.rr@gmail.com

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define ff            first
#define ss            second
#define sz(x)         ((int)(x).size())
#define all(x)        (x).begin(), (x).end()
#define debug_lmidr   cerr << l << " " << mid << " " << r << "\n";
#define INF           (int)1e18
#define PI            3.141592653589793238462
#define MOD7          1000000007
#define MOD9          998244353
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(NULL);                \
  cout.tie(NULL)

using ll   =          long long;
using ull  =          unsigned long long;
using lld  =          long double;
using pbds =          tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (auto i:v) os << i << " "; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "{" << p.ff << ", " << p.ss << "}"; return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) { for (auto i:s) os << i << " "; return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) { for (auto i:s) os << i << " "; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) { for (auto i: m) os << i.ff << " -> " << i.ss << "\n"; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) { for (auto i: m) os << i.ff << " -> " << i.ss << "\n"; return os; }
ostream& operator<<(ostream& os, const pbds& t) { for (auto i: t) os << i << " "; return os; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* -------------------------------------------- */
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++) if (arr[i] == 0) { vect.push_back(i); for (int j = 2 * i; j <= n; j += i) arr[j] = 1; } return vect; }
vector<bool> compute_primes(ll n){ vector<bool> isPrime(n+1, 1); isPrime[0] = isPrime[1] = 0; for (int i = 2; i*i <= n; i++) if (isPrime[i]) for (int j = i*i; j <= n; j+=i) isPrime[j] = 0; return isPrime; }

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/* -------------------------------------------- */

void setIO() { 
  fast; 
  #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
  #endif 
}


void solve() {
  ll n; cin >> n;
  string s; cin >> s;

  vector<bool> f(26, 0);
  ll answer = 0;
  for (ll i = 0; i < n; i++){
    if (!f[s[i] - 'a']){
      f[s[i]-'a'] = 1;
      answer += (n-i);
    }
  }

  cout << answer << "\n";
}

int main(void){
  setIO();
  auto start = high_resolution_clock::now();
  ll t; cin >> t;
  while (t--) solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return 0;
}
