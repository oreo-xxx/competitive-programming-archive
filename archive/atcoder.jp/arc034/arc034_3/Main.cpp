#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

map<ll, ll> mp;
void prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        mp[p] += num;
    }
    if (n != 1) mp[n] += 1;
}

int main() {
  ll a,b;cin >>a>> b;
  for(ll i = b+1; i <=a; ++i){
    prime_factorize(i);
  }
  ll ans=1;
  for(auto it : mp){
    ans *= it.second+1LL;
    ans %= MOD;
  }
  cout << ans << endl;
}
