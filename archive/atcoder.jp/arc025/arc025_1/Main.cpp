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
  int n = 7;
  vector<int> d(n),j(n);
  for(int i = 0; i < n; ++i) cin >> d[i];
  for(int i = 0; i < n; ++i) cin >> j[i];
  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans += max(d[i],j[i]);
  }
  cout << ans << endl;
}
