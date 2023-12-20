// https://codeforces.com/problemset/problem/679/A
// Rahul R, rahulranjan25.rr@gmail.com

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define INF (int)1e18
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(NULL);                \
  cout.tie(NULL)

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define PI 3.141592653589793238462
#define MOD7 1000000007
#define MOD9 998244353

using ll = long long;
using ull = unsigned long long;
using lld = long double;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "[ "; for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << " "; } os << " ]"; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "{" << p.ff << ", " << p.ss << "}"; return os; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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
    // freopen("input.txt","r",stdin); 
    // freopen("output.txt","w",stdout); 
  #endif 
}

struct Interactor {
  private:
    ll hidden_number;
    string answer;
    vector<bool> isPrime;
    ll queries;
    ll max_limit;
    bool debug;
  public:
    Interactor(ll n, ll limit = 10, bool d = false){
      hidden_number = n;
      isPrime = compute_primes(n);
      // sleep(2);
      answer = isPrime[hidden_number] ? "prime" : "composite";
      queries = 0;
      max_limit = limit;
      debug = d;
    }

    void __can_query(){ 
      if(queries >= max_limit) cout << "Made more than limit queries for " << hidden_number << endl; 
      assert(queries < max_limit); 
    }

    string make_query(ll x){
      __can_query(); queries++;
      if (debug) cerr << "? " << x << endl;

      if (hidden_number % x == 0) return "yes";
      else return "no";
    }

    void validate(string s){
      answer == s ? cout << "Passed for " << s << endl : cout << "Failed for " << s << endl;
    }

    void show_answer(){
      cout << hidden_number << endl;
    }
};

void solve() {
  Interactor intrctr = Interactor(95, 20, true);
  vector<ll> primes = sieve(101);
  cerr << primes << endl;
  ll tries = 0;
  map<ll, bool> primeFactors;

  // Check for 2, 3, 5, 7
  ll counter = 0;
  for (ll i = 0; i < 4 && tries < 20; i++){
    tries++;
    string response; 
    cout << primes[i] << endl;
    cin >> response;
    // response = intrctr.make_query(primes[i]);
    if (response == "yes"){
      primeFactors[primes[i]] = true;
      counter++;
    }
  }
  if (counter == 0){
    // intrctr.validate("prime");
    cout << "prime" << endl;
    return;

  } else if (counter > 1){
    // intrctr.validate("composite");
    cout << "composite" << endl;
    return;

  } else if (counter == 1){
    vector<ll> chckfr;
    if (primeFactors[primes[0]]){
      chckfr.push_back(4);
      for (ll i = 4; i < 15; i++) chckfr.push_back(primes[i]);

    } else if (primeFactors[primes[1]]){
      chckfr.push_back(9);
      for (ll i = 4; i < 11; i++) chckfr.push_back(primes[i]);
    
    } else if (primeFactors[primes[2]]){
      chckfr.push_back(25);
      for (ll i = 4; i < 8; i++) chckfr.push_back(primes[i]);
    
    } else if (primeFactors[primes[3]]){
      chckfr.push_back(49);
      for (ll i = 4; i < 6; i++) chckfr.push_back(primes[i]);
    }
    cerr << chckfr << endl;
    for (ll i = 0; i < chckfr.size(); i++){
      cout << chckfr[i] << endl;
      string response; cin >> response;
      // string response = intrctr.make_query(chckfr[i]);
      if (response == "yes"){
        // intrctr.validate("composite");
        cout << "composite" << endl;
        return;
      }
    }
    // intrctr.validate("prime");
    cout << "prime" << endl;
    return;
  }
}

int main(void){
  setIO();
  auto start = high_resolution_clock::now();
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cerr << endl << "[!] Total Execution Time: " << duration . count() / 1000 << " ms" << endl;
  return 0;
}
