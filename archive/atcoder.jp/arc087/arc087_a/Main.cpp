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
  map<ll, ll> mp;
  for(int i = 0; i < n; ++i){
    ll a;cin >> a;
    ++mp[a];
  }
  ll ans = 0;
  for(auto it : mp){
    ll tmp = 0;
    if(it.second>=it.first)tmp=it.second-it.first;
    else tmp = it.second;
    ans += tmp;
  }
  cout << ans << endl;
}

