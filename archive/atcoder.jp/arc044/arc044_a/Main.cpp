#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) return false;
    }
    return true;
}
int main(){
  ll n; cin >> n;
  ll org = n;
  bool f = is_prime(n);
  if(!f)
    {
  f = true;
  ll m = n%10;
  f &= (m%2==1);
  f &= (m!=5);
  ll k = 0;
  while(n>0){
    ll s = n % 10;
    k+= s;
    n /= 10;
  }
  f &= (k%3!=0);
    }
  string ans = "Not Prime";
  if(f && org != 1)ans = "Prime";
  cout << ans << endl;
}
