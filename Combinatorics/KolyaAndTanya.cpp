// https://codeforces.com/problemset/problem/584/B
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
#define MULTIPLE      0
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
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phi(ll n) { ll res = n; for (ll i = 2; i*i<=n; i++){ if (n%i == 0) { while (n%i == 0) n /= i; res -= res/i; } } if (n > 1) res -= res/n; return res; }
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> listOfPrimes; for (int i = 2; i <= n; i++) if (arr[i] == 0) { listOfPrimes.push_back(i); for (int j = 2 * i; j <= n; j += i) arr[j] = 1; } return listOfPrimes; }
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
  const ull mod = 1e9+7;
  cout << mod_sub(expo(3, 3*n, mod), expo(7, n, mod), mod) << "\n";
}

int main(void){
  setIO();
  auto start = high_resolution_clock::now();
  ll t = 1;
  #if MULTIPLE
    cin >> t;
  #endif
  while (t--) solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cerr << "[!] Total Execution Time: " << duration . count() / 1000 << " ms" << endl;
  return 0;
}
