// https://codeforces.com/problemset/problem/1486/C1
// Rahul R, rahulranjan25.rr@gmail.com

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define ff      first
#define ss      second
#define sz(x)   ((int)(x).size())
#define all(x)  (x).begin(), (x).end()
#define INF     (int)1e18
#define PI      3.141592653589793238462
#define MOD7    1000000007
#define MOD9    998244353
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(NULL);                \
  cout.tie(NULL)

using ll =      long long;
using ull =     unsigned long long;
using lld =     long double;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (int i = 0; i < v.size(); ++i) os << v[i] << " "; return os; }
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
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
  #endif
}

struct Interactor {
  private:
    // TODO: 
    vector<ll> hidden;
    ll queries, max_limit; bool debug;
  public:
    Interactor(vector<ll> hn, 
    ll limit = 10, bool d = false){ 
      hidden = hn; 
      queries = 0; max_limit = limit; debug = d; }
    void __can_query() { if(queries >= max_limit) cout << "Made more than limit queries for " << hidden << endl; assert(queries < max_limit); }

    ll ask(ll l, ll r){
      #ifndef ONLINE_JUDGE
        __can_query(); queries++;
        ll m1 = -1, m2 = -1;
        ll i1 = -1, i2 = -1;
        cerr << "? " << l << " " << r << endl;
        for (ll i = l; i <= r; i++){
          if (hidden[i] > m1){
            i1 = i; m1 = hidden[i];
          }
        }
        for (ll i = l; i <= r; i++){
          if (hidden[i] > m2 && i != i1){
            i2 = i; m2 = hidden[i];
          }
        }
        cerr << i2 << endl;
        return i2;
      #else
        cout << "? " << l << " " << r << endl;
        ll x; cin >> x;
        return x;
      #endif
    }

    void answer(ll x){
      cout << "! " << x << endl;
    }
};

void solve(){
  ll n; cin >> n;
  // vector<ll> h = {-1, 
  // 98,52,63,2,18,96,31,58,84,40,
  // 41,45,66,100,46,71,26,48,81,20,
  // 73,91,68,76,13,93,17,29,64,95,
  // 79,21,55,75,19,85,54,51,89,78,
  // 15,87,43,59,36,1,90,35,65,56,
  // 62,28,86,5,82,49,3,99,33,9,
  // 92,32,74,69,27,22,77,16,44,94,
  // 34,6,57,70,23,12,61,25,8,11,
  // 67,47,83,88,10,14,30,7,97,60,
  // 42,37,24,38,53,50,4,80,72,39};
    vector<ll> h = {-1, 1,2};
  Interactor it = Interactor(h, 40, true);
  ll l = 1, r = n, ans = -1;
  while (l < r){
    if (l == r) break;
    if (l+1 == r){
      ll i = it.ask(l, r);
      if (i == l) r = r;
      else r = l;
      break;

    } else {
      ll mid = l+r/2-l/2;
      ll i = it.ask(l, r);
      if (i < mid){
        if (l != mid-1 && it.ask(l, mid-1) == i) r = mid-1;
        else l = mid;
      } else {
        if (mid != r && it.ask(mid, r) == i) l = mid;
        else r = mid-1;
      }
    }
  }
  it.answer(r);
}

int main(void){
  setIO();
  auto start = high_resolution_clock::now();
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cerr << "[!] Total Execution Time: " << duration . count() / 1000 << " ms" << endl;
  return 0;
}
