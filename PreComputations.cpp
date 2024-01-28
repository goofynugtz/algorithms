#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}
const ll inf = 1e17;
const ll MAXM = 1e5;

using lld  =          long double;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (auto i:v) os << i << " "; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "{" << p.ff << ", " << p.ss << "}"; return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) { for (auto i:s) os << i << " "; return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) { for (auto i:s) os << i << " "; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) { for (auto i: m) os << i.ff << " -> " << i.ss << "\n"; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) { for (auto i: m) os << i.ff << " -> " << i.ss << "\n"; return os; }

// PreCompute factors
vector<vector<ll>> get_all_factors(ll upto = 1e6){
  vector<vector<ll>> factors(upto+1);
  for (ll i = 1; i <= upto; i++) for (ll j = i; j <= upto; j += i) factors[j].push_back(i);
  return factors;
}

// PreCompute factorials
vector<ull> compute_factorials(ll upto = 1e5){
  vector<ull> factorial(upto+1);
  factorial[0] = factorial[1] = 1;
  for (ull i = 2; i <= upto; ++i) factorial[i] = (i*factorial[i-1]);
  return factorial;
}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll c(ll n, ll r, ll m, vector<ll>& factorial, vector<ll>& inverse_factorial){
  return mod_mul(factorial[n], mod_mul(inverse_factorial[r], inverse_factorial[n-r], m), m);
}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
pair<vector<ull>, vector<ull>> get_fact_inverse(ll upto = 1e6, ll mod){
  vector<ull> factorial(upto+1);
  vector<ull> invfactorial(upto+1);
  factorial[0] = 1;
  for (ull i = 1; i <= upto; ++i){
    factorial[i] = mod_mul(factorial[i-1], i, mod);
  }
  invfactorial[upto] = mminvprime(factorial[upto], mod);
  for (ll i = upto - 1; i >= 0; i--){
    invfactorial[i] = mod_mul(invfactorial[i+1], i+1, mod);
  }
  return {factorial, invfactorial};
}

// PreCompute Prime and Composite numbers
vector<bool> compute_primes(ll n){ vector<bool> isPrime(n, 1); isPrime[0] = isPrime[1] = 0; for (int i = 2; i*i <= n; i++) if (isPrime[i]) for (int j = i*i; j < n; j+=i) isPrime[j] = 0; return isPrime; }

// PreCompute all prime numbers
vector<ll> sieve(ll n){ ll*arr = new ll[n + 1](); vector<ll> primes; for (ll i = 2; i <= n; i++) if (arr[i] == 0){ primes.push_back(i); for (ll j = 2 * i; j <= n; j += i) arr[j] = 1; } return primes; }

vector<pair<ll,ll>> get_prime_factors_of(ll n){
  vector<pair<ll,ll>> factorization;
  for (ll d = 2; d*d <= n; d++){
    ll power = 0, x = n;
    while (n % d == 0){
      n /= d; power++;
    }
    if (x % d == 0) factorization.push_back({d, power});
  }
  if (n > 1) factorization.push_back({n,1});
  return factorization;
}

vector<vector<pair<ll,ll>>> compute_prime_factors(ll upto = 1e6){
  vector<vector<pair<ll,ll>>> pfs(upto+1);
  for (ll i = 1; i <= upto; i++) pfs[i] = get_prime_factors_of(i);
  return pfs;
}

vector<ll> get_spf(){
  vector<ll> spf(1e5+1);
  for (ll i = 1; i <= 1e5; i++) spf[i] = i;
  for (ll i = 2; i <= 1e5; i++) for (ll j = 2*i; j <= 1e5; j+=i) if (spf[j] == j) spf[j] = i;
  return spf;
}

// int main(void){
//   vector<vector<pair<ll,ll>>> pfs = compute_prime_factors();
//   for (ll i = 1; i <= 100; i++){
//     cerr << i << ": ";
//     for (auto it: pfs[i]) cerr << it.first << " ";
//     cerr << "\n";
//   }
//   cerr << "\n";
// }