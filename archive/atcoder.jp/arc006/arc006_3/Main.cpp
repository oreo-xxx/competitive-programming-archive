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
  ll n; cin >> n;
  vector<ll> a(n), used(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i){
    ll tmp = INF, idx;
    for(int j = 0; j < i; ++j){
      if(used[j]==1){continue;}
      if(a[j] >= a[i] && tmp>a[j]){
        tmp = a[j];
        idx = j;
      }
    }
    if(tmp==INF){continue;}
    used[idx]= 1;
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(used[i]==0){++ans;}
  }
  cout << ans << endl;
}
