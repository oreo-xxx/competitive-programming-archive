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
  vector<ll> a(n), l(n), r(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  int j= 0;
  for(int i = 1; i < n; ++i){
    if(a[i-1]>a[i]){
      j= i;
      continue;
    }
    l[i]= i-j;
  }
  j = n-1;
  for(int i = n-2; i >= 0; --i){
    if(a[i] < a[i+1]){
      j = i;
      continue;
    }
    r[i]= j-i;
  }
  
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ll tmp= l[i]+ r[i]+ 1;
    ans=max(ans,tmp);
  }
  cout << ans << endl;
}
