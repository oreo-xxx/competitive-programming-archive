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

int main() {
  ll n;cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  sort(a.begin(),a.end());
  vector<ll> sum(n+1);
  map<ll, ll> mp;
  for(int i = 0; i < n; ++i){
    sum[i+1]=sum[i]+a[i];
    ++mp[a[i]];
  }
  ll ans1 = 0, ans2= 1;
  for(int i = 0; i <= n; ++i){
    ans1 += sum[i];
  }
  cout << ans1 << endl;
  for(auto it : mp){
    ll tmp= 1;
    for(int i = 1; i <= it.second; ++i){
      tmp*=i;
      tmp%=MOD;
    }
    ans2 *= tmp;
    ans2 %= MOD;
  }
  cout << ans2 << endl;
}

