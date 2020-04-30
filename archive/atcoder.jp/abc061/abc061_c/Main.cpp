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

int main(){
  ll n,k;cin >> n >> k;
  vector<pll> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  ll tmp = 0;
  for(int i = 0; i < n; ++i){
    tmp += a[i].second;
    if(tmp>=k){
      cout << a[i].first << endl;
      return 0;
    }
  }
}
