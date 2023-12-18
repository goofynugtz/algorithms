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

// PreCompute factors
vector<ll> factors[MAXM+5];
void calculateFactors(){
  for (ll i = 1; i <= MAXM; i++)
    for (ll j = i; j <= MAXM; j += i)
      factors[j].push_back(i);
}

// PreCompute factorials
ull factorial[int(1e5+1)];
void calcFactorial(){
  const ull mod = 1000000007;
  factorial[0] = 1;
  factorial[1] = 1;
  for(ull i = 2; i <= 1e5; ++i) {
    factorial[i] = (i*factorial[i-1]);
  }
}

// PreCompute Prime and Composite numbers
vector<bool> compute_primes(ll n){ vector<bool> isPrime(n, 1); isPrime[0] = isPrime[1] = 0; for (int i = 2; i*i <= n; i++) if (isPrime[i]) for (int j = i*i; j < n; j+=i) isPrime[j] = 0; return isPrime; }

// PreCompute all prime numbers
vector<ll> sieve(ll n){ ll*arr = new ll[n + 1](); vector<ll> primes; for (ll i = 2; i <= n; i++) if (arr[i] == 0){ primes.push_back(i); for (ll j = 2 * i; j <= n; j += i) arr[j] = 1; } return primes; }