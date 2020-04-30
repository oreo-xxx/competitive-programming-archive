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
  int n;cin >>n;
  vector<pll> a(n);
  for(int i = 0; i < n; ++i){
    cin >>a[i].first >> a[i].second;
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    ll x3 =a[i].first;
    ll y3 =a[i].second;
    for(int j = i+1; j < n; ++j){
      ll x2 = a[j].first;
      ll y2 = a[j].second;
      for(int k = j+1; k < n; ++k){
        ll x1=a[k].first;
        ll y1=a[k].second;
        ll s=abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));
        if(s%2==0 && s!= 0){++ans;}
      }
    }
  }
  cout << ans << endl;
}
