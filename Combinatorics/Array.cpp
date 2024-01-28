// https://codeforces.com/contest/57/problem/C
// 
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

ll c(ll n, ll r, ll m, vector<ll>& factorial, vector<ll>& inverse_factorial){
  return mod_mul(factorial[n], mod_mul(inverse_factorial[r], inverse_factorial[n-r], m), m);
}

pair<vector<ll>, vector<ll>> get_fact_inverse(ll upto = 1e7, ll mod = 1e9+7){
  vector<ll> factorial(upto+1);
  vector<ll> invfactorial(upto+1);
  factorial[0] = 1;
  for (ll i = 1; i <= upto; ++i){
    factorial[i] = mod_mul(factorial[i-1], i, mod);
  }
  invfactorial[upto] = mminvprime(factorial[upto], mod);
  for (ll i = upto - 1; i >= 0; i--){
    invfactorial[i] = mod_mul(invfactorial[i+1], i+1, mod);
  }
  return {factorial, invfactorial};
}

void solve() {
  pair<vector<ll>, vector<ll>> v = get_fact_inverse();

  ll n; cin >> n;
  cout << c(2*n-1, n, 1e9+7, v.ff, v.ss)*2 - n;
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
